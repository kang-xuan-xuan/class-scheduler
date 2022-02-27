#ifndef TITLE_HPP
#define TITLE_HPP
#include <string>
#include <vector>
#include "course.hpp"
using namespace std;
class Title{
    public:
    Title(string name);
    void addcourse(Course * c);
    vector<Course*>  getcourse() ;
    string getname();


    private:
    vector<Course *> courses_;
    string name_;


    

};
#endif