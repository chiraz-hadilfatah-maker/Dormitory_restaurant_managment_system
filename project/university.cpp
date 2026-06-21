#include "university.h"
university::university(std::string = "") {}
void university::display_dormitories() const {}
void university::add_dormitory(const dormitory &dorm)
{
    dormitories.push_back(dorm);
}
void university::remove_dormitory(const std::string &dorm)
{

    int i = 0;
    while (i < dormitories.size())
    {
        if (dorm == dormitories[i].get_dorm_name())
        {
            if (dormitories[i].is_empty())
            {
                dormitories.erase(dormitories.begin() + i);
                return;
            }
            else
            {
                throw std::logic_error("You can't remove a non empty dorm");
            }
        }
        i++;
    }
}
student university::find_student_by_id(int id) const
{
    for (int i = 0; i < 200; i++)
    {
        if(students[i].get_student_id()==id){
            return students[i];
        }
    }
    throw std::logic_error("this student is not in this university");
    
}