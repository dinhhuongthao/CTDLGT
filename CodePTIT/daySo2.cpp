#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> m;
int n;

void print(){
    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < m[i].size(); j++){
            if (j == 0) cout << "[";
            cout << m[i][j];
            if (j != m[i].size() - 1) cout << " ";
            else cout << "]";
        }
        cout << " ";
    }
}

void dq(int i){
    if (m[i-1].size() == 1) return;
    for (int j = 0; j < m[i-1].size()-1; j++){
        m[i].push_back(m[i-1][j] + m[i-1][j+1]);
    }
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
    }
    cout << endl;
    dq(1);
    print();

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}