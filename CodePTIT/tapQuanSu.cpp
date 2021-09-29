#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<bool> check;
int n, k;
bool ok;

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
    check.resize(n+1, false);
    for (int i = 1; i <= k; i++){
        cin >> a[i];
        check[a[i]] = 1;
    }
    ok = true;
    nextCom();

    if (ok) {
        int count = 0;
        for (int i = 1; i <= k; i++){
            if (check[a[i]] == 0) 
                count++;
                // cout << a[i];
        }
        cout << count;
        // cout << endl;
    } else {
        cout << k;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        a.clear();
        check.clear();
        solve();
        cout << endl;
    }
}