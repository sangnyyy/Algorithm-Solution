#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    vector<string> v;
    vector<string> ans;
    cin >> n >> m;
    for(int i = 1; i<=n+m; i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    vector<string>::iterator it;

    for(it = v.begin(); it != v.end()-1; it++){
        if(*it == *(it+1)) ans.push_back(*it);
    }

    cout << ans.size() << '\n';

    for(it = ans.begin(); it != ans.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}