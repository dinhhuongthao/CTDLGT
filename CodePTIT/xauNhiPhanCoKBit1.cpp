#include<iostream>

using namespace std;

int a[100001];
bool ok = true;
int n, k;

bool check(){
    int count = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == 1) count++;
    }
    if (count == k) return 1;
    else return 0;
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
        cout << a[i];
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
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        solve();
    }
}