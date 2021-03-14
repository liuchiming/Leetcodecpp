//
// Created by Admin on 2021/3/14.
//

#include "_901StockSpanner.h"

_901StockSpanner::_901StockSpanner() {
    prices = std::stack<int>();
    weights = std::stack<int>();
};

int _901StockSpanner::next(int price) {
    int w = 1;
    while (!prices.empty() && prices.top() <= price) {
        prices.pop();
        w += weights.top();
        weights.pop();
    }
    prices.push(price);
    weights.push(w);
    return w;
};
