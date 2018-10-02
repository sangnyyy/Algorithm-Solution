//
// Created by SML on 2018. 10. 2..
//

#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

bool check[10000];
int prime[10000];

bool isPrime(int num){
    bool isPrimeNum = true;
    if(prime[num] == 1) return false;
    if(prime[num] == 2) return true;
    for (int i = 2; i < num ; ++i) {
        if((num % i) == 0) isPrimeNum = false;
    }
    if(isPrimeNum) {
        prime[num] = 2;
        return true;
    }
    else {
        prime[num] = 1;
        return false;
    }

}

int main(){
    int t;
    cin >> t;
    while(t){
        memset(check, 0, sizeof(check));
        memset(prime, 0, sizeof(prime));
        int n, goal;
        bool canGo = false;
        cin >> n >> goal;
        queue<int> qn;
        queue<int> qc;
        qn.push(n);
        qc.push(0);
        check[n] = true;
        while(!qn.empty()){
            int now = qn.front();
            int count = qc.front();
            qn.pop(); qc.pop();
            if(now == goal) {
                canGo = true;
                cout << count << '\n';
                break;
            }
            int copy = now;
            for (int i = 0; i < 4; ++i) {
                int powNum = pow(10, i);
                int temp = now - powNum*(copy%10);
                copy /= 10;
                for (int j = 0; j <= 9; ++j) {
                    if(i == 3 && j == 0) continue;
                    int next = powNum*j + temp;
                    if(isPrime(next) && !check[next]){
                        check[next] = true;
                        qn.push(next);
                        qc.push(count+1);
                    }
                }
            }
        }
        if(!canGo) cout << 0 << '\n';
        t--;
    }
    return 0;
}