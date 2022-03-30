#include <set>
#include <vector>
#include <algorithm>
#define ll long long 
#define vi_t std::vector<int>
#define pii_t std::pair<int, int>
#define vpii_t std::vector<pii_t>

class TwoFairDice {
 private:
  vpii_t Boundaries;
  vi_t Alice;
 public:
  ll finish(std::vector<int> A, std::vector<int> B) {
    // Corner case
    if (B.size() == 6) {
      if (this->equal(A, B))
        return 1;
      return 0;
    }
    std::sort(A.begin(), A.end());
    std::set<std::pair<int, int>> boundariesSet;
    int s = 0;
    for (int i=0; i<6; i++) {
      if (s <= (A[i] - 1))
        boundariesSet.insert({ s, A[i] - 1});
      boundariesSet.insert({ A[i], A[i] });
      s = A[i] + 1;
    }
    boundariesSet.insert({ s, 1000 });

    for (auto& b : boundariesSet)
      this->Boundaries.push_back(b);
    
    this->Alice = A;
    ll ans = 0;
    for (auto& p : this->Boundaries) 
      ans += this->next(B, p);
    return ans;   
  }
  
  // 4 _ _
  ll next(vi_t V, pii_t p) {

    V.push_back(p.first);

    // If we are on last leg
    if (V.size() == 6) {
      if (this->equal(this->Alice, V))
        return (p.second - p.first + 1);
      return 0;
    }
    ll ret = 0;
    for (auto& b : this->Boundaries)
      ret += this->next(V, b);
    return (p.second - p.first + 1)*ret;
  }

  // Assume sorted
  bool equal(std::vector<int> A, std::vector<int> B) {
    int l = 0, g = 0;
    for (auto& a : A) {
      for (auto& b : B) {
        if (a > b) g++;
        if (a < b) l++;
      }
    }
    return l == g;
  }
};
