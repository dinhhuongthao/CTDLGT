#include<bits/stdc++.h>

using namespace std;

vector<int> a;
int n, k;
bool ok;

void print(){
    for (int i = 1; i < a.size(); i++){
        cout << a[i];
    }
    cout << " ";
}

void nextCom(){
    int i = k;
    while (i > 0 && a[i] == n-k+i) i--;
    if (i > 0){
        a[i]++;
        for (int j = i+1; j <= k; j++){
            a[j] = a[i] + j - i;
        }
    } else {
        ok = false;
    }
}

void solve(){
    cin >> n >> k;
    a.resize(k+1);
    ok = 1;
    for (int i = 1; i < a.size(); i++){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    while (ok){
        print();
        nextCom();
    }
}

int main(){
    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}