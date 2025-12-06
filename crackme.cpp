/* crackme */
#include <iostream>

// get input from user like python
std::string input(const char* text)
{
    std::string buffer;
    std::cout << text;
    std::cin >> buffer;
    return buffer;
}

// check if token is valid
bool verify(std::string token)
{
    return token == "amAmDdCJhTvUh6sV1AsZhfTEieAxbRtbgP1TkKnyK4snWpPGNwCwQi";
}

// main entry point
int main(int argc, char const *argv[])
{
    // get token from user input
    std::string token = input("activation token: ");
    
    // check if token is valid
    if (verify(token))
      std::cout << "[info] Congratulations ure GOAT!" << '\n';
    else 
       std::cout << "[info] Invalid token!" << '\n';

    return 0;
}
