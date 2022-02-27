#include "title.hpp"

Title::Title(std::string name){
    name_ = name;
}
void Title::addcourse(Course* c){
    courses_.push_back(c);
}
vector<Course*> Title::getcourse() {
    return courses_;
}
string Title::getname() {
    return name_;
}