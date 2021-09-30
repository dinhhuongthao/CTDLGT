#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
int n, m;

void mov(int i, int j, int &count){
    if (i == n-1 && j == m-1) count++;
    if (i < n && j < m) {
        mov(i, j+1, count);
        mov(i+1, j, count);
    }
}

void solve(){
    cin >> n >> m;
    a.resize(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);
            // cin >> a[i][j];
        }
    }
    int count = 0;
    mov(0, 0, count);
    cout << count;

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}