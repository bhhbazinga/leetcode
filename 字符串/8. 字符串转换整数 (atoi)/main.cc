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
class Solution {
 public:
  int myAtoi(string str) {
    int sign = 0;
    long res = 0;
    for (int i = 0; i < str.size(); ++i) {
      char c = str[i];
      if (sign == 0) {
        if (c >= '0' && c <= '9') {
          sign = 1;
          res = c - '0';
        } else if (c == '-') {
          sign = -1;
        } else if (c == '+') {
          sign = 1;
        } else if (c != ' ') {
          break;
        }
      } else {
        if (c >= '0' && c <= '9') {
          res *= 10;
          res += c - '0';
          if (res > INT_MAX) {
            return sign == 1 ? INT_MAX : INT_MIN;
          }
        } else {
          break;
        }
      }
    }
    return res * sign;
  }
};

// class Automaton {
//     string state = "start";
//     unordered_map<string, vector<string>> table = {
//         {"start", {"start", "signed", "in_number", "end"}},
//         {"signed", {"end", "end", "in_number", "end"}},
//         {"in_number", {"end", "end", "in_number", "end"}},
//         {"end", {"end", "end", "end", "end"}}
//     };

//     int get_col(char c) {
//         if (isspace(c)) return 0;
//         if (c == '+' or c == '-') return 1;
//         if (isdigit(c)) return 2;
//         return 3;
//     }
// public:
//     int sign = 1;
//     long long ans = 0;

//     void get(char c) {
//         state = table[state][get_col(c)];
//         if (state == "in_number") {
//             ans = ans * 10 + c - '0';
//             ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long
//             long)INT_MIN);
//         }
//         else if (state == "signed")
//             sign = c == '+' ? 1 : -1;
//     }
// };

// class Solution {
// public:
//     int myAtoi(string str) {
//         Automaton automaton;
//         for (char c : str)
//             automaton.get(c);
//         return automaton.sign * automaton.ans;
//     }
// };

int main(int argc, char const* argv[]) {
  Solution s;
  log("%d\n", s.myAtoi("+1"));
  return 0;
}
