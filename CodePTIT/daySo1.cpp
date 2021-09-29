#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> m;
int n;

void dq(int i){
    if (m[i-1].size() == 1) return;
    cout << "[";
    for (int j = 0; j < m[i-1].size()-1; j++){
        m[i].push_back(m[i-1][j] + m[i-1][j+1]);
        cout << m[i][j];
        if (j!= m[i-1].size()-2) cout << " ";
    }
    cout << "]" << endl;
    dq(i+1);
}

void solve(){
    cin >> n;
    m.clear();
    m.resize(n);
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        m[0].push_back(tmp);
        if (i == 0) cout << "[";
        cout << tmp;
        if (i != n-1) cout << " ";
        if (i == n-1) cout << "]";
    }
    cout << endl;
    dq(1);

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}