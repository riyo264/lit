class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
            int n = numbers.size();
            int i = 0;
            int a = -1, b = -1;
            vector <int> ans;
            while(i<n)
            {
                int low = i + 1;
                int high = n - 1;
                while(low<=high)
                {
                    int mid = (high + low)/2;
                    if(numbers[i] + numbers[mid] == target){
                        a = i + 1;
                        b = mid + 1;
                        break;
                    }
                    else if(numbers[i] + numbers[mid] < target){
                        low = mid + 1;
                    }
                    else if (numbers[i] + numbers[mid] > target){
                        high = mid - 1;
                    }
                }
                if((a != -1) && (b != -1)){
                    break;
                }
                else{
                    i++;
                    continue;
                }
            }
            ans.push_back(a);
            ans.push_back(b);
            return ans;
        }
};