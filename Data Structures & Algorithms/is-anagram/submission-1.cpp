class Solution {
public:
    bool isAnagram(string s, string t) {

        std::unordered_map<char, int> letters;

        // Iterate s adding from letters while keeping count
        for(int i=0; i < s.size(); ++i)
        {
            auto &letter = s[i];
            if (letters.contains(letter)) {
                ++letters[letter];
            }
            else {
                letters[letter] = 1;
            }
        }

#if DEBUG
        for(auto [letter, count] : letters)
        {
            std::cerr << letter << "=" << count << ";";
        }
        std::cerr << std::endl;
#endif

        // Iterate through t removing from letters reducing count
        for(int i=0; i < t.size(); ++i)
        {
            auto &letter = t[i];
            if (letters.contains(letter)) 
            {
                // remove letters if this is the last one
                if (letters[letter] == 1) 
                {
                    letters.erase(letter);
                }
                else
                {
                    --letters[letter];
                }
            }    
            else
            {
               return false;     
            }
        }

#if DEBUG
        for(auto [letter, count] : letters)
        {
            std::cerr << letter << "=" << count << ";";
        }
        std::cerr << std::endl;
#endif
        // If it's empty this is an anagram
        return letters.empty();
    }
};