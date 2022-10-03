#include <bits/stdc++.h>

using namespace std;



int main(){

    int n,m,x;
    
    cin>>n>>m;
    
    int a[n][m],b[n][m],c[n][m];
    
    for(int i=1; i<=n;i++)
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
    }
    
    for(int i=1; i<=n;i++)
        for(int j=1; j<=m; j++){
            cin>>b[i][j];
    }
    
    c = a+b;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
