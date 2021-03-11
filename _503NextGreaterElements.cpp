//
// Created by Admin on 2021/3/11.
//

#include <stack>
#include "_503NextGreaterElements.h"

std::vector<int> _503NextGreaterElements::nextGreaterElements(std::vector<int>& nums) {
    int n = nums.size();
    std::stack<int> myStack;
    std::vector<int> ret(n, -1);
    for (int i = 0; i < n * 2; i++) {
        while (!myStack.empty() && nums[myStack.top()] < nums[i % n]) {
            ret[myStack.top()] = nums[i % n];
            myStack.pop();
        }
        myStack.push(i % n);
    }
    return ret;
}