#include <vector>
#include <limits>
class GetGas {
  public:
    double optimize(int G, std::vector<int> Dto, std::vector<int> Dfrom, std::vector<int> gasPrice) {
        
        // Calc cost
        double minPrice = std::numeric_limits<double>::infinity();
        for (int i = 0; i < Dto.size(); i++) {
            
            double gallonsLeft = G - Dto[i]/25.0;
            if (gallonsLeft < 0)
                continue;
            double cost = gasPrice[i]*(Dfrom[i] - gallonsLeft*25.0)/25.0;
			minPrice = std::max(0.0, std::min(cost, minPrice));
        }
        return minPrice;   
    }
};
