#include<iostream>

using namespace std;

int a[100001];
bool ok = true;
int k, n;

void printCom(){
    for (int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void nextCom(){
    int i = k;
    while (i > 0 && a[i] == n-k+i){
        i--;
    }
    if (i > 0) {
        a[i]++;
        for (int j = i+1; j <= k; j++){
            a[j] = a[i] + j - i;
        }
    } else {
    //     ok = false;
        for (int j = 1; j <= k; j++){
            a[j] = j;
        }
    }
}

void solve(){
    // ok = true;
    // for (int i = 1; i <= k; i++){
    //     a[i] = i;
    // }

    // while (ok){
        nextCom();
        printCom();
    // }
}

int main() {
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        for (int i = 1; i <= k; i++){
            cin >> a[i];
        }
        solve();
    }
}