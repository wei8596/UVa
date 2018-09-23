/**
*  Author: ≠SØuﬁ≥
*  Date: Mar. 12, 2017
*  Purpose: Check the guesses about the outcome of the ballot.
*/
#include <iostream>
#include <map>
#include <sstream>  //stringstream
using namespace std;

int main() {
    int p, g;
    string party = "";
    float percentage;
    map<string, int> mapParty;

    cin >> p >> g;
    while(p--) {
        cin >> party >> percentage;
        percentage *= 10;  //mul 10 to avoid error(the comparison of floating point values)
        mapParty.insert(pair<string, int>(party, percentage));
    }
    cin.ignore();

    string str = "";
    int n, c = 1;  //@n: guess percentage, @c: Guess #

    while(g--) {
        cout << "Guess #" << c << " was ";
        getline(cin, str);  //read a guess

        stringstream ss(str);
        int sum = 0;

        while(ss >> str) {
            if(str == "+") {
                continue;
            }
            else if(str == "<") {
                ss >> n;
                if(sum < n*10) {
                    cout << "correct.\n";
                }
                else {
                    cout << "incorrect.\n";
                }
            }
            else if(str == ">") {
                ss >> n;
                if(sum > n*10) {
                    cout << "correct.\n";
                }
                else {
                    cout << "incorrect.\n";
                }
            }
            else if(str == "<=") {
                ss >> n;
                if(sum <= n*10) {
                    cout << "correct.\n";
                }
                else {
                    cout << "incorrect.\n";
                }
            }
            else if(str == ">=") {
                ss >> n;
                if(sum >= n*10) {
                    cout << "correct.\n";
                }
                else {
                    cout << "incorrect.\n";
                }
            }
            else if(str == "=") {
                ss >> n;
                if(sum == n*10) {
                    cout << "correct.\n";
                }
                else {
                    cout << "incorrect.\n";
                }
            }
            sum += mapParty[str];
        }
        ++c;
    }

    return 0;
}
