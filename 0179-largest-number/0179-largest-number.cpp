class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> s;
        for(int i = 0; i < n; i++)
        {
            string t = to_string(nums[i]);
            s.push_back(t);
        }
        sort(s.begin(), s.end(), [](const string& a, const string& b) {
            return (a+b > b+a);
    });
        if(s[0] == "0") {
            return "0";
        }
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            ans = ans + s[i];
        }
        return ans;
    }
};