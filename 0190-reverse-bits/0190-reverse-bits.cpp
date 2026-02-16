class Solution {
public:
    int reverseBits(int n) {
        bitset<32> binary_representation(n);
        string s = binary_representation.to_string();
        reverse(s.begin(), s.end());
        int a = 0;
        for(int i = 0; i < 32; i++)
        {
            int b = s[31-i] - '0';
            a += (b * pow(2, i));
        }
        return a;
    }
};