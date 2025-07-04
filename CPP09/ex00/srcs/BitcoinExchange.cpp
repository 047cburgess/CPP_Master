#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const std::string& infileName): _inputFile(infileName)
{
	this->setUpDatabase();
	//this->printDatabase();
	this->launch();
}

BitcoinExchange::~BitcoinExchange(void)
{


}


float BitcoinExchange::convert(std::string& date, std::string& value)
{
	std::map<std::string, float>::iterator it = _database.begin();

	if (date < it->first)
		throw std::out_of_range ("Error: date too early vs database");

	it = _database.upper_bound(date);
	it--;
	char* endptr;
	float f = std::strtof(value.c_str(), &endptr);
	(void)endptr;

	return (f * it->second);
}


void	BitcoinExchange::launch(void)
{
	std::ifstream infile(_inputFile.c_str());

	if (!infile.good())
		throw std::range_error("Could not open infile...");

	std::string line;
	std::getline(infile, line);
	std::string date;
	std::string pipe;
	std::string value;
	if (line != "date | value")
		throw std::range_error("invalid header format on infile");
	while (std::getline(infile, line))
	{
		date.clear();
		pipe.clear();
		value.clear();
		if (line.empty())
			continue;
		std::istringstream iss(line);
		iss >> date;
		if (!is_valid_date(date))
		{
			std::cout << "Error: Not valid date: " << date << std::endl;
			continue;
		}
		iss >> pipe;
		if (pipe != "|")
		{
			std::cout << "Error: Not valid syntax" << std::endl;
			continue;
		}
		iss >> value;
		if (iss.fail())
			std::cout << "Error: Not valid value";
		if (!is_valid_value(value))
		{
			std::cout << "Error: Not valid value: " << value << std::endl;
			continue;
		}

		float final;
		try 
		{
			final = convert(date, value);
			std::cout << date << " => " << value << " = " << final << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}



int	is_valid_value(std::string& value)
{
	char* endptr;
	errno = 0;
	float f = std::strtof(value.c_str(), &endptr);
	if (f < 0 || f > 1000)
		return (0);
	if (errno == ERANGE || *endptr != '\0')
		return (0);
	return (1);
}

int	is_leapyear(int year)
{
	if (year % 4 != 0)
		return (0);
	if (year % 100 != 0)
		return (1);
	if (year % 400 == 0)
		return (1);
	return (0);
}

int	is_valid_day(int year, int month, int day)
{
	if (day <= 0 || day > 31)
		return (0);
	if (month == 2)
	{
		if (day > 29 || (day == 29 && !is_leapyear(year)))
			return (0);
	}
	if (month == 9 || month == 4 || month == 6 || month == 11)
	{
		if (day > 30)
			return (0);
	}
	if (day > 31)
		return (0);
	return (1);
}

int	is_valid_date(std::string& date)
{
	// Checking right syntax
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (0);
	
	double year;
	double month;
	double day;
	std::istringstream iss(date);
	std::string buffer;

	std::getline(iss, buffer, '-');
	if (buffer.find_first_not_of("0123456789") != std::string::npos)
		return (0);
	year = atoi(buffer.c_str());
	if (year <= 0)
		return (0);
	buffer.clear();
	std::getline(iss, buffer, '-');
	if (buffer.find_first_not_of("0123456789") != std::string::npos)
		return (0);
	month = atoi(buffer.c_str());
	if (month <= 0 || month > 12)
		return (0);

	buffer.clear();
	std::getline(iss, buffer, '-');
	if (buffer.find_first_not_of("0123456789") != std::string::npos)
		return (0);
	day = atoi(buffer.c_str());
	if (!is_valid_day(year, month, day))
		return (0);
	return (1);
}

void	BitcoinExchange::setUpDatabase(void)
{
	std::ifstream database("data.csv");
	if (!database.good())
		throw std::range_error("Unable to open data.csv");
	std::string line;

	// Skip header of file
	std::getline(database, line);
	while (std::getline(database, line))
	{
		std::istringstream iss(line);
		std::pair<std::string, float> entry;
		std::getline(iss, entry.first, ',');
		iss >> entry.second;
		_database.insert(entry);
	}
}

void	BitcoinExchange::printDatabase(void) const
{
	std::map<std::string, float>::const_iterator it = _database.begin();
	for (; it != _database.end(); it++)
		std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
}
