class Solution {
public:
    string encode(vector<string>& strs) {
        string code(strs.size() + 1, 'X');

        code[0] = (char)(strs.size() + 1);

        for (int i = 0; i < strs.size(); i++) {
            code[i + 1] = (char)strs[i].size();
            code += strs[i];
        }

        return code;
    }

    vector<string> decode(string s) {
        int hSize = (unsigned char)s[0];

        vector<string> strs;
        int cur = hSize;

        for (int i = 1; i < hSize; i++) {
            int len = (unsigned char)s[i];

            strs.push_back(s.substr(cur, len));
            cur += len;
        }

        return strs;
    }
};