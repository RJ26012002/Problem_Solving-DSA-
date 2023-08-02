//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &arr,int size, int index ){
        while(index<=size){
            int left = index*2;
            int right = index*2 + 1;
            int greatest = index;
            if(left<=size && arr[left]>arr[greatest]){
                greatest = left;
            }
            if(right<=size && arr[right]>arr[greatest]){
                greatest = right;
            }
            if(greatest != index){
                swap(arr[greatest],arr[index]);
                index=greatest;
            }
            else{
                break;
            }
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> merge;
        merge.push_back(-1);
        for(auto i:a){
            merge.push_back(i);
        }
        for(auto i:b){
            merge.push_back(i);
        }
        int size = merge.size()-1;
        
        for(int i =size/2;i>=1;i--){
            heapify(merge,size,i);
        }        
        vector<int> ans;
        for(int i =1;i<merge.size();i++){
            ans.push_back(merge[i]);
            // cout<<merge[i]<<" ";
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends