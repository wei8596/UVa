/**
*  Author: 范真瑋
*  Date: Feb. 28, 2017
*  Purpose: Make a dictionary, and enter the foreign words.
*           Output is the message translated to English, one word per line.
*           Foreign words not in the dictionary should be translated as‘eh’.
*/
#include <iostream>
#include <map>  //for constructing a dictionary
#include <sstream>
using namespace std;

int main() {
    map<string, string> dic;  //dictionary
    map<string, string>::iterator iter;  //map iterator
    //@words stored a line containing an @English word and a @foreign word
    string words = "", en = "", foreign = "";
    stringstream ss;  //for convert

    dic.clear();  //clean the dictionary
    while (getline(cin, words)) {  //read a line
        if (words[0] == '\0') {  //completed
            break;
        }
        ss << words;
        ss >> en >> foreign;  //convert
        ss.clear();  //clean the ss
        dic.insert(pair<string, string>(foreign, en));  //add to the dictionary
        en = "";                                        //@foreign is the key
        foreign = "";                                   //@en is the value
    }

    words = "";
    while (cin >> words) {  //enter the message(foreign word)
        iter = dic.find(words);  //find the key

        if (iter != dic.end()) {  //found
            cout << iter->second << endl;  //output the message translated to English
        }
        else {  //foreign word not in the dictionary
            cout << "eh\n";
        }
    }

    return 0;
}
