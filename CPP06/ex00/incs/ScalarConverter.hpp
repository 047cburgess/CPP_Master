#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class	ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static void	convert(const std::string input);
};

bool	isChar(const std::string& input);
bool	isPseudoLiteral(const std::string& input);
bool	isInt(const std::string& input);
bool	isDouble(const std::string& input);
bool	isFloat(const std::string& input);
void	convertChar(const std::string input);
void	convertInt(const std::string& input);
void	convertDouble(const std::string& input);
void	convertFloat(const std::string& input);
void	printImpossible(void);
void	convertPseudoLiteral(const std::string& input);

#endif
