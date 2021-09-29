#include<iostream>

using namespace std;

int a[100001];
bool ok = true;
int k, n;

void printCom(){
    for (int i = 1; i <= k; i++){
        cout << (char) (a[i] + 'A' - 1);
    }
    cout << endl;
}

void nextCom(){
    int i = k;
    while (i > 0 && a[i] == n-k+i){
        i--;
    }
    if (i > 0) {
        a[i]++;
        for (int j = i+1; j <= k; j++){
            a[j] = a[i] + j - i;
        }
    } else {
        ok = false;
    }
}

void solve(){
    ok = true;
    for (int i = 1; i <= k; i++){
        a[i] = i;
    }

    while (ok){
        printCom();
        nextCom();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        solve();
        cout << endl;
    }
}