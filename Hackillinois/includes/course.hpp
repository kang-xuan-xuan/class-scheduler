#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
#include <iostream>
using namespace std;
class Course{
    public:
    Course();
    int CRN;
    string type;
    string time;
    string day;
    string section;
    string instructor;

};
std::ostream & operator<<(std::ostream & os, const Course c);
std::ostream & operator<<(std::ostream & os, const Course * c);
#endif