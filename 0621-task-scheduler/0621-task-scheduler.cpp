class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        unordered_map<char, int> mpp;
        for(int i = 0; i < len; i++)
        {
            mpp[tasks[i]]++;
        }
        priority_queue<int> maxHeap;
        for(auto x : mpp) 
        {
            maxHeap.push(x.second);
        }
        int time = 0;
        while(!maxHeap.empty())
        {
            vector<int> cooldown;
            int cycle = n+1;
            int i = 0;
            while(i < cycle && !maxHeap.empty()) 
            {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;
                if(cnt > 0) {
                    cooldown.push_back(cnt);
                }
                time++;
                i++;
            }
            for(int i : cooldown) {
                maxHeap.push(i);
            }
            if(maxHeap.empty()) break;
            time += (cycle - i);
        }
        return time;
    }
};