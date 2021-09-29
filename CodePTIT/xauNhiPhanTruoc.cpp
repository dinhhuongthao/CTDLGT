#include<iostream>
#include<string>

using namespace std;

int a[100001];
bool ok = true;
int n;
string s;

void nextBin(){
    int i = n;
    while (i > 0 && a[i] != 1){
        a[i] = 1;
        i--;
    }
    if (i > 0) {
        a[i] = 0;
    } else {
        // ok = false;
        for (int i = 1; i <= n; i++){
            a[i] = 1;
        }
    }
}

void printBin(){
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
}

void solve(){
    // ok = true;
    // for (int i = 1; i <= n; i++){
    //     a[i] = 1;
    // }

    // while (ok) {
        // split();
        nextBin();
        printBin();
    // }
}

void split(){
    for (int i = 1; i <= n; i++){
        a[i] = s[i-1] - '0';
    }
    // printBin();

}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        cin >> s;
        n = s.length();
        split();
        solve();
    }
}