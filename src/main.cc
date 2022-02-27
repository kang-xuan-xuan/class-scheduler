#include "courses.hpp"
#include "course.hpp"
#include "title.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> a{"CS374", "CS421", "MATH412"};
    Courses c(a);
    // std::cout<< c.gettitle().size() << std::endl;
    // for(Course * a : c.gettitle()[1]->getcourse()){
    //     std::cout<< a << std::endl;
    // }
    vector<Title*> titles = c.gettitle();
    c.createSchedule(titles);
    return 0;
}