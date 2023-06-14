class Solution {
public:
    // khudse kia 
    int removeElement(vector<int>& nums, int val) {
        vector<int> output;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=val){
                output.push_back(nums[i]);
            }
        }
        
        for(int i =0;i<output.size();i++){
            nums[i]=output[i];
        }

        return output.size();
    }
};