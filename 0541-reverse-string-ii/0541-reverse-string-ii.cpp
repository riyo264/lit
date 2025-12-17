class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        if(n < k) {
            reverse(s.begin(), s.end());
            return s;
        }
        while(i < n) 
        {
            if(i % (2*k) == 0) {
                int left = i;
                int right = (k + i - 1);
                if(right >= n) {
                    right = n-1;
                }
                while(left < right) 
                {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
            }
            i++;
        }
        return s;
    }
};