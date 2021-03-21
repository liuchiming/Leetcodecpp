//
// Created by Admin on 2021/3/20.
//
#include <map>
#include "_684FindRedundantConnection.h"

class UnionFind {
public:
    int find(int x) {
        int root = x;
        while (father[root] != root) {
            root = father[root];
        }
        while (x != root) {
            int originFather = father[x];
            father[x] = root;
            x = originFather;
        }
        return root;
    }
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootY != rootX) {
            father[rootX] = rootY;
        }
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    void add(int x) {
        father[x] = x;
    }
private:
    std::map<int, int> father;
};

std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
    UnionFind uf;
    for (int i = 0; i < edges.size(); i++) {
        uf.add(i);
    }
    for (int i = 0; i < edges.size(); i++) {
        if (uf.isConnected(edges[i][0], edges[i][1])) {
            return edges[i];
        } else {
            uf.merge(edges[i][0], edges[i][1]));
        }
    }
    return {};
}
