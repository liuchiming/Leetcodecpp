//
// Created by Admin on 2021/3/21.
//
#include <vector>
#ifndef LEETCODE_CPP__200NUMISLANDS_H
#define LEETCODE_CPP__200NUMISLANDS_H


class _200NumIslands {
public:
    int numIslands(std::vector<std::vector<char>>& grid);

private:
    int getIndex(int x, int y);
    int row;
    int cols;
};


#endif //LEETCODE_CPP__200NUMISLANDS_H
