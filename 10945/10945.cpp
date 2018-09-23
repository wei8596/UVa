/**
*  Author: ≠SØuﬁ≥
*  Date: Jun. 16, 2017
*  Purpose: You°¶ll be given many sentences.
*           You have to determine if they are palindromes or not, ignoring case and punctuations.
*
*           On each input, output °•You won't be eaten!°¶ if it is a palindrome,
*           and °•Uh oh..°¶ if it is not a palindrome.
*/
#include <iostream>
#include <string>  //string::length
#include <cctype>  //tolower()
using namespace std;

int main(void) {
    string sentence;
    //The end of input will be a line containing the word °•DONE°¶
    while(getline(cin, sentence) && sentence!="DONE") {
        int i;
        string str;
        for(i = 0; i < sentence.length(); ++i) {
            if(isalpha(sentence[i]))
                str += tolower(sentence[i]);
        }

        bool isPalindrome = true;
        for(i = 0; i <= str.length()/2; ++i) {
            if(str[i] != str[str.length()-i-1])
                isPalindrome = false;
        }

        if(isPalindrome) {
            cout << "You won't be eaten!\n";
        }
        else {
            cout << "Uh oh..\n";
        }
    }

    return 0;
}
