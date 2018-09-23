/**
*  Author: ≠SØuﬁ≥
*  Date: Jun. 16, 2017
*  Purpose: determine if the gap can be closed.
*/
#include <iostream>
using namespace std;

int main(void) {
    int cases, n, y1, y2;
    cin >> cases;  //# of the cases
    while(cases--) {
        cin >> n;  //# of columns W of the ground to be considered
        //@y1: the north-most row of the gap in this column
        //@y2: the south-most row of the gap in this column
        cin >> y1 >> y2;
        int diff = y1 - y2;
        bool check = true;
        --n;
        while(n--) {
            cin >> y1 >> y2;
            if(y1-y2 != diff) {
                check = false;
            }
        }
        if(check) {
            //the gap can be closed by sliding blocks north and south
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
        if(cases) cout << endl;
    }

    return 0;
}
