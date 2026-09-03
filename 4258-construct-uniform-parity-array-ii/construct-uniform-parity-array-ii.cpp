class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isEven = true, isOdd = true;
        int minE = -1, minO = -1;
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] & 1) {
                isEven = false;
                if(minO == -1) {
                    minO = nums1[i];
                }
                minO = min(minO, nums1[i]);
            } else {
                isOdd = false;
                if(minE == -1) {
                    minE = nums1[i];
                }
                minE = min(minE, nums1[i]);
            }
        }
        if(isOdd || isEven)
        return true;
        if(minO < minE)
        return true;
        return false;
    }
};