class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size(); 
        int cnt = 0;   
        for(int i = 0; i < n; i++)
        {
            bool flag = false;
            for(int j = 0; j < m; j++)
            {
                if(fruits[i] <= baskets[j]) {
                    baskets.erase(baskets.begin()+j);
                    m = baskets.size();
                    flag = true;
                    break;
                }
            }
            if(flag == false) {
                cnt++;
            }
        }
        return cnt;
    }
};