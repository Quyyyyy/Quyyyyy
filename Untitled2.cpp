#include <bits/stdc++.h>

using namespace std;



int main(){

    int n,m,x;
    
    cin>>n>>m;
    
    int a[n+2][m+2];
	
	for(int i=0; i< n+2;i++)
        for(int j=0; j< m+2; j++) a[i][j] = 0;
    
    for(int i=1; i<=n;i++)
        for(int j=1; j<=m; j++){
            cin>>x;
            a[i][j] = x;
    }
    
    int g[m+2][n+2]={0};
	for(int i=0; i< n+2;i++)
        for(int j=0; j< m+2; j++) g[i][j] = 0;
	
	for( int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++){
	    	g[i][j] = a[i-1][j-1]*-1 + a[i-1][j]*0 + a[i-1][j+1]*1 + a[i][j-1]*-1 + a[i][j]*0 + a[i][j+1]*1 + a[i+1][j-1]*-1 + a[i+1][j]*0 + a[i+1][j+1]*1;	    	
		}     
	cout<<endl;
	
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
}
