class Solution {
public:
   
   bool checkParen(char &s,stack<char> &st){
       if(st.empty()){
           return false;
       }
       if(s == ']' && st.top() == '[' ){
           st.pop();
           return true;
       }
       if(s == '}' && st.top() == '{'){
           st.pop();
           return true;
       }
       if(s== ')' && st.top() == '('){
           st.pop();
           return true;
       }
       return false;
   }
    bool isValid(string s) {
        stack<char> st;
        if(s.length() ==1){
            return false;
        }
        if(s.length()==0){
            return true;
        }
        for(int i =0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]== '[' ){
                st.push(s[i]);
            }
            else{
                if(checkParen(s[i],st)==0){
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;


       
        
    }
};