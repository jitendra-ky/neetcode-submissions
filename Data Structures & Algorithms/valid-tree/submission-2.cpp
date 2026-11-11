class Solution {
public:
    vector<vector<int>> adj;
    unordered_set<int> visited;
    unordered_set<int> allVisited;

    bool dfs(int node, int parentNode) {
        // cout << node << " " << parentNode << endl;
        if (allVisited.find(node) == allVisited.end()) {
            allVisited.insert(node);
        }
        if (visited.find(node) != visited.end()) return true; // cycle detected

        visited.insert(node);
        for (int nbr : adj[node]) {
            if (nbr == parentNode) continue;
            if (dfs(nbr, node)) return true;
        }
        visited.erase(node);

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if (m != n - 1) return false;

        // now detect cycle using topology sort
        
        //make the adj list graph first
        adj.resize(n);

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        bool isCycle = dfs(0, -1);
        bool connected = (allVisited.size() == n);

        return (!isCycle && connected);
    }
};
