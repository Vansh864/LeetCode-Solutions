class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1, ans = nums[0];
        while(st <= end) {
            int mid = st + (end - st) / 2;
            ans = min(ans, nums[mid]);
            if(nums[mid] <= nums[end]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};