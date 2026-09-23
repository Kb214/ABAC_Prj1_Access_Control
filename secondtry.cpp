#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>

struct User_Attrib{
    int User_ID;
    std::string random_attrib; 
};

int main(){
    int numb_att;
    std::string attribute;
    std::vector<std::string> a;

    std::cout << "How many attributes? : ";
    std::cin >> numb_att;

    std::vector<User_Attrib> UA;
    

    for(int i = 0; i < numb_att; i++){
        std::cout << "Enter Attribute: ";
        std::cin >> attribute;
        a.push_back(attribute);
    }

    std::cout << "\n\n";

    std::random_device rd;
    std::mt19937 gen(rd());

    std::cout << "Generated Users and Attributes:\n";
    for(int p = 0; p < 10; p++){
        User_Attrib newatt;
        std::shuffle(a.begin(),a.end(), gen);
        std::uniform_int_distribution<size_t> dist(2,numb_att);
        int random = dist(gen);

        std::cout << "User " << p + 1 << ": {";

        for(int i = 0; i < random; i++){
            std::cout <<  a.at(i) << ", ";
        }
        std::cout << "}";


        std::cout << "\n";

    }

   

    return 0;
}