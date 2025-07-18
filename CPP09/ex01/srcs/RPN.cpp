#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return (*this);
}

void	RPN::calculate(std::string& input)
{
	std::istringstream iss(input);

	std::string buff;
	
	while (iss >> buff)
	{
		if (buff.size() != 1)
			throw std::invalid_argument("inputs should be 1 character");
		if (std::isdigit(buff[0]))
			stack.push(atoi(buff.c_str()));
		else 
		{
			if (buff[0] != '+' && buff[0] != '-' && buff[0] != '*' && buff[0] != '/')
					throw std::invalid_argument("operator not recognised: " + buff);
			if (stack.size() < 2)
				throw std::logic_error("cannot complete calculation, < 2 nums in stack");
			int b = this->pop();
			int a = this->pop();
			switch (buff[0])
			{
				case '+':
					stack.push(a + b);
					continue;
				case '-':
					stack.push(a - b);
					continue;
				case '*':
					stack.push(a * b);
					continue;
				case '/':
					if (b == 0)
						throw std::logic_error("division by zero");
					stack.push(a / b);
					continue;
				default:
					throw std::invalid_argument("input not recognised" + buff);
			}
		}

	}
	if (stack.size() != 1)
		throw std::logic_error("cannot complete calculation, more than 1 num left in stack");
	std::cout << stack.top() << std::endl;
}

int	RPN::pop(void)
{
	int temp = stack.top();
	stack.pop();
	return (temp);
}

void	RPN::print_stack(void) const
{
	std::cout << "printing stack" << std::endl;
	MutantStack<int>::const_iterator it = stack.begin();

	while (it != stack.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}
