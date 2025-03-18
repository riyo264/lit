class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        vector<int> nse;
        stack<int> st;
        int n = arr.size();
        for(int i = n-1; i > -1; i--)
        {
            while(st.empty()==0 && (arr[i] <= arr[st.top()]))
            {
                st.pop();
            }
            if(st.empty()==1)
            {
                nse.push_back(n);
            }
            else{
                nse.push_back(st.top());
            }
            st.push(i);
        }
        for(int i = 0; i < n/2; i++)
        {
            nse[i]=nse[i]^nse[(n-1)-i];
            nse[(n-1)-i]=nse[i]^nse[(n-1)-i];
            nse[i]=nse[i]^nse[(n-1)-i];
        }
        return nse;
    }
    vector<int> psee(vector<int>& arr) {
        vector<int> psee;
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            while(st.empty()==0 && (arr[i] < arr[st.top()]))
            {
                st.pop();
            }
            if(st.empty()==1)
            {
                psee.push_back(-1);
            }
            else{
                psee.push_back(st.top());
            }
            st.push(i);
    }
    return psee;
    }

    vector<int> nge(vector<int>& arr) {
        vector<int> nge;
        stack<int> st;
        int n = arr.size();
        for(int i = n-1; i > -1; i--)
        {
            while(st.empty()==0 && (arr[i] >= arr[st.top()]))
            {
                st.pop();
            }
            if(st.empty()==1)
            {
                nge.push_back(n);
                st.push(i);
            }
            else
            {
                nge.push_back(st.top());
                st.push(i);
            }
        }
        for(int i = 0; i < n/2; i++)
        {
            nge[i]=nge[i]^nge[(n-1)-i];
            nge[(n-1)-i]=nge[i]^nge[(n-1)-i];
            nge[i]=nge[i]^nge[(n-1)-i];
        }
        return nge;
    }

    vector<int> pge(vector<int>& arr) {
        vector<int> pge;
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            while(st.empty()==0 && (arr[i] > arr[st.top()]))
            {
                st.pop();
            }
            if(st.empty()==1)
            {
                pge.push_back(-1);
            }
            else
            {
                pge.push_back(st.top());
            }
            st.push(i);
        }
        return pge;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long Ltotal = 0;
        long long Stotal = 0;
        long long lefts = 0;
        long long rights = 0;
        long long leftm = 0;
        long long rightm = 0;
        int mod = (1e9 + 7);
        vector<int> PSE = psee(nums);
        vector<int> NSE = nse(nums);
        for(int i = 0; i < n; i++)
        {
            leftm = i - PSE[i];
            rightm = NSE[i] - i;
            Stotal = (Stotal + ((leftm*rightm)*nums[i]));
        }
        vector<int> PGE = pge(nums);
        vector<int> NGE = nge(nums);
        for(int i = 0; i < n; i++)
        {
            lefts = i - PGE[i];
            rights = NGE[i] - i;
            Ltotal = (Ltotal + ((lefts*rights)*nums[i]));
        }
        return (Ltotal - Stotal);
    }
};