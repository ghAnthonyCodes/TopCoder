#include <string>
using namespace std;

// https://community.topcoder.com/stat?c=problem_statement&pm=17159&rd=18868
class LightbulbRow {
 public:
  string solve(string bulbStates, int startIndex, int goalCount) {
    int need = goalCount;
    string ans = "";
    for (auto c: bulbStates)
      if (c == 'O')
        need--;
    if (need == 0)
      return "SS";

    int N = bulbStates.length();
    // 1. Go to closest side (at most N/2 Actions, then turn each one on = 2N actions)
    for (int i=startIndex+1; i<N; i++) // At most N operations
      ans += ">";
    if (need > 0) {
      for (int i=N-1; i >= 0; i--) {
      if (bulbStates[i] == 'X') {
        ans += 'S';    
        need--;
      }
      if (i == 0 || need == 0)
        return ans;
        ans += '<';
      }
    }
    else {
      for (int i=N-1; i >= 0; i--) {
        if (bulbStates[i] == 'O') {
          ans += 'S';    
          need++;
        }
        if (i == 0 || need == 0)
          return ans;
        ans += '<';
      }
    }
    return "";
  }
};
