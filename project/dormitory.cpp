#include "dormitory.h"
#include <iostream>
dormitory::dormitory(int size, const resteaurant &rest, std::string &name, int room_capacity)
{
    set_capacity(size);
    dorm_resteau = rest;
    dorm_name = name;
    room_capacity = (room_capacity > 0) ? room_capacity : 1;
    for (int i = 0; i < capacity; i++)
    {
        room_occupancy.push_back(room(i + 1, room_capacity)); // at first rooms are empty because we don't assign any student to it
    }
}
void dormitory::set_capacity(int size)
{
    capacity = (size > 0) ? size : 100;
}
int dormitory::get_available_room() const
{
    return available_rooms;
}
std::string dormitory::get_dorm_name() const
{
    return dorm_name;
}
void dormitory::set_occupied_room(const room &chambre)
{
    if (chambre.room_is_full() || chambre.get_number_of_occuper() > 0)
    {
        room_occupancy[chambre.get_room_number()] = chambre;
    }
}
room &dormitory::find_room_by_number(int room_number)
{
    for (int i = 0; i < capacity; i++)
    {
        if (room_occupancy[i].get_room_number() == room_number)
        {
            return room_occupancy[room_number];
        }
    }
    throw std::invalid_argument("room not found");
}
void dormitory::set_student_to_room(const student &eleve, int room_number)
{
    room &r = find_room_by_number(room_number);
    r.set_student_to_room(eleve);
}
void dormitory::remove_student_from_room(const student &eleve, int room_number)
{
    room &r = find_room_by_number(room_number);
    r.remove_student(eleve);
}

void dormitory::display_occupied_room() const
{
    for (int i = 0; i < capacity; i++)
    {
        if (!room_occupancy[i].room_is_empty())
        {
            std::cout << "The room " << room_occupancy[i].get_room_number() << "is occupied" << std::endl;
        }
    }
}
void dormitory::display_available_room() const
{
    for (int i = 0; i < capacity; i++)
    {
        if (room_occupancy[i].room_is_empty())
        {
            std::cout << "The room " << room_occupancy[i].get_room_number() << "is available with " << room_occupancy[i].get_room_capacity() << " bed available" << std::endl;
        }
        else if (room_occupancy[i].get_number_of_occuper() < room_occupancy[i].get_room_capacity())
        {
            std::cout << "The room " << room_occupancy[i].get_room_number() << "is available with " << room_occupancy[i].get_room_capacity() - room_occupancy[i].get_number_of_occuper() << " bed available" << std::endl;
        }
    }
}
bool dormitory::is_empty() const
{
    for (int i = 0; i < capacity; i++)
    {
        if (room_occupancy[i].get_number_of_occuper() != 0)
        {
            return false;
        }
    }
    return true;
}