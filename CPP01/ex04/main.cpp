#include <iostream>
#include <fstream>
#include <string>

//ofstream = creates and writes infiles
//ifstream = reads from files
//fstream = combi of ofstream and ifstream: creates, reads and writes into files

// TESTS
// ./prog.out
// ./prog.out "A"
// ./prog.out emptyfile "hello" "world"
// ./prog.out Makefile "" ""
// ./prog.out Makefile "" "C"
// ./prog.out Makefile "C" ""
// ./prog.out Makefile "NAME" "CASEY"
// ./prog.out norights "hello" "world"
// ./prog.out spaces " " "A"
// ./prog.out spaces " " "     "
// ./prog.out lalaland.txt " " "X"
// ./prog.out lalaland.txt "a" ""

int	open_files(std::string& infile, std::string& outfile, std::ifstream& input, std::ofstream& output);
void	copy_file(std::ifstream& infile, std::ofstream& outfile, std::string& from, std::string& to);

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./prog <file> <s1> <s2>\n";
		return (1);
	}
	std::string infile = av[1];
	std::string	outfile = infile + ".replace";
	std::ifstream input;
	std::ofstream output;
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (!open_files(infile, outfile, input, output))
		return (2);
	copy_file(input, output, s1, s2);
	output.close();
	input.close();
}

int	open_files(std::string& infile, std::string& outfile, std::ifstream& input, std::ofstream& output)
{
	input.open(infile.c_str());
	if (input.fail())
	{
		std::cerr << "Could not open infile\n";
		return (0);
	}
	output.open(outfile.c_str());
	if (output.fail())
	{
		std::cerr << "Could not create outfile\n";
		input.close();
		return (0);
	}
	return (1);
}

void	replace_buffer(std::string& buffer, std::string& from, std::string& to)
{
	size_t	found_pos = 0;

	if (from.empty())
		return ;
	while (found_pos != std::string::npos)
	{
		found_pos = buffer.find(from, found_pos);
		if (found_pos != std::string::npos)
		{
			buffer.erase(found_pos, from.length());
			buffer.insert(found_pos, to);
			if (!to.empty())
				found_pos += to.length();
		}
	}
}

void	copy_file(std::ifstream& infile, std::ofstream& outfile, std::string& from, std::string& to)
{
	std::string	buffer;

	while (std::getline(infile, buffer))
	{
		if (infile.fail())
		{
			std::cerr << "Error: getline failed" << std::endl;
			return;
		}
		replace_buffer(buffer, from, to);
		if (!infile.eof())
			buffer += "\n";
		outfile << buffer;
	}
}
