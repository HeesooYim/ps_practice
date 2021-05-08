class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<char> st;
        stack<int> stn;
        int n = 0;

        for (int i = 0; i < s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                n = n * 10 + s[i] - '0';
            }
            else if (s[i] == '[') {
                st.push(s[i]);
                n == 0 ? stn.push(1) : stn.push(n);
                n = 0;
            }
            else if (s[i] == ']') {
                string add;
                while (!st.empty()) {
                    if (st.top() == '[') {
                        st.pop();
                        break;
                    }
                    add.push_back(st.top());
                    st.pop();
                }

                int cnt = stn.top();
                stn.pop();
                while (cnt--) {
                    for (int i = add.length() - 1; i >= 0; i--) {
                        st.push(add[i]);
                    }
                }
            }
            else {
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
