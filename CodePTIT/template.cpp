#include<bits/stdc++.h> //cau nen dung thu vien nay, no la thu vien cua tat ca cac thu vien, khai bao 1 lan sau do phai them

using namespace std;

vector<int> a; //khai bao vector a
vector<int> b; //khai bao vector b
bool ok = true;
int n, k;

void nextBin(){
    int i = n;
    while (i > 0 && a[i] != 0){
        a[i] = 0;
        i--;
    }
    if (i > 0) {
        a[i] = 1;
    } else {
        ok = false;
    }
}

void printBin(){
    for (int i = 1; i <= n; i++){
        if (a[i] == 1) cout << b[i] << " ";
    }
    cout << endl;
}

void solve(){
    ok = true;
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
    int count = 0;
    while (ok) {
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == 1) sum += b[i];
        }
        if (sum == k) {
            printBin();
            count++;
        }
        nextBin();
    }
    cout << count << endl;
}

int main(){
    int t = 1; //hay de nhu nay, sau khong co bo test thi // dong cin >> t thoi cho nhanh
    // cin >> t;
    while (t--){
        cin >> n >> k;
    	a.resize(n+1);
		b.resize(n+1);
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        solve();
    }
}