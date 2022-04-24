#include <bits/stdc++.h>
using namespace std;

class ShortShortSuperstring {
  public:
    string M(string X, string Y) {
        string ret = X;
        int startY = 0;
        for (int s=X.length()-1; s>=0; s--) {
            bool allMatch = true;
            for (int j=0; j<Y.length() && s+j < X.length(); j++)
            	allMatch &= X[s+j] == Y[j];
            if (allMatch)
            	startY = (X.length() - s);
        }
        for (int y=startY; y<Y.length(); y++)
            ret += Y[y];
        return ret;
    }
    vector <string> constructAll(string A, string B, string C) {
        
        vector<string> mL = { "nnnnnnnnnnnnnnnn" };
        vector<string> potential;
        potential.push_back(M(M(A, B), C));  
        potential.push_back(M(M(A, C), B));
        potential.push_back(M(M(B, A), C));
        potential.push_back(M(M(B, C), A));
        potential.push_back(M(M(C, A), B));
        potential.push_back(M(M(C, B), A));
        for (auto& p : potential) {
            if (p.length() < mL[0].length())
                mL = { p };    
            else if (p.length() == mL[0].length())
                mL.push_back(p);
        }
        set<string> S;
        vector<string> Ans;
        for (auto& p : mL)
            S.insert(p);
        for (auto& s : S)
            Ans.push_back(s);
        return Ans;
    }
};
