#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>

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
        
        std::shuffle(a.begin(),a.end(), gen);
        std::uniform_int_distribution<size_t> dist(2,numb_att);
        std::string rand_a = a[dist(gen)];
        int random = dist(gen);

    
        std::cout << "User " << p + 1 << ": {";

        for(int i = 0; i < random; i++){
            std::cout <<  a.at(i) << ", ";
            UA.emplace_back(User_Attrib{p + 1,a.at(i)});
            
        }
    

        std::cout << "}";

        // UA.emplace_back(User_Attrib{p + 1, rand_a});
       

        std::cout << "\n";

    }

    // std::cout << "\nall user attributes stored in struct and vector: \n";
    // for(auto m : UA){

    //     std::cout << m.User_ID << ": " << m.random_attrib << "\n\n";
    // }

   

    return 0;
}