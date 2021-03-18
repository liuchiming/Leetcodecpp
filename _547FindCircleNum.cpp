//
// Created by Admin on 2021/3/18.
//

#include "_547FindCircleNum.h"
#include <map>

class UnionFind {
public:
    int find(int x) {
        int root = x;
        while (father[root] != -1) {
            root = father[root];
        }
        // 路径压缩
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
        if (rootX != rootY) {
            father[rootY] = rootX;
            numOfSet--;
        }
    }
    void add(int x) {
        if (!father.count(x)) {
            father[x] = -1;
            numOfSet++;
        }
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    int getNumOfSet() {
        return numOfSet;
    }

private:
    int numOfSet = 0;
    std::map<int, int> father;
};

int _547FindCircleNum::findCircleNum(std::vector<std::vector<int>>& isConnected) {
    UnionFind uf;
    for (int i = 0; i < isConnected.size(); i++) {
        uf.add(i);
        for (int j = 0; j < i; j++) {
            if (isConnected[i][j]) {
                uf.merge(i, j);
            }
        }
    }
    return uf.getNumOfSet();
}
