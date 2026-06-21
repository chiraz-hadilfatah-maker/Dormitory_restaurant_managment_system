#include <menu.h>
#ifndef restaurant_h
#define restaurant_h
class resteaurant
{

private:
    menu menu_of_the_day;
    int number_of_served_meals;

public:
    resteaurant();
    resteaurant(const menu &);
    void display_menu() const;
    int get_counter() const;
    bool take_the_meal();
};

#endif