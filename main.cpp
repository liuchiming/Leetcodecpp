#include <iostream>
#include "nextexceed.h"
#include "_85MaximalRectangle.h"
#include "_503NextGreaterElements.h"
#include "_239MaxSlidingWindow.h"
#include "util.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    std::vector<std::vector<char>> input = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    std::vector<int> input = {1,3,-1,-3,5,3,6,7};
    _239MaxSlidingWindow test;
    std::vector<int> ret = test.maxSlidingWindow(input, 3);
    util::printArray(ret);
    return 0;
}
