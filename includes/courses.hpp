#ifndef COURSES_HPP
#define COURSES_HPP
#include <string>
#include <vector>
#include <unordered_map>
#include "course.hpp"
#include "title.hpp"
using namespace std;
class Courses{
    public:
    Courses(vector<string> courses);
    vector<Title *> gettitle();
    void createSchedule(vector<Title*> &Titlees);
    void backTrack(vector<tuple<int, int, int>> &list, vector<vector<tuple<int, int, int>>> &Q,
              unordered_map<Title*,vector<tuple<int, int, int>>> &dict, vector<Title*> &Titlees, unsigned int c);
    private:
    vector<Title *> titles_;

};
#endif