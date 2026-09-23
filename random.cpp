#include <iostream>
#include <random>
#include<ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>

int main(){
    std::vector<std::string> attr{"student","staff","execute","read","write"};
    std::vector<std::string> usr_attr;

    std::random_device rd_attr;
    // std::uniform_int_distribution<size_t> dist(2, attr.size()- 1);
    // std::shuffle(attr.begin(), attr.end(),rd_attr);
    usr_attr.resize(2, attr.size());

     std::mt19937 gen(rd_attr());
     std::ranges::sample(attr,)
    std::unordered_set<std::string> attr_set;
    for(auto a : attr){
        std::cout << a << " " << '\n';
    }


    return 0;
}