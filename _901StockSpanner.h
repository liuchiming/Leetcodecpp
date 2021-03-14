//
// Created by Admin on 2021/3/14.
//

#ifndef LEETCODE_CPP__901STOCKSPANNER_H
#define LEETCODE_CPP__901STOCKSPANNER_H


#include <stack>

class _901StockSpanner {
public:
    _901StockSpanner();
    int next(int price);

private:
    std::stack<int> prices;
    std::stack<int> weights;

};


#endif //LEETCODE_CPP__901STOCKSPANNER_H
