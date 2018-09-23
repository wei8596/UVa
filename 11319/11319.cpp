/**
*  Author: ≠SØuﬁ≥
*  Date: Apr. 28, 2017
*  Purpose: you will be given the first 1500 terms of stupid sequence, and you will have to find
*           the values of a0, a1, a2, a3, a4, a5, a6.
*/
#include <iostream>
using namespace std;

unsigned long long int mypow(unsigned long long int base, int exponent);  //raise to power for unsigned long long int

unsigned long long int element[1501];  //element of a stupid sequence
unsigned long long int ans[7];  //coefficients

int main() {
    int n;

    cin >> n;  //the total number of input set
    while(n--) {
        int i;
        for(i = 1; i <= 1500; ++i) {  //the stupid sequence
            cin >> element[i];
        }

        unsigned long long int temp = element[1001];  //f(1001)
        for(i = 0; i <= 6; ++i) {  //calculate the coefficients
            ans[i] = temp % 1001;
            temp -= ans[i];
            temp /= 1001;
        }

        bool smart = false;
        for(i = 1; i <= 1500; ++i) {  //checking
            temp = 0;
            for(int j = 0; j <=6; ++j) {
                temp += ans[j]*mypow(i, j);
            }
            if(temp != element[i]) {  //smart sequence
                smart = true;
                break;
            }
        }

        bool first = true;
        if(smart) {
            cout << "This is a smart sequence!\n";
        }
        else {
            for(i = 0; i <= 6; ++i) {
                if(first) {
                    first = false;
                }
                else {
                    cout << " ";
                }
                cout << ans[i];
            }
            cout << endl;
        }
    }

    return 0;
}

//raise to power for unsigned long long int
unsigned long long int mypow(unsigned long long int base, int exponent) {
    if(exponent == 0) {
        return 1;
    }
    if(exponent == 1) {
        return base;
    }

    unsigned long long int result = 1;
    for(int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}
