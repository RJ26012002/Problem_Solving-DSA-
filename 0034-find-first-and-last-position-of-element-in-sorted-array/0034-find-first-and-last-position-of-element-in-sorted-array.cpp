class Solution {
public:

    int lastOc(vector<int> & arr , int  target ,int  n){
        int s = 0;
        int e = n-1;
        int lastOc = -1;
        int mid = s+(e-s)/2;
        
        while(s<=e){
           
            // cout<<"Here mid is "<<mid<<endl;
            if(arr[mid] ==  target){
                lastOc = mid;
                s = mid+1;
            }
            
           else if(target > arr[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
             mid = s+(e-s)/2;
        }
        return lastOc;
    }
    
    int firstOc(vector<int> & arr ,int target , int n ){
        int s = 0;
        int e = n-1;
        int firstOc = -1;
        int mid = s + (e-s)/2 ;
        
        while(s<=e){
           if(arr[mid]==target){
                firstOc = mid;
                e = mid -1;
            }
            else if(target > arr[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
             mid = s+(e-s)/2;
        }
        
        return firstOc; 
    }
   
    vector<int> searchRange(vector<int>& v, int x) {
        vector<int> ans;
        int a=firstOc(v,x,v.size());
        int b = lastOc(v,x,v.size());
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    
    }
};