#include<iostream>
#include<string>

using namespace std;

int a[100001];
string s;
int n;

void printBin(){
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
}

void split(){
    for (int i = 1; i <= n; i++){
        a[i] = s[i-1] - '0';
        cout << a[i] << " " << s[i-1] << endl;
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
        // // solve();
    }
}