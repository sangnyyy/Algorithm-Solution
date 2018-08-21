//
// Created by SML on 2018. 8. 21..
//

#include <iostream>
using namespace std;
int main(){
    int a,b,c, count=0;
    cin >> a >> b >>c;
    while(!(b-a==1 && c-b==1)){
        if(b-a > c-b){
            int temp = b;
            b = a+1;
            c = temp;
            count++;
        }else{
            int temp = b;
            b = c-1;
            a = temp;
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}