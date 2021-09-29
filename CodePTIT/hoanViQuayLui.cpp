#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<bool> check;
int n;

void printVec(){
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << " ";
}

void printPer(int i){
    for (int j = 1; j <= n; j++){
        if (!check[j]){
            check[j] = 1;
            a[i]=j;
            if (i == n)
                printVec();
            else
                printPer(i+1);
            check[j] = 0;
        }
    }
}

void solve(){
    cin >> n;
    check.resize(n+1, false);
    a.resize(n+1);
    printPer(1);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}