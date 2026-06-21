#ifndef dormitory_h
#define dormitory_h
#include "room.h"
#include <vector>
#include "restaurant.h"
class dormitory
{
private:
    int capacity;
    int available_rooms;
    resteaurant dorm_resteau;
    std::string dorm_name;
    std::vector<room> room_occupancy;

public:
    dormitory(int = 100, const resteaurant &, std::string &, int = 1);
    void set_capacity(int);
    int get_available_room() const;
    std::string get_dorm_name() const;
    void set_occupied_room(const room &);

    room &find_room_by_number(int room_number);
    void set_student_to_room(const student &, int room_number);
    void remove_student_from_room(const student &, int room_number);
    bool is_empty() const;

    void display_available_room() const;
    void display_occupied_room() const;
};
#endif