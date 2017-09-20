/**
 * CSC232 Data Structures with C++
 * Missouri State University, Fall 2017
 *
 * @file Main.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Sam Aguayo <aguayo923@missouristate.edu>
 * @brief   Entry point for this application. This is nothing more than a playground.
 */

#include <cstdlib>
#include <iostream>
#include <locale>
#include <cstring>
#include <sstream>

void Reverse_String(std::string& string1, std::string& string2, size_t x );
size_t StringLength (const std:: string &string1);
void createTemp(std:: string& reverseName, size_t len);
int checkNewPass(std:: string& newPass, const std:: string &tempPass);

int main(int argc, char **argv) {
    std::cout << "Hello, Main" << std::endl;
    std::cout <<"Enter your full name, including middle initial: ";
    std::string my_string;
    getline(std::cin, my_string, '\n');
   // std::cout << my_string<<std::endl; tester

    std::string string2;
    size_t len{0};
    len = (StringLength(my_string));
    Reverse_String(my_string, string2, len);
    createTemp(string2, len);
    std::cout<<"Your auto-generated password is: "<< string2<<std:: endl;
    std::cout<<"Would you like to change your password now [Y|N]? ";
    std::string choice;
    std:: cin>> choice;
    if(choice[0] == 'Y'){
        std::cout<<"Enter your password: "<<std::endl;
        std:: string NewPass; // user's new password
       // std::cout<<"test1"<<std::endl;
        std::cin>> NewPass;
        //std::cout<<NewPass<<std::endl; tester
        int check{0};
        check = checkNewPass(NewPass, string2);
        if(check != 0) {
            std::cout << "Thank you. Please use your new password " << NewPass
                      << " the next time you log into our system." << std::endl;
        }
        return EXIT_SUCCESS;
    }
    if(choice[0] == 'N'){
        std::cout<<"Thank you. It is recommended that you change your password the next time you log into our system.";
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}

void Reverse_String(std::string& string1, std::string& string2, size_t x){
    size_t  i{0};
    for(i = 0; i < x; ++i) {
        string1[i] = static_cast<char>(tolower(string1[i]));
    }
    for(i = 0; i < x; ++i){
        if(string1[i] == ' '){
            string1[i+1] = static_cast<char>(toupper(string1[i + 1]));
        }
    }
    string1[0] = static_cast<char>(toupper(string1[0]));
    for(i = x ; i != '\0'; i--) {
        string2 += string1[i];
    }
    string2 += string1[0];
}

size_t StringLength (const std:: string &string1)
{
    size_t num = 0;
    for (unsigned index = 0; index < string1.size(); index++)
    {
        num++;
    }
    //std:: cout<< num<< std:: endl; tester
    return num;
}
void createTemp(std:: string& reverseName, size_t len){
    std:: string placeHolder;
    for (size_t i{0}; i <= len; ++i){
        if(isalpha(reverseName.at(i)) != 0){
            placeHolder += reverseName[i];
        }
    }
    reverseName = placeHolder;
    size_t newLen = (StringLength(reverseName));
    if(newLen >= 6) reverseName += "10";
    while(newLen < 6){
        reverseName += '6';
        newLen = (StringLength(reverseName));
    }
    //reverseName += "10";
    //std::cout<< reverseName<<std::endl;
    /*int flagU{0};
    int flagL{0};
    for (size_t i{0}; i <= newLen; ++i){
        if(isupper(reverseName.at(i)) != 0){
            flagU = 1;
        }
        if(islower(reverseName.at(i)) != 0){
            flagL = 1;
        }
    }
    if(flagU != 1){
        reverseName += 'M';
    }
    if(flagL != 1){
        reverseName += 's';*/
}
int checkNewPass(std::string& newPass, const std:: string& tempPass){
    size_t len{0};
    len = StringLength(newPass);
    int uFlag{0}, lFlag{0}, nFlag{0}, lenFlag{0};
    for (size_t i{0}; i < len; ++i) {
        if (isupper(newPass.at(i)) != 0) {
            uFlag = 1;
        }
        if (islower(newPass.at(i)) != 0) {
            lFlag = 1;
        }
        if (isdigit(newPass.at(i)) != 0) {
            nFlag = 1;
        }
        if( len >= 6){
            lenFlag = 1;
        }
    }
   // std:: cout<< uFlag << lFlag << nFlag<< std::endl; tester
    if( uFlag + nFlag + lFlag +lenFlag != 4){
        std::cout<<"We're sorry. Your password does not meet our requirements:\n"
                "    * Your password does not contain at least one uppercase and one lowercase letter\n"
                "    * Your password does not contain at least 1 digit\n"
                "Your password was not changed; it remains: "<<tempPass<<"\n"
                "As a reminder, your password should\n"
                "    * be at least 6 characters long\n"
                "    * contain at least one uppercase and at least one lowercase letter\n"
                "    * contain at least 1 digit\n"
                "It is recommended that you change your password the next time you log into our system.\n"
                <<std::endl;
        newPass = tempPass;
        return EXIT_SUCCESS;
    } return 1;
}
