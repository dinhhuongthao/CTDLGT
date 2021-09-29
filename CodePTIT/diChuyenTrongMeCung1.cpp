#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> m;
int n;
bool done;
// vector<string> res;
// string step;

// void print(){
//     for (int i = 0; i < res.size(); i++){
//         cout << res[i];
//         if (i != res.size()-1) cout << " ";
//     }
// }

void mov(int x, int y, string step){
    if (x == n || y == n) return;
    if (m[x][y] == 0) return;
    if (x == n-1 && y == n-1){
        cout << step << " ";
        done = 1;
        return;
    }
    mov(x+1, y, step + 'D');
    mov(x, y+1, step + 'R');
    // if (x+1 < n && m[x + 1][y] == 1){
    //     step.push_back('D');
    //     move(x+1, y);
    //     step.pop_back();
    // }
    // if (y+1 < n && m[x][y + 1] == 1){
    //     step.push_back('R');
    //     move(x, y+1);
    //     step.pop_back();
    // }
}

void solve(){
    cin >> n;
    done = 0;
    m.clear();
    m.resize(n, vector<int> (n));
    // step.clear();
    // res.clear();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }
    mov(0, 0, "");
    if (!done) cout << -1;
}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }

}