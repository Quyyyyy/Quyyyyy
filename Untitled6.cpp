#include<iostream>
#include<math.h>
using namespace std;

int main(){
	
    int L;
    
    cin>>L;
    
    int r[20][20],pk[L+1];
    
    float sk[L+1],pi[L+1],e[L+1];
    
    for(int i=0;i<L;i++) cin>>i;
    //pk
    for(int k=0;k<L;k++)
        cin>>pk[k]=0;
    
    //sk
    for(int i=0;i<L;i++){
        float sum = 0;
        if(pk[i]!=0){
            for(int j=0;j<=i;j++){
                sum += pk[j];
            }
        }
        sk[i] = sum/(m*n);
    }
    //pi
    float max = 0;
    for(int i=0;i<L;i++){
    	float sum = 0;
    	if(pk[i]!=0){
    		for(int j=0;j<=i;j++){
    			sum += j*pk[j];
			}
		}
		pi[i] = sum/(m*n);
		if(pi[i]>max) max = pi[i];
	}
	//e
	float z = 0;
	int d = 1, t = 0 ;
	for(int i=0;i<L;i++){
		float sum = 0;
		if(pk[i]!=0){
			e[i] = (max*sk[i]-pi[i])*(max*sk[i]-pi[i])/sk[i];
			e[i] = e[i]/(1-sk[i]);
		}
		if(z < e[i])  {
			z = e[i];
			t = i;
		} else if (z == e[i]){
			d++;
			t += i;
		}
	}
	for(int i=0;i<L;i++) cout<<i<<" "<<e[i]<<endl;

	
	cout<<z<<" "<<t/d<<endl;
}
