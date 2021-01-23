class Solution {
public:
	void dfs(int l, int r, int n, string s, vector<string>& ret) {
		if (l == n && r == n) {
			ret.push_back(s);
			return;
		}

		if (l < n)
			dfs(l + 1, r, n, s + '(', ret);
		if (r<n && l>r)
			dfs(l, r + 1, n, s + ')', ret);
	}

	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string s = "(";

		dfs(1, 0, n, s, ret);

		return ret;
	}
};