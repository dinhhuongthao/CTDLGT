#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<bool> check;
int n;

void print(){
    for (int i = 0; i < n; i++){
        cout << (char) (a[i] + 65);
    }
    cout << " ";
}

void hoanVi(int i){
    if (i == n) {
        print();
        return;
    }
    for (int j = 0; j < n; j++){
        if (!check[j]){
            a[i] = j;
            check[j] = 1;
            hoanVi(i+1);
            check[j] =  0;
        }
    }
}

void solve(){
    string s;
    cin >> s;
    n = s.length();
    a.resize(n);
    check.resize(n, 0);
    hoanVi(0);
}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}