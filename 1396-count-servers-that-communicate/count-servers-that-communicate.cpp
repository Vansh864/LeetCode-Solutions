class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    bool temp = false;
                    for(int k = 0; k < grid[0].size(); k++) {
                        if(j != k && grid[i][k] == 1) {
                            temp = true;
                            break;
                        }
                    }
                    for(int k = 0; k < grid.size(); k++) {
                        if(i != k && grid[k][j] == 1) {
                            temp = true;
                            break;
                        }
                    }
                    if(temp)
                    ans++;
                }
            }
        }
        return ans;
    }
};