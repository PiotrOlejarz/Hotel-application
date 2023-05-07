//
// Created by polej on 06.05.2023.
//

#ifndef FUNWITHOBJECT_CASE1_H
#define FUNWITHOBJECT_CASE1_H

#include "Case2.h"

/*In this case I'm using functions declared in FunctionInCase1.h and methods Users/Rooms it's important to understand code
What happening here? Functions from FunctionInCase1 are checking name, last name and other personal details.
 If everything is ok, I'm calling to Users to get special code, new_guest.get_special_code is returning code.
 Now I'm calling to Rooms, Rooms is getting special code. If room is empty map key(number of room) get new value,
 which is special number

 */
void case1(){
    std::string name{};
    std::string last_name{};
    std::string personal_number{};
    name =get_guest_name(name); //function in FunctionsInMenu loop is checking correct of data (only alpha signs), if wrong cin again
    last_name=get_guest_last_name(last_name); //function in FunctionsInMenu loop is checking correct of data (only alpha signs), if wrong cin again
    personal_number = get_personal_number(personal_number);//checking correct personal number
    Users new_guest; //creating new object which is adding to guests
    new_guest.get_personal_data(name, last_name, personal_number);//Users function, initialization data in object
    std::string phone_number{};
    std::string address{};
    phone_number = get_phone_number(phone_number);
    address = get_address(address);
    new_guest.get_contact_details(phone_number, address);
    int special_code;
    special_code = new_guest.get_special_code();
    std::cout <<"Guest code: "<< special_code<<std::endl;
    Rooms new_room;
    int room{};
    std::cout << "Room number: ";
    room = is_room_ok(); // function from checkers, checking int correct
    std::cout<<"Here is room: " << room<<std::endl;
    while(new_room.check_room_free(room)){
        std::cout << "If you want display free rooms press 1: ";
        std::string choice{};
        std::cin>>choice;
        if(choice == "1" )
            case2(); //User can display information about rooms, if he has problem to find empty room.
        std::cout << "Room: " ;
        room = is_room_ok(); // function from checkers, checking int correct
    }

    new_guest.save_user_to_file();
    new_room.registr_new_guest(room, special_code);

}
#endif //FUNWITHOBJECT_CASE1_H
