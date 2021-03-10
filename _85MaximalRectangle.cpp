//
// Created by Admin on 2021/3/10.
//

#include <stack>
#include "_85MaximalRectangle.h"

int _85MaximalRectangle::maximalRectangle(std::vector<std::vector<char>>& matrix) {
    if (matrix.size() == 0) {
        return 0;
    }
    int max = 0;
    std::vector<int> heights (matrix[0].size(), 0);
    for (int rows = 0; rows < matrix.size(); rows++) {
        for (int col = 0; col < matrix[rows].size(); col++) {
            // every line
            if (matrix[rows][col] == '1') {
                heights[col] += 1;
            } else {
                heights[col] = 0;
            }
        }
        max = std::max(max, maxArea(heights));
    }
    return max;
}

// leetcode 84
int _85MaximalRectangle::maxArea(std::vector<int>& heights) {
    heights.push_back(0);
    int ret = 0;
    std::stack<int> myStack;
    for (int i = 0; i < heights.size(); i++) {
        while (!myStack.empty() && heights[myStack.top()] > heights[i]) {
            int h = heights[myStack.top()];
            myStack.pop();
            int w = myStack.empty() ? -1 : myStack.top();
            ret = std::max(ret, h * (i - w - 1));
        }
        myStack.push(i);
    }
    return ret;
}
