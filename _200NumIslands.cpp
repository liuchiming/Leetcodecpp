//
// Created by Admin on 2021/3/21.
//

#include <map>
#include "_200NumIslands.h"

class UnionFind {
public:
    UnionFind(int x) {
        this->count = x;
        for (int i = 0; i < x; i++) {
            father[i] = i;
        }
    }
    int getCount() {
        return count;
    }
    int find(int x) {
        int root = x;
        while (father[root] != root) {
            root = father[root];
        }
        // 路径压缩
        while (x != root) {
            int originRoot = father[x];
            father[x] = root;
            x = originRoot;
        }
        return root;
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        // 判断是否是已联通，如果是，则什么都不做，否则才count--。
        // 不然会有重复减的错误操作！
        if (rootY == rootX) {
            return;
        }
        father[rootX] = rootY;
        count--;
    }
private:
    std::map<int, int> father;
    int count;
};

int _200NumIslands::numIslands(std::vector<std::vector<char>>& grid) {
    row = grid.size();
    if (row == 0) {
        return 0;
    }
    cols = grid[0].size();
    int spaces = 0;
    UnionFind uf(row * cols);
    std::vector<std::vector<int>> directions {{1, 0}, {0, 1}};

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '0') {
                spaces++;
            } else {
                for (std::vector<int> direction : directions) {
                    int newX = i + direction[0];
                    int newY = j + direction[1];
                    if (newX < row && newY < cols && grid[newX][newY] == '1') {
                        uf.merge(getIndex(i, j), getIndex(newX, newY));
                    }
                }
            }
        }
    }
    return uf.getCount() - spaces;
}
int _200NumIslands::getIndex(int x, int y) {
    return x * cols + y;
}