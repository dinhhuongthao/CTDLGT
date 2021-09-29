#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, k;
vector<int> tmp;
vector<vector<int> > a, res;
map<int, int> dd;

void printResult(){
    cout << res.size()<<endl;
    for(vector<int> i: res) {
        for(int j: i) cout << j+1 <<' ';
        cout << endl;
    }
}

void Find(int vt, int sum){
    if (sum > k) return;
    if (vt == n && sum == k){
        res.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        if (dd[i] == 0){
            dd[i] = 1;
            tmp.push_back(i);
            Find(vt+1, sum + a[vt][i]);
            tmp.pop_back();
            dd[i] = 0;
        }
    }
}

void solve(){
    cin >> n >> k;
    a.resize(n, vector<int> (n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> a[i][j];
    Find(0, 0);
    printResult();
}

int main(){
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}