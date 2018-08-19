//
// Created by SML on 2018. 8. 18..
//

#include <iostream>
using namespace std;

int checked[1001];

int main(){
    int n, k, count = 0;
    cin >> n >> k;
    for (int i = 2; i <=n ; ++i) {
        for (int j = i; j <=n ; j+=i) {
            if(!checked[j]){
                count++;
                checked[j] = 1;
                if(count == k){ cout << j << '\n'; break;}
            }
        }
    }

    return 0;

}