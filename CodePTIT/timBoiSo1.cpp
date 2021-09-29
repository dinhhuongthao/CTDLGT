#include<bits/stdc++.h>

using namespace std;

vector<int> a; 
int n;
long long length;
bool ok;
long long res = 1e18;

void find(int i){
    if (i == length){
        long long sum = 0;
        for (int k = 0; k < length; k++){
            sum = sum*10 + a[k];
        }
        sum *= 9;
        if (sum%n == 0 && sum >= n){
            res = min(sum, res);
            ok = 1;
        }
        return;
    }  
    for (int j = 0; j <= 1; j++){
        a[i] = j;
        find(i+1);
    }
}

void solve(){
    cin >> n;
    length = log10(n) + 1;
    ok = false;
    res = 1e18;
    while (length <= 18 && !ok){
        a.resize(length);
        find(0);
        length++;
    }
    cout << res << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}