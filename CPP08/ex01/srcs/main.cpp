#include "Span.hpp"


void	subject_test();
void	test_fill_iterator_function();
void	test_exceptions();
void	test_fill_exceeding_capacity();
void	test_copy_constructor();
void	test_copy_assignment_constructor();


void	print_int_array(int *array, unsigned long size);
void	printHeader(void);
void	printFooter(void);
void	printDivider(void);
std::vector<int>	fill_vector(int *testValues, int size);

int main()
{
	printHeader();
	
	// TEST 1
	subject_test();
	printDivider();
	
	// TEST 2
	test_fill_iterator_function();
	printDivider();

	// TEST 3
	test_exceptions();
	printDivider();

	// TEST 4
	test_fill_exceeding_capacity();
	printDivider();

	// TEST 5
	test_copy_constructor();
	printDivider();

	// TEST 6
	test_copy_assignment_constructor();
	printFooter();
}

void	subject_test()
{
	std::cout << "-- SUBJECT TEST --" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print(INFO);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_fill_iterator_function()
{
	std::cout << "-- SUBJECT TEST BUT USING FILL ITERATOR FUNCTION --" << std::endl;
	Span sp = Span(5);
	int testValues[] = {6, 3, 17, 9, 11};

	std::vector<int> vec = fill_vector(testValues, sizeof(testValues)/sizeof(int));

	sp.fill(vec.begin(), vec.end());

	sp.print(INFO);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_exceptions()
{
	std::cout << "-- TESTING SPAN EXCEPTIONS, NOT ENOUGH VALUES --" << std::endl;
	Span sp = Span(1);
	int testValues[] = {6};

	std::vector<int> vec = fill_vector(testValues, sizeof(testValues)/sizeof(int));

	std::cout << "Attempting to call shortestSpan()" << std::endl;
	try
	{
		sp.fill(vec.begin(), vec.end());
		sp.print(INFO);
		std::cout << sp.shortestSpan() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl << std::endl;
	}
	
	std::cout << "Attempting to call longestSpan()" << std::endl;
	try
	{
		Span empty(5);
		empty.print(INFO);
		std::cout << empty.longestSpan() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}

void	print_int_array(int *array, unsigned long size)
{
	for (unsigned long i = 0; i < size; i++)
		std::cout << "[" << array[i] << "] ";
	std::cout << std::endl;
}

void	test_fill_exceeding_capacity()
{
	std::cout << "-- TEST FILL EXCEEDING CAPACITY --" << std::endl;
	Span sp = Span(3);
	int testValues[] = {600, 3, 170, -99, 111};

	try
	{
		std::vector<int> vec = fill_vector(testValues, sizeof(testValues)/sizeof(int));
		std::cout << "Attempting to add 5 elements with capacity of 3" << std::endl;
		std::cout << "Values trying to add: ";
		print_int_array(testValues, sizeof(testValues)/sizeof(int));
		sp.fill(vec.begin(), vec.end());
		sp.print(INFO);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
		sp.print(INFO);
	}


}

void	test_copy_constructor()
{
	std::cout << "-- TEST COPY CONSTRUCTOR --" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);

	std::cout << "ORIGINAL SPAN: " << std::endl;
	sp.print(INFO);

	Span copy(sp);
	std::cout << "COPY SPAN: " << std::endl;
	copy.print(INFO);

	std::cout << "MODIFYING COPY -> adding number 0" << std::endl;
	copy.addNumber(0);
	copy.print(INFO);

	std::cout << "ORIGINAL SPAN HASNT CHANGED" << std::endl;
	sp.print(INFO);
}

void	test_copy_assignment_constructor()
{
	std::cout << "-- TEST COPY ASSIGNMENT CONSTRUCTOR --" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);

	std::cout << "ORIGINAL SPAN: " << std::endl;
	sp.print(INFO);

	Span copy = sp;
	std::cout << "COPY SPAN: " << std::endl;
	copy.print(INFO);

	std::cout << "MODIFYING COPY -> adding number 0" << std::endl;
	copy.addNumber(0);
	copy.print(INFO);

	std::cout << "ORIGINAL SPAN HASNT CHANGED" << std::endl;
	sp.print(INFO);
}


std::vector<int>	fill_vector(int *testValues, int size)
{
	std::vector<int> values;
	for (int i = 0; i < size; i++)
		values.push_back(testValues[i]);
	return values;
}

void	printHeader(void)
{
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "#####################  -----------  TESTING   ------------ #########################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << std::endl;
}

void	printFooter(void)
{
	std::cout << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "#####################  -----------  THE END   ------------ #########################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << std::endl;
}

void	printDivider(void)
{
	std::cout << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << "####################################################################################" << std::endl;
	std::cout << std::endl;
}
