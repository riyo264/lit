class Solution {
public:   
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge;
        stack<int> st;
        int n = nums.size();

        for(int i = (2*n)-1; i > -1; i--)
        {
            while(st.empty()==0 && (st.top() <= nums[i%n]))
            {
                st.pop();
            }
            if(i<n){
                if(st.empty()==1)
                {
                    nge.push_back(-1);
                }
                else{
                    nge.push_back(st.top());
                }
                st.push(nums[i]);
            }
            else{
                st.push(nums[i%n]);
            }
        }

/* Inverting the nge vector below */

        int n1 = nge.size();
        for (int i = 0; i < n1/2; i++)
        {
            if(i != ((n1-1)-i)){
            nge[i] = nge[i]^nge[(n1-1)-i];
            nge[(n1-1)-i] = nge[i]^nge[(n1-1)-i];
            nge[i] = nge[i]^nge[(n1-1)-i];
            }
            else{
                break;
            }        
        }
    return nge; 
    }
};