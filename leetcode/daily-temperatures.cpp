// solution with stack O(N)
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> ans(T.size(), 0);
		stack<int> st;

		for (int i = T.size() - 1; i >= 0; i--) {
			while (!st.empty() && T[i] >= T[st.top()])
				st.pop();
			ans[i] = st.empty() ? 0 : st.top() - i;
			st.push(i);
		}

		return ans;
	}
};


// (NW) W = number of allowd values for T[i]
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> ans(T.size(), 0);
		int visit[101] = {};
		int mx = 30;

		for (int i = T.size() - 1; i >= 0; i--) {
			int warmi = T.size();
			visit[T[i]] = i;
			mx = max(mx, T[i]);
			for (int j = T[i] + 1; j <= mx; j++) {
				if (!visit[j]) continue;
				if (visit[j] > i) {
					warmi = min(warmi, visit[j]);
				}
			}
			if (warmi < T.size())
				ans[i] = warmi - i;
			else ans[i] = 0;
		}

		return ans;
	}
};
