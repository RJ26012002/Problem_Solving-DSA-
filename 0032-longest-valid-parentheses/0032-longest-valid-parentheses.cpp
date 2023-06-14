class Solution {
public:
    int longestValidParentheses(string s){
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                maxi = max(maxi,i-st.top());
            }
        }
        return maxi;
    }
    // void check(stack<char> &st,char ch,int &count){
    //     if(st.empty()){
    //         // st.push(ch);
    //         count =0;
    //         return;
    //     }
    //     if(st.top()=='('){
    //         st.pop();
    //         count+2;
    //         return;
    //     }
    //     // st.push(ch);
    //     count=0;
    //     return;
    // }
    // int longestValidParentheses(string s) {
    //     stack<char> st;
    //     int maxi=INT_MIN;
    //     int count=0;
    //     for(int i =0;i<s.length();i++){
    //         char ch=s[i];
    //         if(ch=='('){
    //             st.push(ch);
    //         }
    //         else{
    //             check(st,ch,count);
    //             cout<<"value of count is "<<count<<endl;
    //             maxi=max(maxi,count);
    //         }
    //     }
    //     cout<<st.size()<<" len "<<s.length()<<endl;
    // return maxi;
    // }
};