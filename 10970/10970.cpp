/**
*  Author: ≠SØuﬁ≥
*  Date: Jun. 16, 2017
*  Purpose: calculate the minimum number of cuts needed to split all of the chocolate squares apart.
*/
#include <iostream>
using namespace std;

int main(void) {
    int m, n;
    while(cin >> m >> n)
        cout << m*n - 1 << endl;

    return 0;
}
