#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<vector<int>> res;
bool ok;

void nextBin(){
    int i = a.size() - 1;
    while (i > 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i > 0) {
        a[i] = 1;
    } else {
        ok = false;
    }
}

bool check(int &k){
    int maxCount = 0;
    int count = 1;
    for (int i = 2; i < a.size(); i++){
        if (a[i] == 0){
            if (a[i-1] == a[i]) count++;
        }
        else {
            maxCount = max(maxCount, count);
            count = 1;
        }
    }

    return (maxCount == k || count == k);
}

void printString(vector<int> &a){
    for (int i = 1; i < a.size(); i++){
        if (a[i] == 0) cout << "A";
        else cout << "B";
    }
    cout << endl;
}

void solve(){
    int n, k;
    cin >> n >> k;
    a.resize(n+1, 0);
    res.clear();
    ok = 1;
    int count = 0;
    while (ok){
        if (check(k)) {
            res.push_back(a);
            count++;
        }
        nextBin();
    }
    cout << count << endl;
    for (int i = 0; i < res.size(); i++){
        printString(res[i]);
    }

}

int main(){
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}