/**
*  Author: 范真瑋
*  Date: Feb. 28, 2017
*  Purpose:n which denotes the total number of test cases
*           Three integers e, f, c, where
*           e equals the number of empty soda bottles in Tim’s possession at the start of the day,
*           f the number of empty soda bottles found during the day, and
*           c the number of empty bottles required to buy a new soda.
*           For each test case print how many sodas did Tim drink on his extra thirsty day?
*/
#include <iostream>
using namespace std;

int cal(int e, int f, int c, int& ans);  //calculate the answer
int main() {
    int n, e, f, c, ans;

    cin >> n;  //the total number of test cases
    while (n--) {
        ans = 0;
        cin >> e >> f >> c;
        cout << cal(e, f, c, ans) << endl;  //print the answer
    }

    return 0;
}

int cal(int e, int f, int c, int& ans) {  //calculate the answer
    int remainder;  //the number of the rest of the bottles

    f = e + f;  //the total number of empty bottles
    while (f >= c) {
        ans += f / c;  //new soda
        remainder = f % c;  //the rest of the bottles
        f /= c;  //new soda's bottle
        f += remainder;  //the total number of empty bottles
    }

    return ans;
}
