/**
*  Author: ≠SØuﬁ≥
*  Date: Mar. 12, 2017
*  Purpose: Find out the morphing order from the original word to the morphed one.
*/
#include <iostream>
using namespace std;

string word[10000];  //large array (global)
int index[10000];

int main() {
    int num_word, num_letter;

    while(cin >> num_word >> num_letter) {
        cin.ignore();
        getline(cin, word[0]);  //the first word
        index[0] = 0;  //first

        for(int i = 1; i < num_word; ++i) {
            int dif = 0;  //difference

            getline(cin, word[i]);
            for(int j = 0; j < num_letter; ++j) {
                if(word[i][j] != word[0][j]) {
                    ++dif;
                }
            }
            index[dif] = i;
        }

        for(int i = 0; i < num_word; ++i) {
            cout << word[index[i]] << endl;
        }
    }

    return 0;
}
