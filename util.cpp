//
// Created by Chi on 2021/3/8.
//

#include "util.h"

void util::printArray(const std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
