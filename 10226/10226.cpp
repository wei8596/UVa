/**
*  Author: ≠SØuﬁ≥
*  Date: Feb. 28, 2017
*  Purpose: The first line is the number of test cases, followed by a blank line.
*           Each test case of your program consists of a list of the species of
*           every tree observed by the satellite; one tree per line.
*           There is a blank line between each consecutive test cases.
*           For each test case print the name of each species represented in the population,
*           in alphabetical order, followed by the percentage of the population it represents,
*           to 4 decimal places. Print a blank line between 2 consecutive test cases.
*/
#include <iostream>
#include <map>
#include <iomanip>  //setprecision()
using namespace std;

int main() {
    int t;  //the number of test cases
    float sum;  //the total number of trees
    string blank_line, tree;
    map<string, float>species;  //store the species and the number of trees
    map<string, float>::iterator iter;  //map iterator

    cin >> t;  //the number of test cases
    cin.ignore();  //ignore the '\n'
    getline(cin, blank_line);  //read the blank line
    while (t--) {
        species.clear();  //clean the species
        sum = 0;
        while (getline(cin, tree)) {
            if (tree[0] == '\0') {  //end
                break;
            }
            iter = species.find(tree);  //find out if the species of the tree was found
            if (iter != species.end()) {  //was found
                ++iter->second;  //plus one
            }
            else {  //is new species. insert new element
                species.insert(pair<string, int>(tree, 1));
            }
            ++sum;  //plus one
        }

        float percent;

        for(iter = species.begin(); iter != species.end(); ++iter) {
            percent = (iter->second * 100) / sum;  //the percentage of the population
            cout << iter->first << " " << fixed << setprecision(4) << percent << endl;  //4 decimal places
        }
        if (t != 0) {
            cout << endl;
        }
    }

    return 0;
}
