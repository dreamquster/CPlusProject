#include "method_declare.h"


int maxProduct(int A[], int n) {
    if (n <= 0) {
        return 0;
    }
    vector<vector<int> > max_products(n,vector<int>(3));
    max_products[0][0] = max(A[0], 0);
    max_products[0][1] = min(A[0], 0);
    max_products[0][2] = 0;
    for (int i = 1; i < n; ++i) {
        max_products[i][0] = max(max_products[i-1][0]*A[i], max(A[i], 0));
        max_products[i][1] = min(max_products[i-1][1]*A[i], min(A[i], 0));
        max_products[i][2] = max(max_products[i-1][2], max_products[i-1][1]);
        max_products[i][2] = max(max_products[i][2], max_products[i-1][0]);
    }

    int res = max(max_products[n-1][0], max_products[n-1][2]);
    return res;
}
