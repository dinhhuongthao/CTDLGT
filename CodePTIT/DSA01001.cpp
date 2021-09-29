#include<iostream>
#include<string>

using namespace std;

int a[100001];
bool ok = true;
int n;
string s;

void nextBin(){
    int i = n;
    while (i > 0 && a[i] != 0){
        a[i] = 0;
        i--;
    }
    if (i > 0) {
        a[i] = 1;
    // } else {
    //     ok = false;
    }
}

void printBin(){
    for (int i = 1; i <= s.length(); i++){
        cout << a[i];
    }
    cout << endl;
}

void solve(){
    n = s.length();
    nextBin();
    printBin();
}

void split(){
    for (int i = 0; i < s.length(); i++){
        a[i+1] = s[i] - '0';
    }
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        cin >> s;
        split();
        solve();
    }
}