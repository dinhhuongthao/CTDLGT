#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> sample;
int n, k;
bool ok;

void print(){
    for (int i = 0; i < sample.size(); i++){
        if (i == 0) cout << "[";
        cout << sample[i];
        if (i != sample.size() - 1) cout  << " ";
        else cout << "] ";
    }
}

void find(int i, int sum){
    if (i < n && sum > k){
        return;
    }
    if (i == n && sum == k) {
        print();
        ok = 1;
        return;
    }
    if (i < n) {
        sample.push_back(a[i]);
        find(i+1, sum + a[i]);
        sample.pop_back();
        find(i+1, sum);

    }
}

void solve(){
    cin >> n >> k;
    a.resize(n);
    sample.clear();
    ok = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    find(0, 0);
    if (!ok) cout << -1;
}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}