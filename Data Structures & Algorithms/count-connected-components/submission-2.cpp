class DSU {
public:
    vector<int> parents;
    vector<int> size;

    DSU(int n) {
        // initialize a DSU of size n
        parents.assign(n, 0);
        for (int i = 0; i < n; i++) parents[i] = i;
        size.assign(n, 1);
    }

    int find(int a) {
        // return the group of a
        if (parents[a] == a) return a;
        return parents[a] = find(parents[a]);
    }

    void add(int a, int b) {
        if (size[find(a)] < size[find(b)]) swap(a, b);
        parents[find(b)] = find(a);
        size[find(a)] += size[find(b)];
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU* dsu = new DSU(n);
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            dsu->add(u, v);
        }

        // now find how many unique group in DSU
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(dsu->find(i));
        }

        return st.size();
    }
};
