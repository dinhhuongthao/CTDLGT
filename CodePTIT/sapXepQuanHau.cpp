#include<iostream>

using namespace std;

int x[11], a[11], xuoi[20], nguoc[20];
int dem, n;

void Try (int i){
    for (int j = 1; j <= n; j++){
        if (a[j] && xuoi[i-j+n] && nguoc[i+j-1]){
            x[i] = j;
            a[j] = 0; xuoi[i-j+n] = 0; nguoc[i+j-1] = 0;
            if (i == n) dem++;
            else Try(i+1);
            a[j] = 1; xuoi[i-j+n] = 1; nguoc[i+j-1] = 1;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        for (int j=1; j < 20; j++){
            if (j < 11) {
                a[j] = 1;
            }
            xuoi[j] = 1;
            nguoc[j] = 1;            
        }
    }
}