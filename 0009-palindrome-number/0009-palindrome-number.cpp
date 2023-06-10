class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        vector<int> nums;
        while(x!=0){
            int digit = x%10;
            nums.push_back(digit);
            x=x/10;
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != nums[nums.size() - 1 - i] ){
                return false;
            }
            
        }
        return true;
        
    }
};