#include <stdio.h>
#include <iostream>
#include <fstream>


void main()
{
    std::ifstream file("input.txt");
    std::string str;
    while (std::getline(file, str))
    {
        std::cout << str << std::endl;
    }
}