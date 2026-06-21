#include <iostream>
#include "room.h"
#include "room_empty.h"
#include "room_full.h"
room::room(int porte, int size)
{
    people = 0;
    set_room_capacity(size);
    set_room_number(porte);
    room_occuper = new student[room_capacity];
}

void room::set_room_capacity(int capacity)
{
    room_capacity = (capacity > 0) ? capacity : 1;
}
void room::set_room_number(int porte)
{
    room_number = (porte > 0) ? porte : 0;
}
void room::set_student_to_room(const student &eleve)
{
    if (!room_is_full())
    {
        room_occuper[people] = eleve;
        people++;
        std::cout << "The student :" << eleve.get_fullname() << " is well added to this room";
    }
    else
    {
        throw room_full();
    }
}
void room::remove_student(const student &eleve)
{
    if (!room_is_empty())
    {
        for (int i = 0; i < people; i++)
        {
            if (room_occuper[i] == eleve)
            {
                people--;
                for (int j = i; j < people; j++)
                {
                    room_occuper[j] = room_occuper[j + 1];
                }
                std::cout << "The student:" << eleve.get_fullname() << " is well removed " << std::endl;
            }
        }
        std::cout << "This student is not found" << std::endl;
    }
    else
    {
        throw room_empty();
    }
}

int room::get_room_number() const
{
    return room_number;
}
int room::get_room_capacity() const
{
    return room_capacity;
}
student *room::get_room_occupancy() const
{
    return room_occuper;
}
int room::get_number_of_occuper() const
{
    return people;
}

bool room::room_is_full() const
{
    if (people == room_capacity)
    {
        return true;
    }
    return false;
}
bool room::room_is_empty() const
{
    if (people == 0)
    {
        return true;
    }
    return false;
}

std::ostream operator<<(const std::ostream &output, const room &chambre)
{
}