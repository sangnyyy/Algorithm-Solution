//
// Created by SML on 2018. 8. 19..
//
#include <iostream>
#include <string>
using namespace std;
int main(){
    while(1){
        string str;
        getline(cin, str);
        if(str=="") break;
        int a, b, c, d;
        a=b=c=d=0;
        for (int j = 0; j < str.length(); ++j) {

            int num = str.at(j);
            if(num >= 97 && num <= 122) a++;
            if(num >= 65 && num <= 90) b++;
            if(num >= 48 && num <= 57) c++;
            if(str.at(j) == ' ') d++;

        }
        cout << a <<' ' << b <<' ' << c << ' ' << d;
        cout << '\n';

    }
    return 0;
}