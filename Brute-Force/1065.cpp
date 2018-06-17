#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, total = 0;
    cin >> n;
    
        for(int i =1; i<=n;i++){
            if(i < 100) total ++;
            else{
                bool isHansu = true;
                int temp = i;
                int count = 0;
                while(temp >0){
                    temp /= 10;
                    count++;
                }
                temp = i;
                int * arr = new int[count];
                for(int j =count-1; j >= 0; j--){
                    arr[j] = temp%10;
                    temp /=10;
                }
                for(int j =0; j< count-2; j++){
                    if(arr[j] - arr[j+1] != arr[j+1] - arr[j+2]){
                        isHansu = false;
                    }
                }
                if(isHansu) total++;
            }
        }
        cout << total << endl;
    
    
    
    
    return 0;
}
