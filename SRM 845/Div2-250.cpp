#include <vector>
using namespace std;
class FindBob {
  public:
    vector<int> find(int N, vector<int> houses) {
        // All possible to begin
        vector<bool> possible = vector<bool>(N, true);

        for (int i=0; i<N; i++) {
            if (houses[i] == -1)
                continue;
            for (int j=0; j<N; j++) {
                if ((j == (i - houses[i])) || (j == (i + houses[i])))
                    continue;
                possible[j] = false;
            }
        }
        vector<int> final = vector<int>();
        for (int i=0; i < N; i++) {
            if (possible[i])
                final.push_back(i);
        }
        return final;
                 
	}
};
