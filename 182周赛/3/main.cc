#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <numeric>
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

class UndergroundSystem {
  unordered_map<string, set<pair<int, int>>> in_map;
  unordered_map<string, set<pair<int, int>>> out_map;

 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    in_map[stationName].emplace(t, id);
  }

  void checkOut(int id, string stationName, int t) {
    out_map[stationName].emplace(t, id);
  }

  double getAverageTime(string startStation, string endStation) {
    set<pair<int, int>> start_set = in_map[startStation];
    set<pair<int, int>> end_set = out_map[endStation];
    // log("%d\n", start_set.size());
    // log("%d\n", end_set.size());
    double sum = 0;
    int cnt = 0;
    for (auto i = start_set.begin(); i != start_set.end(); ++i) {
       for (auto j = end_set.begin(); j != end_set.end(); ++j) {
        // log("%d,%d,%d,%d\n", i->second, j->second, i->first, j->first);
        if (i->second == j->second && i->first < j->first) {
          sum += (j->first - i->first);
          ++cnt;
        }
      }
    }
    if (sum > 0 && cnt > 0) {
      return sum / cnt;
    }
    return -1;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(int argc, char const* argv[]) {
  UndergroundSystem undergroundSystem = UndergroundSystem();
  undergroundSystem.checkIn(45, "Leyton", 3);
  undergroundSystem.checkIn(32, "Paradise", 8);
  undergroundSystem.checkIn(27, "Leyton", 10);
  undergroundSystem.checkOut(45, "Waterloo", 15);
  undergroundSystem.checkOut(27, "Waterloo", 20);
  undergroundSystem.checkOut(32, "Cambridge", 22);
  double res = undergroundSystem.getAverageTime(
      "Paradise", "Cambridge");  // 返回 14.0。从 "Paradise"（时刻 8）到
  // "Cambridge"(时刻 22)的行程只有一趟
  log("res=%f\n", res);

  undergroundSystem.getAverageTime(
      "Leyton",
      "Waterloo");  // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo"
                    // 的行程，编号为 id=45 的乘客出发于 time=3 到达于
                    // time=15，编号为 id=27 的乘客出发于 time=10 到达于
                    // time=20。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
  undergroundSystem.checkIn(10, "Leyton", 24);
  undergroundSystem.getAverageTime("Leyton", "Waterloo");  // 返回 11.0
  undergroundSystem.checkOut(10, "Waterloo", 38);
  undergroundSystem.getAverageTime("Leyton", "Waterloo");  // 返回 12.0

  return 0;
}
