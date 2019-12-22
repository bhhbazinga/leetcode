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

const int kMaxLength = 1000;
class Solution {
 public:
  int maxCandies(vector<int>& status, vector<int>& candies,
                 vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes) {
    bool key[kMaxLength];
    memset(&key[0], 0, sizeof(key[0]) * kMaxLength);
    for (int i : initialBoxes) {
      key[i] = true;
    }

    bool visit[kMaxLength];
    memset(&visit[0], 0, sizeof(visit[0]) * kMaxLength);
    for (int i : initialBoxes) {
      DfsKey(status, keys, containedBoxes, i, key, visit);
    }

    memset(&visit[0], 0, sizeof(visit[0]) * kMaxLength);
    int count = 0;
    for (int i : initialBoxes) {
      DfsCandy(status, candies, containedBoxes, i, key, visit, count);
    }
    return count;
  }

  void DfsKey(vector<int>& status, vector<vector<int>>& keys,
              vector<vector<int>>& containedBoxes, int index,
              bool key[kMaxLength], bool visit[kMaxLength]) {
    if (visit[index] || (!key[index] && status[index] == 0)) {
      return;
    }

    visit[index] = true;

    for (int i : keys[index]) {
      key[i] = true;
    }

    for (int i : containedBoxes[index]) {
      DfsKey(status, keys, containedBoxes, i, key, visit);
    }
  }

  void DfsCandy(vector<int>& status, vector<int>& candies,
                vector<vector<int>>& containedBoxes, int index,
                bool key[kMaxLength], bool visit[kMaxLength], int& count) {
    if (visit[index] || (!key[index] && status[index] == 0)) {
      return;
    }

    visit[index] = true;
    count += candies[index];

    for (int i : containedBoxes[index]) {
      DfsCandy(status, candies, containedBoxes, i, key, visit, count);
    }
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> status = {1, 0, 1, 0};
  vector<int> candies = {7, 5, 4, 100};
  vector<vector<int>> keys = {{}, {}, {1}, {}};
  vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
  vector<int> initialBoxes = {0};

  log("%d\n",
      s.maxCandies(status, candies, keys, containedBoxes, initialBoxes));
  return 0;
}
