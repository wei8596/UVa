/**
*  Author: 范真瑋
*  Date: May. 18, 2017
*  Purpose: Willy Wonka gives the three children candies of weight a, b and c, respectively.
*           The badness of this distribution is the difference between the maximum of a, b, c and the minimum of a, b, c.
*           Unfortunately, Willy Wonka is not very good in mathematics, so he needs your help.
*/
#include <iostream>
#include <cstring>  //memset()
#include <algorithm>  //max(), min()
using namespace std;

const int max_candy = 32;  //the maximum number of candies to be distributed
const int N = 700;
int weight[max_candy];  //the weight of the different candies
bool dp[N][N];

void distributing(int caseNum, int n, int sum) {
    int ans = 99999;
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;  //a = 0, b = 0, c = sum
    for(int i = 0; i < n; ++i) {
        for(int j = sum; j >= 0; --j) {
            for(int k = sum; k >= 0; --k) {
                if(dp[j][k]) {
                    dp[j+weight[i]][k] = dp[j][k+weight[i]] = true;
                    /*cout << "\n----------\n";
                    cout << i << " " << j << " " << k << endl;
                    cout << "dp[j+weight[i]][k] = dp[" << j << "+" << weight[i] << "][" << k << "] = " << "dp[" << j+weight[i] << "][" << k << "]" << endl;
                    cout << "dp[j][k+weight[i]] = dp[" << j << "][" << k << "+" << weight[i] << "]] = " << "dp[" << j << "][" << k+weight[i] << "]" << endl;
                    cout << "\n----------\n";*/
                }
            }
        }
    }

    //find the smallest badness that can be achieved when distributing all candies to the children
    for(int a = 0; a <= sum; ++a) {
        for(int b = 0; b <= sum; ++b) {
            if(dp[a][b]) {  //if this distribution exists, find minimum
                int c = sum-a-b;
                //the difference between the maximum of a, b, c and the minimum of a, b, c
                int mm = max(max(a,b), c) - min(min(a,b), c);
                ans = min(ans, mm);
            }
        }
    }
    cout << "Case " << caseNum << ": " << ans << endl;
}

int main(void) {
    int t, n, sum;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cin >> n;  //the number of candies to be distributed
        sum = 0;
        for(int j= 0; j < n; ++j) {
            cin >> weight[j];  //the weight of the different candies
            sum += weight[j];
        }
        distributing(i, n, sum);
    }

    return 0;
}
