#pragma once

class RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
};
