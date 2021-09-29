#include<bits/stdc++.h>

using namespace std;

vector<int> a;
int n, k;
bool ok;

void printArr(){
    if (k == 1) cout << "(" << a[1] << ")";
    else {
        cout << " (";
        for (int i = 1; i < a.size()-1; i++){
            cout << a[i] << " ";
        }
        cout << a[a.size()-1] << ")";
    }
}

void nextArr() {
    int i = k, d, r, s;
    while (i > 0 && a[i] == 1) {
        a.pop_back();
        i--;
    }
    if (i > 0){
        a[i]--;
        d = k-i+1;
        r = d/a[i];
        s = d%a[i];
        while (r--){
            a.push_back(a[i]);
        }
        if (s > 0){
            a.push_back(s);
        }
    } else {
        ok = 0;
    }
}

void solve(){
    ok = 1;
    a.resize(2);
    cin >> n;
    a[1] = n;
    while(ok) {
        k = a.size()-1;
        printArr();
        nextArr();
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}