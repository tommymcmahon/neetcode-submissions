class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int count=0;
        for (int i = 0; i < words.size(); ++i) 
        {
            for (int j = i+1; j < words.size(); ++j) 
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    ++count;
                }
            }
        }
        return count;
    }

    bool isPrefixAndSuffix(std::string pattern, std::string word)
    {
        int wsize = word.size();
        int psize = pattern.size();

        if ( psize > wsize) return false;
/*
        cout << "pattern: " << pattern << std::endl;
        cout << "word: "    << word    << std::endl;
*/
        for (int i=0; i < psize; ++i)
        {
            char p=pattern[i];
            char l=word[i];
            char r=word[wsize-psize+i]; 

            cout << "p[" << i << "]= " << p
                 << " l=" << l << " r="  << r  
                 << std::endl;

            if ((l != p) || (r != p))
            {
                return false;
            }
        }
        return true;
    }
};