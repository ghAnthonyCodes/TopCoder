#include <vector>
#include <string>

class VisitPoints {
  public:
    std::string visit(std::vector<int> X, std::vector<int> Y) {
    int maxX = 0;
    int maxY = 0;
    std::string ans = "";
    for (int i = 0; i < X.size(); i++) {
      maxX = std::max(maxX, X[i]);
      maxY = std::max(maxY, Y[i]);
    }
    bool goingUp = true;
    for (int i=0; i <= maxX; i++) {
      if (goingUp) {
        for (int j=0; j < maxY; j++) 
          ans += "N";
        if (i != maxX)
          ans += "E";
        goingUp = false;
      } else {
        for (int j=0; j < maxY; j++)
          ans += "S";
        if (i != maxX)
          ans += "E";
        goingUp = true;
      }
    }
    return ans;   
    }
};
