#include<iostream>

using namespace std;

int a[10001], n;
bool ok;

void printPre(){
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << " ";
}

void nextPre(){
    int i = n-1;
    while (i > 0 && a[i] < a[i+1]) i--;
    if (i > 0) {
        int k = n;
        while (k > i && a[k] > a[i]) k--;
        swap(a[i], a[k]);
        int l = i+1, r = n;
        while (l < r){
            swap(a[l++], a[r--]);
        }
    } else {
        ok = false;
    }
}

void solve(){
    ok = true;
    for (int i = 1; i <= n; i++){
        a[i] = n-i+1;
    }
    while (ok) {
        printPre();
        nextPre();
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