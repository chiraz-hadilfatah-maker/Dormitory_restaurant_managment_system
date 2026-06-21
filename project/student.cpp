#include "student.h"
#include <iostream>
student::student(int id, std::string name, int year)
{
    set_student_id(id);
    set_fullname(name);
    set_academic_year(year);
}

std::string student::get_fullname() const
{
    return full_name;
}
int student::get_student_id() const
{
    return ID;
}
int student::get_academic_year() const
{
    return academic_year;
}

void student::set_fullname(std::string name)
{
    full_name = name;
}
void student::set_student_id(int id)
{
    ID = (id > 0) ? id : 0;
}
void student::set_academic_year(int year)
{
    academic_year = (year > 0 && year < 6) ? year : 1;
}

void student::set_assigned_room(int)
{
}
void student::set_assigned_dorm(std::string) {}
void student::set_is_assigned(bool) {}

std::ostream &operator<<(const std::ostream &output, const student &eleve)
{
}
