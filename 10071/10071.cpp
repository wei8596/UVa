/**
*  Author: ≠SØuﬁ≥
*  Date: Jun. 17, 2017
*  Purpose: A particle has initial velocity and acceleration.
*           If its velocity after certain time is v then what will its displacement be in twice of that time?
*/
#include <iostream>
using namespace std;

int main(void) {
    int v, t;
    while(cin >> v >> t)
        cout << 2*v*t << endl;

    return 0;
}
