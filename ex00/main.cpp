#include <iostream>

int main(int argc, char *argv[])
{
    std::string word;

    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        word = argv[i];
        for (size_t c = 0; c < word.length(); c++)
        {
            std::cout << static_cast<char>(std::toupper(word[c]));
        }
        std::cout << " ";
    }
    std::cout << "\n";
    return 0;
}