class Solution {
public:
    // bool solve(int index , string &s ,set<string>& st){
    //     if(index == s.size()){
    //         return true;
    //     }
    //     string str;
    //     for(int i =index;i<s.length();i++){
    //         // string str;
    //         str += s[i];
    //         if(st.find(str)!=st.end() && solve(i+1,s,st)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     set<string> st;
    //     for(auto a:wordDict){
    //         st.insert(a);
    //     }
    //    return solve(0,s,st);
        
    // }
     unordered_set<string> st;
    int t[301];
    int n;
    
    bool solve(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return t[idx] = true;
            
        }
        
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        memset(t, -1, sizeof(t));
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};