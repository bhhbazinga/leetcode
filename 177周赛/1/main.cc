#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

class Solution {
 public:
  int mon2days[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool LeapYear(int y) {
    if (y % 400 == 0) return true;
    if (y % 4 == 0 && y % 100 != 0) return true;
    return false;
  }

  int GetDaysFrom1971(int year, int mon, int day) {
    int res = 0;
    for (int i = 1971; i < year; ++i) {
      res += LeapYear(i) ? 366 : 365;
    }

    for (int i = 1; i < mon; ++i) {
      res += mon2days[i];
    }
    if (mon > 2) {
      res += LeapYear(year) ? 29 : 28;
    }
    res += day;
    // log("%d,%d,%d,%d\n", year, mon, day, res);
    return res;
  }
  int daysBetweenDates(string date1, string date2) {
    int y1, m1, d1;
    int y2, m2, d2;
    sscanf(date1.c_str(), "%d-%d-%d", &y1, &m1, &d1);
    sscanf(date2.c_str(), "%d-%d-%d", &y2, &m2, &d2);
    return abs(GetDaysFrom1971(y1, m1, d1) - GetDaysFrom1971(y2, m2, d2));
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%d\n", s.daysBetweenDates("2020-01-15", "2019-12-31"));
  return 0;
}
