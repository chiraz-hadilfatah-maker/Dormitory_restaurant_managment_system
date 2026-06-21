#include<stdexcept>
#ifndef room_full_h
#define room_full_h
class room_full:public std::runtime_error{
    public:
    room_full():runtime_error("This room is full"){}
};
#endif