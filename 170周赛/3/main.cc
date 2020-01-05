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
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                        vector<vector<int>>& friends, int id,
                                        int level) {
    unordered_map<string, int> res;
    bfs(watchedVideos, friends, id, level, res);

    struct Watch {
      Watch(const string& name_, int count_) : name(name_), count(count_) {}

      string name;
      int count;
      bool operator<(const Watch& b) const {
        if (count != b.count) {
          return count < b.count;
        }

        return name < b.name;
      }
    };

    vector<Watch> watches;
    for (const auto& pair : res) {
      watches.push_back(Watch(pair.first, pair.second));
    }

    sort(watches.begin(), watches.end());
    vector<string> name_res;
    for (int i = 0; i < watches.size(); ++i) {
      name_res.push_back(watches[i].name);
    }
    return name_res;
  }

  void bfs(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends,
           int id, int level, unordered_map<string, int>& res) {
    struct Node {
      Node(int id_, int level_) : id(id_), level(level_) {}
      int id;
      int level;
    };

    vector<bool> vis(watchedVideos.size(), false);
    vis[id] = true;

    queue<Node> q;
    q.emplace(id, 0);
    while (!q.empty()) {
      const Node& cur = q.front();
      int cur_id = cur.id;
      int cur_level = cur.level;

      if (cur_level >= level) {
        for (int i = 0; i < watchedVideos[cur_id].size(); ++i) {
          ++res[watchedVideos[cur_id][i]];
        }
      }

      for (int i = 0; i < friends[cur_id].size(); ++i) {
        int next_id = friends[cur_id][i];
        int next_level = cur_level + 1;
        if (!vis[next_id] && next_level <= level) {
          vis[next_id] = true;
          q.emplace(next_id, next_level);
        }
      }

      q.pop();
    }
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;

  vector<vector<string>> watchedVideos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
  vector<vector<int>> friends = {{1, 2,}, {0, 3}, {0, 3}, {1, 2}};
  vector<string> res = s.watchedVideosByFriends(watchedVideos, friends, 0, 2);
  for (int i = 0; i < res.size(); ++i) {
    log("%s,", res[i].c_str());
  }
  return 0;
}
