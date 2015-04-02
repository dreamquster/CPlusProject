#include "method_declare.h"

int findMin(vector<int> &num) {
    int s = 0;
    int e = num.size()-1;
    while (1 < (e - s) && num[s] >= num[e]) {
        int mid = s + (e - s)/2;
        if (num[mid] < num[e]) {
            e = mid;
        } else if (num[s] < num[mid]){
            s = mid;
        } else {
            ++s;
        }
    }
    int res = min(num[s], num[e]);

    return res;
}
