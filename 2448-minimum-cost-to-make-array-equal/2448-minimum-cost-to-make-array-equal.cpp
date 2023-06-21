class Solution {
public:
    /*long long minCost(vector<int>& nums, vector<int>& cost) {
        long long sum =0;
        int maxIndex =0;
        int n=nums.size();
        int c = cost.size();

        for(int i =0;i<c;i++){

            if(cost[maxIndex]<cost[i]){
                maxIndex=i;
            }
            
        }
        for(int i =0;i<n;i++){
            long long diff = abs(nums[i]-nums[maxIndex]);
            sum+=diff*cost[i];
        }
        return sum;
    }*/
     typedef long long ll;
    
    ll getCost(vector<int>& nums, vector<int>& cost, int target) {
        ll result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result += (ll) abs(nums[i] - target) * cost[i];
        }
        return result;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        ll answer = INT_MAX;
        
        int left = *min_element(nums.begin(), nums.end());  //1
        int right = *max_element(nums.begin(), nums.end()); //5
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            ll cost1 = getCost(nums, cost, mid);
            ll cost2 = getCost(nums, cost, mid + 1);
            
            answer = min(cost1, cost2);
            if (cost1 > cost2)
                left = mid + 1;
            else
                right = mid-1;
        }
        return answer == INT_MAX ? 0 : answer;
    } 
};