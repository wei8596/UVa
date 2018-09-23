/**
*  Author: ­S¯uŞ³
*  Date: Jun. 7, 2017
*  Purpose: For 10>n>2 numbers we form n*(n-1)/2 sums by adding every pair of the numbers.
*           Your task is to find the n numbers given the sums.
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int Nx = 40;
const int Na = 10;

int main(void) {
    int n, x, sum[Nx], a[Na];
    int i, j, k, m;
    while(cin >> n) {
        x = n*(n-1) / 2;
        for(i = 0; i < x; ++i) {
            cin >> sum[i];
        }
        sort(sum, sum+x);
        //enumerate sum[i], let a[2] + a[3] = sum[i]
        for(i = 2; i < x; ++i) {
            /*****Equation solving*****/
            a[2] = (sum[0]-sum[1]+sum[i]) / 2;
            a[1] = sum[0] - a[2];
            a[3] = sum[1] - a[1];
            if(a[2]+a[3] != sum[i]) {
                continue;
            }
            /*****Equation solving*****/

            bool used[Nx] = {false};  //true: used, false: not used
            used[i] = true;
            bool check = true;
            int index = 2;
            for(j = 4; j<=n && check; ++j) {  //recurrence
                //use the sum that has not been used to generate a number(a[j])
                while(used[index]) {
                    ++index;
                }
                a[j] = sum[index] - a[1];
                used[index] = true;  //sum[index] is used(a[1] + a[j])
                for(k = 2; k<j && check; ++k) {  //check (a[j] + a[k])'s sum whether it exists
                    for(m = index+1; m < x; ++m) {
                        if(!used[m] && a[j]+a[k]==sum[m]) {
                            used[m] = true;  //sum[m] is used
                            break;  //a[j] pass the check
                        }
                    }
                    if(m >= x) {  //(a[j] + a[k])'s sum doesn't exist
                        check = false;
                    }
                }
            }
            if(check) {  //pass all check --> successful
                break;
            }
        }
        if(i < x) {  //successful
            cout << a[1];
            for(i = 2; i <= n; ++i) {
                cout << " " << a[i];
            }
            cout << endl;
        }
        else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
