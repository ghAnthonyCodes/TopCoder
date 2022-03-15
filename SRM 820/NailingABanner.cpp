#define ll long long
#include <cmath>
#include <vector>
#include <cstdio>

class NailingABanner {
  public:
    // start(round) = size / 2^(round)
    // spacer(round) = size / 2^(round - 1)
    // R[round] = R[round-1] + 2^(round - 1)
    // 1. increment rounds
    //    placed = 2;
    
    // *---------------*
    // R[0] = 2
    
    // Round 1
    // spacer = size, start = size/2
	  // *-------x-------*
    // R[1] = R[0] + 1 + (size - start)/spacer = 3 ( add 1 )
    
    // Round 2
    // spacer = size/2, start = size/4
    // *---x---*---x---*
    // R[2] = R[1] + 1 + (size - start)/spacer = 5 ( add 2 )
    
    // spacer = N/4, start = size/8
    // *-x-*-x-*-x-*-x-*
    // R[3] = R[2] + 1 + (size - start)/spacer = 9 ( add 4 )
    
    // spacer = N/8, start = size/16
    // *x*x*x*x*x*x*x*x*
    // R[4] = R[3] + 1 + (size - start)/spacer = 17 ( add 8 ), etc...
    ll coordinate(ll N) {
        std::vector<ll> T = std::vector<ll>(61, 0);
        ll size = (ll)pow(2, 60);
        T[0] = 2;
        // start(round) = size / 2^(round)
        // spacer(round) = size / 2^(round - 1)
        // R[round] = R[round-1] + 2^(round - 1)
        if (N == 1) return 0;
        if (N == 2) return (ll)pow(2, 60);
        
        // Build T
        for (int round = 1; round <= 60; round++)
        	T[round] = T[round - 1] + (ll)pow(2, round - 1);
        
        // Find starting point
		    // T[0] = 2
        // T[1] = 3
        // T[2] = 5...
		    int round = 1;
        while (T[round] < N)
            round++;
       
        ll spacer = size/(ll)pow(2, round - 1);
        ll start = size/(ll)pow(2, round);
        
        return start + (N - T[round-1] - 1)*spacer;
    }
};
