#include<bits/stdc++.h>

using namespace std;

vector<int> a;
int n, sum;
bool ok;

void sumCheck(int i, int subSum){
    if (subSum > sum/2) return;
    if (subSum == sum/2) {
        ok = 1;
        return;
    }
    if (i < n && !ok){
        sumCheck(i+1, subSum + a[i]);
        sumCheck(i+1, subSum);
    }
}

void solve(){
    cin >> n;
    a.resize(n);
    ok = 0;
    sum = 0;
    for (int &i: a){
        cin >> i;
        sum += i;
    }
    sort(a.begin(), a.end());
    sumCheck(0, 0);
    if (!ok || sum % 2 != 0) cout << "NO";
    else cout << "YES";
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}