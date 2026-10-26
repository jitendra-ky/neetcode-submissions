class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        if (n == 1) return words[0];

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> in_degree;

        // make sure comple alphabet presetn in graph
        for (int i = 0; i < n; i++)
            for (int j = 0; j < words[i].size(); j++) 
                adj[words[i][j]];

        // get edges
        string& prev = words[0];

        for (int i = 1; i < n; i++) {
            string& cur = words[i];
            int p = prev.size();
            int q = cur.size();
            bool get_edge = false;
            for (int j = 0; j < min(p, q); j++) {
                if (prev[j] != cur[j]) {
                    if (adj[prev[j]].count(cur[j]) == 0) {
                        adj[prev[j]].insert(cur[j]);
                        in_degree[cur[j]]++;
                    }
                    get_edge = true;
                    break;
                }
            }
            if (!get_edge && p > q) return ""; // for case like abc, ab
            prev = cur;
        }

        // now find the ans using topologiy sort
        string ans = "";

        queue<char> q;
        for (auto& it : adj) {
            if (in_degree[it.first] == 0) 
                q.push(it.first);
        }

        while (!q.empty()) {
            char cur = q.front(); q.pop();
            ans += cur;
            for (char nbr : adj[cur]) {
                in_degree[nbr]--;
                if (in_degree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if (ans.size() == adj.size())
            return ans;
        return "";
    }
};
