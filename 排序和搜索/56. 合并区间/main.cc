#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& deltas) {
    std::sort(deltas.begin(), deltas.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0];
              });

    std::vector<std::vector<int>> res;
    for (int i = 0; i < deltas.size(); ++i) {
      std::vector<int> cur = deltas[i];
      for (int j = i + 1; j < deltas.size(); ++j) {
        if (Intersect(cur, deltas[j])) {
          cur[1] = std::max(cur[1], deltas[j][1]);
          ++i;
        } else {
					break;
        }
      }
      res.push_back(std::move(cur));
    }

		return res;
  }

  bool Intersect(const std::vector<int>& a, const std::vector<int>& b) {
    return std::max(a[0], b[0]) <= std::min(a[1], b[1]);
  }
};