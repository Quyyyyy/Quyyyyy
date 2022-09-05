#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int m, n, L; 
	cin>>m>>n>>L;
	int r[20][20], pk[m*n+1];
	float sk[m*n+1];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>r[i][j];
    cout<<"m = "<<m<<", n = "<<n<<", L = "<<L<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<r[i][j]<<"   ";
        cout<<endl;
    }
    //pk
    for(int k=0; k<L; k++)
        pk[k]=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            pk[r[i][j]]++;
    cout<<endl;
    for(int k=0; k<L; k++)
        cout<<k<<"   "<<pk[k]<<endl;
    //sk
    for(int i=0;i<L;i++){
    	float sum =  0;
    	if(pk[i]!=0){
	    	for(int j=0;j<=i;j++){
	    		sum += pk[j];
			}
	    }
	    sk[i] = (L-1)*sum/(m*n);
	    sk[i] = round(sk[i]);
	}
	
	for(int i=0;i<L;i++){
		cout<<sk[i]<<" ";
	}
	cout<<endl;

    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		int a = r[i][j];
    		for(int k=0;k<L;k++){
    			if(a==k && sk[k]!=0){
				 r[i][j] = sk[k];
				 break;
			}
			}
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
}
