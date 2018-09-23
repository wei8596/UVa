/**
*  Author: ≠SØuﬁ≥
*  Date: Mar. 30, 2017
*  Purpose: I have n distinct numbers. What I can ask is whether a-th number is larger than
*           b-th number and he will answer me properly. What I have to do is to find out
*           the largest and second largest number. What is minimum number of comparison?
*/
#include <iostream>
#include <algorithm>  //ceil()
#include <cmath>  //log2()
using namespace std;

int main() {
    long long n;  //n will be less than any 10 digit prime number and not less than the smallest prime.

    while(cin >> n) {
        cout << n-1 + (long long)ceil(log2((double)n))-1 << endl;
    }

    return 0;
}
