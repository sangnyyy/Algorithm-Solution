#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int deq[10001];

int main(){
    int n;
    cin >> n;
    int deqSize = 0;
    while(n){
        string str;
        cin >> str;
        if(str == "push_front"){
            int num;
            cin >> num;
            if(deqSize > 0) {
                for (int i = deqSize; i > 0; i--) {
                    deq[i] = deq[i - 1];
                }
            }
            deq[0] = num;
            deqSize++;
        }else if(str == "push_back"){
            int num;
            cin >> num;
            deq[deqSize++] = num;
        }else if(str == "pop_front"){
            if(!deqSize) cout << -1 << '\n';
            else {
                if(deqSize == 1) cout << deq[0] << '\n';
                else{
                    for (int i = 0; i < deqSize - 1; ++i) {
                        if (!i) cout << deq[i] << '\n';
                        deq[i] = deq[i + 1];
                    }
                }
                deqSize--;
            }
        }else if(str == "pop_back"){
            if(deqSize == 0) cout << -1 << '\n';
            else {
                cout << deq[--deqSize] << '\n';

            }
        }else if(str == "size"){
            cout << deqSize <<'\n';
        }else if(str == "empty"){
            if(!deqSize) cout << 1 << '\n';
            else cout << 0 << '\n';
        }else if(str == "front"){
            if(!deqSize) cout << -1 << '\n';
            else{
                cout << deq[0] << '\n';
            }
        }else if(str == "back"){
            if(!deqSize) cout << -1 << '\n';
            else{
                cout << deq[deqSize-1] << '\n';
            }
        }
        n--;
    }
    return 0;
}