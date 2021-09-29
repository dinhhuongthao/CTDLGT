#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<int> check;
vector<int> pos;
vector<vector<int>> res;
int n, k, sum;

void printPos(vector<int> &kq){
    for (int i = 1; i <= n; i++){
        cout << kq[i] << " ";
    }
}

void printPer(int i){
    for (int j = 1; j <= n; j++){
        if (!check[j] && sum + a[i][j] <= k) {
            check[j] = 1;
            pos[i] = j;
            sum += a[i][j];
            if (i == n) {
                if (sum == k) {
                    // printPos();
                    res.push_back(pos);
                }
            } else {
                printPer(i+1);
            }
            sum -= a[i][j];
            check[j] = 0;
        }
    }
}

void solve(){
    cin >> n >> k;
    a.resize(n+1, vector<int> (n+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
    check.clear();
    check.resize(n+1);
    pos.resize(n+1);

    sum = 0;
    printPer(1);
    
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++){
        printPos(res[i]);
        cout << endl;
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}
