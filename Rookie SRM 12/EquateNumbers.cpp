#include <bits/stdc++.h>
using namespace std;
class EquateNumbers {
  public:
    string canMakeEqual(vector <int> A) {
        
        // 1 check
        bool allOnes = true;
        for (auto& a : A)
            allOnes = allOnes && (a == 1);
        if (allOnes)
            return "yes";
        int gcd = A[0];
        for (int i=1; i<A.size(); i++) {
            gcd = __gcd(A[i], gcd);
        }
        if (gcd == 1)
            return "no";
        return "yes";
    }
};
