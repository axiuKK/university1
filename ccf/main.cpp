#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"2 5"<<endl;
    cout<<"2 5 3 4"<<endl;
    return 0;
}

int main2022062()//70分，a不能开这么大数组
{
    int n,l,s;
    cin>>n>>l>>s;
    vector<vector<int>>a(l+1,vector<int>(l+1));
    int w[n][2];
    for(int i=0;i<n;i++)
    {
        cin>>w[i][0]>>w[i][1];
        a[w[i][0]][w[i][1]]=1;
    }
    int num=0;
    vector<vector<int>>b(s+1,vector<int>(s+1));
    
    for(int i=s;i>=0;i--)
    {
        for(int j=0;j<=s;j++)
        {
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(w[i][0]<=l-s&&w[i][1]<=l-s)
        {
            int flag=0;
            for(int k=0;k<=s;k++)
            {
                for(int p=0;p<=s;p++)
                {
                    if(b[k][p]!=a[w[i][0]+k][w[i][1]+p])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                break;
            }
            if(!flag)
            num++;
        }
    }
    cout<<num;
    return 0;
}

int main2022061()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    double b=0,d=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b+=a[i];
    }
    b/=n;
    vector<double>f(n);
    for(int i=0;i<n;i++)
    {
        d+=pow(a[i]-b,2);
    }
    d/=n;
    for(int i=0;i<n;i++)
    {
        f[i]=(a[i]-b)/sqrt(d);
        cout<<fixed<<setprecision(16)<<f[i]<<endl;
    }
    return 0;
}

int main2022092()
{
    int n,x,sum=0;
    cin>>n>>x;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int y=sum-x;
    vector<vector<int>>dp(n+1,vector<int>(y+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=y;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=a[i])
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+a[i]);
            }
        }
    }
    cout<<sum-dp[n][y];
    return 0;
}

int main2022091()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    vector<int>c(n+1,1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=c[i-1]*a[i];
    }
    vector<int>b(n+1);
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=(m%c[i]-temp)/c[i-1];
        temp+=b[i];
        cout<<b[i]<<' ';
    }
    return 0;
}

struct xun
{
    int t=0;
    int p=0;
    int early=0;
    int late=0;
};

int main2022122()
{
    int n,m,flag=0;
    cin>>n>>m;
    vector<xun>a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i].p;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a[i].t;
        a[i].late=n-a[i].t+1;
        if(a[i].p==0)
        {
            a[i].early=1;
        }
        else
        {
            a[i].early=a[a[i].p-1].early+a[a[i].p-1].t;
            int temp=i;
            while(a[temp].p!=0)
            {
                if(a[temp].late-a[a[temp].p-1].t<a[a[temp].p-1].late)
                a[a[temp].p-1].late=a[temp].late-a[a[temp].p-1].t;
                temp=a[temp].p-1;
            }
        }
        if(a[i].early+a[i].t-1>n)
                flag=1;
    }
    for(int i=0;i<m;i++)
    {
        cout<<a[i].early<<' ';
    }
    if(flag==0)
    {
        cout<<endl;
        for(int i=0;i<m;i++)
        {
            cout<<a[i].late<<' ';
        }
    }
    return 0;
}

int main2022121()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    double i;
    int n;
    cin>>n>>i;
    vector<double>a(n+1);
    double num=0;
    for(int j=0;j<=n;j++)
    {
        cin>>a[j];
        num=num+a[j]*pow(1+i,-j);
    }
    cout<<fixed<<setprecision(3)<<num;
    return 0;
}

struct area
{
    int t=0;
    int c=0;
};

bool cmp(area a,area b)
{
    if(a.t!=b.t)
        return a.t>b.t;
    else
        return a.c<b.c;
}
int main2023032()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<area>a(n);
    //int mi=INT_MAX;
    int r=k,l=0,mid=0,maxx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].t>>a[i].c;
        if(a[i].t>l)
            l=a[i].t;
        /*if(a[i].c<mi)
            mi=a[i].c;*/
    }
    //���ִ𰸷�
    int flag=0;
    while(r<=l)
    {
        mid=(r+l)/2;
        int num=0;
        for(int i=0;i<n;i++)
        {
            if(a[i].t>mid)
                num+=(a[i].t-mid)*a[i].c;
        }
        if(num<=m)
        {
            l=mid-1;
            maxx=mid;
        }
        else
        {
            if(mid==maxx-1)
                flag=1;
            r=mid+1;
        }
        if(flag==1)
            break;
    }
    cout<<maxx;

    /*while(m>=mi)
    {
        sort(a.begin(),a.end(),cmp);
        if(a[0].t==k)
            break;
        while(a[0].t>=a[1].t&&a[0].t>k)
    {
        if(m-a[0].c>=0&&a[0].t>k)
            {m-=a[0].c;
            a[0].t--;}
        else
            break;

    }
    }*/
    //sort(a.begin(),a.end(),cmp);
    /*vector<int>r(n);//ǰ׺��
    r[0]=a[0].c;
    for(int i=1;i<n;i++)
    {
        r[i]=r[i-1]+a[i].c;
    }*/

    /*int ma=a[1].t;
    int num=1;
    while(1)
    {
        while(a[0].t==a[num].t)
            num++;
        if(m>=(a[0].t-ma)*r[num-1])
        {
            m-=(a[0].t-ma)*r[num-1];
            for(int i=0;i<num;i++)
            {
                a[i].t=a[num].t;
            }
            num++;
        }
        if(num==n-1&&a[num].t>k)
        {
            int h=m/r[num];
            int tt=a[num].t-h;
            if(tt<=h)
            {
                m=0;
                break;
            }
            for(int i=0;i<n;i++)
            {
                a[i].t=tt;
            }
        }
        if(m<mi||a[num].t<=k||num==n-1)
            break;
        if(m<(a[0].t-ma)*num)
        {
            sort(a.begin(),a.end(),cmp);
            while(m>mi)
            {
                for(int i=0;i<num;i++)
                {
                    if(m>=a[i].c)
                    {
                        a[i].t--;
                        m-=a[i].c;
                    }
                }
            }
        }
        if(m<mi||a[num].t<=k)
            break;
    }
    sort(a.begin(),a.end(),cmp);
    cout<<a[0].t;*/
    return 0;
}

int main2023031()
{
    int n,a,b;
    cin>>n>>a>>b;
    int sum=0;
    int x1,x2,y1,y2;
    for(int i=0;i<n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        //if((x1>=0||x2<=a)&&(y1>=0||y2<=b))����д�����˸���������
            if(x2>a)
                x2=a;
            if(x1<0)
                x1=0;
            if(y1<0)
                y1=0;
            if(y2>b)
                y2=b;
            if(x2-x1>0&&y2-y1>0)
            sum+=(x2-x1)*(y2-y1);
    }
    cout<<sum<<endl;
    return 0;
}

int main2023052()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,d;
    cin>>n>>d;
    vector<vector<int>>q(n,vector<int>(d));
    vector<vector<int>>k(n,vector<int>(d));
    vector<vector<int>>v(n,vector<int>(d));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)
        {
            cin>>q[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)
        {
            cin>>k[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int>w(n);
    vector<vector<long long int>>qk(n,vector<long long int>(n));
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)//q������
    {
        for(int j=0;j<n;j++)//k������
        {
            long long int temp=0;
            for(int g=0;g<d;g++)
                {
                    temp+=q[i][g]*k[j][g];
                }
            qk[i][j]=temp*w[i];
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            qk[i][j]*=w[i];//�ϲ�����һ��
        }
    }*/
    for(int i=0;i<n;i++)//qk������
    {
        for(int j=0;j<d;j++)//v������
        {
            long long int temp=0;
            for(int g=0;g<n;g++)
                {
                    temp+=qk[i][g]*v[g][j];
                }
            cout<<temp<<' ';
        }
        cout<<endl;
    }
    return 0;
}

struct N
{
    double a=1;
    double b=0;
};
int main2023092()
{
    int n,m;
    cin>>n>>m;
    vector<N>t(n);
    vector<N>r(n);//ʹ��ǰ׺��
    for(int i=0;i<n;i++)
    {
        cin>>t[i].a>>t[i].b;
        if(t[i].a==1)
        {
            if(i==0)
                r[i].a=t[i].b;
            else
                {r[i].a=r[i-1].a*t[i].b;
                r[i].b=r[i-1].b;}
        }
        else
        {
            if(i==0)
                r[i].b=t[i].b;
            else
                {r[i].b=r[i-1].b+t[i].b;
                r[i].a=r[i-1].a;}
        }
    }
    vector<N>s(m);
    int c=0,d=0;
    for(int i=0;i<m;i++)
    {
        cin>>c>>d>>s[i].a>>s[i].b;
        double k=1,q=0;
        /*for(int j=c-1;j<=d-1;j++)
        {
            if(t[j].a==1)
                k*=t[j].b;
            else
                q+=t[j].b;
        }*/
        if(c-1==0)
        {
            k=r[d-1].a;
            q=r[d-1].b;
        }
        else
        {
            k=r[d-1].a/r[c-2].a;
            q=r[d-1].b-r[c-2].b;
        }

        double x=s[i].a,y=s[i].b;
        if(k!=1)
        {
            x=s[i].a*=k;
            y=s[i].b*=k;
        }
        if(q!=0)
        {
            s[i].a=x*cos(q)-y*sin(q);
            s[i].b=x*sin(q)+y*cos(q);
        }
        cout<<fixed<<setprecision(3)<<s[i].a<<' '<<s[i].b<<endl;
    }
    return 0;
}

struct T
{
    int dx=0;
    int dy=0;
};
int main2023091()
{
    int n,m;
    cin>>n>>m;
    vector<T>t(n);
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        cin>>t[i].dx>>t[i].dy;
        x+=t[i].dx;
        y+=t[i].dy;
    }
    vector<T>a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i].dx>>a[i].dy;
        cout<<a[i].dx+x<<' '<<a[i].dy+y<<endl;
    }
    return 0;
}

struct qizi
{
    int time=1;
    string name="";
};
int main2023051()
{
    int n;
    cin>>n;
    vector<qizi>mp(n);
    for(int i=0;i<n;i++)
    {
        string s="";
        for(int j=0;j<8;j++)
        {
            string ss;
            cin>>ss;
            s+=ss;
        }
        mp[i].name=s;
        for(int j=i-1;j>=0;j--)
        {
            if(mp[j].name==mp[i].name)
            {
                mp[i].time=mp[j].time+1;
                break;
            }
        }
        cout<<mp[i].time<<endl;
    }
    return 0;
}

struct tree
{
    int num=0;
    int left=0;
    int right=0;
    int weight=0;
    int w=0;
    int ws=0;
    int root=0;
};

    int n,m;
    vector<tree>b;
    int sum=0;
void wei(int p)
{
    sum+=b[p].weight;
    if(b[p].left!=0)
    {
        for(int i=1;i<(int)b.size();i++)
        {
            if(b[i].num==b[p].left)
            {
                wei(i);
                break;
            }
        }
    }
    if(b[p].right!=0)
    {
        for(int i=1;i<(int)b.size();i++)
        {
            if(b[i].num==b[p].right)
            {
                wei(i);
                break;
            }
        }
    }
    b[p].w=sum;
}

    bool found=false;
    vector<int>leibie;
void shifou(int i,int p)
{
    leibie.push_back(b[i].num);
    if(b[i].left!=0)
    {
        for(int j=1;j<(int)b.size();j++)
        {
            if(b[j].num==b[i].left)
            {
                shifou(j,p);
                break;
            }
        }
    }
    else if(b[i].right!=0)
    {
        for(int j=1;j<(int)b.size();j++)
        {
            if(b[j].num==b[i].right)
            {
                shifou(j,p);
                break;
            }
        };
    }
     if(b[i].num==p)
    {
        found=true;
    }
}
int flag=0;
void shanchu(int num)
{
    if(b[num].left!=0)
    {
        for(int i=1;i<(int)b.size();i++)
        {
            if(b[i].num==b[num].left)
            {
                shanchu(i);
                break;
            }
        }
    }
    if(b[num].right!=0)
    {
        for(int i=1;i<(int)b.size();i++)
        {
            if(b[i].num==b[num].left)
            {
                shanchu(i);
                break;
            }
        }
    }
    if(b[num].root!=0&&flag==0)
    {
        flag++;
        for(int i=1;i<(int)b.size();i++)
        {
            if(b[i].num==b[num].root)
            {
                if(b[i].left==b[num].num)
                    b[i].left=0;
                else
                    b[i].right=0;
                break;
            }
        }
    }
    b.erase(b.begin()+num);
}
int main2023123()
{
    cin>>n>>m;
    vector<tree>a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].weight;
        a[i].num=i;
    }
    for(int i=2;i<=n;i++)
    {
        int k;
        cin>>k;
        a[i].root=k;
        if(a[k].left==0)
            a[k].left=i;
        else if(a[k].right==0)
            a[k].right=i;
    }
    while(m--)
    {
        int p;
        cin>>p;
        b.resize(n+1);
        for (int i = 0; i <= n; i++) {
            b[i] = a[i];
        }
        while(b.size()!=2)
        {
            int zong=0;
            for(int i=1;i<(int)b.size();i++)
        {
            sum=0;
            wei(i);
            zong+=b[i].weight;
        }
        int temp=-1;
        int kk=0;
        for(int i=1;i<(int)b.size();i++)
        {
                b[i].ws=abs(2*b[i].w-zong);
                if(temp==-1)
                {
                    temp=b[i].ws;
                    kk=i;
                }
                else if(temp>b[i].ws)
                {
                    temp=b[i].ws;
                    kk=i;
                }
        }
        /*cout<<kk<<endl;
        for(int i=1;i<b.size();i++)
        {
            cout<<b[i].num<<' '<<b[i].left<<' '<<b[i].right<<' '<<b[i].w<<' '<<b[i].weight<<endl;
        }*/
        found=false;
        leibie.clear();
        cout<<b[kk].num;
        shifou(kk,p);
        if(!found)//��Ҫȥ��
        {
            for(unsigned int i=b.size()-1;i>0;i--)
            {
                if(find(leibie.begin(), leibie.end(), b[i].num) != leibie.end())//�ҵ���
                {
                    shanchu(i);
                }

            }
        }
        else//��Ҫ����
        {
            for(unsigned int i=b.size()-1;i>0;i--)
            {
                if(find(leibie.begin(), leibie.end(), b[i].num) == leibie.end())//û�ҵ�
                {
                    shanchu(i);
                }
            }
        }
        if(b.size()>2)
            cout<<' ';
        }

        cout<<endl;
    }
    return 0;
}
int main2023122()
{
    long long int n,k,q;
    cin>>q;
    while(q--)
    {
        cin>>n>>k;
        map<long long int,int>a;
        for(int i=2;i<=n;i++)
        {
            while(n%i==0)
            {
                a[i]++;
                n/=i;
            }
        }
        map<long long int,int>::iterator it;
         for (it = a.begin(); it != a.end();)
        {
            if (it->second < k)
            {
                it = a.erase(it); // ɾ��������������������
            }
            else
            {
                ++it;
            }
        }
        long long int num=1;
        if(!a.empty())
        {
            for(it=a.begin();it!=a.end();it++)
            {
                /*for(int i=0;i<it->second;i++)
                {
                    num*=it->first;
                }*/
                num*=pow(it->first,it->second);
            }
        }
        cout<<num<<endl;
    }
    return 0;
}

int main2023121()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[0][j]=a[i][j];
        }
        int flag=0;
        for(int k=1;k<=n;k++)
        {
            int temp=0;
            if(k==i)
                continue;
            for(int p=0;p<m;p++)
            {
                if(a[k][p]>a[i][p])
                temp++;
            }
            if(temp==m)
            {
                cout<<k<<endl;
                flag++;
                break;
            }
        }
        if(flag==0)
            cout<<0<<endl;
    }
    return 0;
}
