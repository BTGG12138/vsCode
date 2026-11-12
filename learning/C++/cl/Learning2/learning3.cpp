#include <iostream>
#include <sstream>
#include <string>
int main() 
{
    std::string filename = "00205.txt.123";
    std::stringstream ss(filename);
    std::string token;

    while (std::getline(ss, token, '.')) {
        std::cout << token << std::endl;
    }
    return 0;
}