/**
*  Author: ≠SØuﬁ≥
*  Date: Mar. 01, 2017
*  Purpose: For each input print the current value of the median.
*           The input file consists of series of integers X(0<=X<2^31)
*/
#include <iostream>
#include <algorithm>  //swap()
using namespace std;

int main() {
    const int N = 10000;
    unsigned int num[N] = {0};  //total number of integers is less than 10000
    unsigned int x, median, length;

    //first data
    cin >> x;
    num[0] = x;
    length = 1;
    cout << num[0] << endl;

    while (cin >> x) {  //input the integer
        num[length] = x;  //insert the integer
        ++length;  //total number of integers plus 1

        for (int i = length-1; i > 0; --i) {  //sort
            while (num[i] < num[i-1]) {
                swap(num[i], num[i-1]);
            }
        }

        if (length % 2) {  //odd number of values
            median = num[length / 2];
            cout << median;  //print the current value of the median
        }
        else {  //even number of values
            median = (num[length/2-1] + num[length/2]) / 2;
            cout << median;  //print the current value of the median
        }
        cout << endl;
    }

    return 0;
}
