/**
*  Author: ≠SØuﬁ≥
*  Date: May. 30, 2017
*  Purpose: To find number of adjacent swaps necessary to sort a given sequence of integers.
*/
#include <iostream>
using namespace std;

const int N = 500000;  //Every test case begins with a line that contains a single integer n < 500000
int a[N], temp[N];

long long int merge_sort(int l, int r) {
    if(r-l == 1) return 0;
    int mid = (l+r) / 2;
    long long int ans = merge_sort(l, mid) + merge_sort(mid, r);
    int i = l, j = mid, k = 0;
    while(i < mid && j < r) {
        if(a[i] > a[j]) {
            temp[k] = a[j];
            ans += mid - i;
            ++k, ++j;
        }
        else {
            temp[k] = a[i];
            ++k, ++i;
        }
    }
    while(i < mid) {
        temp[k] = a[i];
        ++k, ++i;
    }
    while(j < r) {
        temp[k] = a[j];
        ++k, ++j;
    }
    for(i = l; i < r; ++i) {
        a[i] = temp[i-l];
    }

    return ans;
}

int main(void) {
    int n;  //the length of the input sequence
    while(cin >> n) {
        if(n == 0) break;  //Input is terminated by a sequence of length n = 0
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        //exploit the merge sort algorithm to calculate inversions count
        cout << merge_sort(0, n) << endl;
    }

    return 0;
}
