#include <iostream>
using namespace std;

int main(){
    int n, a, b, round = 0;
    cin >> n >> a >> b;
    while(a != b){
        a = a/2 + a%2;
        b = b/2 + b%2;
        round++;
    }
    cout << round << '\n';
    return 0;
}