class Solution {
public:
    string generateTag(string caption) {
        stack<char> st;
        string result;
        result.push_back('#');
        for(int i = caption.size()-1; i > -1; i--) 
            {
                if(caption[i] == ' ') {
                    continue;
                }
                else if(i != 0 && caption[i-1] == ' ') {
                    st.push(toupper(caption[i]));
                }
                else {
                    st.push(tolower(caption[i]));
                }
            }

        while(!st.empty()) 
            {
                if(result.size() == 100) {
                    st.pop();
                    continue;
                }
                if(result.size()==1) {
                    result.push_back(tolower(st.top()));
                    st.pop();
                }
                else{
                    result.push_back(st.top());
                    st.pop();  
                }
            }
        return result;
    }
};