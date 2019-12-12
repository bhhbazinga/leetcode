#include <queue>
#include <unordered_map>
#include <vector>
class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> num2count;
    for (int num : nums) {
      if (num2count.find(num) == num2count.end()) {
        num2count[num] = 0;
      } else {
        ++num2count[num];
      }
    }

    struct Comparator {
      bool operator()(const std::pair<int, int>& pair_a,
                      const std::pair<int, int>& pair_b) const {
        return pair_a.second > pair_b.second;
      }
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        Comparator>
        pq;
    for (const auto& pair : num2count) {
      pq.push(pair);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    std::vector<int> res(k);
    for (int i = k - 1; i >= 0; --i) {
      res[i] = pq.top().first;
      pq.pop();
    }
    return res;
  }
};
