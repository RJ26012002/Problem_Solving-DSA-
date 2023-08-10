//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // building minHeap in order to find the kth largest
	   // priority_queue<int , vector<int> , greater<int>> q;
	   // int i=0;
	   // while(k!=0){
	   //     q.push(arr[i]);
	   //     i++;
	   //     k--;
	   // }
	   // for(;i<n;i++){
	   //     if(q.top()<arr[i]){
	   //         q.pop();
	   //         q.push(arr[i]);
	   //     }
	   // }
	   // return q.top();
	   vector<int> ans;
	   priority_queue<int> q;
	   for(int i =0;i<n;i++){
	       q.push(arr[i]);
	   }
	   while(k!=0){
	       ans.push_back(q.top());
	       q.pop();
	       k--;
	   }
	   return ans;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends