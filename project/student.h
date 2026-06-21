#include<string>
#include<iostream>
#ifndef student_h
#define student_h
class student{
private:
int ID;
std::string full_name;
int academic_year;
bool is_assigned;
int assigned_room;
std::string assigned_dorm;
public:
student(int=0,std::string="",int=1);

std::string get_fullname()const;
int get_student_id()const;
int get_academic_year()const;

void set_fullname(std::string);
void set_student_id(int);
void set_academic_year(int);
void set_assigned_room(int);
void set_assigned_dorm(std::string);
void set_is_assigned(bool);

bool operator == (const student &);
friend std::ostream & operator << (const std::ostream &,const student &);

};
#endif