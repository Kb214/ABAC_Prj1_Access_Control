#include <iostream>
#include <random>
#include<ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>

struct User_Attrib{
    int u;
    std::string att;
};


int main(){
    // std::vector<std::string> attr{"student","staff","execute","read","write"};
    // std::vector<std::string> usr_attr;

    // std::random_device rd_attr;
    // // std::uniform_int_distribution<size_t> dist(2, attr.size()- 1);
    // // std::shuffle(attr.begin(), attr.end(),rd_attr);
    // usr_attr.resize(2, attr.size());

    // std::mt19937 gen(rd_attr());
    // std::ranges::sample(attr);
    // std::unordered_set<std::string> attr_set;

    int users = 10;
    int n = 5;
    
    std::vector<std::string> attr{"student","staff","execute","read","write"};
    std::vector<User_Attrib> UA;

    std::random_device rd_attr;
    std::mt19937 gen(rd_attr());


    for(int i = 0; i < users; i++){

        std::shuffle(attr.begin(), attr.end(), gen);

        std::uniform_int_distribution<size_t> dist(2,n);
        int random = dist(gen);


        std::cout << "User " << i + 1 << ": " << random;
        std::cout << "\n\n";
    }

    // for(auto a : attr){
    // std::cout << a << " " << '\n';
    // }


    return 0;
}