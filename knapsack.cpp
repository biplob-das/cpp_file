#include<bits/stdc++.h>
using namespace std;
int p[100];
int w[100];
float r[100];
void Ratio(int n){
    for(int i=0;i<n;i++)
    {
        r[i]=(float)p[i]/(float)w[i];
    }
}
void sort(int n){
    Ratio(n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if( r[i]<r[j])
            {
                swap(p[i],p[j]);
                swap(w[i],w[j]);
                swap(r[i],r[j]);
            }
        }

    }


}
void Knapsack(int n,int m)
{
    sort(n);
    int i=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(w[i]>m)
        {
            break;
        }
        else
        {
            sum=sum + p[i];
            m=m-w[i];
        }
    }
    if(i<n)
    {
        sum =sum +(r[i]*m);
    }
    cout<<"The max profit is:"<<sum<<endl;
    cout<<"solution vector:"<<endl;
    for(int i=0;i<n;i++){
        cout<<r[i]<<endl;
    }
}
int main()
{
    int n,m;
    cout<<"enter m,n"<<endl;
    cin>>m>>n;
    cout<<"enter p"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        
    }
     cout<<"enter w"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        
    }
    
Knapsack(n,m);
return 0;
}