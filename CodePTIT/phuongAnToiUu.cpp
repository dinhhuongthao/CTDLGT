#include<bits/stdc++.h>

using namespace std;

struct item {
    int weight;
    int value;
};

vector<item> pack;
vector<int> chosing;
vector<int> xopt;
int fopt = INT_MIN;
int bmax, n;

// bool cmp (item a, item b){
//     return (a.value/a.weight > b.value/b.weight)
// }

void update(int &g){
    if (fopt < g) {
        fopt = g;
        xopt = chosing;
    }
}

void printRes(vector<int> res){
    for (int i = 0; i < res.size(); i++){
        cout << res[i] <<  " ";
    }
    // cout << endl;
}

void chooseItem(int i, int &b, int &g){
    for (int j = 1; j >= 0; j--){
        if (b + j*pack[i].weight <= bmax){
            chosing.push_back(j);
            b = b + j*pack[i].weight;
            g = g + j*pack[i].value;
            if (i == n-1){
                update(g);
                // printRes(chosing);
                // cout << g << " ";
                // cout << fopt << endl;
            }
            else {
                    // cout << g << " " << bmax << " " << b << " " << pack[i+1].weight << " " << pack[i+1].value << " & ";
                    // cout << (g + ((bmax - b)/pack[i+1].weight)*pack[i+1].value) << endl;
                    chooseItem(i+1, b, g); 
                // if (g + ((bmax - b)/pack[i+1].weight)*pack[i+1].value >= fopt) {
                //     cout << i << endl;
                // }
            }
            chosing.pop_back();
            b = b - j*pack[i].weight;
            g = g - j*pack[i].value;
        }
    }
}

void solve(){
    cin >> n >> bmax;
    pack.clear();
    chosing.clear();
    pack.resize(n);
    fopt = INT_MIN;
    for (int i = 0; i < n; i++){
        int value;
        cin >> value;
        pack[i].value = value;
    }
    for (int i = 0; i < n; i++){
        int weight;
        cin >> weight;
        pack[i].weight = weight;
    }
    int b = 0, g = 0;
    chooseItem(0, b, g);
    cout << fopt << endl;
    printRes(xopt);
}

int main(){
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}