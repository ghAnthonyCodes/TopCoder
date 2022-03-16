#include <vector>
#include <cmath>
#include <cstdio>
class DecimalCoins {
  public:
    // If C[0] < 9, we know that we the min we cannot do is C[0] + 1
    // Else, we know we can do up to C[1]*10 + C[0].
    // If C[1]*10 + C[0] is less than 99, we know the min we cannot do is C[1]*10 + C[0] + 1
    // Else, we know we can do up to C[2]*100 + C[1]*10 + C[0],
    // etc...
    int pay(std::vector<int> C) {
        
        int x = 0;
        int m = C[0];
        
        while (x < 6) {
            if (m < (int)pow(10, x+1) - 1)
                return m + 1;
            x++;
            m += C[x]*(int)pow(10, x);
        }
        return m + 1;
    }
};
