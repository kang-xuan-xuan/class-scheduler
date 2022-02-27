#include "courses.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <unordered_map>

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

void Courses::createSchedule(vector<Title*> &Titlees) {
  unordered_map<Title*, vector<tuple<int, int, int>>> dict;
  for (Title* Title : Titlees) {
    vector<tuple<int, int, int>> timeSlots;
    for (Course* course : Title->getcourse()) {
      int crn = course->CRN;
      string time = course->time;
      int t1 = 0, t2 = 0, i = 0;
      while (i == 0 || i == 1 || i == 3 || i == 4) {
        t1 *= 10;
        t1 += (time[i] - '0');
        i++;
      }
      if (time[5] == 'P') t1 += 1200;
      i = 10;
      while (i == 10 || i == 11 || i == 13 || i == 14) {
        t2 *= 10;
        t2 += (time[i] - '0');
        i++;
      }
      if (time[15] == 'P') t2 += 1200;
      timeSlots.push_back({t1, t2, crn});
    }
    dict[Title] = timeSlots;
  }
  vector<tuple<int, int, int>> list;
  vector<vector<tuple<int, int, int>>> Q;
  backTrack(list, Q, dict, Titlees, 0);
  for (auto &a : Q) {
    for (auto &b : a) {
      cout << "(" << get<0>(b) << "-" << get<1>(b) << " " << get<2>(b) << ")" << endl;
    }
    cout << endl;
  }
}

void backTrack(vector<tuple<int, int, int>> &list, vector<vector<tuple<int, int, int>>> &Q,
              unordered_map<Title*,vector<tuple<int, int, int>>> &dict, vector<Title*> &Titlees, unsigned int c) {
  if (c == Titlees.size()) {
    Q.push_back(list);
    return;
  }
  for (tuple<int, int, int> p : dict[Titlees[c]]) {
    bool flag = true;
    for (tuple<int, int, int> t : list) {
      if (get<1>(t) < get<0>(p) || get<0>(t) > get<1>(p)) {
        flag = false;
        break;
      }
    }
    if (flag) {
      list.push_back(p);
      backTrack(list, Q, dict, Titlees, c+1);
      list.pop_back();
    }
  }
}