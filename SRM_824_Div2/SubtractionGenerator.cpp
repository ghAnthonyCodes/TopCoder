#include <vector>
#include <cmath>
using namespace std;

class SubtractionGenerator {
  public:
    vector <int> generate(int result) {

        // Possibility 1
        int y = pow(10, floor(log10(result)));
        int x = y + result;
        if (x >= pow(10, floor(log10(result)) + 1))
        	return { x, y };
        
        // Possiblity 2
        x = pow(10, floor(log10(result)) + 1);
        y = x - result;
        return { x, y };
    }
};
