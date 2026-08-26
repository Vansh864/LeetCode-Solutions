class Solution {
public:
    string lex(string ans, string s) {
        if(ans.length() > s.length())
        return s;
        if(ans.length() < s.length())
        return ans;
        for(int i = 0; i < s.length(); i++) {
            if(ans[i] < s[i])
            return ans;
            if(ans[i] > s[i])
            return s;
        }
        return ans;
    }

    string shortestBeautifulSubstring(string s, int k) {
        vector<int> vec;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1')
            vec.push_back(i);
        }
        if(vec.size() < k)
        return "";
        int len = s.length();
        for(int low = 0, high = k - 1; high < vec.size(); low++, high++) {
            len = min(len, vec[high] - vec[low] + 1);
        }
        string ans = s;
        for(int low = 0, high = k - 1; high < vec.size(); low++, high++) {
            if(len == vec[high] - vec[low] + 1)
            ans = lex(ans, s.substr(vec[low], len));
        }
        return ans;
    }
};