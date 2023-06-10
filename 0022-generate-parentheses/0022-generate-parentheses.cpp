class Solution {
public:

    // khudse kara hian ** maze agaye 
    void solve(int n , int o ,int c,string &output , vector<string>& ans ){
        // base case 
        if(c == 0 && o ==  0){
            ans.push_back(output);
            return;
        }

        if(o>0){
            char ch = '(';
            output.push_back(ch);
            solve(n,o-1,c,output,ans);
            output.pop_back();
        }

        if(o<c){
            char ch = ')';
            output.push_back(ch);
            solve(n, o ,c-1,output , ans);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int o = n-1;
        int c = n;
        string output = "(";
        vector<string> ans;
        solve(n,o,c,output,ans);
        return ans;
        
    } 
};