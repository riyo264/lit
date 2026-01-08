class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch : expression)
        {
            if(ch == ',' || ch == '(') {
                continue;
            }
            else if(ch != ')') {
                st.push(ch);
            }
            else {
                bool hasTrue = false;  // if a set of subexpression has atleast one True then for OR the whole is True 
                bool hasFalse = false; // if a set of subexpression has atleast one False then for AND the whole is False
                while(st.top() == 't' || st.top() == 'f') 
                {
                    char exp = st.top();
                    st.pop();
                    if(exp == 'f') {
                        hasFalse = true;
                    }
                    else {
                        hasTrue = true;
                    }
                }
                char op = st.top();
                st.pop();
                if(op == '!') {
                   if(hasTrue){
                        st.push('f');
                   }
                   else {
                        st.push('t');
                   }
                }
                else if(op == '&') {
                    if(hasFalse) {
                        st.push('f');
                    }
                    else {
                        st.push('t');
                    }
                }
                else {
                    if(hasTrue) {
                        st.push('t');
                    }
                    else {
                        st.push('f');
                    }
                }
            }
        }
        return st.top() == 't';
    }
};