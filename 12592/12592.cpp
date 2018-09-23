/**
*  Author: ≠SØuﬁ≥
*  Date: Jun. 17, 2017
*  Purpose: Given the list of the slogans and also the first lines Princess going to hear,
*           print out the second line of the slogans.
*/
#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int n;
    string str1, str2;
    map<string, string> m;

    cin >> n;
    cin.ignore();
    while(n--) {
        getline(cin, str1);
        getline(cin, str2);
        m.insert(pair<string, string>(str1, str2));
    }


    int q;
    string str;
    map<string, string>::iterator iter;

    cin >> q;
    cin.ignore();
    while(q--) {
        getline(cin, str);
        iter = m.find(str);
        cout << iter->second << endl;
    }

    return 0;
}
