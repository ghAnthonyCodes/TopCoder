#include <bits/stdc++.h>
using namespace std;

class WeightedDice {
  public:
    vector<vector<double>> memo;
    double wc(vector <double> prob, int rollIndex, int target) {
       
       int origTarget = target;
       if (memo[rollIndex][target] != -1) {
           return memo[rollIndex][target];
       }
       if (rollIndex + 1 == target) {
           memo[rollIndex][target] = 1.0;
           return 1.0;
       }
       if (rollIndex + 1 > target) {
           memo[rollIndex][target] = 0.0;
           return 0.0;
       }
       target -= (rollIndex + 1);
       double winChance = 0.0;
       for (int i=0; i<6; i++) {
           winChance += prob[i]*wc(prob, i, target);
       }
       memo[rollIndex][origTarget] = winChance;
       return winChance;
    }
    double winChance(vector <double> prob, int target) {
        memo = vector<vector<double>>(6, vector<double>(101, -1));
        double chance = 0;
        for (int i=0; i<prob.size(); i++) {
            // roll prob[i]
            chance += prob[i]*wc(prob, i, target);
            //printf("wc: %f\n", chance);
        }    
        return chance;
    }
};
