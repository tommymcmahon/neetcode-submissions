class Solution {
public:

    bool isAlphaNum(std::string& s, int i)
    {
        // Check for uppercase and convert to lowercase if necessary
        if ((s[i] >= 'A' && s[i] <= 'Z'))
        {
            s[i] = tolower(s[i]);
            return true;
        }

        // Check for lower or numeric 
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') )
        {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {

        int left=0; 
        int right=s.size()-1;

        while(left < right) 
        {
            if (!isAlphaNum(s, left))  {  ++left; continue; }
            if (!isAlphaNum(s, right)) { --right; continue; }

            if (s[left] == s[right])
            {
                ++left; --right;
            }
            else
            {
                return false;    
            }
        } 
        return true;
    }
};
