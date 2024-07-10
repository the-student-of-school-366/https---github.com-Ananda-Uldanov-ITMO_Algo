#include<iostream>
using namespace std;


int main()
{
    int m,n;
    cin>>m>>n;
    int a[n];
    int c[n];
    int b[m];
    if(m>n){
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            a[i]=b[i];
            c[i]=0;
        }
        for(int p=n;p<m;p++)
        {   int trash;
            int presure=b[p];
            trash=a[0];
            c[2]=a[n-1];
            for(int i=1;i<n-1;i++)
            {
            a[i-1]=a[i];
            }
            c[0]=trash;
            c[1]=presure;
            a[n-2]=c[0]+c[1]+c[2]-max(max(c[0],c[1]),c[2])-min(min(c[0],c[1]),c[2]);
            a[n-1]=max(max(c[0],c[1]),c[2]);
        
  

        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<' ';
        }
    }
    else{
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<m;i++)
        {
            cout<<a[i]<<' ';
        }
    }
    
}