//
// Created by SML on 1/26/20.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    string str;
    string explode;

    vector<char> ans;

    cin >> str >> explode;

    int esize = explode.size();

    for (int i = 0; i < str.size() ; ++i) {
        ans.push_back(str[i]);
        int vidx = ans.size() - 1;
        if(ans[vidx] == explode[esize - 1]){
            string temp = "";
            for (int j = vidx + 1 - esize; j <= vidx; ++j) {
                temp += ans[j];
            }
            if(temp == explode){ //터진다
                for (int j = 1; j <= esize; ++j) {
                    ans.pop_back();
                }
            }
        }
    }

    if(!ans.size()) cout << "FRULA" << '\n';
    else{
        for (int i = 0; i < ans.size() ; ++i) {
            cout << ans[i];
        }
        cout << '\n';
    }


    return 0;
}