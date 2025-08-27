#include "MutantStack.hpp"
#include <stack>
#include <list>

void	subject_test();
void	list_vs_subject_test();
void	vector_test();
void	strings_test();

int main()
{
	printHeader();

	subject_test();
	printDivider();

	list_vs_subject_test();
	printDivider();

	strings_test();
	printDivider();

	printFooter();
}

void	list_vs_subject_test()
{
	printStr("--- TEST: LIST VS STACK ---");
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Back of list: " << mstack.back() << std::endl;
	printStr("Executing lst pop back - removing last in list");
	mstack.pop_back();
	std::cout << "List size: " << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	printStr("*Iterating through list*");
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}


void	subject_test()
{
	printStr("--- SUBJECT TEST: MUTANT STACK INTS ---");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top of stack: " << mstack.top() << std::endl;
	printStr("Executing stack pop - removing last added");
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	printStr("*Iterating through stack*");
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	strings_test()
{
	printStr("--- TEST: MUTANT STACK STRINGS ---");
	MutantStack<std::string> mstack;
	mstack.push("First");
	mstack.push("Second");
	std::cout << "Top of stack: " << mstack.top() << std::endl;
	printStr("Executing stack pop - removing last added");
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << std::endl;
	mstack.push("Third");
	mstack.push("Fourth");
	mstack.push("Fifth");
	mstack.push("Sixth");
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	++it;
	--it;
	printStr("*Iterating through stack*");
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<std::string> s(mstack);
}
