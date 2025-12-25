class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++)
        {
            bool stay = true;
            while(!st.empty() && (st.top() > 0 && asteroids[i] < 0)) {
                if(abs(st.top()) > abs(asteroids[i])) {
                    stay = false;
                    break;
                }
                else if(abs(st.top()) < abs(asteroids[i])) {
                    st.pop();
                }
                else {
                    st.pop();
                    stay = false;
                    break;
                }
            }
            if(stay) {
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};