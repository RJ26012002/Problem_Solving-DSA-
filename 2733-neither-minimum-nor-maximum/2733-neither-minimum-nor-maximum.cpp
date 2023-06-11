class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
    
    if (n < 3)
        return -1;

    // Sort the array in ascending order
    sort(nums.begin(), nums.end());

    // The number at index 1 will always be neither the minimum nor the maximum value
    return nums[1];
    }
};