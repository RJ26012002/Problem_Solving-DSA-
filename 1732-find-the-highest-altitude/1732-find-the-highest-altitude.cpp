class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int val=0;
        int maxAlt=0;

        for(int i=0;i<gain.size();i++){
            val+=gain[i];
            maxAlt = max(val,maxAlt);
        }
        return maxAlt;
    }
};