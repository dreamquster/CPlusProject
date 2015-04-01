#include "method_declare.h"


int maxProductBefore(int pos_max, int max_prod) {
    if (pos_max == -1) {
        return max_prod;
    }
    return max(pos_max, max_prod);
}

int maxProduct(int A[], int n) {
    if (n <= 0) {
        return 0;
    }
    vector<vector<int> > max_products(n,vector<int>(3));
    max_products[0][0] = max(A[0], -1);
    max_products[0][1] = min(A[0], 1);
    max_products[0][2] = A[0];
    for (int i = 1; i < n; ++i) {
        if (0 <= A[i]) {
            if (0 <= max_products[i-1][0]) {
                max_products[i][0] = max(max_products[i-1][0]*A[i], A[i]);
            } else {
                max_products[i][0] = A[i];
            }
            if (max_products[i-1][1] <= 0) {
                max_products[i][1] = max_products[i-1][1]*A[i];
            } else {
                max_products[i][1] = 1;
            }
        } else {
            if (0 <= max_products[i-1][0]) {
                max_products[i][1] = min(max_products[i-1][0]*A[i],A[i]);
            } else {
                max_products[i][1] = A[i];
            }

            if (max_products[i-1][1] <= 0) {
                max_products[i][0] = max_products[i-1][1]*A[i];
            } else {
                max_products[i][0] = -1;
            }
        }
        max_products[i][2] = maxProductBefore(max_products[i][0], max_products[i-1][2]);
    }

    int res = maxProductBefore(max_products[n-1][0], max_products[n-1][2]);
    return res;
}
