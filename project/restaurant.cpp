#include "restaurant.h"
#include <iostream>
resteaurant::resteaurant(const menu &Menu)
{
    menu_of_the_day = Menu;
}
resteaurant::resteaurant()
{
    menu_of_the_day = menu();
}
void resteaurant::display_menu() const
{
    menu_of_the_day.get_menu();
}
int resteaurant::get_counter() const
{
    return number_of_served_meals;
}
bool resteaurant::take_the_meal() {}