/**
*  Author: 范真瑋
*  Date: Feb. 28, 2017
*  Purpose: analysis of a given text
*/
#include <iostream>
#include <cctype>  //isalpha(), toupper()
using namespace std;

int main() {
    //@n: the number of lines
    //@i: index
    //@max_num: the most times
    int n, i, max_num = 0;
    string str;  //store zero or more characters
    const int L = 128;  //array size (ASCII 128 characters)
    int num[L] = {0};  //store the number of occurrence

    cin >> n;  //the number of lines
    cin.ignore();  //ignore the '\n'
    while (n--) {
        getline(cin, str);  //read a line
        i = 0;
        while (str[i] != '\0') {
            if (isalpha(str[i])) {  //checks whether str[i] is an alphabetic letter
                str[i] = toupper(str[i]);  //convert to its uppercase
                ++num[str[i]-1];  //counting
                if (num[str[i]-1] > max_num) {
                    max_num = num[str[i]-1];  //store the most times
                }
            }
            ++i;
        }
    }

    for (int i = max_num; i >=1; --i) {  //in descending count order
        for (int j = 64; j < 90; ++j) {  //the letter which comes first in the alphabet
            if (num[j] == i) {         //must appear first in the output
                cout << char(j+1) << " " << num[j] << endl;
            }
        }
    }

    return 0;
}
