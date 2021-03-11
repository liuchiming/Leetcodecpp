#include <iostream>
#include "nextexceed.h"
#include "_85MaximalRectangle.h"
#include "_503NextGreaterElements.h"
#include "util.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    std::vector<std::vector<char>> input = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    std::vector<int> input = {1, 2, 1};
    _503NextGreaterElements test;
    std::vector<int> ret = test.nextGreaterElements(input);
    util::printArray(ret);
    return 0;
}
