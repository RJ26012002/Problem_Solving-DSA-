//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(vector<int> &arr , int n , int index, vector<int> &sums){
       for(int i =0;i<n;i++){
           int sum =0;
           for(int j=i;j<n;j++){
               sum+=arr[j];
               sums.push_back(sum);
           }
           
       }
    }
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int> sums;
        
        solve(Arr,N,0,sums);
        // for(auto i:sums){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        priority_queue<int,vector<int>,greater<int>> q;
        int i =0;
        while(K!=0){
            q.push(sums[i]);
            K--;
            i++;
        }
        for(;i<sums.size();i++){
            if(q.top()<sums[i]){
                q.pop();
                q.push(sums[i]);
                
            }
        }
        return q.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends