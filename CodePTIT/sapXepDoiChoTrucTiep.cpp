#include<iostream>

using namespace std;

int a[100001];

// interchange sort - doi cho truc tiep

void print(int n, int k){
    cout << "Buoc " << k << ": ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void run(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0 ; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
        print(n, i+1);
    }
    
}

int main(){
    run();
}