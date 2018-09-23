/**
*  Author: ≠SØuﬁ≥
*  Date: May. 26, 2017
*  Purpose: For every input value n, you are to compute the smallest Smith number which is larger than n.
*           Smith Number:
*               The sum of the digits of that number was equal to the sum of the digits of the prime factors of that number.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;  //prime table

bool is_prime(int n) {  //checking whether n is a prime number
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

void building(void) {  //building the prime table
    prime.push_back(2);  //2 is a prime number
    //Each test case consists of one line containing a single positive integer smaller than 10^9(1e9).
    for(int i = 3; i*i < 1e9; i+=2) {
        if(is_prime(i)) {
            prime.push_back(i);
        }
    }
}

void solve(int start) {
    int num = start + 1;
    while(true) {
        //a prime number is not a Smith number
        if(is_prime(num)) {
            ++num;
            continue;
        }

        //the sum of the digits
        int temp = num, sum = 0;
        while(temp) {
            sum += (temp % 10);
            temp /= 10;
        }

        //the sum of the digits of its prime factors
        int fac_sum = 0;
        temp = num;
        for(int i = 0; i < prime.size(); ++i) {
            if(temp%prime[i] == 0) {
                while(temp%prime[i] == 0) {
                    temp /= prime[i];
                    int temp_prime = prime[i];
                    while(temp_prime) {
                        fac_sum += (temp_prime % 10);
                        temp_prime /= 10;
                    }
                }
            }
        }
        if(temp != 1) {
            while(temp) {
                fac_sum += (temp % 10);
                temp /= 10;
            }
        }
        if(sum == fac_sum) {
            cout << num << endl;
            break;
        }
        ++num;
    }
}

int main(void) {
    building();
    int t, num;
    cin >> t;
    while(t--) {
        cin >> num;
        solve(num);
    }

    return 0;
}
