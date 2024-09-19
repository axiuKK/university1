#include <bits/stdc++.h>

using namespace std;

int main11()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long int max,min;
	long long int rec=0;
	for(int i=1;i<n;i++)
	rec+=abs(a[i]-a[i-1]);
	max=0;
	min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		a[i]+=k;
		int temp=0;
		for(int j=1;j<n;j++)
		temp+=abs(a[j]-a[j-1]);
		if(temp>max) max=temp;
		if(temp<min) min=temp;
		a[i]-=k;
	}
	for(int i=0;i<n;i++)
	{
		a[i]-=k;
		int temp=0;
		for(int j=1;j<n;j++)
		temp+=abs(a[j]-a[j-1]);
		if(temp>max) max=temp;
		if(temp<min) min=temp;
		a[i]+=k;
	}
	cout<<max<<" "<<min<<endl;
	return 0;
}

int main18()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<int>b(n-1);
    int g=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            b[i-1]=abs(a[i]-a[i-1]);
            g+=b[i-1];
        }
    }
    int big=0,small=INT_MAX;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(i!=0&&i<n-1)
        {
            temp=abs(a[i]+k-a[i-1])-b[i-1]+abs(a[i]+k-a[i+1])-b[i];
            if(temp+g<small)
                small=temp+g;
            if(temp+g>big)
                big=temp+g;
            temp=abs(a[i]-k-a[i-1])-b[i-1]+abs(a[i]-k-a[i+1])-b[i];
            if(temp+g<small)
                small=temp+g;
            if(temp+g>big)
                big=temp+g;
        }
        if(i==n-1)
        {
            temp=abs(a[i]+k-a[i-1])-b[i-1];
            if(temp+g<small)
                small=temp+g;
            if(temp+g>big)
                big=temp+g;
            temp=abs(a[i]-k-a[i-1])-b[i-1];
            if(temp+g<small)
                small=temp+g;
            if(temp+g>big)
                big=temp+g;
        }
        if(i==0)
        {
            temp=abs(a[i]+k-a[i+1])-b[i+1];
            if(temp+g<small)
                small=temp+g;
            if(temp+g>big)
                big=temp+g;
            temp=abs(a[i]-k-a[i+1])-b[i+1];
            if(temp+g<small)
                small=temp+g;
            if(temp+g>big)
                big=temp+g;
        }
    }
    cout<<big<<' '<<small<<endl;
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    long long int sum=0;
    vector<int>a(n);
    int temp=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>temp)
            temp=a[i];
        sum+=a[i];
    }
    long long int l=temp,r=sum;
    int num=0;
    long long int ans=sum;
    while(l<=r)
    {
        int mid=l+r>>1;
        num=0;
        sum=0;
        for(int i=0;i<n;i++)
    {
        sum=0;
        int flag=0;
        while(sum+a[i]<=mid&&i<n)
        {
            sum+=a[i];
            i++;
            flag++;
        }
        if(flag!=0)
            i--;
        else
            if(a[i]>mid)
            mid=INT_MAX;
        num++;
    }
        /*if(num<m)
            r=mid-1;
        else if(num>m)
            l=mid+1;
        else if(num=m)//符合的不一定是最优解
        {
            ans=mid;
            r=mid-1;
        }
        if(mid>ans)//更新后的值不是最优解区间里
            break;*/

        if(num<=m)
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
