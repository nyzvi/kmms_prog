#include<bits/stdc++.h>
int main(){
    int n,k;
    std:: cin >> n;
    std:: vector <int> a(pow(10,3) + 1);
    for (int i = 0; i < n;++i){
        std:: cin >> k;
        a[k] += 1;
    }
    for (int i = 0; i < pow(10,3) + 1 ; i++){
        for (int j = 0; j < a[i]; j++){
            std:: cout << i << " ";
        }
    }
}