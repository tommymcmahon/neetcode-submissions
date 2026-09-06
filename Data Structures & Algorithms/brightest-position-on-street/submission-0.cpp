class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {

        std::map<int, int> diffs;
        for (auto light : lights)
        {
            int start = light[0] - light[1];
            int end   = light[0] + light[1];
            diffs[start]++;
            diffs[end+1]--;
        }

        int offset=INT_MIN;
        int maxBright {-1};
        int brightness {0};

        for (auto& [pos, light] : diffs)
        {
            brightness += light;    
            if (brightness > maxBright)
            {
                maxBright = brightness;
                offset=pos;
            }
        }

        return offset;
    }
};
