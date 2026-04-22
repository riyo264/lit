class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();
        vector<string> ans;

        for(int i = 0; i < n; i++)
        {
            string q = queries[i];
            for(int j = 0; j < m; j++)
            {
                string d = dictionary[j];
                int cnt = 0;
                for(int k = 0; k < d.size(); k++)
                {
                    if(q[k] != d[k] && cnt == 2) {
                        cnt++;
                        break;
                    }
                    else if(q[k] != d[k]) {
                        cnt++;
                    }
                }
                if(cnt <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;        
    }
};