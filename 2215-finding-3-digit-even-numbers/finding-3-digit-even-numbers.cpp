class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        for(int i = 100; i <= 998; i++) {
            if(i % 2 == 0) {
                int a = -1, b = -1, c = -1;
                for(int j = 0; j < digits.size(); j++) {
                    if(a == -1 && digits[j] == i / 100) {
                        a = j;
                    } else if(b == -1 && digits[j] == (i / 10) % 10) {
                        b = j;
                    } else if(c == -1 && digits[j] == i % 10) {
                        c = j;
                    }
                }
                if(a != -1 && b != -1 && c != -1)
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};