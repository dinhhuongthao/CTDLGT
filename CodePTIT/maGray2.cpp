#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> grayCode(15);

void prepare(){
    grayCode[1].push_back("0");
    grayCode[1].push_back("1");
    for (int i = 2; i <= 10; i++){
        for (int j = 0; j < grayCode[i-1].size(); j++){
            grayCode[i].push_back('0' + grayCode[i-1][j]);
        }
        for (int j = grayCode[i-1].size()-1; j >= 0; j--){
            grayCode[i].push_back('1' + grayCode[i-1][j]);
        }
    }
}

// int sqr(int a){
//     return a * a;
// }
// 
// int pwr(int a, int b){
//     if (b == 0) return 1;
//     else {
//         int tmp = b%2;
//         if (tmp == 0) return sqr(pwr(a, b/2));
//         else return a * sqr(pwr(a, b/2));
//     }
// }

void bitToDec(string &bin, int &dec){
    int bit, so = 1;
    for (int i = bin.length()-1; i >= 0; i--){
        bit = (int) bin[i] - '0';
        if (bit == 1) dec += so;
        so *= 2;
    }
}

void solve(){
    string bin;
    cin >> bin;
    int dec = 0;
    bitToDec(bin, dec);
    cout << grayCode[bin.length()][dec] << endl;
}

int main(){
    prepare();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}