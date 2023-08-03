class Solution {
    private:
    void solve(string digits,vector<string> &ans,string output, int index,string str[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = str[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,ans,output,index+1,str);
            output.pop_back();
        }
    }
   
public:
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
      if(digits.length() == 0)
      return ans;
      string output;
      int index = 0;
      string str[11]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",""};
      solve(digits,ans,output,index,str);
    return ans;
    }
};