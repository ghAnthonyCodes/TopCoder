#include <vector>
#include <cstdio>
#define ll long long

// https://community.topcoder.com/stat?c=problem_statement&pm=17218&rd=18891
class SunShroom {
  public:
    ll produceSun(std::vector<ll> plantingTime, ll queryTime) {
        ll sun = 0;
        for (auto& t : plantingTime) {
       		sun += 25*std::max(0LL, (queryTime - t - 96)/24);
            sun += 15*std::min(4LL, std::max(0LL, (queryTime - t)/24));
        }
        return sun;
    }
};
