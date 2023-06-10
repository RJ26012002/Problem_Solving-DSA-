class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val = 1;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i] !=nums[i+1]){
                nums[val]= nums[i+1];
                val++;
            }
        }
        return val;
    }
};