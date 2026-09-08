class Solution {
public:
    [[nodiscard]] int countSubstrings(string s) 
    {
        int count {0};
        for (int i=0; i < s.size(); ++i)
        {
            count += countPalindromes(s, i, i);
            count += countPalindromes(s, i, i+1);
        }
        return count;
    }

    [[nodiscard]] int countPalindromes(const std::string &s, int left, int right)  
    {
        int count=0;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            ++count;
            --left;
            ++right;
        }
        return count;
    }

};
