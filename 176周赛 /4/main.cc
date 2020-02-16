#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
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

// class Solution {
//  public:
//   bool isPossible(vector<int>& target) {
//     priority_queue<long> pq;
//     long sum = 0;
//     for (int num : target) {
//       pq.push(num);
//       sum += num;
//     }

//     long top;
//     while ((top = pq.top()) != 1) {
//       pq.pop();
//       sum -= top;
//       long prev_num = top - sum;
//       if (prev_num < 1) return false;
//       sum += prev_num;
//       pq.push(prev_num);
//     }

//     return true;
//   }
// };


class Solution {
 public:
  bool isPossible(vector<int>& target) {
  }
};

int main(int argc, char const* argv[]) { 
  Solution s;
  vector<int> target = {5,8};
  log("%d\n", s.isPossible(target));
}
