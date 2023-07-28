class Solution {
    /*private:
    bool solve(vector<int>& arr,int i,int j ,int sum){
    // base case 
    if(i>j){
        return 0;
    }
   
    int choice1=arr[i]+min(solve(arr,i+1,j-1,sum),solve(arr,i+2,j,sum));
    //cout<<"value of choice 1 is "<<choice1<<endl;
    if(choice1>=sum-choice1)
        //cout<<"turu hain"<<endl;
        return true;
    
    int choice2=arr[j]+min(solve(arr,i,j-2,sum),solve(arr,i+1,j-1,sum));

    //cout<<"value of choice 2 is "<<choice2<<endl;
    if(choice2>=sum-choice2)
        return true;
    
    
    return false;
        
}
public:
    bool PredictTheWinner(vector<int>& arr) {
        int sum=0;
    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];

    }

   // cout<<"sum is "<<sum;
   if(solve(arr,0,arr.size()-1,sum))
        return true;
    
    else
        return false ;
    
        
    }*/

    int solve(vector<int> & nums ,int i , int j){
        // base case 
        if(i>j){
            return 0;
        }
        if(i == j){
            return nums[i];
        }

        int option1 =  nums[i] +  min(solve(nums, i+2,j), solve(nums, i+1,j-1));
        int option2 =  nums[j] + min(solve(nums,i+1,j-1),solve(nums,i,j-2));

        return max(option1 , option2);

    }
    public:
    bool PredictTheWinner(vector<int>& arr){
        int p1=solve(arr,0,arr.size()-1);
        int total = 0;
        for(int i=0;i<arr.size();i++){
            total = total + arr[i];
        }
        int p2 = total - p1;

        if(p1>=p2){
            return true;
        }
        return false;
    }

};