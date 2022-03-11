#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class OxToTiger {
  public:
    string rewrite(string message) {
        string word;
        string answer;
        vector<string> wordList;
        stringstream messageStream(message);
        
        // Still need to preserve all spaces
        while (getline(messageStream, word, ' ')) {
         	if (word == "ox") {
                wordList.push_back("tiger");
            }
            else if (word != "")
                wordList.push_back(word);
        }
        
        // Build answer
        int wordPtr = 0;
        int msgPtr = 0;
        while (msgPtr < message.size()) {
        	if (message[msgPtr] == ' ') {
                answer += ' ';
                msgPtr++;
            }
            else {
            	answer += wordList[wordPtr];
                wordPtr++;
                
                // Fast forward
                while (msgPtr < message.size() && message[msgPtr] != ' ')
                	msgPtr++;
            }
        }
        
        // Remove last space if present
        return answer;
    }
};
