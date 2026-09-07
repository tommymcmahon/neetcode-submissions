class Solution {
public:
    string simplifyPath(string path) {

        std::vector<std::string> stk; 
        std::string word;

        path += '/';
        for (int i=0; i < path.size(); ++i)
        {
            char p = path[i];

            if (p == '/')
            {
                if (word == ".")
                {
                    word.clear();
                }
                else if (word == "..")
                {
                    if (!stk.empty())
                    {
                        stk.pop_back();
                    }
                    word.clear();
                }
                else if (!word.empty())
                {
                    std::cout << word << std::endl;
                    stk.push_back(word);
                    word.clear();
                }
            }
            else
            {
                word += p; 
            }
        }

        if (stk.empty())
        {
            return {"/"};
        }
        
        std::string cpath;
        for (auto p : stk)
        {
            cpath += "/";
            cpath += p;
        }
        return cpath;
    }
};