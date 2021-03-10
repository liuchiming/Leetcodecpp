//
// Created by Admin on 2021/3/10.
//
#include <vector>

#ifndef LEETCODE_CPP__85MAXIMALRECTANGLE_H
#define LEETCODE_CPP__85MAXIMALRECTANGLE_H


class _85MaximalRectangle {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix);

private:
    int maxArea(std::vector<int>& heights);
};


#endif //LEETCODE_CPP__85MAXIMALRECTANGLE_H
