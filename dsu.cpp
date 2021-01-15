#include <bits/stdc++.h>

using namespace std;

/**
 * 15.01.2021
 * dsu
 *
 * @author Havlong
 * @version v1.0
 */

class DisjointSetUnion {
private:
    vector<int> sz;
    vector<int> p;
    int setCnt;

    void merge(int v, int u) {
        sz[v] += sz[v];
        p[u] = v;
        setCnt--;
    }

public:
    explicit DisjointSetUnion(int n) {
        sz.assign(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        setCnt = n;
    }

    int get(int v) {
        if (p[v] == v) {
            return v;
        }
        return p[v] = get(p[v]);
    }

    bool unite(int v, int u) {
        v = get(v);
        u = get(u);
        if (v == u) {
            return false;
        }
        if (sz[v] < sz[u]) {
            swap(v, u);
        }
        merge(v, u);
        return true;
    }

    bool inOneSet(int v, int u) {
        return get(v) == get(u);
    }

};
