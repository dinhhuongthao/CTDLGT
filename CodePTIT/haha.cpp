#include<iostream>

using namespace std;

int a[100001];
bool ok = true;
int n;

bool check(){
    for (int i = 1; i < n; i++){
        if (a[i] == a[i+1] && a[i] == 1) return false;
    }
    return true;
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
        if (a[i] == 0) cout << "A";
        else cout << "H";
    }
    cout << endl;
}

void solve(){
    ok = true;
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }

    while (ok) {
        if (a[1] == 1 && a[n] == 0 && check()) printBin();
        nextBin();
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        solve();
    }
}