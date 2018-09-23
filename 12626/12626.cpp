/**
*  Author: ­S¯uŞ³
*  Date: Jun. 17, 2017
*  Purpose: Given a set of ingredients, you have to say how many pizzas MARGARITA can be made.
*/
#include <iostream>
#include <algorithm>  //min()
using namespace std;

int main(void) {
    int n;
    string str;
    const int MAX = 999999;
    cin >> n;
    while(n--) {
        cin >> str;
        int num[128] = {0};
        for(int i = 0; str[i] != '\0'; ++i) {
            ++num[str[i]];
        }
        int ans = MAX;
        ans = min(ans, num['M']/1);
        ans = min(ans, num['A']/3);
        ans = min(ans, num['R']/2);
        ans = min(ans, num['G']/1);
        ans = min(ans, num['I']/1);
        ans = min(ans, num['T']/1);
        cout << ans << endl;
    }

    return 0;
}
