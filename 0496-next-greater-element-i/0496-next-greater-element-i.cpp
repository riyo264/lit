class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n2 = nums2.size();
        int n1 = nums1.size();
        vector<int> ans_ref;
        vector<int> ans;

        for(int i = n2-1; i > -1; i--)
        {
            while(st.empty()==0 && (st.top()<=nums2[i]))
            {
                st.pop();
            }
            if(st.empty()==1)
            {
                ans_ref.push_back(-1);
                st.push(nums2[i]);
            }
            else{
                ans_ref.push_back(st.top());
                st.push(nums2[i]);
            }
        }
        for(int i = 0; i < n1; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(nums1[i]==nums2[j]){
                    ans.push_back(ans_ref[(n2-1)-j]);
                }
            }
        }
        return ans;
    }

};