//
// Created by Chi on 2021/3/8.
//

#include <stack>
#include "nextexceed.h"

std::vector<int> nextexceed::nextExceed(const std::vector<int>& input) {
    std::vector<int> result(input.size(), -1);
    std::stack<int> stack;
    for (int i = 0; i < input.size(); i++) {
        while (!stack.empty() && input[stack.top()] < input[i]) {
            result[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }
    return result;
}
