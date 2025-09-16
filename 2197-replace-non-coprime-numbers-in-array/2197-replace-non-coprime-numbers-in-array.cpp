class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int g = gcd(st.back(), st[st.size()-2]);
                if (g == 1) break;
                long long lcm = (1LL * st.back() / g) * st[st.size()-2];
                st.pop_back();
                st.back() = lcm;
            }
        }
        return st;
    }
};