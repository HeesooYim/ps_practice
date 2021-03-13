// 이렇게 하면 통과는 되는데..시간이 매우 오래 걸림..
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        int alpha[26];
        int alpha_cp[26];

        for (int i = 0; i < strs.size(); i++) {
            vector<string> group;

            memset(alpha, 0, sizeof(alpha));
            for (char c : strs[i])
                alpha[c - 'a']++;

            int len = strs[i].length();
            group.push_back(strs[i]);
            strs.erase(strs.begin() + i);
            i--;

            for (int j = i + 1; j < strs.size(); j++) {
                if (len != strs[j].length()) continue;

                bool is_anagram = true;
                memcpy(alpha_cp, alpha, sizeof(alpha));

                for (char c : strs[j]) {
                    int index = c - 'a';
                    if (!alpha_cp[index]) {
                        is_anagram = false;
                        break;
                    }
                    alpha_cp[index]--;
                }

                if (is_anagram) {
                    group.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
                }
            }
            ans.push_back(group);
        }

        return ans;
    }
};

// unordered map 사용, sort된 string을 key값으로 사용
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       	vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }

        for (auto val : m) {
            ans.push_back(val.second);
        }

        return ans;
    }
};
