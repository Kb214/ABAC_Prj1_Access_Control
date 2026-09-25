#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>

/*
DESCRIPTION:

1. Input number of n total attribs in system [X]
2. generate n-type of attrbs [X]
3. generate 10 users with random attrbs from set of n [at least 2]  [ X ]
4. prog allows user input as (attrib1 AND attrib2)OR
                             (2 of (attrib3, attrib4, attrib5)); [ ]
                             (attrib1 AND attrib2)OR
                             (attrib3 AND attrib4)
[AND, OR need to be capitalized]
5. evaluation is processed when user inputs attrbs. program returns true or false [ ]



*/

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

        std::cout << "\n";

    }

    
    while(true){
        std::cout << "\nEnter UserID: ";
        int id;
        std::cin >> id;

        std::cout << "\nEnter Attribute-Based Policy for the user: ";
        std::string policy;
        std::cin.ignore(); // Ignore the newline character left in the input buffer
        std::getline(std::cin, policy);


        if(policy == UA[id - 1].random_attrib){
            std::cout << "Policy is valid.\n";
            std::cout << "User " << id << " has the attribute " << policy << ".\n";

        } else{
            std::cout << "Policy is invalid. Please enter a valid policy.\n";}

        // if(policy == "AND" || policy == "OR" && policy == attribute || policy == attribute){
        //     std::cout << "Policy is valid.\n";
        //     std::cout << "User " << id << " has the attribute " << attribute << ".\n";
        // } else if(policy != "AND" && policy != "OR" && policy != attribute || policy != attribute){
        //     std::cout << "Policy is invalid. Please enter a valid policy.\n";
        //     std::cout << "User " << id << " does not have the attribute " << attribute << ".\n";
        // } else{
        //     std::cout << "Invalid input. Please enter a valid policy or attribute.\n";
        // }
    }


    // std::cout << "\nall user attributes stored in struct and vector: \n";
    // for(auto m : UA){

    //     std::cout << m.User_ID << ": " << m.random_attrib << "\n\n";
    // }

   

    return 0;
}