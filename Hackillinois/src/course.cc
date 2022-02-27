#include "course.hpp"
#include <iostream>
Course::Course(){
    //do nothing
}

std::ostream & operator<<(std::ostream & os, const Course c){
    os << to_string(c.CRN) << " " << c.day << " " << c.time << " " << c.section << " " << c.instructor << " " << c.type;
    return os;
}
std::ostream & operator<<(std::ostream & os, const Course * c){
     os << to_string(c->CRN) << " " << c->day << " " << c->time << " " << c->section << " " << c->instructor << " " << c->type;
    return os;
}