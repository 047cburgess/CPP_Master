#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{


}


// Parses the bitcoin database into a map.
// Check for additional parsing/errors etc
void	BitcoinExchange::setUpDatabase(void)
{
	std::ifstream database("data.csv");
	if (!database.good())
		throw std::runtime_error("Unable to open data.csv");

	std::string line;

	// Skip header of file
	std::getline(database, line);
	if (line != "date,exchange_rate")
		throw std::invalid_argument("Database missing valid header");
	while (std::getline(database, line))
	{
		std::istringstream iss(line);
		std::pair<std::string, float> entry;
		if (!std::getline(iss, entry.first, ',') || !(iss >> entry.second))
			throw std::invalid_argument("Database is formatted incorrectly: " + line);
		_database.insert(entry);
	}
}

float	BitcoinExchange::getExchangeRate(const std::string& date)
{
	std::map<std::string, float>::iterator it = _database.begin();
	std::map<std::string, float>::iterator ite = _database.end();
	ite--;

	if (date < it->first)
		throw std::out_of_range ("date earlier than 1st database entry: " + date + "/" + it->first);
	if (date > ite->first)
		throw std::out_of_range ("date later than last database entry: " + date + "/" + ite->first);

	it = _database.upper_bound(date);
	it--;
	return (it->second);
}

float BitcoinExchange::convert(const std::string& value, const float& exchangeRate)
{
	char* endptr;
	float f = std::strtof(value.c_str(), &endptr);
	(void)endptr;

	return (f * exchangeRate);
}

void	BitcoinExchange::processLine(std::string& line)
{
	std::string date;
	std::string pipe;
	std::string value;

	if (line.empty())
		return ;

	std::istringstream iss(line);
	if (!(iss >> date) || !is_valid_date(date))
		throw std::invalid_argument("Not valid date: " + date);
	if (!(iss >> pipe) || pipe != "|")
		throw std::invalid_argument("Not valid syntax: <date> | <value> : " + line);
	if (!(iss >> value) || !is_valid_value(value))
		throw std::invalid_argument("Value is not a positive number (0 - 1000): " + value);

	float	exchangeRate = getExchangeRate(date);
	float final = convert(value, exchangeRate);

	std::cout << GREEN << date << "=> " << value << " = " << final << " /xrate= " << exchangeRate << RESET << std::endl;
}

void	BitcoinExchange::launch(const std::string& filename)
{
	std::ifstream infile(filename.c_str());

	if (!infile.good())
		throw std::runtime_error("Could not open infile...");

	std::string line;
	if (!std::getline(infile, line) || line != "date | value")
		throw std::invalid_argument("invalid header format on infile");

	while (std::getline(infile, line))
	{
		try 
		{
			processLine(line);
		}
		catch (std::exception &e)
		{
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
}



int	BitcoinExchange::is_valid_value(std::string& value)
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

int	BitcoinExchange::is_leapyear(int year)
{
	if (year % 4 != 0)
		return (0);
	if (year % 100 != 0)
		return (1);
	if (year % 400 == 0)
		return (1);
	return (0);
}

int	BitcoinExchange::is_valid_day(int year, int month, int day)
{
	if (day <= 0 || day > 31)
		return (0);

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month == 2 && is_leapyear(year))
		daysInMonth[2] = 29;
	return (day <= daysInMonth[month]);
}

int	BitcoinExchange::is_valid_date(std::string& date)
{
	// Checking right syntax [YYYY-MM-DD]
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (0);
	
	double year;
	double month;
	double day;

	std::string dayStr = date.substr(8, 2);
	std::string monthStr = date.substr(5, 2);
	std::string yearStr = date.substr(0, 4);

	// Checking they are all digits
	if (dayStr.find_first_not_of("0123456789") != std::string::npos)
		return (0);
	if (monthStr.find_first_not_of("0123456789") != std::string::npos)
		return (0);
	if (yearStr.find_first_not_of("0123456789") != std::string::npos)
		return (0);

	year = atoi(yearStr.c_str());
	month = atoi(monthStr.c_str());
	day = atoi(dayStr.c_str());

	if (month <= 0 || month > 12)
		return (0);
	if (!is_valid_day(year, month, day))
		return (0);
	return (1);
}


void	BitcoinExchange::printDatabase(void) const
{
	std::map<std::string, float>::const_iterator it = _database.begin();
	for (; it != _database.end(); it++)
		std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
}
