#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> grayCode(15);
int n;

void prepare(){
    grayCode[1].push_back("0");
    grayCode[1].push_back("1");
    for (int i = 2; i <= 10; i++){
        for (int j = 0; j < grayCode[i-1].size(); j++){
            grayCode[i].push_back('0' + grayCode[i-1][j]);
        }
        for (int j = grayCode[i-1].size()-1; j >= 0; j--){
            grayCode[i].push_back('1' + grayCode[i-1][j]);
        }
    }
}

void solve(){
    cin >> n;
    for (int i = 0; i < grayCode[n].size(); i++){
        cout << grayCode[n][i] << " ";
    }
}

int main(){
    int t;
    cin >> t;
    prepare();
    while (t--){
        solve();
        cout << endl;
    }
}