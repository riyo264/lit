class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = -1;
        int tgas = 0;
        int tcost = 0;
        int current = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            tgas += gas[i];
            tcost += cost[i];
            current += gas[i] - cost[i];
            if(current < 0) {
                start = i + 1;
                current = 0;
            }
        }

        if(tgas >= tcost) {
            ans = start;
        }
        //BRUTE FORCE
        // for(int i = 0; i < n; i++)
        // {
        //     int petrol = 0;
        //     bool check = false;
        //     int cnt = 0;
        //     int end = 2*n - 1;
        //     int j = i;
        //     while(j <= end) 
        //     {
        //         int k = j%n;
        //         if(petrol < 0 ) {
        //             break;
        //         }
        //         else if(gas[k] - cost[k] >= 0 || petrol >= 0) {
        //             if(petrol + (gas[k] - cost[k]) < 0) {
        //                 break;
        //             }
        //             petrol += (gas[k] - cost[k]);
        //             cnt++;
        //             if(cnt == gas.size()) {
        //                 check = true;
        //                 break;
        //             }
        //         }
        //         j++;
        //     }
        //     if(check == true) {
        //         ans = i;
        //         break;
        //     }
        // }
        return ans;
    }
};