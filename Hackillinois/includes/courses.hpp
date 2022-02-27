#ifndef COURSES_HPP
#define COURSES_HPP
#include <string>
#include <vector>
#include "course.hpp"
#include "title.hpp"
using namespace std;
class Courses{
    public:
    Courses(vector<string> courses);
    vector<Title *> gettitle();
    private:
    vector<Title *> titles_;

};
#endif