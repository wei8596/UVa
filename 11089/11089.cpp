/**
*  Author: ≠SØuﬁ≥
*  Date: May. 30, 2017
*  Purpose: For each test case output one line containing the n-th Fi-Binary number.(1 <= N <= 1e9) --> (int)
*           A Fi-binary number is a number that contains only 0 and 1. It does not contain any leading 0.
*           And also it does not contain 2 consecutive 1.
*                8 5 3 2 1
*           1            1
*           2          1 0
*           3        1 0 0
*           4        1 0 1
*           5      1 0 0 0
*           6      1 0 0 1
*           7      1 0 1 0
*           8    1 0 0 0 0
*           9    1 0 0 0 1
*          10    1 0 0 1 0
*          11    1 0 1 0 0
*          12    1 0 1 0 1
*/
#include <iostream>
using namespace std;

const int N = 45;  //int can't represent f[45]

int main(void) {
    int f[N] = {1, 2};  //f[0] = 1, f[1] = 2
    for(int i = 2; i < N; ++i) {
        f[i] = f[i-1] + f[i-2];  //Fibonacci number
    }

    int t, n;
    cin >> t;  //the number of test cases
    while(t--) {
        cin >> n;
        int d = N - 1;  //d = 44 (the highest digit)
        while(f[d] > n) {
            --d;
        }
        for( ; d >= 0; --d) {
            if(f[d] <= n) {
                cout << 1;
                n -= f[d];
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}
