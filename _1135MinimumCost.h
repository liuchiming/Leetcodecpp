//
// Created by Admin on 2021/3/29.
//

#ifndef LEETCODE_CPP__1135MINIMUMCOST_H
#define LEETCODE_CPP__1135MINIMUMCOST_H
#include <vector>

class _1135MinimumCost {
public:
    int minimumCost(int N, std::vector<std::vector<int>>& connections);

private:
    static bool compare(std::vector<int>& vec1, std::vector<int>& vec2) {
        if (vec1.size() == 3 && vec2.size() == 3) {
            return vec1[2] < vec2[2];
        }
        return false;
    }
};


#endif //LEETCODE_CPP__1135MINIMUMCOST_H
