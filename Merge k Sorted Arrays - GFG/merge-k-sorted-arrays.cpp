//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class data{
    public:
    int val , apos, vpos;
    data(int d , int ap , int vp){
        val = d;
        apos = ap;
        vpos = vp;
    }
};
struct myComp{
    bool operator()(data &d1,data &d2){
        return d1.val>d2.val;
    }
};
class Solution
{
    public:
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<data,vector<data>,myComp> q;
        for(int i=0;i<K;i++){
            data d(arr[i][0],i,0);
            q.push(d);
        }
        
        
        while(!q.empty()){
            data curr = q.top();q.pop();
            ans.push_back(curr.val);
            int cp = curr.apos , vp = curr.vpos;
            if(vp+1<arr[cp].size()){
                data d(arr[cp][vp+1],cp,vp+1);
                q.push(d);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends