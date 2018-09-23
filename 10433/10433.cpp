/**
*  Author: ≠SØuﬁ≥
*  Date: Apr. 16, 2017
*  Purpose: Each line containing a arbitrarily big integer. Some Automorphic number have leading zeros.
*           So leading zeros must be considered as significant. Input is terminated by end of file.
*           Determine whether a given number is Automorphic or not.
*           Automorphic numbers are those numbers whose square ends with the number itself.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input = "";
    int i, j;

    while(cin >> input) {
        if(input=="0" || input=="1") {  //0, 1 are not Automorphic Number
            cout << "Not an Automorphic number.\n";
            continue;
        }

        int a[5000] = {0}, b[5000] = {0};
        int length = input.size();

        for(i = 0, j = length-1; i < length; ++i, --j) {  //reverse
            a[j] = input[i] - '0';
        }

        i = length - 1;

        while(i>=0 && a[i]==0) {
            --i;
        }
        if(i<0 || (i==0 && a[i]==1)) {  //00...0, 00...1 are not Automorphic Number
            cout << "Not an Automorphic number.\n";
            continue;
        }

        bool wrong = false;

        for(i = 0; i < length && !wrong; ++i) {
            if(a[i]) {
                for(j = 0; i+j < length; ++j) {
                    b[i+j] += a[i] * a[j];
                }
            }
            b[i+1] += b[i] / 10;
            b[i] %= 10;
            if(b[i] != a[i]) {
               	wrong = true;
            }
        }

        if(wrong) {
            cout << "Not an Automorphic number.\n";
        }
        else {
            cout << "Automorphic number of " << length << "-digit.\n";
        }
    }
    return 0;
}
