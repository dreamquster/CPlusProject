#include <iostream>
#include <algorithm>
#include "gtest/gtest.h"
using namespace std;

TEST_F(C11Test, autokey) {
    auto i = 1;
    auto func = less<int>();
}
