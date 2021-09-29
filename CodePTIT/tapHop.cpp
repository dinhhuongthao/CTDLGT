#include<bits/stdc++.h>

using namespace std;

vector<int> a;
map<int, bool> dd;
int s, n, k;

void print(){
    for (int i = 1; i < a.size(); i++){
        cout << a[i];
    }
    cout << endl;
}

void sinhTH(int i, int sum, int &count){
    if (sum > s) return;
    if (i > k) {
        if (sum == s){
            count++;
            // print();
        }
        return;
    }
    // if (i > k) {
    //     print();
    //     return;
    // }
    for (int j = a[i-1]+1; j <= n; j++){
        a[i] = j;
        sum += j;
        sinhTH(i+1, sum, count);
        sum -= j;
    }
}

void solve(){
    int count = 0;
    a.resize(k+1, 0);
    // int sum = 0;
    sinhTH(1, 0, count);
    cout << count << endl;

}

int main(){
    while (1){
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s== 0){
            break;
        }
        solve();

    }
}