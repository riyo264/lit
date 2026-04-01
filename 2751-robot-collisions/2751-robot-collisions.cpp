class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int,int,char,int>> robo;
        for(int i = 0; i < n; i++) {
            robo.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robo.begin(), robo.end());

        stack<tuple<int,int,char,int>> st;

        for(int i = 0; i < n; i++) {
            int pos = get<0>(robo[i]);
            int h = get<1>(robo[i]);
            char d = get<2>(robo[i]);
            int idx = get<3>(robo[i]);

            if(d == 'R') {
                st.push({pos, h, d, idx});
            } else {
                while(!st.empty() && get<2>(st.top()) == 'R' && h > 0) {
                    auto top = st.top();
                    st.pop();

                    if(get<1>(top) > h) {
                        get<1>(top)--;
                        h = 0;
                        st.push(top);
                    } else if(get<1>(top) < h) {
                        h--;
                    } else {
                        h = 0;
                    }
                }

                if(h > 0) {
                    st.push({pos, h, d, idx});
                }
            }
        }

        vector<pair<int,int>> temp;
        while(!st.empty()) {
            auto t = st.top(); st.pop();
            temp.push_back({get<3>(t), get<1>(t)});
        }

        sort(temp.begin(), temp.end());

        vector<int> ans;
        for(auto &p : temp) ans.push_back(p.second);

        return ans;
    }
};