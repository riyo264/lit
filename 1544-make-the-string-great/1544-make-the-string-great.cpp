class Solution {
public:
    string makeGood(string s) {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans;
        stack<char> st;
        int n = s.length();
        for(int i = n-1; i > -1; i--)
        {
            for(int j = 0; j < alpha.length(); j++){
            if(st.empty()==1)
            {
                st.push(s[i]);
                break;
            }
            else if((st.top()==alpha[j]) && (s[i]!=ALPHA[j]))
            {
                st.push(s[i]);
                break;
            }
            else if((st.top()==ALPHA[j]) && (s[i]!=alpha[j]))
            {
                st.push(s[i]);
                break;
            }
            else if((st.top()==alpha[j]) && (s[i]==ALPHA[j]))
            {
                st.pop();
                break;
            }
            else if((st.top()==ALPHA[j]) && (s[i]==alpha[j]))
            {
                st.pop();
                break;
            }
            }
        }
        while(st.empty()==0){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};