#include <vector>
// https://community.topcoder.com/stat?c=problem_statement&pm=17246&rd=18897
class ShoppingStickers {
 public:
  std::vector<int> purchase(int S, std::vector<int> items) {
    int aNoFit = 0;
    int A = 0;
    int B = 0;
    for (auto& i : items) {
      B += i/S;   
      if (i % S == 0)
        A += i/S;
      else
        aNoFit += i;
    }
    A += aNoFit/S;
    return { A, B };
  }
};
