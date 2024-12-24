class Solution {
public:
    bool search(vector<int>& nums, int target) {
int n = nums.size();
bool x = false;
int low = 0;
int high = n-1;
int temp;

while (low <= high)
{
   int mid;
   mid = (low + high)/2;

   temp = mid;

   if(nums[mid]==target){
    x = true;
    break;
   } 

   else if (nums[low]==nums[mid] && nums[mid]==nums[high])
   {
        low++;
        high--;
        continue;
   }

   // Left Sorted

   else if (nums[low] <= nums[mid])
   {
    if (nums[low]<=target && target<=nums[mid])
    {
        high = mid -1;
    }
    else
    {
        low = mid + 1;
    }
    
   }

   // Right sorted
   else if(nums[high] >= nums[mid])
   {
    if (nums[high]>=target && target>=nums[mid])
    {
        low = mid + 1;
    } 
    else
    {
        high = mid - 1;
    }
   }
}
return x;
    }
};