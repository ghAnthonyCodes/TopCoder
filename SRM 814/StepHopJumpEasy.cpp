#include <string>

// https://community.topcoder.com/stat?c=problem_statement&pm=17214&rd=18888
class StepHopJumpEasy {
  public:
    std::string solve(std::string level) {
      std::string answer = "";
      for (int i = 1; i < level.length(); i++) {
        if (level[i] == '-') {
          answer += 'S';
        } else if (level[i] == '*' && level[i + 1] == '-') {
          answer += 'H';
          i++;
        } else if (level[i] == '*' && level[i + 1] == '*' && level[i + 2] == '-') {
          answer += 'J';
          i += 2;
        } else
          return "";
      }
      return answer;
    }
};
