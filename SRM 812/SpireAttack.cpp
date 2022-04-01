#include <vector>
#include <cstdio>
using namespace std;

// https://community.topcoder.com/stat?c=problem_statement&pm=17133&rd=18805
class SpireAttack {
public:
	int dealMostDamage(int N, vector <int> actions, vector <int> damage) {
        
        // Let T[i,j] be the max damage for cards up to j that use i energy
        vector<vector<int> > T = vector<vector<int>> (4, vector<int>(N + 1, 0));
        for (int energy=1; energy<=3; energy++) {
       		for (int card=1; card<=N; card++) {
                T[energy][card] = T[energy][card-1];
                if (actions[card-1] <= energy) {
                	T[energy][card] = std::max(T[energy][card], damage[card-1] + T[energy - actions[card-1]][card-1]);
                }
            }
        }
        int maxDam = 0;
        for (int i=1; i<=N; i++) {
            maxDam = std::max(T[3][i], maxDam);
        }
            
        return maxDam;
	}
};
