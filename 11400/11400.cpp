/**
*  Author: 范真瑋
*  Date: Jun. 16, 2017
*  Purpose: Each case in the input begins with n(1<=n<=1000), denoting the number of categories.
*           Each of the following n lines describes a category. A category is described by 4 integers -
*           V, the voltage rating, K, the cost of a voltage source of this rating,
*           C, the cost of a lamp of this rating and L, the number of lamps required in this category.
*           For each test case, print the minimum possible cost.
*/
#include <iostream>
#include <algorithm>  //sort(), min()
using namespace std;

const int N = 1001;
const int MAX = 999999;

struct Lamp {
    int v, k, c, l;
    bool operator < (const Lamp &a) const {
        return v < a.v;
    }
};

int main(void) {
    int n, i, j;
    Lamp L[N];
    while(cin>>n && n) {  //the input terminates with a test case where n = 0
        for(i = 0; i < n; ++i) {
            cin >> L[i].v >> L[i].k >> L[i].c >> L[i].l;
        }
        sort(L, L+n);  //sort by voltage rating
        int dp[N];  //dp[i]: lamp(0~i-1)'s minimum cost
        //can reduce the total system cost by eliminating some of the voltage sources and
        //replacing the lamps of that category with higher rating lamps
        for(i = 0; i < n; ++i) {
            int sum = 0;
            dp[i] = MAX;
            for(j = i; j >= 0; --j) {
                sum += L[j].l;
                if(j) {
                    dp[i] = min(dp[i], dp[j-1] + L[i].k + sum*L[i].c);
                }
                else {
                    dp[i] = min(dp[i], L[i].k + sum*L[i].c);
                }
            }
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}
