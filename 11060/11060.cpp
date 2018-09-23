/**
*  Author: ≠SØuﬁ≥
*  Date: May. 13, 2017
*  Purpose: Sorting a list of beverages according to the relative order of their alcohol content.
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

int main(void) {
    int n, m, c = 1;  //@n: the number of available beverages, @c: counting
    string name, b1, b2;
    map<string, int>Map;

    while(cin >> n) {
        vector<string> v[n];
        Map.clear();

        for(int i = 0; i < n; ++i) {
            cin >> name;  //the name of each beverage
            Map.insert(pair<string, int>(name, i));  //record input order
            v[i].push_back(name);
        }

        cin >> m;
        while(m--) {
            cin >> b1 >> b2;            //beverage b2 has more alcohol that beverage b1
            v[Map[b2]].push_back(b1);   //record alcohol content order
        }

        int total = 0;  //total of output
        cout << "Case #" << c << ": Dilbert should drink beverages in this order: ";
        for(int i = 0; i < n; ++i) {
            if(v[i].size() == 1) {
                cout << v[i][0];  //output
                for(int j = 0; j<n; ++j) {
                    for(int k = 0; k < v[j].size(); ++k) {
                        if(v[j][k] == v[i][0]) {  //if was output, remove it
                            v[j].erase(v[j].begin()+k);
                            k = -1;  //search again
                        }
                    }
                }
                ++total;
                if(total != n) {
                    cout << " ";
                }
                else {  //the last output of a case
                    cout << ".\n\n";
                }
                i = -1;  //search again
            }
        }
        ++c;
    }

    return 0;
}
