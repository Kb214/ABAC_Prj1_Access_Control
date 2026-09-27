#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>
#include <sstream>

//STORAGE AND STORAGE FUNCTIONS
struct User_Attrib{
    int User_ID;
    std::vector<std::string> random_attrib;
};
std::vector<User_Attrib>UA;

void generate(int numb, std::vector<std::string> b){
    std::random_device rd;
    std::mt19937 gen(rd());
    for(int p = 0; p < 10; p++){
            std::shuffle(b.begin(),b.end(), gen);
            std::uniform_int_distribution<size_t> dist(2,numb);
            int random = dist(gen);


            std::cout << "User " << p + 1 << ": {";

            for(int i = 0; i < random; i++){

                std::cout <<  b.at(i) << ", ";
                UA.emplace_back(User_Attrib{p + 1,{b.at(i)}});

            }

            std::cout << "}";    

            std::cout << "\n";
        }
}


//SEARCH AND PARSE FUNCTIONS
bool attribSearch(int userID, const std::string& attr){
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


bool parsePolicy( std::string& policy,std::string& attr1,std::string& op ,std::string& attr2){
    std::istringstream input(policy);
    std::string extra;

    if(!(input >> attr1 >> op >> attr2) || (input >> extra)){
        return false;
    }

    return op == "AND" || op == "OR";
}


bool parsePolicy2( std::string& policy, std::string& attr1, std::string& op, std::string& attr2, std::string& op2, std::string& attr3,  std::string& op3, std::string& attr4){
    
    std::istringstream input(policy);
    std::string extra;

    if(!(input >> attr1 >> op >> attr2 >> op2 >> attr3 >> op3 >> attr4) || (input >> extra)){
        return false;
    }

    return (op == "AND" || op == "OR") && (op2 == "AND" || op2 == "OR") && (op3 == "AND" || op3 == "OR");

}


bool parsePolicy3( std::string& policy, std::string& attr1, std::string& op,  std::string& attr2, std::string& op2, std::string clause , std::string& attr3, std::string& attr4, std::string& attr5){
    
    std::istringstream input(policy);
    std::string extra;

    if(!(input >> attr1 >> op >> attr2 >> op2 >> clause >> attr3 >> attr4 >> attr5) || (input >> extra)){
        return false;
    }

    return (op == "AND" || op == "OR") && (op2 == "AND" || op2 == "OR") && (clause == "2of");

}



//OPERATOR FUNCTIONS
bool AND(const std::string& attr1, const std::string& attr2, int userID){


    if(attribSearch(userID, attr1) && attribSearch(userID, attr2)){
        return true;
    } else{
        return false;
    }

}


bool OR(const std::string& attr1, const std::string& attr2, int userID){

    if(attribSearch(userID, attr1) || attribSearch(userID, attr2)){
        return true;
    } else{
        return false;
    }

}


bool ANDOR(const std::string& attr1, const std::string& attr2, const std::string& attr3, const std::string& attr4, int userID){
    if((attribSearch(userID, attr1) && attribSearch(userID, attr2)) || (attribSearch(userID, attr3) && attribSearch(userID, attr4))){
        return true;
    } else{
        return false;
    }
}


bool TWOOF(const std::string& attr1, const std::string& attr2, const std::string& attr3, const std::string& attr4, const std::string& attr5, int userID){
    int matches = 0;
    for(auto& attr : {attr3, attr4, attr5}){
        if(attribSearch(userID, attr)){
            matches++;
        }
    }

    if(matches == 2 || attribSearch(userID, attr1) && attribSearch(userID, attr2)){

        return true;
    } else{
        return false;
    }
}  







//MAIN CODE
int main(){
    int numb_att;
    std::string attribute;
    std::vector<std::string>a;
    std::string choice;

    std::cout << "================= RULES: =================\n1)Input number of attributes\n2)Input your attributes\n3)Input UserID\n4)Enter Attribute-Based Policy for that user\n";
    std::cout << "4A)The attribute operation MUST BE CAPITALIZED (e.g. AND,OR)\n4B)When checking the '2 of' attribute DO NOT put a space in between the characters --> 2of\n";
    std::cout << "Do you understand the rules? (y/n): ";
    std::cin >> choice;

    if(choice == "y"){

        //Attributes
        std::cout << "\n\nHow many attributes do you want? : ";
        std::cin >> numb_att;

        for(int i = 0; i < numb_att; i++){
            std::cout << "Enter Attribute " << i + 1 << ": ";
            std::cin >> attribute;
            a.push_back(attribute);
        }

        std::cout << "\n\n";




        //USER AND ATTRIBUTE GENERATION
        std::cout << "Your Generated Users and Attributes\n";
        generate(numb_att, a);



        //CHECKING ATTRIBUTE POLICY
        while(true){
            std::cout << "\nEnter UserID: ";
            int id;

            std::cin >> id;

            std::cout << "\nEnter Attribute-Based Policy for the user. policy options:\n";
            std::cout << "attrib1\nattrib1 AND attrib2\nattrib1 OR attrib2\nattrib1 AND attrib2 OR attrib3 AND attrib4\nattrib1 AND attrib2 OR 2of attrib3 attrib 4 attrib5\n\nPolicy: ";
            std::string policy;
            std::cin.ignore();
            std::getline(std::cin, policy);

            std::string attrib1, attrib2, attrib3, attrib4, attrib5, op, op2, op3, clause;

            if(parsePolicy(policy, attrib1, op, attrib2)){

                bool valid = (op == "AND") ? AND(attrib1, attrib2, id) : OR(attrib1, attrib2, id);
                std::cout << (valid ? "Policy is valid.\n" : "Policy is invalid.\n");


            }else if(op.empty()){

                bool valid2 = (op.empty()) ? (attribSearch(id, attrib1)) : false;
                std::cout << (valid2 ? "Policy is valid.\n" : "Policy is invalid.\n");

            }else if(parsePolicy2(policy, attrib1, op, attrib2, op2, attrib3, op3, attrib4) && (policy.find("AND") != std::string::npos && policy.find("OR") != std::string::npos) && policy.find("2of") == std::string::npos){

                bool valid = ANDOR(attrib1, attrib2, attrib3, attrib4, id);
                std::cout << (valid ? "Policy is valid.\n" : "Policy is invalid.\n");

            }else if(parsePolicy3(policy, attrib1, op, attrib2, op2, clause, attrib3, attrib4, attrib5) && policy.find("2of") != std::string::npos){

                bool valid = TWOOF(attrib1, attrib2, attrib3, attrib4, attrib5, id);
                std::cout << (valid ? "Policy is valid.\n" : "Policy is invalid.\n");

            }else{

                std::cout << "Invalid policy format. Please enter a valid policy.\n";
                std::getline(std::cin, policy);

            }


            std::cout << "\ndo you want to check another user policy? (y/n): ";
            std::cin >> choice;
            if(choice == "y"){
                continue;
            } else if(choice == "n"){
                std::cout << "\nEXITING.....";
                return false;
            }else{
                std::cout << "Invalid choice, try again: ";
                std::cin >> choice;
            }

        }





    }else if(choice == "n"){
        std::cout << "\nEXITING..... ";

    }else{
        std::cout << "Invalid choice, restart to try again.";

    }



    return 0;
}