class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        vector<int> list;
        for(int i=0;i<nums.size();i++){
            list.push_back(nums[i]);
            if(i+1<nums.size() && nums[i+1]==nums[i]+1){
                continue;
            }
            else{
                if(list.size()>1){
                    string s= to_string(list[0])+"->"+to_string(list[list.size()-1]);
                    ans.push_back(s);
                    list.clear();
                }
                else{
                    ans.push_back(to_string(list[0]));
                    list.clear();
                }

            }
        }
        return ans;
    }
};