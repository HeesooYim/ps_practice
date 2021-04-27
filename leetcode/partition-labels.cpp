class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> ans;
		int visit[26] = {};

		int ni = 0;
		while (ni < S.length()) {
			int mx = ni;
			int mn = ni;
			for (int i = ni; i <= mx; i++) {
				if (visit[S[i] - 'a']) continue;
				visit[S[i] - 'a'] = 1;
				for (int j = S.length() - 1; j >= 0; j--) {
					if (S[i] == S[j]) {
						mx = max(j, mx);
						break;
					}
				}
			}
			ni = mx + 1;
			ans.push_back(mx - mn + 1);
		}
		return ans;
	}
};
