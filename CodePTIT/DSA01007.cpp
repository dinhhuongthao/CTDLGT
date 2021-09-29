#include<iostream>

using namespace std;

int a[100001], n;
bool ok;

void printBin(){
    for (int i = 1; i <= n; i++){
        if (a[i] == 0) cout << "A";
        else cout << "B";
    }
    cout << " ";
}

void nextBin(){
    int i = n;
    while (i > 0 && a[i] != 0) {
        a[i] = 0;
        i--;
    }
    if (i > 0) a[i] = 1;
    else ok = false;
}

void solve(){
    ok = true;
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }

    while (ok) {
        printBin();
        nextBin();
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        solve();
        cout << endl;
    }
}