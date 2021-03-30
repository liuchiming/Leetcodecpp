//
// Created by Admin on 2021/3/29.
//

#include <algorithm>
#include "_1135MinimumCost.h"

class UnionFind{
public:
    UnionFind (int n) {
        for (int i = 0; i < n; i++) {
            father.push_back(i);
        }
    }
    int find(int n) {
        int root = n;
        while (father[root] != root) {
            root = father[root];
        }
        while (n != root) {
            int originRoot = father[n];
            father[n] = root;
            n = originRoot;
        }
        return root;
    }
    void merge(int x, int y) {
        int rootX = father[x];
        int rootY = father[y];
        if (rootY != rootX) {
            father[rootY] = rootX;
        }
    }
private:
    std::vector<int> father;
};

int _1135MinimumCost::minimumCost(int N, std::vector<std::vector<int>>& connections) {
    if (connections.empty() || connections.size() < N - 1) {
        return -1;
    }
    int value = 0;
    int count = 1;
    std::sort(connections.begin(), connections.end(), compare);
    UnionFind uf(N);
    for (auto conn : connections) {
        if (uf.find(conn[0] - 1) != uf.find(conn[1] - 1)) {
            uf.merge(conn[0] - 1, conn[1] - 1);
            value += conn[2];
            count++;
        }
    }
    return count == N ? value : -1;
}