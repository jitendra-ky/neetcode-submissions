class Solution {
public:
    string delimiter = "X|X";

    string encode(vector<string>& strs) {
        string code = "";
        for (string& str : strs) {
            code += str + delimiter;
        }
        return code;
    }

    vector<string> decode(string s) {
        int d = delimiter.size();
        vector<string> strs;
        int n = s.size();
        int i = 0;
        while (i < n - d + 1) {
            // edge case of empty string
            if (s.substr(i, d) == delimiter) {
                strs.push_back("");
                i = i + d;
                continue;
            }        
            int st = i;
            int ed = i;
            while (s.substr(ed + 1, d) != delimiter)
                ed++;
            strs.push_back(s.substr(st, ed - st + 1));
            i = ed + d + 1;
        }
        return strs;
    }
};
