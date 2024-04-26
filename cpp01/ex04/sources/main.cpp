#include <iostream>
#include <fstream>

static void	replace(std::ifstream &input, std::ofstream &output, std::string const &S1, std::string const &S2);

int main(int argc, char *argv[])
{
	if (argc != 4){
		std::cerr << "Usage: " << argv[0] << " <filename> <S1> <S2>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input.is_open()){
		std::cerr << "Unable to open file:" << argv[1] << std::endl;
		return (1);
	}

    std::ofstream output((std::string(argv[1]) + ".replace").c_str());
	if (!output.is_open()){
		input.close();
		std::cerr << "Unable to create output file" << std::endl;
		return (1);
	}

	replace(input, output, argv[2], argv[3]);
	input.close();
	output.close();
	return 0;
}

static void replace(std::ifstream &input, std::ofstream &output, const std::string &S1, const std::string &S2)
{
    std::string line;
    while (std::getline(input, line))
    {
        size_t skipPos = line.find(S1);
        while (skipPos != std::string::npos)
        {
            output << line.substr(0, skipPos) << S2;
            line = line.substr(skipPos + S1.length());
            skipPos = line.find(S1);
        }
        output << line << std::endl;
    }
}
