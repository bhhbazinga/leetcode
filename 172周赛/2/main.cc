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
  vector<string> split(const string& str, const string& delim) {  
	vector<string> res;  
	if("" == str) return res;  
	//先将要切割的字符串从string类型转换为char*类型  
	char * strs = new char[str.length() + 1] ; //不要忘了  
	strcpy(strs, str.c_str());   
 
	char * d = new char[delim.length() + 1];  
	strcpy(d, delim.c_str());  
 
	char *p = strtok(strs, d);  
	while(p) {  
		string s = p; //分割得到的字符串转换为string类型  
		res.push_back(s); //存入结果数组  
		p = strtok(NULL, d);  
	}  
 
	return res;  
} 

    vector<string> printVertically(string s) {
      vector<string> ss =  split(s, " ");
      int max_len = INT_MIN;
      for (const string &s : ss) {
        max_len = std::max<int>(s.length(), max_len);
      }

      for (string &s : ss) {
        int space_num = max_len - s.length();
        for (int i = 0; i < space_num; ++i) {
          s.append(" ");
        }
      }

      vector<string> res;
      for (int j = 0; j < max_len; ++j) {
        string tmp = "";
        for (int i = 0; i < ss.size(); ++i) {
          tmp += ss[i][j];
        }
        for (int k = tmp.length() - 1; k >=0; --k) {
          if (tmp[k] != ' ') {
            ++k;
            tmp.erase(k, tmp.length() - k);
            break;
          }
        }

        // log("%s,%d\n", tmp.c_str(), tmp.length());
        res.push_back(std::move(tmp));
      }

      return res;
    }
};
int main(int argc, char const* argv[]) {
  /* code */

  Solution s;
  s.printVertically("CONTEST IS COMING");
  return 0;
}
