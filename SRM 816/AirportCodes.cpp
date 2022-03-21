#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
#include <set>

// https://community.topcoder.com/stat?c=problem_statement&pm=17223&rd=18894
class AirportCodes {
 public:
  // No matching subsequences between any two airport names, or if there is, 
  // you can't use that sequence
  std::vector<std::string> name(std::vector<std::string> airports) {

    std::vector<std::string> answer;

    // List of airport code vectors
    std::vector<std::set<std::string>> codes;
    std::set<std::string> eraseCodes;
    for (auto& airport : airports)
      codes.push_back(getCodes(airport));

    // Remove codes from each airport that are in other airports
    for (int i = 0; i < airports.size(); i++) {
      for (int j = 0; j < airports.size(); j++) {
        if (i == j) 
          continue;

        // For each code for airport[i], erase 
        for (auto& code : codes[i]) {
          if (codes[j].find(code) != codes[j].end())
            eraseCodes.insert(code);
        }
      }
    }

    // Erase codes
    for (auto& code : eraseCodes) {
      for (int i = 0; i < airports.size(); i++) {
        while (codes[i].find(code) != codes[i].end())
          codes[i].erase(codes[i].find(code));
      }
    }

    // Form answer
    for (int i = 0; i < airports.size(); i++) {
      if (codes[i].size() == 0)
        answer.push_back("");
      else
        answer.push_back(*codes[i].begin());
    }
    return answer;
  }
  
  std::set<std::string> getCodes(std::string airport) {
    std::set<std::string> codes;
    for (int a = 0; a < airport.length() - 2; a++) {
      for (int b = a + 1; b < airport.length() - 1; b++) {
        for (int c = b + 1; c < airport.length(); c++) {
          std::stringstream ss;
          ss << airport[a] << airport[b] << airport[c];
          codes.insert(ss.str());
        }
      }
    }
    return codes;
  }
};
