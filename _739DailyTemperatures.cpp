//
// Created by Admin on 2021/3/11.
//

#include <stack>
#include "_739DailyTemperatures.h"

// [73,74,75,71,69,72,76,73]
std::vector<int> _739DailyTemperatures::dailyTemperatures(std::vector<int>& T) {
    std::vector<int> ret(T.size(), 0);
    std::stack<int> myStack;
    for (int i = 0; i < T.size(); i++) {
        while (!myStack.empty() && T[myStack.top()] < T[i]) {
            ret[myStack.top()] = i - myStack.top();
            myStack.pop();
        }
        myStack.push(i);
    }
    return ret;
}
