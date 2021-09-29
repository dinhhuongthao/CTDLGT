#include<bits/stdc++.h>

using namespace std;

vector<int> a;
long long res = 1e18;
int n;
bool ok;
int length;

// void sinhBS(int i){
//     if (done == 1) return;
//     for (int j = 0; j <= 9; j = j+9){
//         if (i == 0 && j == 0) {
//             continue;
//         }
//         a.push_back(j);
//         sum = ((sum*10) + j);
//         if (sum%n == 0){
//             print(a);
//             done = 1;
//             return;
//         } else {
//             sinhBS(i+1);    
//         }
//         a.pop_back();
//         sum -= j;
//     }
// }

void sinhBS(int i){
    for (int j = 0; j <= 1; j++){
        a[i] = j;
        if (i  == length-1){
            long long s = 0;
            for (int k = 0; k < length; k++){
                s = s*10 + a[k];
            }
            s =  s*9;
            if (s%n == 0 && s >= n) {
                res = min(s, res);
                ok = 1;
            }
        } else {
            sinhBS(i+1);
        }
    }
}

void solve(){
    cin >> n;
    ok = 0;
    a.clear();
    length = log10(n)+1;
    res = 1e18;
    while (length <= 17 && !ok){
        a.resize(length);
        sinhBS(0);
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