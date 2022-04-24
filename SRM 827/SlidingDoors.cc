#include <bits/stdc++.h>
using namespace std;

class SlidingDoors {
 public:
  vector <string> openSection(int N, vector <string> rails, int S) {
    int a = 0, b = 0;
    for (int i=0; i<N; i++) {
      if (rails[0][i] == '-')
        a++;
      if (rails[1][i] == '-')
        b++;
    }
    string aAns = "";
    string bAns = "";
    // Build a
    for (int i=0; i<N; i++) {
      if (i == S) {
        aAns += '.';
      } else if (a > 0) {
        aAns += '-'; 
        a--;
      } else {
        aAns += '.';    
      }
    }
    for (int i=0; i<N; i++) {
      if (i == S) {
        bAns += '.';
      } else if (b > 0) {
        bAns += '-'; 
        b--;
      } else {
        bAns += '.';    
      }
    }
    return { aAns, bAns };
  }
};
