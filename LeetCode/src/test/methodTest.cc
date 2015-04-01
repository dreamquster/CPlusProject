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
}
