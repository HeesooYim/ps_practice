class Solution {
public:
    string arr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    
    void dfs(int n, string digits, string s, vector<string> &ret) {
        if (n == digits.size()) {
            ret.push_back(s);
            return;
        }

        int arri = digits[n] - '0';
        for (char c : arr[arri]) {
            s.push_back(c);
            dfs(n + 1, digits, s, ret);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (!digits.empty())
            dfs(0, digits, "", ret);
        return ret;
    }
};