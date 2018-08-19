//
// Created by SML on 2018. 8. 19..
//

#include <iostream>
#include <string>

using namespace std;
int main(){
    long long ans = 0;
    string a,b,c,d,s="",e="";
    cin>>a>>b>>c>>d;
    s += a += b;
    e += c += d;
    long long count = 1;
    for (int i = 0; i < s.size(); ++i) {
        ans += (s[s.size()-1-i] - '0')*count;
        count *= 10;
    }
    count = 1;
    for (int i = 0; i < e.size(); ++i) {
        ans += (e[e.size()-1-i] - '0')*count;
        count *= 10;
    }
    cout << ans << '\n';
    return 0;
}