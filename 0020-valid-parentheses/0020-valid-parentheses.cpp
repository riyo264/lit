class Solution {
public:
bool isValid(string s)
{
    bool x = true;
  stack<char> st;
  int n = s.size();
  for(int i = 0; i<n; i++)
  {
    if(s.size()==1){
        x = false;
        break; 
    }
    else if(i == n-1 &&((s[i]=='(') || (s[i]=='{') || (s[i]=='['))){
        x = false;
        break;
    }
    else if((s[i]=='(') || (s[i]=='{') || (s[i]=='['))
    {
        st.push(s[i]);
    }
    else{
        if(st.size()==0){
        x = false;
            break;
        }
        else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')) 
        {
            st.pop();
        }
        else{
            x = false;
            break;
        }
    }
  } 
  if(st.size()!=0){
    x = false;
  }
  return x; 
}
};