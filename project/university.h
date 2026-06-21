#ifndef university_h
#define university_h
#include <string>
#include<vector>
#include"student.h"
#include"dormitory.h"
class university{
    private:
     std::string university_name;
     std::vector<dormitory> dormitories;
     std::vector<student> students;


    public:
    university(std::string="");
    void display_dormitories()const;
    void add_dormitory(const dormitory &);
    void remove_dormitory(const std::string&);
    student find_student_by_id(int id)const;
};

#endif