#include <iostream>

using namespace std;

void re(int n,int m,int p,int q)
{
    int j=0;
    for(int i=0;i<p;i++)
    {
        for(int s=0;s<q;s++)
        {
            if(s!=q)cout<<a[j]<<' ';
            j++;
        }
        cout<<endl;
    }
}
int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    int*a=new int[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<t;i++)
    {
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1)
        re(n,m,p,q);
        if(op==2)
    }
    return 0;
}
