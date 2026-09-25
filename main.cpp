#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

/*
DESCRIPTION:

1. Input number of n total attribs in system [X]
2. generate n-type of attrbs [X]
3. generate 10 users with random attrbs from set of n [at least 2]  [ X ]
4. prog allows user input as (attrib1 AND attrib2)OR
                             (2 of (attrib3, attrib4, attrib5)); [ ]
                             (attrib1 AND attrib2)OR
                             (attrib3 AND attrib4)  [ ]
[AND, OR need to be capitalized]
5. evaluation is processed when user inputs attrbs. program returns true or false [ ]



*/


// struct Users{
//     public: 
//     std::list<std::string> attrname;

//     private:
//     std::string attr;
//     int user_id;
    
// };

class System{
    public:
    std::string attr;
    int user;
    std::list<std::string>attrname;

    void display(){
        for (auto i : attrname){
        std::cout << i << "\n";
        }
    }

};

int main(){
    std::cout << "YO\n";

//1. Input number of n total attribs in system
    int x;
    // std::list<std::string> attrname;
    System sys;

    std::cout << "Enter number of user attributes:";
    std::cin >> x;

    for(int i=0; i<x;i++){
        std::cout << "Enter user attribute name " << i + 1 << ":  ";
        std::cin >> sys.attr;
        sys.attrname.push_back(sys.attr);
    }

    // for (auto i : sys.attrname){
    //     std::cout << i << "\n";
    // }
    sys.display();
    
    std::srand(std::time({})); 
    const int random_value = std::rand();
    for(int i = 0; i<10;i++){
        
    }



    

    return 0;
}