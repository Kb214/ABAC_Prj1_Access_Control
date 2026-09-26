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



the searching of attributes is done wrong. we need to find the attributes not by number/index
but by the attributes name. when user inputs "attrib1 AND attrib2" we need to use the find function
to search for the attributes in the vector. 



*/

struct User_Attrib{
    int User_ID;

    std::vector<std::string> random_attrib; 
};

std::vector<User_Attrib> UA;

bool attribSearch(int userID, std::string& attr){
    for(auto& u: UA){
        if(u.User_ID == userID){
            for(auto& a: u.random_attrib){
                if(a == attr){
                    return true;
                    std::cout<< "Policy is valid.\n";
                }
            }
        }
    }
    return false;
    std::cout<< "Policy is invalid.\n";
}

bool AND(std::string& attr1, std::string& attr2, int userID){


    if(attribSearch(userID, attr1) && attribSearch(userID, attr2)){
        return true;
    } else{
        return false;
    }

}

bool OR(std::string& attr1, std::string& attr2, int userID){

    if(attribSearch(userID, attr1) || attribSearch(userID, attr2)){
        return true;
    } else{
        return false;
    }

}


int main(){
    int numb_att;
    std::string attribute;
    std::vector<std::string> a;

    std::cout << "How many attributes? : ";
    std::cin >> numb_att;
    
    


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
            UA.emplace_back(User_Attrib{p + 1,{a.at(i)}});
            
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


        // if(attribSearch(id, policy)){
        //     std::cout << "Policy is valid.\n";

        // } else if(policy.find("AND")){

        //     if(AND(a[0],a[1], id) == true){
        //         std::cout << "policy is valid.\n";
        //     }


        // } else if(policy.find("OR")){

        //     if(OR(a[0], a[1], id) == true){
        //         std::cout << "policy is valid.\n";
        //     }

        // } else if(policy.find("AND") && policy.find("OR")){

        
        //     if(AND(a[0], a[1], id) || OR(a[0], a[1], id)==true){
        //         std::cout << "policy is valid.\n";
        //     }

        // }else{

        //     std::cout << "Policy is invalid. Please enter a valid policy.\n";

        // }

        std::string attrib1, attrib2;


        if(policy.find("AND") != std::string::npos){

            if(AND(attrib1, attrib2, id) == true){
                std::cout << "Policy is valid.\n";
            } else{
                std::cout << "Policy is invalid.\n";
            }


        }else if(policy.find("OR") != std::string::npos){
            
            if(OR(attrib1,attrib2, id) == true){
                std::cout << "Policy is valid.\n";
            } else{
                std::cout << "Policy is invalid.\n";
            }


        }else if(policy.find("AND") && policy.find("OR") != std::string::npos){
            if(AND(a[0], a[1], id) || OR(a[0], a[1], id)==true){
                std::cout << "Policy is valid.\n";
            } else{
                std::cout << "Policy is invalid.\n";
            }


        } else if(attribSearch(id, policy) == true){
            std::cout << "Policy is valid.\n";


        } else if(attribSearch(id, policy) == false){
            std::cout << "Policy is invalid.\n";


        }





        std::cout << "do you want to check another user policy? (y/n): ";
        char choice;
        std::cin >> choice;
        if(choice == 'y'){
            continue;
        } else{
            return false;
        }
    }


    std::cout << "\nall user attributes stored in struct and vector: \n";

    for(auto m : UA){

        std::cout << m.User_ID << ": ";
        for(const auto& attr : m.random_attrib){
            std::cout << attr << " ";
        }
        std::cout << "\n\n";
    }
    return 0;

}
