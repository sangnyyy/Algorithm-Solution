//
// Created by SML on 3/5/19.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> strings;
char answer[51];

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string temp; cin >> temp; strings.push_back(temp);
    }
    for (int i = 0, size = strings[0].size(); i < size; ++i) {
        char temp = strings[0][i];
        bool allSame = true;
        for (int j = 1; j < n; ++j) {
            if(temp != strings[j][i]) allSame = false;
        }
        if(allSame) answer[i] = temp;
        else answer[i] = '?';
    }
    for (int i = 0, size = strings[0].size(); i < size; ++i) {
        cout << answer[i];
    }


    return 0;
}