/**
*  Author: 范真瑋
*  Date: Feb. 27, 2017
*  Purpose: Given two strings s and t,
*            decide whether s is a subsequence of t.
*/
#include <iostream>
using namespace std;

//decide whether s is a subsequence of t
bool check(string s1, string s2);

int main() {
    string s = "", t = "";

    while (cin >> s >> t) {  //input is terminated by EOF
        if (check(s, t)) {
            cout << "Yes\n";  //s is a subsequence of t
        }
        else {
            cout << "No\n";
        }
        s = "";
        t = "";
    }

    return 0;
}

//decide whether s is a subsequence of t
bool check(string s1, string s2) {
    int c1 = 0, c2 = 0;  //index

    while (s1[c1] != '\0') {
        while (s1[c1]!=s2[c2] && s2[c2]!='\0') {
            ++c2;
        }
        if (s2[c2] == '\0') {  //end
            break;
        }
        ++c1;
        ++c2;
    }

    if (s1[c1] == '\0') {  //s1 is a subsequence of s2
        return true;
    }
    else {
        return false;
    }
}
