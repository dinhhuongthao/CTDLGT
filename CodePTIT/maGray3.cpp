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

string decToBin(int dec){
    string bin = "";
    while (dec != 0){
        int bit = dec%2;
        if (bit == 0) bin = '0' + bin;
        else bin = '1' + bin;
        dec /= 2;
    }
    return bin;
}

void solve(){
    string n, bin = "";
    cin >> n;
    int dec;
    for (int i = 0; i < grayCode[n.length()].size(); i++){
        if (n == grayCode[n.length()][i]) {
            dec = i;
            // cout << dec << endl;
            break;
        }
    }
    bin = decToBin(dec);
    while (bin.length() < n.length())
        bin = '0' + bin;
    cout << bin << endl;
}

int main(){
    prepare();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}