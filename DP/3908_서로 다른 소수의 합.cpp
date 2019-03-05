//
// Created by SML on 2/26/19.
//

#include <iostream>
#include <cstring>
#include <vector>
#define LIMIT 1120
using namespace std;

int t;
bool isPrime[1121];
int d[1121][15];
vector<int> primes;

void eratosthenes(){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= LIMIT; ++i) {
        if(isPrime[i]){
            for (int j = i*2; j <= LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= LIMIT; ++i) {
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    eratosthenes();
    d[0][0] = 1;
    for (int i = 0, size = primes.size(); i < size; ++i) {
        for (int j = LIMIT; j >= primes[i] ; --j) {
            for (int k = 1; k <= 14; ++k) {
                d[j][k] += d[j - primes[i]][k-1];
            }
        }
    }
    cin >> t;
    while(t > 0){
        int n, k;
        cin >> n >> k;
        cout << d[n][k] << '\n';
        t--;
    }
    return 0;
}