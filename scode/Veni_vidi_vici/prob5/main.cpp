#include <iostream>
#include <string>

int main()
{
    std::string r;
    std::string k;
    std::string w;
    std::string r1;
    std::string r2;
    std::string test;
    
    std::getline(std::cin, r);
    std::getline(std::cin, k);
    std::getline(std::cin, w);
    
    r1 = r;
    r2 = r;
    r1[2] = w[2];
    r2[1] = w[1];
    
    if (k[1] == r[1] && k[2] == r[2])
    {
        test = "NO";
        std::cout << test;
    }
    else
    {
        test = "YES";
        std::cout << test;
    }
    
    return 0;
}

