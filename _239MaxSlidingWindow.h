//
// Created by Admin on 2021/3/17.
//
#include <deque>
#include <vector>
#ifndef LEETCODE_CPP__239MAXSLIDINGWINDOW_H
#define LEETCODE_CPP__239MAXSLIDINGWINDOW_H


class _239MaxSlidingWindow {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
private:
    void push(int x);
    int max();
    void pop(int x);
    std::deque<int> window_;
};


#endif //LEETCODE_CPP__239MAXSLIDINGWINDOW_H
