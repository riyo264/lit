class Solution {
public:
    string isValid(int q) {
        int hour = q >> 6;
        int min = q & 63;
        if (hour >= 12 || min >= 60) return "";
        return to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn == 0) return {"0:00"};
        if(turnedOn > 8) return {};
        vector<string> ans;
        int q = (1 << turnedOn) - 1;
        while(q < (1 << 10)) {
            string time = isValid(q);
            if(!time.empty()) ans.push_back(time);
            int r = q & -q;
            int n = q + r;
            q = (((n^q)/r)>>2) | n; 
        }
        return ans;
    }
};