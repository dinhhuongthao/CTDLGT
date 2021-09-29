#include<iostream>

using namespace std;

int a[100001];
int b[100001];
bool ok = true;
int n, k;

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
        if (a[i] == 1) cout << b[i] << " ";
    }
    cout << endl;
}

void solve(){
    ok = true;
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
    int count = 0;
    while (ok) {
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == 1) sum += b[i];
        }
        if (sum == k) {
            printBin();
            count++;
        }
        nextBin();
    }
    cout << count << endl;
}

int main(){
    // int t;
    // cin >> t;
    // while (t--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        solve();
    // }
}