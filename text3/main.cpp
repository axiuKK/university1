#include <bits/stdc++.h>

using namespace std;

int main1()
{
    int n;
    cin>>n;
    map<int,int>a;
    for(int i=2;i<=n;i++)//依次判断并相加
    {
        int x=i;
        for(int j=2;j<=i;j++)
        {
            while(x%j==0)//质因子分解函数->不用判断是否为质数；降低时间复杂度
                {
                    a[j]++;
                    x/=j;
                }
        }
    }
    map<int,int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
    {
        cout<<it->first<<' '<<it->second<<endl;
    }
    return 0;
}

int main0()
{
    int n,m,f;
    cin>>n>>m>>f;
    cout<<n<<' '<<m<<' '<<f<<endl;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
int aa[2001][2001];
int sum[2001][2001];

bool check1(int row,int col,int mid,int f)
{
    int num=0;
    num=mid*mid-sum[row+mid-1][col+mid-1]+sum[row-1][col+mid-1]+sum[row+mid-1][col-1]-sum[row-1][col-1];
    if(num<=f)
        return 1;
    else
        return 0;
}
int main()
{
    int n,m,f;
    cin>>n>>m>>f;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>aa[i][j];
            /*if(i==0&&j==0)//也可以加一圈边界，从ij=1开始就不会越界
            {
                sum[i][j]=a[i][j];
            }
            else if(i==0&&j!=0)
            {
                sum[i][j]=sum[i][j-1]+a[i][j];
            }
            else if(i!=0&&j==0)
            {
                sum[i][j]=sum[i-1][j]+a[i][j];
            }
            else*/
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+aa[i][j];//计算前缀和

        }
    }
    int l=1,r=n;
    if(n>m)
        r=m;
    while(l<=r)
    {
        int mid=(r+l)/2;
        int flag=0;
        for(int i=1;i<=n-mid+1;i++)
        {
            for(int j=1;j<=m-mid+1;j++)
            {
                if(check1(i,j,mid,f))
                {
                    ans=mid;
                    flag=1;
                    l=mid+1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
int a[150][150];
bool check(int row,int col,int mid)
{
    for(int i=row;i<row+mid;i++)
    {
        for(int j=col;j<col+mid;j++)
        {
            if(a[i][j]==0)
                return 0;
        }
    }
    return 1;
}
int main13871()//洛谷1387二分答案法
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    int ans=1,l=1,r=n;
    if(n>m)
    {
        r=m;
    }
    while(l<=r)
    {
        int flag=0;
        int mid=(l+r)/2;
        for(int i=0;i<=n-mid;i++)
        {
            for(int j=0;j<=m-mid;j++)
            {
                if(check(i,j,mid))
                {
                    flag++;
                    ans=mid;
                    l=mid+1;
                    break;
                }
            }
        }
        if(flag==0)
            r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}

int main13872()
{
    int n,m;
    int dp[150][150];
    cin>>n>>m;
    int ans=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>dp[i][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(dp[i][j]==1)
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            if(dp[i][j]>ans)
                ans=dp[i][j];
        }
    }
    cout<<ans;
    return 0;
}
