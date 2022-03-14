#include <vector>

class AssignPoints {
  public:
    std::vector<int> assign(int N, std::vector<int> results) {
        
        int placesLeft = N;
        int points = N;
        std::vector<int> answer = std::vector<int>(N, 0);
        while (placesLeft > 0) {
            int min = 10001;
            
            // Find new max
            for (int i=0; i<N; i++) {
                if (results[i] != -1 && results[i] < min)
                    min = results[i];
            }
            
            // We are done
            if (min == 10001) {
            	return answer;   
            }
            
            // Create new vector while handing out places
            for (int i=0; i<N; i++) {
                if (results[i] == min) {
                    answer[i] = points;
                    results[i] = -1; // effectively remove this from future parses
                    placesLeft -= 1;
                }
            }
            points = placesLeft;
        }
        return answer;
    }
};
