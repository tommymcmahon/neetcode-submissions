class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        long long rev = 0;
        long long num = x;
        while (num != 0)
        {
            rev = (rev * 10) + (num %10);
            num /= 10; 
        }

        std::cout << rev << std::endl;
        return rev == x;
    }
};