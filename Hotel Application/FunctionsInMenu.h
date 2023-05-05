//
// Created by polej on 29.04.2023.
//

#ifndef FUNWITHOBJECT_FUNCTIONSINMENU_H
#define FUNWITHOBJECT_FUNCTIONSINMENU_H

#include "checkers.h"
#include <vector>


std::string get_guest_name(std::string is_correct_name){

    std::cout << "Name: ";
    do {
        std::cin >> is_correct_name;
    }while(name_checker(is_correct_name) != true);
    return is_correct_name;
}
std::string get_guest_last_name(std::string is_correct_last_name){
    std::cout << "Last name: ";
    do {
        std::cin >> is_correct_last_name;
    }while(name_checker(is_correct_last_name) != true);
    return is_correct_last_name;
}
std::string get_personal_number(std::string is_personal_numb_correct){

    do {

        std::cout << "Personal number: ";
        std::cin >> is_personal_numb_correct;
    }while(personal_number_checker(is_personal_numb_correct) != true);
    return is_personal_numb_correct;
}
std::string get_phone_number(std::string phone_number){
    do{
        std::cout << "Phone number with prefix: ";
        std::cin >> phone_number;

    }while(check_number_phone(phone_number)!=true);
    return phone_number;
}
std::string get_address(std::string address){
    std::cout << "Do you want add address? (Optional) || 1. Yes. 2. No";
    char choice;
    do{
        std::cin >> choice;
        if(choice == '2')
            return "No address added";
        else {
            std::vector<std::string> full_address;
            std::string post_code{};
            std::string city{};
            std::string street{};
            std::string house_number{};
            bool condition_for_correct {false}; // creating condition for case, in first user has to complete all contact details, in second time he can only  chosen one case
            bool breaker_while_loop {true};  // this sentence breaking loop if contact details are correct and saved, bool is changing for false
            bool condition_for_switch_loop{true}; // correct for all switch, loop starting in 61 line and ending
            char correct{'1'};
            do {
            switch (correct) {
                case '1': { // in first cin, all cases doesn't have break, user has to put all details
                    std::cout << "Post code: ";
                    std::cin >> post_code;
                    post_code+=" ";
                    full_address.push_back(post_code);
                    if (condition_for_correct == true) { //in second cin, if user put wrong details he can correct, condition is changing and he can choose which details he want change
                        full_address.at(0) = post_code;
                        break;
                    }
                }
                case '2': {
                    std::cout << "City: ";
                    std::cin >> city;
                    city += " ";
                    full_address.push_back(city);
                    if (condition_for_correct == true) {
                        full_address.at(1) = city;
                        break;
                    }
                }
                case '3': {
                    std::cout << "Street: ";
                    std::cin >> street;
                    street+=" ";
                    if(condition_for_correct == false)
                        full_address.push_back(street);
                    if (condition_for_correct == true) {
                        full_address.at(2) =street;
                        break;
                    }
                }
                case '4': {

                        std::cout << "House number: ";
                        std::cin >> house_number;
                        house_number +=" ";
                        if(condition_for_correct == false) {
                            full_address.push_back(house_number);
                            break;
                        }

                    if(condition_for_correct == true) {
                        full_address.at(3) = house_number;
                        break;
                    }
                }
                case '5': {
                    std::cout << "Saved\n";
                    break;
                }
            }
            std::cout << "Do you want save these contact details? 1. Yes. 2. Correct: ";

            for(int i{0}; i < full_address.size(); i++){
                std::cout << full_address.at(i);
            }
            char save_or_correct{};
            std::cin >> save_or_correct;
            if(save_or_correct == '1'){
                for(int i{0}; i < full_address.size(); i++) {
                    address += full_address.at(i);
                }
                condition_for_switch_loop = false; //changing condition and breaking loop, because details are correct


            }
            else if (save_or_correct == '2'){
                std::cout << "Which contact details do you want correct?\n 1. Post code\n 2. City\n 3. Street\n 4. House number\n Miss click? Press 5.";
                condition_for_correct = true; // changing condition do-while (do is starting in 61 line)
                std::cin >> correct;
            }

            }
            while(condition_for_switch_loop);

            return address;

        }



    }while(choice != '1' && choice != '2');


}


#endif //FUNWITHOBJECT_FUNCTIONSINMENU_H
