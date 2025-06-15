class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        stable_sort(nums1.begin(), nums1.end());
        stable_sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> result;

        if(n1 < n2) {
            for(int i = 0; i < n1; i++) 
            {
                int l = 0;
                int h = n2-1;
                while(l <= h)
                {
                    int mid = (l+h)/2;
                    if(nums2[mid] == nums1[i]) {
                        result.push_back(nums1[i]);
                        break;
                    }
                    else if(nums2[mid] < nums1[i]) {
                        l = mid + 1;
                    }
                    else {
                        h = mid - 1;
                    }
                }
            }
        }

        else {
            for(int i = 0; i < n2; i++) 
            {
                int l = 0;
                int h = n1-1;
                while(l <= h)
                {
                    int mid = (l+h)/2;
                    if(nums1[mid] == nums2[i]) {
                        result.push_back(nums2[i]);
                        break;
                    }
                    else if(nums1[mid] < nums2[i]) {
                        l = mid + 1;
                    }
                    else {
                        h = mid - 1;
                    }
                }
            }
        }
        if(result.size()>1) {
        auto it = unique(result.begin(), result.end());
        result.erase(it, result.end());
        }
        return result;
    }
};