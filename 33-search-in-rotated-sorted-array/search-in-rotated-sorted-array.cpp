class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0] == target)
        return 0;
        if(nums[n - 1] == target)
        return n - 1;
        if(n <= 2)
        return -1;
        int low = 1, high = n - 2;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
            return mid;
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target <= nums[mid])
                high = mid - 1;
                else
                low = mid + 1;
            } else {
                if(target >= nums[mid] && target <= nums[high])
                low = mid + 1;
                else
                high = mid - 1;
            }
        }
        return -1;
    }
};