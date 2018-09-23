/**
*  Author: ≠SØuﬁ≥
*  Date: Apr. 28, 2017
*  Purpose: Our team wants to meet together in one place to do our homework.
*           We have decided to meet in the place that has the least total minimum cost.
*           In this problem you are asked to write a program that
*           determines the possible place that has the least total minimum cost.
*           The house of each member is considered as a place here.
*           (All pairs shortest path problem)
*           (can solved by a dynamic programming method)
*/
#include <iostream>
#include <algorithm>  //min()
using namespace std;

int main() {
    const int MAX_LENGTH = 100000;
    const int MAX_CASE = 105;  //The input consists of at most 105 test cases.
    string name[MAX_CASE];  //members name
    int length[MAX_CASE][MAX_CASE];  //the length of shortest path
    int n, m;  //@n:the number of members, @m:the number of path
    int place_A, place_B, cost;
    int i, j, k, A, B, c = 0;  //@c:case number
    int shortest_i;

    while(cin >> n) {
        if(n == 0) {  //The input n = 0 mark as the end of the input.
            return 0;
        }
        ++c;
        cin >> m;

        for(i = 0; i < n; ++i) {  //members name
            cin >> name[i];
        }

        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                if(i == j) {
                    length[i][j] = 0;  //from place i to place i
                }
                else {
                    length[i][j] = MAX_LENGTH;  //infinity
                }
            }
        }

        for(i = 0; i < m; ++i) {
            //from @place_A to @place_B have @cost cost.
            cin >> place_A >> place_B >> cost;
            A = place_A-1;
            B = place_B-1;
            length[A][B] = cost;  //from A to B
            length[B][A] = cost;  //from B to A
        }

        for(k = 0; k < n; ++k) {
            for(i = 0; i < n; ++i) {
                for(j = 0; j < n; ++j) {
                    length[i][j] = min(length[i][j], length[i][k]+length[k][j]);
                }
            }
        }

        int sum[MAX_CASE] = {0};  //the sum of the distance from all source places to destination place.
        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                sum[i] += length[j][i];
            }
        }

        int shortest = MAX_LENGTH;  //determines the possible place that has the least total minimum cost.
        for(i = 0; i < n; ++i) {
            if(sum[i] < shortest) {
                shortest = sum[i];
                shortest_i = i;
            }
        }

        cout << "Case #" << c << " : " << name[shortest_i] << endl;
    }

    return 0;
}
