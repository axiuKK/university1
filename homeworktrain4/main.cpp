#include <bits/stdc++.h>

using namespace std;

int main1()
{
    string a,b;
    cin>>a>>b;
    int as=0,bs=0,ag=0,bg=0,ak=0,bk=0;
    stringstream ss(a);
    string str;
    int flag=0;
    cin.ignore();
    while(getline(ss,str,'.'))
    {
        stringstream p(str);
        if(flag==0)
        {
            p>>ag;
            flag++;
        }
        else if(flag==1)
        {
            p>>as;
            flag++;
        }
        else
            p>>ak;
    }
    stringstream s(b);
    flag=0;
    while(getline(s,str,'.'))
    {
        stringstream p(str);
        if(flag==0)
        {
            p>>bg;
            flag++;
        }
        else if(flag==1)
        {
            p>>bs;
            flag++;
        }
        else
            p>>bk;
    }
    int k=0;
    int sg=0,sss=0,sk=0;
    int f=0;
    if(bg<ag)
    {
        sg=bg;
        bg=ag;
        ag=sg;
        sss=bs;
        bs=as;
        as=sss;
        sk=bk;
        bk=ak;
        ak=sk;
        f++;
    }
    else if(bg==ag&&bs<as)
    {
        sg=bg;
        bg=ag;
        ag=sg;
        sss=bs;
        bs=as;
        as=sss;
        sk=bk;
        bk=ak;
        ak=sk;
        f++;
    }
    else if(bg==ag&&bs==as&&bk<ak)
    {
        sg=bg;
        bg=ag;
        ag=sg;
        sss=bs;
        bs=as;
        as=sss;
        sk=bk;
        bk=ak;
        ak=sk;
        f++;
    }
    if(bk-ak>=0)
        sk=bk-ak;
    else
    {
        sk=29+bk-ak;
        k++;
    }
    if(bs-as-k>=0)
    {
        sss=bs-as-k;
        k=0;
    }
    else
    {
        sss=bs-as-k+17;
        k=1;
    }
    sg=bg-ag-k;
    if(f!=0)
        cout<<'-';
    cout<<sg<<'.'<<sss<<'.'<<sk;
    return 0;
}
string jia(int j)
{
    string s;
    if(j==0)
        s="0";
    else if(j==1)
        s="1";
    else if(j==2)
        s="2";
    else if(j==3)
        s="3";
    else if(j==4)
        s="4";
    else if(j==5)
        s="5";
    else if(j==6)
        s="6";
    else if(j==7)
        s="7";
    else if(j==8)
        s="8";
    else if(j==9)
        s="9";
    return s;
}
int main2()
{
    int a[10]={0};
    int num=0,n=0;
    while(cin>>num)
    {
        a[num]++;
        n++;
    }
    string s="";
    for(int j=1;j<=9;j++)
    {
        if(a[j]!=0)
        {
            s+=jia(j);
            a[j]--;
            break;
        }
    }

    for(int j=0;j<=9;j++)
    {
        while(a[j]!=0)
        {
            s+=jia(j);
            a[j]--;
        }
    }
    cout<<s<<endl;
    return 0;
}

int main3()
{
    int n;
    while(cin>>n&&n)
    {
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='a'&&s[i+1]=='b')
                a++;
            else if(s[i]=='b'&&s[i+1]=='a')
                b++;
        }
        cout<<a-b<<endl;
    }
    return 0;
}

int main4()
{
    int n;
    while(cin>>n&&n)
    {
        int*s=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        int num=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]>s[j])
                    num++;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}

int main5()
{
    int n;
    cin>>n;
    int num=0;
    while(n>=100)
    {
        n-=100;
        num++;
    }
    while(n>=20)
    {
        n-=20;
        num++;
    }
    while(n>=10)
    {
        n-=10;
        num++;
    }
    while(n>=5)
    {
        n-=5;
        num++;
    }
    num+=n;
    cout<<num;
    return 0;
}

char s11(int n)
{
    char c='1';
    if(n==0)
        c='1';
    else if(n==1)
        c='0';
    else if(n==2)
        c='X';
    else if(n==3)
        c='9';
    else if(n==4)
        c='8';
    else if(n==5)
        c='7';
    else if(n==6)
        c='6';
    else if(n==7)
        c='5';
    else if(n==8)
        c='4';
    else if(n==9)
        c='3';
    else if(n==10)
        c='2';
    return c;
}
int main6()
{
    int a[17]={0};

    while(1)
    {
        string s;
        cin>>s;
        if(s=="-1")
            return 0;
       for(int i=0;i<17;i++)
       {
           a[i]=(int)s[i]-'0';
       }
    int sum=0;
    sum=a[0]*7+a[1]*9+a[2]*10+a[3]*5+a[4]*8+a[5]*4+a[6]*2+
    a[7]+a[8]*6+a[9]*3+a[10]*7+a[11]*9+a[12]*10+a[13]*5+a[14]*8+a[15]*4+a[16]*2;
    if(s[17]==s11(sum%11))
        cout<<1<<endl;
    else
        cout<<0<<endl;
    }
}

int main7()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int num=1,m=1;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        while(a[i]<a[j])
        {
                num++;
                if(num>m)
                    m=num;
                i++;
                j++;
                if(j>=n)
                    break;
        }
        num=1;
    }
    cout<<m<<endl;
    return 0;
}

char m5(char c)
{
    char a='A';
    if(c=='A')
        a='V';
    else if(c=='B')
        a='W';
    else if(c=='C')
        a='X';
    else if(c=='D')
        a='Y';
    else if(c=='E')
        a='Z';
    else if(c=='F')
        a='A';
    else if(c=='G')
        a='B';
    else if(c=='H')
        a='C';
    else if(c=='I')
        a='D';
    else if(c=='J')
        a='E';
    else if(c=='K')
        a='F';
    else if(c=='L')
        a='G';
    else if(c=='M')
        a='H';
    else if(c=='N')
        a='I';
    else if(c=='O')
        a='J';
    else if(c=='P')
        a='K';
    else if(c=='Q')
        a='L';
    else if(c=='R')
        a='M';
    else if(c=='S')
        a='N';
    else if(c=='T')
        a='O';
    else if(c=='U')
        a='P';
    else if(c=='V')
        a='Q';
    else if(c=='W')
        a='R';
    else if(c=='X')
        a='S';
    else if(c=='Y')
        a='T';
    else if(c=='Z')
        a='U';
    return a;
}
int main8()
{
    string s;
    while(cin>>s)
    {
        if(s=="ENDOFINPUT")
            break;
        if(s=="START")
        {
            while(1)
            {
                string k;
                cin>>k;
                if(k=="END")
                {
                    cout<<endl;
                    break;
                }
                int p=k.length();
                for(int i=0;i<p;i++)
                {
                    if(k[i]>='A'&&k[i]<='Z')
                         cout<<m5(k[i]);
                    else
                        cout<<k[i];
                }
                cout<<' ';
            }

        }
    }
    return 0;
}

int main9()
{
    int n;
    while(cin>>n&&n)
    {
        string s;
        cin>>s;
        int p=s.length();
        int r=p-1;
        int num=0;
        for(int i=p-2;i>=0;i--)//从尾部判断是否为回文串
        {
            string a="",c="";
            for(int j=i;j<p;j++)
            {
                a+=s[j];
            }
            for(int j=p-1;j>=i;j--)
            {
                c+=s[j];
            }
            if(a==c)
            {
                num=p-a.length();
                if(num<r)
                    r=num;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}

int main10()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%7==0)
        {
            cout<<i<<endl;
            continue;
        }
        int p=i;
        while(p>0)
        {
            if(p%10==7)
            {
                cout<<i<<endl;
                break;
            }
            p/=10;
        }
    }
    return 0;
}

int main11() {//动规
	int n;
	cin>>n;
	int day[n];//ai
	for(int i=0; i<n; i++) {
		cin>>day[i];
	}
	int dp[n][3];//0编程 1运动 2休息,dp[i][j]表示第i+1天(dp[0]表示第1天)为j状态,此时休息的最少天数
	for(int i=0; i<n; i++)
		for(int j=0; j<3; j++)dp[i][j]=INT_MAX;

	if(day[0]==1)dp[0][0]=0;//若第1天编程，休息0天
	if(day[0]==2)dp[0][1]=0;//若第1天运动，休息0天
	if(day[0]==3) {//若第1天编程或运动
		dp[0][1]=0;//选编程，休息0天
		dp[0][0]=0;//选运动，休息0天
	}
	dp[0][2]=1;//若第1天休息，休息1天

	for(int i=1; i<n; i++) {
		if(day[i]==1)dp[i][0]=min(dp[i-1][1],dp[i-1][2]);//若编程，则上一天只能运动或休息
		if(day[i]==2)dp[i][1]=min(dp[i-1][0],dp[i-1][2]);//若运动，则上一天只能编程或休息
		if(day[i]==3) {//若编程或运动
			dp[i][0]=min(dp[i-1][1],dp[i-1][2]);//选编程
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);//选运动
		}
		dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;//若休息，则上一天三者均可
	}
	int result=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));//结果为最后一天三种状态的最小值
	cout<<result;
	return 0;
}

int main12()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    int k=1,p=0;
    for(int i=0;i<n;i++)
    {
        if(a[i][0]==0)
        {
            a[i][0]=k;
            k++;
            p=1;
            for(int j=i-1;j>=0;j--)
            {
                a[j][p]=k;
                p++;
                k++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(j==n-i-1)
                cout<<a[i][j];
            else
                cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

int main13()
{
    int m1=0,m2=0;
    string s;
    while(cin>>m1>>m2>>s)
    {
        int r1=0,r2=0,r3=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='A')
            {
                r1=m1;
            }
            else if(s[i]=='B')
            {
                r2=m2;
            }
            else if(s[i]=='C')
            {
                m1=r3;
            }
            else if(s[i]=='D')
            {
                m2=r3;
            }
            else if(s[i]=='E')
            {
                r3=r1+r2;
            }
            else if(s[i]=='F')
            {
                r3=r1-r2;
            }
        }
        cout<<m1<<','<<m2<<endl;
    }
    return 0;
}

struct st
{
    string id;
    int m=0;
    int d=0;
};

bool cmp(st&a,st&b)
{
    if(a.m!=b.m)
        return a.m<b.m;
    else
        return a.d<b.d;
}
int main14()
{
    int n;
    cin>>n;
    st*a=new st[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].id>>a[i].m>>a[i].d;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        int flag=0;
        if(i==n-1)
        {
            cout<<a[i].m<<' '<<a[i].d<<' '<<a[i].id<<endl;
            break;
        }
        while(a[i].m==a[i+1].m&&a[i].d==a[i+1].d)
        {
            if(i+1>=n)
                break;
            if(flag==0)
                cout<<a[i].m<<' '<<a[i].d<<' '<<a[i].id;
            else
                cout<<' '<<a[i].id;
            flag++;
            i++;
        }
        if(flag!=0&&i<n)
            cout<<' '<<a[i].id;
        else
            cout<<a[i].m<<' '<<a[i].d<<' '<<a[i].id;
        cout<<endl;
    }
    return 0;
}

string xingqi(int n)
{
    string s="";
    if(n%7==2)
        s="Monday";
    else if(n%7==3)
        s="Tuesday";
    else if(n%7==4)
        s="Wednesday";
    else if(n%7==5)
        s="Thursday";
    else if(n%7==6)
        s="Friday";
    else if(n%7==0)
        s="Saturday";
    else if(n%7==1)
        s="Sunday";
    return s;
}

bool isrun(int n)
{
    if(n%4==0)
    {
        if(n%100==0&&n%400!=0)
            return 0;
        else
            return 1;
    }
    else
        return 0;
}
int main15()
{
    int n;
    while(cin>>n&&n!=-1)
    {
        string s=xingqi(n);
        n++;
        int a=2000;
        while(n>365)
        {
            if(isrun(a))
            {
                if(n>366)
                    n-=366;
                else
                    break;
            }
            else
                n-=365;
            a++;
        }
        int b=1;
        while(n>=28)
        {
            if(b==1||b==3||b==5||b==7||b==8||b==10||b==12)
            {
                if(n>31)
                    n-=31;
                else
                    break;
            }
            else if(isrun(a)&&b==2)
            {
                if(n>29)//可以为最后一天
                    n-=29;
                else
                    break;
            }
            else if(!isrun(a)&&b==2)
                {
                    if(n>28)
                        n-=28;
                    else
                        break;
                }
            else if(b==4||b==6||b==9||b==11)
            {
                if(n>30)
                    n-=30;
                else
                    break;
            }
            b++;
        }
        cout<<a<<'-';
        if(b<10)
            cout<<'0'<<b<<'-';
        else
            cout<<b<<'-';
        if(n<10)
        {
            if(n==0)
                cout<<"01"<<' ';
            else
                cout<<'0'<<n<<' ';
        }
        else
            cout<<n<<' ';
        cout<<s<<endl;
    }
    return 0;
}

bool Erase(vector<int>& tmp, int flag)
{
	int n = tmp.size();
	for (int i = 1; i < n; i++)
		if (tmp[i]==flag)
		{
			tmp.erase(tmp.begin()+i);
			return true;
		}
	return false;//找了一圈没找到要删除的，说明前面假设sum[i]是n2+n3有误
}

int main16()
{
    int n;
    while(cin>>n&&n)
    {
        int p=n*(n-1)/2;
        vector<int>a(p+1);
        for(int i=1;i<p+1;i++)//s1=a1+a2,s2=a1+a3
        {
            cin>>a[i];
        }
        vector<int>num(n+1);
        for(int i=3;i<=p;i++)//遍历每一个，直到找到a2+a3
        {
            vector<int>b(a);//把a赋值给b
            num[1]=(a[1]+a[2]-a[i])/2;//此时最小为n1+n4,可以确定出n4，删除n1+n4，n2+n4，n3+n4，此时最小为n1+n5
            num[2]=a[1]-num[1];
            num[3]=a[i]-num[2];
            //cout<<num[1]<<' '<<num[2]<<' '<<num[3]<<endl;
            b.erase(b.begin()+i);//删除si
            b.erase(b.begin()+2);
            b.erase(b.begin()+1);//删除s1s2
            if(n==3)
                break;
            int k=4,flag=1;
            while(k<=n)
            {
                num[k]=b[1]-num[1];
                for(int j=1;j<k;j++)
                {
                    bool Flag=true;
                    Flag=Erase(b,num[k]+num[j]);
                    if(!Flag)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                    break;
                k++;
            }
            if(flag!=0)
                break;
        }
        for(int i=1;i<n+1;i++)
        {
            cout<<num[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
int main17()//动规
{
    int n;
    cin>>n;
    //vector<int>dp(n,0);一维数组
    vector<vector<int>>dp(n,vector<int>(n));//二维数组，n个一维数组
    vector<vector<int>>a(n,vector<int>(n));
    vector<vector<int>>b(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin>>a[i][j];
            if(j==0)
            {
                if(i==0)dp[i][j]=a[i][j];
                else dp[i][j]=a[i][j]+dp[i-1][j];
                b[i][j]=0;
            }
            else if(j==i)
            {
                dp[i][j]=dp[i-1][j-1]+a[i][j];
                b[i][j]=1;
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(dp[i-1][j-1]>dp[i-1][j])
            {
                dp[i][j]=dp[i-1][j-1]+a[i][j];
                b[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j]+a[i][j];
                b[i][j]=0;
            }
        }
    }
    auto m=max_element(dp[n-1].begin(),dp[n-1].end());//取最后一行的起始位置,返回迭代器
    cout<<*m<<endl;
    int p=distance(dp[n-1].begin(),m);
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        s.push(a[i][p]);
        if(b[i][p]==1)p--;
        if(p==i)p--;
        if(p<0)p=0;
    }
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}

int main()
{
    int m;
    while(cin>>m&&m)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<int>dp(m+1,10000000);
        for(int i=0;i<n;i++)
        {
            dp[a[i]]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=a[i];j<=m;j++)
            {
                dp[j]=min(dp[j],dp[j-a[i]]+1);
                //cout<<j<<' '<<dp[j]<<endl;
            }
        }
        if(dp[m]==10000000)
            cout<<"Impossible"<<endl;
        else
            cout<<dp[m]<<endl;
    }
    return 0;
}
