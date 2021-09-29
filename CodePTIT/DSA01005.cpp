#include<iostream>

using namespace std;

int a[100001];
int n;
bool ok;

void printPer(){
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << " ";
}

void nextPer(){
    int i = n-1;
    while (i > 0 && a[i] > a[i+1]) i--;
    if (i > 0){
        int k = n;
        while (k > i && a[k] < a[i]) k--;
        swap(a[k], a[i]);
        int l = i+1, r = n;
        while (l < r){
            swap(a[l], a[r]);
            l++; r--;
        }
    } else {
        ok = false;
    }
}

void solve(){
    cin >> n;
    ok = true;
    for (int i = 1; i <= n; i++){
        a[i] = i;
    }

    while (ok){
        printPer();
        nextPer();        
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}