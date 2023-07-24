class Solution {
public:
    double myPow(double x, int n) {

        double ans=1.0;
        long k=n;
        if(k<0){
            k=(-1)*k;
        }
        while(k>0){
            if(k%2==1){
                ans*=x;
            }
            x=x*x;
            k=k/2;
        }
        if(n<1){
            ans=double(1.0)/(double)(ans);
        }
        return ans;
    }
};