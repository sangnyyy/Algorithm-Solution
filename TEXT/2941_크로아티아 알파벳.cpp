//
// Created by SML on 1/26/20.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#define LIST_SIZE 6
using namespace std;

map<char, vector<char>> check;

char clist[LIST_SIZE] = {'c', 'd', 'l', 'n', 's', 'z'};

void checkInit(){

    vector<char> list;
    list.push_back('=');
    list.push_back('-');
    // c
    check['c'] = list;
    list.pop_back();
    // s
    check['s'] = list;
    // z
    check['z'] = list;
    // d
    list.pop_back();
    list.push_back('j');
    // l
    check['l'] = list;
    // n
    check['n'] = list;
}

int main(){
    checkInit();
    string s;
    cin >> s;
    int size = s.size();
    int idx = 0, result = 0;
    while(idx < size){
        for (int i = 0; i < LIST_SIZE; ++i) {
            if(s[idx] == clist[i] && idx + 1 < size){
                if(s[idx] == 'd'){
                    if(idx + 2 < size){
                        if(s[idx + 1] == 'z' && s[idx + 2] == '='){
                            idx++;
                            idx++;
                        }
                    }
                    if(s[idx + 1] == '-') idx++;
                }else{
                    for (int j = 0; j < check[s[idx]].size(); ++j) {
                        if(s[idx +1] == check[s[idx]][j]){
                            idx++;
                        }
                    }
                }
            }
        }
        result++;
        idx++;
    }
    cout << result << '\n';
    return 0;
}