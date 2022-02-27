#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

void createSchedule(vector<Class*> &classes) {
  unordered_map<Class*, vector<tuple<int, int, string>>> dict;
  for (Class* class : classes) {
    vector<tuple<int, int, string>> timeSlots;
    for (string crn : class->CRNs()) {
      string time = class->getTime(crn);
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
    dict[class] = timeSlots;
  }
  vector<tuple<int, int, string>> list;
  vector<vector<tuple<int, int, string>>> Q;
  backTrack(list, Q, dict, classes, 0);
}

void backTrack(vector<tuple<int, int, string>> &list, vector<vector<tuple<int, int, string>>> &Q,
              unordered_map<Class*,vector<tuple<int, int, string>>> &dict, vector<Class*> &classes, int c) {
  if (c == classes.size()) {
    Q.push_back(list);
    return;
  }
  for (tuple<int, int, string> p : dict[classes[c]]) {
    bool flag = true;
    for (tuple<int, int, string> t : list) {
      if (get<1>(t) < get<0>(p) || get<0>(t) > get<1>(p)) {
        flag = false;
        break;
      }
    }
    if (flag) {
      list.push_back(p);
      backTrack(list, Q, dict, classes, c+1);
      list.pop_back();
    }
  }
}