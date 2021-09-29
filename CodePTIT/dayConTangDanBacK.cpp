#include<bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> indexx;
vector<int> arr;
int n, k;

void print(){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool incCheck(){
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] - arr[i-1] <= 0) return 0;
    }
    return 1;
}

void incArr(int i, int &count){
    if (i > k){
        if (incCheck()) {
            count++;
            // print();
        }
        return;
    }
    for (int j = indexx[i-1]+1; j <= n; j++){
        indexx.push_back(j);
        arr[i-1] = a[j-1];
        incArr(i+1, count);
        indexx.pop_back();
    }
}

void solve(){
    cin >> n >> k;
    a.clear();
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    // indexx.resize(k+1, 0);
    indexx.clear();
    indexx.push_back(0);
    arr.resize(k);
    int count = 0;
    incArr(1, count);
    cout << count << endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}
