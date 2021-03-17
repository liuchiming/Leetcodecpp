//
// Created by Admin on 2021/3/17.
//

#include "_239MaxSlidingWindow.h"

std::vector<int> _239MaxSlidingWindow::maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> ret;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {
            push(nums[i]);
        } else {
            push(nums[i]);
            ret.push_back(max());
            pop(nums[i - k + 1]);
        }
    }
    return ret;
}

void _239MaxSlidingWindow::push(int x) {
    while (!window_.empty() && window_.back() < x) {
        window_.pop_back();
    }
    window_.push_back(x);
}

int _239MaxSlidingWindow::max() {
    return window_.front();
}

void _239MaxSlidingWindow::pop(int x) {
    if (!window_.empty() && window_.front() == x) {
        window_.pop_front();
    }
}
