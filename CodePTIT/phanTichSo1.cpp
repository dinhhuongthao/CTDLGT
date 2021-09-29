#include<bits/stdc++.h>

using namespace std;

int a[100001];
int k, n;
bool ok;

void printArr(){
    if (k == 1) cout << "(" << a[1];
    else {
        cout << " (";
        for (int i = 1; i < k; i++){
            cout << a[i] << " ";
        }
        cout << a[k];
    }
    cout << ")";
}

void nextArr(){
    int i = k, d, r, s;
    while (i > 0 && a[i] == 1) i--;
    if (i > 0) {
        a[i]--;
        d = k-i+1;
        r = d/a[i];
        s = d%a[i];
        k = i;
        if (r > 0) {
            for (int j = i+1; j <= i+r; j++){
                a[j] = a[i];
            }
            k += r;
        }
        if (s > 0) {
            a[++k] = s;
        }
    } else {
        ok = 0;
    }
}

void solve(){
    ok = 1;
    cin >> n;
    a[1] = n;
    k = 1;
    while (ok){
        printArr();
        nextArr();
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}