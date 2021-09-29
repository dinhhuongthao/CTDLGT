#include<bits/stdc++.h>

using namespace std;

vector<int> a;
bool ok;

void nextPer(){
    int i = a.size()-2;
    while (i > 0 && a[i] >= a[i+1]) i--;
    if (i > 0) {
        int k = a.size()-1;
        while (k > i && a[k] < a[i]) k--;
        swap(a[i], a[k]);
        int l = i+1, r = a.size()-1;
        while (l < r){
            swap(a[l++], a[r--]);
        }
    } else {
        ok = false;
    }
}

void split(string &s){
    for (int i = 1; i <= s.length(); i++){
        a[i] = s[i-1] - '0';
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ok = true;
    a.resize(s.length()+1);
    split(s);
    nextPer();

    cout << n << " ";
    if (next_permutation(s.begin(), s.end())) {
        // for (int i = 1; i <= a.size()-1; i++){
        //     cout << a[i];
        // }
        cout << s;
        
    } else {
        cout << "BIGGEST";
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