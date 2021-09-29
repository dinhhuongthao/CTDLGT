#include<iostream>

using namespace std;

int a[100001];
int b[100001];
bool ok = true;
int n;

bool check(){
    for (int i = n; i >= 1; i--){
        b[n-i+1] = a[i];
    }
    for (int i = 1; i <= n; i++){
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void nextBin(){
    int i = n;
    while (i > 0 && a[i] != 0){
        a[i] = 0;
        i--;
    }
    if (i > 0) {
        a[i] = 1;
    } else {
        ok = false;
    }
}

void printBin(){
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve(){
    ok = true;
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }

    while (ok) {
        if (check()) printBin();
        nextBin();
    }
}

int main(){
    // int t;
    // cin >> t;
    // while (t--){
        cin >> n;
        solve();
    // }
}