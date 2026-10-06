class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        // edge case
        if (n == 1) return words[0];

        // now custruct the graph
        unordered_map< char, vector<char> > adj;
        unordered_map<char, int> inDeg;

        // add all the nodes in graph
        for (string& word : words) {
            for (char c : word) adj[c];
        }

        for (int i = 1; i < n; i++) {
            string s1 = words[i - 1];
            string s2 = words[i];
            bool done = false;
            for (int j = 0; j < min(s1.size(), s2.size()); j++) {
                if (s1[j] == s2[j]) continue;
                done = true;
                adj[s1[j]].push_back(s2[j]);
                inDeg[s2[j]]++;
                break;
            }
            if (!done) {
                if (s1.size() > s2.size()) return "";
            }
        }

        // now do the topology sort
        string ans = "";
        queue<char> q;
        
        // all all zero indegree node
        for (auto& it : adj) {
            if (inDeg[it.first] == 0) q.push(it.first);
        }

        while (!q.empty()) {
            char u = q.front();
            q.pop();
            ans += u;
            // reduce neighbour in degree
            for (auto& nbr : adj[u]) {
                inDeg[nbr]--;
                if (inDeg[nbr] == 0) q.push(nbr);
            }
        }
        if (adj.size() != ans.size()) return "";
        return ans;
    }
};
