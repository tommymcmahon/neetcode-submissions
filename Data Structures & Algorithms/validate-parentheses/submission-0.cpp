/*
   1. Create a map of open to close characters 
   2. Use a stack to push and pop elements
*/

#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {

        std::unordered_map<char, char> lookup = { 
            { ')', '(' },
            { '}', '{' },
            { ']', '[' },
        };

        std::string stackit;
        for (int i=0; i < s.size(); ++i) {
            if (lookup.contains(s[i]))
            {
                auto c = stackit.back();
                if (c != lookup[s[i]])
                {
                    return false;
                }
                stackit.pop_back();
            }
            else
            {
                stackit.push_back(s[i]);
            }
        }

        return stackit.empty();
    }
};
