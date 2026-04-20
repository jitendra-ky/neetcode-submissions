class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int root) {
        // if visited return
        if (visited[root]) return;
        visited[root] = true;

        // traver neigbours
        for (int nbi : graph[root]) {
            dfs(graph, visited, nbi);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const vector<int>& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(graph, visited, i);
            }
        }

        return count;
    }
};
