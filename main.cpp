#include <iostream>
#include "nextexceed.h"
#include "util.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> input = {5,3,1,2,4};
    nextexceed test;
    util::printArray(test.nextExceed(input));
    return 0;
}
