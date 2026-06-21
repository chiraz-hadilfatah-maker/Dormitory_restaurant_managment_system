#include <string>
#include<iostream>
#ifndef menu_h
#define menu_h

class menu
{
private:
    std::string breakfast;
    std::string lunch;
    std::string dinner;

public:
 menu(const std::string& pdej ="",const std::string& dej ="",const std::string & din =""):breakfast(pdej),lunch(dej),dinner(din){}
 void set_menu(const std::string& pdej,const std::string& dej,const std::string & din){
    breakfast=pdej;
    lunch=dej;
    dinner=din;
 }
 void get_menu()const{
    std::cout<<"Breakfast:"<<std::endl;
    std::cout<<breakfast<<std::endl;
    std::cout<<"Lunch:"<<std::endl;
    std::cout<<lunch<<std::endl;
    std::cout<<"Dinner:"<<std::endl;
    std::cout<<dinner<<std::endl;

 }
 menu& operator = (const menu & MENU){
    breakfast=MENU.breakfast;
    lunch=MENU.lunch;
    dinner=MENU.dinner;
    return *this;
 }
};

#endif