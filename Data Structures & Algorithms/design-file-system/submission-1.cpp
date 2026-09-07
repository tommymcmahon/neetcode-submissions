class FileSystem {
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {

        std::string basePath = path.substr(0, path.rfind('/'));

        if (!basePath.empty() && basePath != path)  
        {
            if (!inodes.contains(basePath))
            {
//                std::cout << "BasePath doesn't exsit for " << path << "; " << basePath << std::endl;
                return false;    
            }
        }

        auto retcode = inodes.insert({path, value});

        if (retcode.second == false) 
        {
//            std::cout << "Failed to insert duplicate path" << path << std::endl;
            return false;
        }


        return true;
    }
    
    int get(string path) {

        auto iter = inodes.find(path);
        if (iter != inodes.end())
        {
            return iter->second;    
        }

        return -1;
    }

    std::unordered_map<std::string, int> inodes;

};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
