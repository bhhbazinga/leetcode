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

class TweetCounts {
 public:
  unordered_map<string, set<int>> name2time_set;

  TweetCounts() {}

  void recordTweet(string tweetName, int time) {
    name2time_set[tweetName].insert(time);
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    vector<int> res;
    if (name2time_set.find(tweetName) == name2time_set.end()) return res;

    const set<int>& time_set = name2time_set[tweetName];
    int delta;
    if (freq == "minute") {
      delta = 60;
    } else if (freq == "hour") {
      delta = 3600;
    } else {
      delta = 86400;
    }

    set<int>::iterator index = time_set.end();
    for (auto it = time_set.begin(); it != time_set.end(); ++it) {
      if (*it >= startTime) {
        index = it;
        break;
      }
    }

    int l, r;
    for (int i = 0; (l = startTime + delta * i) <
                    (r = min(startTime + delta * (i + 1), endTime + 1));
         ++i) {
      res.push_back(0);

      while (index != time_set.end() && *index >= l && *index < r) {
        ++res[i];
        ++index;
      }
    }

    return res;
  }
};

int main(int argc, char const* argv[]) {
  TweetCounts tweetCounts = TweetCounts();

  tweetCounts.recordTweet("tweet0", 33);
  tweetCounts.recordTweet("tweet1", 89);
  tweetCounts.recordTweet("tweet2", 99);
  tweetCounts.recordTweet("tweet3", 53);
  tweetCounts.recordTweet("tweet4", 3);

  vector<int> res =
      tweetCounts.getTweetCountsPerFrequency("hour", "tweet0", 89, 3045);
  for (int n : res) {
    log("%d,", n);
  }
  log("%s", "\n");

  return 0;
}
