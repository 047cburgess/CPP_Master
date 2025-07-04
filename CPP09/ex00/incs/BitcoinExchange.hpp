#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdlib.h>

class	BitcoinExchange
{
	private:
		std::map<std::string, float> _database;
		std::string _inputFile;
		void	launch(void);
		std::map<int, int> _monthDayMapping;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& infileName);
		//BitcoinExchange(const BitcoinExchange& other);
		//BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void	printDatabase() const;
		void	setUpDatabase();
		float	convert(std::string& date, std::string& value);

};

int	is_valid_date(std::string& date);
int	is_valid_day(int year, int month, int day);
int	is_leapyear(int year);
int	is_valid_value(std::string& value);
