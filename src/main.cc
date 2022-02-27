#include "courses.hpp"
#include "course.hpp"
#include "title.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> a{"CS101", "CS124"};
    Courses c(a);
    std::cout<< c.gettitle().size() << std::endl;
    for(Course * a : c.gettitle()[1]->getcourse()){
        std::cout<< a << std::endl;
    }
    return 0;
}