/**
*  Author: ≠SØuﬁ≥
*  Date: Jun. 17, 2017
*  Purpose: Finding a suitable number for each blank brick taking into account one simple rule:
*           the number of a brick is obtained by adding the numbers of the two bricks below it.
*           Obviously, this rule does not apply to the ninth row.
*           Numbers are supposed to be integers.
*/
#include <iostream>
using namespace std;

int main(void) {
    int n, i, j;
    const int N = 9;
    cin >> n;
    while(n--) {
        int wall[N][N];  //The wall has 9 rows and row i has exactly i bricks
        for(i = 0; i < N; i += 2) {  //odd rows of the wall, from top to bottom
            for(j = 0; j <= i; j += 2) {
                cin >> wall[i][j];
            }
        }

        int a, b, c;                        //  c
        for(i = N-1; i > 0; i -= 2) {       // x y
            for(j = 0; j < i; j += 2) {     //a n b
                a = wall[i][j];
                b = wall[i][j+2];
                c = wall[i-2][j];
                wall[i][j+1] = (c-a-b) / 2; //c=(a+n)+(b+n) --> n = (c-a-b) / 2
                wall[i-1][j] = wall[i][j] + wall[i][j+1];
                wall[i-1][j+1] = wall[i][j+1] + wall[i][j+2];
            }
        }

        bool firstLine = true;
        for(i = 0; i < N; ++i) {
            if(firstLine) firstLine = false;
            else cout << endl;
            bool firstSpace = true;
            for(j = 0; j <= i; ++j) {
                if(firstSpace) firstSpace = false;
                else cout << " ";
                cout << wall[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
