#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base(void)
{
	return	;
}

Base*	generate(void)
{
	unsigned int num = std::rand() % 10;
	if (num >= 0 && num <= 3)
	{
		std::cout << "New 'A' created" << std::endl;
		return (new A());
	}
	else if (num >= 4 && num <= 6)
	{
		std::cout << "New 'B' created" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "New 'C' created" << std::endl;
		return (new C());
	}
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "Ptr: This is type 'A'." << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "Ptr: This is type 'B'." << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "Ptr: This is type 'C'." << std::endl;
		return ;
	}
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Ref: This is type 'A'." << std::endl;
		return ;
	}
	catch (std::exception& e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Ref: This is type 'B'." << std::endl;
		return ;
	}
	catch (std::exception& e){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Ref: This is type 'C'." << std::endl;
		return ;
	}
	catch (std::exception& e){}
}
