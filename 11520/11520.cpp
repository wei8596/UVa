/**
*  Author: 范真瑋
*  Date: Mar. 11, 2017
*  Purpose: Draw a square using uppercase English Alphabets.
*/
#include <iostream>
using namespace std;

int main() {
    const int N = 10;  //array size
    /*
    *@t: # test cases
    *@n: the dimension of the grid
    *@c: case number
    */
    int t, n, c = 1;
    int dir_ud[] = {-1, 1, 0, 0};  //for checking(up, down)
    int dir_lr[] = {0, 0, -1, 1};  //for checking(left, right)

    cin >> t;  //# test cases
    while(t--) {
        char grid[N][N];  //grid
        int i, j, k;

        cin >> n;  //the dimension of the grid
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                cin >> grid[i][j];  //the cell of the grid
            }
        }

        cout << "Case " << c << ":\n";  //Case #:
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                if(grid[i][j] == '.') {
                    /*
                    *1. Make sure no adjacent cells contain the same letter;
                    *   two cells are adjacent if they share a common edge.
                    *2. There could be many ways to  ll the grid.
                    *   You have to ensure you make the lexicographically smallest one.
                    */
                    for(char letter = 'A'; letter <= 'Z'; ++letter) {
                        bool check = true;

                        for(k = 0; k < 4; ++k) {  //checking
                            int ud = i + dir_ud[k];
                            int lr = j + dir_lr[k];

                            if(ud>=0 && ud<n && lr>=0 && lr<n && grid[ud][lr]==letter) {
                                check = false;
                            }
                        }

                        if(check) {
                            grid[i][j] = letter;
                            break;
                        }
                    }
                }
                cout << grid[i][j];  //output the matrix
            }
            cout << endl;
        }
        ++c;
    }

    return 0;
}
