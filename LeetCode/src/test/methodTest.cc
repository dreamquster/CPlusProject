#include "gtest/gtest.h"
#include "common.h"
#include "method_declare.h"


TEST(Leetcode, reverseWord) {
    char s[] = " ";
    reverseWords(s);
    ASSERT_STRCASEEQ(s, "");

    char threeWords[] = "  ab mid ba ";
    reverseWords(threeWords);
    ASSERT_STRCASEEQ(threeWords, "ba mid ab");

    char reverseTest[] = "fan chen";
    reverseWords(reverseTest);
    ASSERT_STRCASEEQ(reverseTest, "chen fan");

    char s1[] = "   a   b ";
    reverseWords(s1);
    ASSERT_STRCASEEQ(s1, "b a");
}

TEST(Leetcode, maxProduct) {
    int A[] = {2,3,-2,4};
    int res = maxProduct(A, 4);
    ASSERT_EQ(res, 6);

    int o[] = {-2};
    res = maxProduct(o,1);
    ASSERT_EQ(res, -2);

    int w[] = {-4, -3};
    res = maxProduct(w, 2);
    ASSERT_EQ(res, 12);
}

TEST(Leetcode, findMin) {
    int arr[] = {4,5,6,7,0,1,2};
    vector<int> num(arr, arr + 7);
    int res = findMin(num);
    ASSERT_EQ(res, 0);

    int two[] = {3,1};
    vector<int> twonum(two, two + 2);
    res = findMin(twonum);
    ASSERT_EQ(res, 1);

    int three[] = {3, 1, 2};
    vector<int> threenum(three, three + 3);
    res = findMin(threenum);
    ASSERT_EQ(res, 1);

    int rep[] = {4, 4, 5, 7, 8, 1, 4, 4, 4,};
    vector<int> repnum(rep, rep + 9);
    res = findMin(repnum);
    ASSERT_EQ(res, 1);

    int all[] = {4, 4, 4, 4, 4, 4, 4};
    vector<int> allnum(all, all + 7);
    res = findMin(allnum);
    ASSERT_EQ(res, 4);

    int r[] = {3,3,1,3};
    vector<int> rnum(r, r + 4);
    res = findMin(rnum);
    ASSERT_EQ(res, 1);
}
