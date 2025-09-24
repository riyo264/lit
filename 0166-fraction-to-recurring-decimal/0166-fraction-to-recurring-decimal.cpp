class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string ans;
        if ((numerator < 0) ^ (denominator < 0)) ans += "-";
        if(numerator == 0) return "0";
        long long decimal = (abs(numerator) / abs(denominator));
        ans += to_string(decimal);
        long long rem = abs(numerator) % abs(denominator);
        if(rem == 0) {
            return ans;
        }
        ans += ".";
        unordered_map<long long, int> mpp;
        while(rem != 0)
        {
            if(mpp.count(rem)) {
                ans.insert(mpp[rem], "(");
                ans += ")";
                break;
            }
            mpp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem/abs(denominator));
            rem %= abs(denominator);
        }
        return ans;
    }
};