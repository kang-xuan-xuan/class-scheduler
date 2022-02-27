#include "courses.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;
Courses::Courses(vector<string> courses){
    string path = "./data/";
    vector<string> sec;
    for(string course : courses) {
        Title * t = new Title(course);
        titles_.push_back(t);
        for(unsigned int i = 0; i < course.size(); i++) {
            std::cout<< course[i] << std::endl;
            if(!isalpha(course[i])) {
                string section  = course.substr(0,i);
                if(find(sec.begin(), sec.end(), section) == sec.end()) {
                    sec.push_back(section);
                }
                break;
            }
        }
    }
    string line;
    for(string section : sec) {
        fstream ifs(path + section + ".csv");
        if (!ifs.is_open()) {
            cout << path + section + ".csv is not found" << endl;
        } else {
            getline(ifs, line);
            while(getline(ifs, line)){
                vector<string> a;
                string info;
                stringstream eachLine2(line);
                while(getline(eachLine2,info,',')){
                    a.push_back(info);
                }
                for(unsigned int i = 0; i < titles_.size(); i++) {
                    if(titles_[i]->getname() == a[1]) {
                        Course* c = new Course();
                        c->CRN = stoi(a[3]);
                        c->type = a[4];
                        c->day = a[7];
                        c->time = a[6];
                        c->section = a[5];
                        c->instructor = a[9];
                        titles_[i]->addcourse(c);

                    }
                }
                

            }
        }
    }
}

vector<Title *> Courses::gettitle() {
    return titles_;
}