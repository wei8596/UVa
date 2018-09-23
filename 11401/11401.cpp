/**
*  Author: ≠SØuﬁ≥
*  Date: May. 27, 2017
*  Purpose: Calculate the number of non-congruent non-degenerate scalene triangles with maximum side length n.
*/
#include <iostream>
using namespace std;

long long int triangle[1000001] = {0};  //triangle[i]: the triangle with maximum side length i

int main(void) {
    long long int a1, n;
    for(int i = 4; i < 1000001; ++i) {
        a1 = i - 3;  //the first term
        n = (a1+1)/2;  //the number of terms
        triangle[i] = triangle[i-1] + n*(a1-n+1);  //Sn = Sn-1 + An
    }
    int num;
    while(cin >> num) {
        if(num < 3) break;  //The end of input will be indicated by a case with n<3
        cout << triangle[num] << endl;
    }

    return 0;
}
