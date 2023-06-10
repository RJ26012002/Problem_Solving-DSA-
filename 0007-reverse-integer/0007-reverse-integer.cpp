class Solution {
public:
    int reverse(int x) {
        int ans =0;
        while(x!=0){
            int dig =x%10;
            if(ans<INT_MIN/10||ans>INT_MAX/10){
                return false;
            }
            ans=(ans*10+dig);
            x=x/10;
        }
        return ans;
        
    }
};