#include <string>
#include <vector>
#include <set>
class OptimalMemoryGame {
 public:
  int findPairs(std::string known) {
    int ans = 0;
    std::set<char> H;
    int unknown = 0;
    for (auto& k : known) {
      if (k == '-') {
        unknown++;
        continue;
      }
      if (H.find(k) != H.end()) {
        ans++;
        H.erase(H.find(k));
      } else {
        H.insert(k);   
      }
    }

    // We have "x" unkown and a set of single chars s = { A, B, C }
    if (unknown <= H.size())
      ans += unknown;
    else if (unknown == 2)
      ans++;
    return ans;
  }
};
