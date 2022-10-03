#include <bits/stdc++.h>

using namespace std;



int main(){

    int m,x,k,y;
    
    cin>>m>>y>>x>>k;
    
    int a[m+1],b[m+1],e[m+1],u[m+1];
    
	for(int i=0;i<m;i++) cin>>a[i];
	u[0] = a[0];
	if (u[0] > y) b[0] = k;
	else b[0] = x;
	e[0] = b[0] - u[0];
	for(int i=1;i<m;i++){
		u[i] = a[i] - e[i-1];
		if(u[i] > y) b[i] = k;
		else b[i] = x;
		e[i] = b[i] - u[i];
	}
	
	for(int i=0;i<m;i++) cout<<b[i]<<" ";
	
}
