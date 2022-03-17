#include <vector>
#include <cstdio>
#define ll long long
// https://community.topcoder.com/stat?c=problem_statement&pm=17276&rd=18920
class GlobalWarmingCheck {
  public:
    // T = { 7, 12, 19, 8, 19, 12 }
    std::vector<int> solve(int N, int M, int Y) {
        std::vector<ll> T = std::vector<ll>(N);
        for (ll i=0; i<N; i++)
            T[i] = (i*i + 4*i + 7) % M;
        ll sumY = 0;
        for (int i=0; i<Y; i++)
            sumY += T[i];
        ll hi = sumY;
        int hiIdx = 0;
        ll lo = sumY;
        int loIdx = 0;
        for (int start=1; start <= N-Y; start++) {
            sumY -= T[start-1];
            sumY += T[start + Y - 1];
            if (sumY >= hi) {
            	  hi = sumY;
                hiIdx = start;
            }
            if (sumY < lo) {
            	  lo = sumY;
                loIdx = start;
            }
        }
        return { loIdx, hiIdx };
    }
};
