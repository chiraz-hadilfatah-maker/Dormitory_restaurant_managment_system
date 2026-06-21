#include "student.h"
#include <iostream>
#ifndef room_h
#define room_h
class room
{
private:
    student *room_occuper;
    int room_number;
    int room_capacity;
    int people;

public:
    room( int = 0, int = 1);

    void set_room_capacity(int);
    void set_room_number(int);
    void set_student_to_room(const student &);
    void remove_student(const student &);

    int get_room_number() const;
    int get_room_capacity() const;
    student *get_room_occupancy() const;
    int get_number_of_occuper()const;

    bool room_is_full() const;
    bool room_is_empty() const;
    
    friend std::ostream operator<<(const std::ostream &, const room &);
};

#endif