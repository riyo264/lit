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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        long long leftm = 0;
        long long rightm = 0;
        int mod = (1e9 + 7);
        vector<int> PSE = psee(arr);
        vector<int> NSE = nse(arr);
        for(int i = 0; i < n; i++)
        {
            leftm = i - PSE[i];
            rightm = NSE[i] - i;
            total = (total + ((((leftm*rightm)%mod)*arr[i])%mod))%mod;
        }
        return total;
    }
};