#include <stdexcept>
#ifndef room_empty_h
#define room_empty_h
class room_empty :public std::runtime_error{
    public:
    room_empty():runtime_error("This room is empty"){};
};
#endif