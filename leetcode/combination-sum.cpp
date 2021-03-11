class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& visit, int target, int n, int sum){
        if(n == candidates.size()) return;
        if(sum > target) return;
        if(sum == target){
            vector<int> num;
            for(int i=0;i<candidates.size();i++){
                if(visit[i]){
                    int cnt = visit[i];
                    while(cnt--){
                        num.push_back(candidates[i]);
                    }
                }
            }
            ans.push_back(num);

            return;
        }

        visit[n]++;
        dfs(ans, candidates, visit, target, n, sum+candidates[n]);
        visit[n]--;

        dfs(ans, candidates, visit, target, n+1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> visit(candidates.size(), 0);
        dfs(ans, candidates, visit, target, 0, 0);

        return ans;
    }
};
