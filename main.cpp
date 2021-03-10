#include <iostream>
#include "nextexceed.h"
#include "_85MaximalRectangle.h"
#include "util.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    std::vector<std::vector<char>> input = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    std::vector<std::vector<char>> input = {{'0', '1'}};
    _85MaximalRectangle test;
    int ret = test.maximalRectangle(input);
    std::cout << ret;
    return 0;
}
