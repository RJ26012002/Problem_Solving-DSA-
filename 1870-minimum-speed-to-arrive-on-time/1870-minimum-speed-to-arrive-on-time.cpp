class Solution {
public:
    double possible(vector<int>&dist,int speed){
        double time = 0.0;
        for(int i =0;i<dist.size()-1;i++){
            double t = (double)dist[i]/(double)speed;
            time+=ceil(t);
        }
        time+=(double)dist[dist.size()-1]/(double)speed;
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1;
        int e = 1e7;
        int mid = s+(e-s)/2;
        int result =-1;
        while(s<=e){
            mid = s+(e-s)/2;
            if(possible(dist,mid)<=hour){
                result = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return result;
    }
};