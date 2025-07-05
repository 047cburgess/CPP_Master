#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdlib.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"


class	BitcoinExchange
{
	private:
		std::map<std::string, float> _database;
		void	processLine(std::string& line);
		float	getExchangeRate(const std::string& date);
		float	convert(const std::string& value, const float& exchangeRate);
		void	printDatabase() const;
		static int	is_valid_date(std::string& date);
		static int	is_valid_day(int year, int month, int day);
		static int	is_leapyear(int year);
		static int	is_valid_value(std::string& value);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	setUpDatabase(void);
		void	launch(const std::string& filename);

};

