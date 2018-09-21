//
// Created by SML on 2018. 9. 21..
//

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string s;
    int count = 0;
    while(count < 100){
        getline(cin, s);
        cout << s << '\n';
        count++;
    }

    return 0;
}
