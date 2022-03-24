#include <string>
#include <vector>
#define M 1000000007

// https://community.topcoder.com/stat?c=problem_statement&pm=17215&rd=18888
class StepHopJumpMedium {
  public:
    int countWays(std::string level) {
      // T[i] = number of ways to reach square i
      std::vector<int> T = std::vector<int>(level.length(), 0);
      T[0] = 1;
      
      for (int i = 1; i < level.length(); i++) {
        if (level[i] == '*') 
          continue;
  
        for (int j = 1; j <= 3; j++) {
          if ((i - j) >= 0) 
            T[i] = (T[i] + T[i - j]) % M;
        }
      }
      return T[level.length() - 1];
    }
};
