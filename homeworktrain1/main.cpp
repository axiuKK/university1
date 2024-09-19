#include <bits/stdc++.h>

using namespace std;
int main00000()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int num;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            cout<<num<<' ';
        }
        cout<<endl;
    }
}
int main0()
{
    map<int,int>a;
    int n;
    while(cin>>n){
        if(n==0)break;
        for(int i=0;i<n;i++)
    {
        int num=0;
        cin>>num;
        if(a.count(num)==1)a[num]++;//查找成功
        else a[num]=1;
    }
    //sort(a.begin(),a.end(),cmpp);用sort要把map转存到vector里
    map<int,int>::iterator it;
    int temp=a.begin()->second;
    int k=a.begin()->first;
    for(it=a.begin();it!=a.end();it++)
    {
        //cout<<it->first<<' '<<it->second<<endl;用迭代器输出
        if(it->second>temp)
        {
            temp=it->second;
            k=it->first;
        }
    }
    cout<<k<<endl;
    /*for(int i=0;i<a.size();i++)//不能用数组输出
    {
        cout<<a[i].first<<' '<<a[i].second<<endl;
    }*/
    a.erase(a.begin(),a.end());
    }

    return 0;
}

int main1()
{
    int N;
    int a[10000];
    int b[10000];
    int maxx=0;
    int maxn=0;
    while(cin>>N)
    {
        if(N==0)break;
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++)
        {
            cin>>b[i];
            a[b[i]]++;
            if(a[b[i]]>maxn)//比较的是max的次数不是max本身
                {maxx=b[i];
                maxn=a[b[i]];}
        }
        cout<<maxx<<endl;
        maxx=0;
        maxn=0;//归零
    }

    return 0;
}

int main2()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    int b[m];//用char似乎会乱码
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            b[j]=b[j]+(int)a[i][j]-'0';

        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[j]-(int)a[i][j]+'0'==0)break;
            if(j==m-1)
            {
                cout<<"YES";
                return 0;
            }
        }
        if(i==n-1)
            cout<<"NO";
    }
    return 0;
}

int main3()
{
    int n,a,b;
    int l=0,r=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        if(a>0)r++;
        if(a<0)l++;
    }
    if(r==1||l==1||r==0||l==0)cout<<"Yes";//可能都在同一边
    else cout<<"No";//注意大小写
    return 0;
}

int main4()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int N;
    cin>>N;
    /*cin.ignore();
    getline(cin,s);在cin和geline之间用ignore*/
    for(int i=0;i<N;i++)
    {
        while(1)
        {
            cin>>s;
        reverse(s.begin(),s.end());
        cout<<s<<' ';

        if(cin.get()=='\n')break;//要用cinget获取换行符
        }


        /*int n=s.size();
        int start;
        int idx=0;//插入位置的下标
        for(start=0;start<n;start++)
        {
            if(idx!=0)s[idx++]=' ';
            int end=start;
            while(end<n&&s[end]!=' ')s[idx++]=s[end++];
            start=end;
        }
        s.erase(s.begin()+idx,s.end());*/
        cout<<endl;
    }
    return 0;
}

int main5()
{
    int m,n;
    cin>>m>>n;
    int a=n;
    while(a<m||a==m)
    {
        if(a%n==0)
        {
            cout<<a<<' ';
            a++;
            continue;
        }
        /*int aa=a;
        while(aa/10!=0)
        {
            if(aa%10==n)
            {
                cout<<a<<' ';break;
            }
            aa/=10;
        }n可能为多位数，这个只适用于个位数*/
        string s,sn;
        sn=to_string(n);
        s=to_string(a);
        //会爆警告先注释掉if(s.find(sn)!=-1)cout<<a<<' ';//find没找到时返回-1，找到时返回所在位置
        a++;
    }
    return 0;
}

int main6()
{
    int n,m;
    cin>>n>>m;
    string s[m];
    int a[m];
    memset(a,0,sizeof(a));
    for(int i=0;i<m;i++)
    {
        cin>>s[i];
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(s[i][j]>s[i][k])a[i]++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(a[i]>a[j])
            {
                string ss=s[i];
                s[i]=s[j];
                s[j]=ss;
                int aa=a[i];
                a[i]=a[j];
                a[j]=aa;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}

int main7()
{
    double x1,y1,x2,y2,x3,y3,s;//用float精度不够
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        if(x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0) break;//要分开写条件
        double a=x2-x1,b=y3-y1,c=x3-x1,d=y2-y1;
        s=fabs(a*b-c*d)/2;//绝对值fabs为浮点型，abs为整型
        cout<<fixed<<setprecision(6)<<s<<endl;//要用fixed使输出的为浮点型，否则不会补零
    }
    return 0;
}

int main8()
{
    string s,ss,aa;
    cin>>s;
    int n=s.length();
    int b=0,a;
    ss=s.append(s);//循环，方便查找（太聪明了。。
    for(int i=2;i<=n;i++)
    {
        for(int j=n-1;j>0||j==0;j--)
        {
            a=((int)s[j]-'0')*i+b;
            b=0;
            if(a/10!=0)
            {
                b+=a/10;
                a=a%10;
            }
            //aa[j]=to_string(a);改成以下两行部分
            if(j==n-1)aa=to_string(a);
            else aa.insert(0,to_string(a));
            if(j==0&&b!=0)
            {
                //aa[n+1]=to_string(b);数据类型不匹配，会报错
                aa.append(to_string(b));
            }
        }
        //会报警告先注释掉if(ss.find(aa)==-1)
            {
                cout<<"No";
                return 0;
            }
        if(i==n)cout<<"Yes";
    }
    return 0;
}

int main9()
{
    int n,p1,p2,p3,t1,t2,a,result=0;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    int l[n],r[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        result=result+(r[i]-l[i])*p1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            a=l[j]-r[i];
            if(a<t1||a==t1)result+=a*p1;
            else if(a<t2+t1||a==t2+t1)result=result+t1*p1+(a-t1)*p2;
            else result=result+t1*p1+t2*p2+(a-t1-t2)*p3;
            break;//否则会在j里循环，算的就不是间隔时间了
        }
    }
    cout<<result;
    return 0;
}

int main10()
{
    int T;
    int k=0;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        string p;
        cin>>p;
        stringstream s(p);
        string str;
        while(getline(s,str,'.'))
        {
            int num;
            stringstream ss(str);
            ss>>num;
            while(num!=0)//条件与十位数不同
            {
                if(num%2==1)k++;
                num/=2;
            }
        }
        cout<<k<<endl;
            k=0;
    }
    return 0;
}

int main11()
{
    int N;
    while(cin>>N)
    {
        if(N==0)break;//没这条语句while(cin>>N)不会退出
        int a[N];
        float s=0;
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        s/=N;
        float result=0;
        for(int i=0;i<N;i++)
        {
            result=result+(a[i]-s)*(a[i]-s);
        }
        result/=N;
        cout<<(int)result<<endl;
    }

    return 0;
}
/*第12题size（）为无符号整型会有警告
void alloc(vector<int>& v,int n,int &x)
{
    int flag=0;//判断是否查找成功
    int st=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        {
            int num=0;//空闲字节数
            for(;i<v.size();i++)
            {
                if(v[i]==0)num++;
                else break;
                if(num==n)
                {
                    st=i;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)break;
    }
    if(flag==0)cout<<"NULL"<<endl;
    else
    {
        x++;
        for(int i=st;i>st-n;i--)v[i]=x;
        cout<<x<<endl;
    }
}

void erase(vector<int>& v,int x)
{
    bool flag=0;//用判断的类型写
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x)
        {
            v[i]=0;
            flag=1;
        }
    }
    if(!flag)cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
}

void defragment(vector<int>& v)
{
    int s=v.size();//保证长度不变
    for(int i=0;i<v.size();i++)//不能用s，长度在变会越界
    {
        if(v[i]==0)
        {
            v.erase(v.begin()+i);
            i--;//删除后更新curr
        }
    }
    while(v.size()<s)v.push_back(0);
}
int main()
{
    int t,m,n;
    cin>>t>>m;
    string s;
    vector<int> a(m);//数组长度
    int x=0;//标识符
    for(int i=0;i<m;i++)
    {
        a[i]=0;
    }
    while(t--)//t=0时退出循环
    {
        cin>>s;
        if(s=="alloc")
        {
            cin>>n;
            alloc(a,n,x);
        }
        if(s=="erase")
        {
            cin>>n;
            erase(a,n);
        }
        if(s=="defragment")
        {
            defragment(a);
        }
    }
    return 0;
}
*/
int main13()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        int b=0,c=0;
        cin>>a;
        int n=a.length();
        for(int i=n-1;i>-1;i--)
        {
            int k=(int)a[i]-'0';
            if(k>8)k-=2;
            else if(k>3)k-=1;//恢复成八进制,要用else否则会重复减
            b+=k*pow(8,c);
            c++;
        }
        cout<<b<<endl;
    }
    return 0;
}

int trans(string s)
{
    if(s=="monday")return 1;
    if(s=="tuesday")return 2;
    if(s=="wednesday")return 3;
    if(s=="thursday")return 4;
    if(s=="friday")return 5;
    if(s=="saturday")return 6;
    if(s=="sunday")return 7;
}
int main14()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,e;
        int l,r;
        cin>>s>>e>>l>>r;
        int a=trans(s),b=trans(e);
        if(b-a<0)a=b-a+8;
        else a=b-a+1;
        while(a<l)
        {
            a+=7;
        }
        if(a>r)cout<<"impossible"<<endl;
        else if(a+7>r)cout<<a<<endl;
        else cout<<"many"<<endl;
    }
    return 0;
}

struct team
{
    int mark=0;
    string name=" ";
    int num=0;
};

bool cmp(team a,team b)
{
    if(a.mark!=b.mark)return a.mark>b.mark;
    else return a.num>b.num;
}
int main15()
{
    int t;
    cin>>t;
    string n1,n2,useless;
    int m1,m2;
    team a[4];
    while(t--)
    {
        int k=0;
        for(int i=0;i<12;i++)
        {
            cin>>n1>>m1>>useless>>m2>>n2;
            if(k==0)
    {
    a[k].name=n1;
    if(m1>m2)a[k].mark+=3;
                else if(m1==m2)a[k].mark+=1;
    a[k].num+=(m1-m2);
    k++;
    a[k].name=n2;
    if(m1<m2)a[k].mark+=3;
                else if(m1==m2)a[k].mark+=1;
    a[k].num=(m2-m1);
    k++;
    }
    else
    {
        int s=0;
        for(int j=0;j<k;j++)//设置一个退出操作，否则两个值都赋完了还不退出
        {
            if(a[j].name==n1)
            {
                if(m1>m2)a[j].mark+=3;
                else if(m1==m2)a[j].mark+=1;
                a[j].num+=(m1-m2);
                s++;
            }
            //else没考虑完，应该有3种情况，缺了继续向后判断的操作
            else if(k!=4)
            {
                a[k].name=n1;
                if(m1>m2)a[k].mark+=3;
                else if(m1==m2)a[k].mark+=1;
                a[k].num+=(m1-m2);
                k++;
                s++;
            }
            if(a[j].name==n2)
            {
                if(m1<m2)a[j].mark+=3;
                else if(m1==m2)a[j].mark+=1;
                a[j].num+=(m2-m1);
                s++;
            }
            else if(k!=4)
            {
                a[k].name=n2;
                if(m1<m2)a[k].mark+=3;
                else if(m1==m2)a[k].mark+=1;
                a[k].num+=(m2-m1);
                k++;
                s++;
            }
            if(s==2)break;
        }
    }

        }
        sort(a,a+4,cmp);
        cout<<a[0].name<<' '<<a[1].name<<endl;
        for(int j=0;j<4;j++)
        {
            a[j].name=" ";
            a[j].num=0;
            a[j].mark=0;
        }
    }
    return 0;
}


int k=0;
stack<char> a;
/*void legal(char c,char b,string s,int i)//怎么写成函数？？
{
    if(s[i]=='c')
            {if(a.empty())//判断是否栈空
                {
                    cout<<"No"<<endl;
                    k=1;//已经输出no的标识
                    break;//若写成函数，函数里面没有循环，不能用break
                }
                else if(a.top()=='b')
                {
                    a.pop();
                    continue;//跳过入栈过程
                }
                else
                {
                    cout<<"No"<<endl;
                    while(!a.empty())a.pop();//清空栈
                    k=1;
                    break;
                }
            }
}*/
int main16()
{
    int t;
    cin>>t;

    string s;
    while(t--)
    {
        cin>>s;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='>')
            {if(a.empty())//判断是否栈空
                {
                    cout<<"No"<<endl;
                    k=1;//已经输出no的标识
                    break;
                }
                else if(a.top()=='<')
                {
                    a.pop();
                    continue;//跳过入栈过程
                }
                else
                {
                    cout<<"No"<<endl;
                    while(!a.empty())a.pop();//清空栈
                    k=1;
                    break;
                }
                //legal('>','<',s,i);
            }
            if(s[i]==']')
            {
                if(a.empty())
                {
                    cout<<"No"<<endl;
                    k=1;
                    break;
                }
                else if(a.top()=='[')
                    {
                    a.pop();
                    continue;
                }
                else
                {
                    cout<<"No"<<endl;
                    while(!a.empty())a.pop();
                    k=1;
                    break;
                }
            }
            if(s[i]=='}')
            {if(a.empty())
                {
                    cout<<"No"<<endl;
                    k=1;
                    break;
                }
                else if(a.top()=='{')
                    {
                    a.pop();
                    continue;
                }
                else
                {
                    cout<<"No"<<endl;
                    while(!a.empty())a.pop();
                    k=1;
                    break;
                }
            }
            if(s[i]==')')
            {if(a.empty())
                {
                    cout<<"No"<<endl;
                    k=1;
                    break;
                }
                else if(a.top()=='(')
                    {
                    a.pop();
                    continue;
                }
                else
                {
                    cout<<"No"<<endl;
                    while(!a.empty())a.pop();
                    k=1;
                    break;
                }
            }
           /* if(s.[i]==')')legal('(',')');
            if(s.[i]==']')legal('[',']');
            if(s.[i]=='}')legal('{','}');*/
            a.push(s[i]);
        }
        if(k==0&&a.empty())
        {
            cout<<"Yes"<<endl;
            while(!a.empty())a.pop();
        }
        else if(k==0)
        {
            cout<<"No"<<endl;//考虑只有左括号的情况
            while(!a.empty())a.pop();
        }

        else k=0;
    }
    return 0;
}

struct football
{
    int mark=0;
    string name;
    int winnum=0;
    int num=0;
};

bool cmp1(football &a,football &b)
{
    if(a.mark!=b.mark)return a.mark>b.mark;
    else if(a.winnum!=b.winnum)return a.winnum>b.winnum;
    else return a.num>b.num;
}

bool cmp2(football &a,football &b)
{
    return a.name<b.name;
}

int transf(string str)
{
    if(str=="0")return 0;

}
int main17()
{
    int n;
    string s,g;
    int a,b,c,d;
    cin>>n;
    football k[n];
    int m=n*(n-1)/2;
    for(int i=0;i<n;i++)
    {
        cin>>k[i].name;
    }
    while(m--)
    {
        cin>>s>>g;
        stringstream ss(s),gg(g);
        string str;
        int h=0;
        while(getline(gg,str,':'))
        {
            if(h==0)
            {
                stringstream str1(str);
                str1>>c;
                //c=(int)str-'0';不能强制转化，应该用流来转化
                h++;
                continue;
            }
            if(h==1)
            {
                stringstream str2(str);
                str2>>d;
                //d=(int)str-'0';
                break;
            }
        }
        if(c>d)a=3;
        else if(c==d)a=1;
        else a=0;
        if(c<d)b=3;
        else if(c==d)b=1;
        else b=0;
        int p=0;
        while(getline(ss,str,'-'))
        {
            for(int i=0;i<n;i++)
            {
                if(str==k[i].name&&p==0)
                {
                    k[i].mark+=a;
                    k[i].winnum+=(c-d);
                    k[i].num+=c;
                    p++;
                    break;//退出查找
                }
                if(str==k[i].name&&p==1)
                {
                    k[i].mark+=b;
                    k[i].winnum+=(d-c);
                    k[i].num+=d;
                    break;
                }
            }
        }
    }
    sort(k,k+n,cmp1);
    sort(k,k+n/2,cmp2);
    for(int i=0;i<n/2;i++)
    {
        cout<<k[i].name<<endl;
    }
    return 0;
}

int kk=0;

struct car
{
    string name="";
    int mark=0;
    int num[101]={0};//将数组初始化为0
    //memset(num,0,sizeof(num))报错
};

int transfo(int rankk)
{
    if(rankk==1)return 25;
    if(rankk==2)return 18;
    if(rankk==3)return 15;
    if(rankk==4)return 12;
    if(rankk==5)return 10;
    if(rankk==6)return 8;
    if(rankk==7)return 6;
    if(rankk==8)return 4;
    if(rankk==9)return 2;
    if(rankk==10)return 1;
}

bool cmpp1(car& a,car& b)
{
    if(a.mark!=b.mark)return a.mark>b.mark;
    for(int i=1;i<kk+1;i++)
    {
        if(a.num[i]!=b.num[i])return a.num[i]>b.num[i];
    }
}

bool cmpp2(car& a,car& b)
{
    if(a.num[1]!=b.num[1])return a.num[1]>b.num[1];
    else if(a.mark!=b.mark)return a.mark>b.mark;
    for(int i=2;i<kk+1;i++)
    {
        if(a.num[i]!=b.num[i])return a.num[i]>b.num[i];
    }
}
int main18()
{
    int t;
    cin>>t;
    car a[100];
    string s;
    while(t--)
    {
        int n;
        cin>>n;
        int rankk=1;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            int flag=0;//判断是否找到车手
            for(int j=0;j<kk;j++)
            {
                if(a[j].name==s)
                {
                    a[j].mark+=transfo(rankk);
                    a[j].num[rankk]++;
                    rankk++;
                    flag=1;
                    break;
                }
            }
            if(kk==0)
            {
                a[kk].name=s;
                a[kk].mark+=transfo(rankk);
                a[kk].num[rankk]++;
                rankk++;
                kk++;
            }
            else if(flag==0)
            {
                kk++;
                a[kk].name=s;
                a[kk].mark+=transfo(rankk);
                a[kk].num[rankk]++;
                rankk++;
            }
        }
    }
    sort(a,a+kk,cmpp1);
    cout<<a[0].name<<endl;
    sort(a,a+kk,cmpp2);
    cout<<a[0].name<<endl;
    return 0;
}

int main21()
{
    int t;
    cin>>t;
    while(t--)
    {
        int B;
        string N;
        cin>>B>>N;
        int n=N.length();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(N[i]<='9')
            sum+=((int)N[i]-'0');
            else if(N[i]=='a')sum+=10;
            else if(N[i]=='b')sum+=11;
            else if(N[i]=='c')sum+=12;
            else if(N[i]=='d')sum+=13;
            else if(N[i]=='e')sum+=14;
            else if(N[i]=='f')sum+=15;
        }
        for(int i=0;i<B;i++)
        {
            if((sum+i)%(B-1)==0)
            {
                if(i<10)
                {
                    cout<<i<<endl;
                    break;
                }
                else if(i==10){
                    cout<<'a'<<endl;
                    break;
                }
                else if(i==11){
                    cout<<'b'<<endl;
                    break;
                }
                else if(i==12){
                    cout<<'c'<<endl;
                    break;
                }
                else if(i==13){
                    cout<<'d'<<endl;
                    break;
                }
                else if(i==14){
                    cout<<'e'<<endl;
                    break;
                }
                else if(i==15){
                    cout<<'f'<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}

void dfs(string in,string fro)
{
    if(in.empty()||fro.empty())//边界
        return;
    char root=fro[0];
    int rootpos=in.find(root);
    dfs(in.substr(0,rootpos),fro.substr(1,rootpos));//左子树递归
    dfs(in.substr(rootpos+1),fro.substr(rootpos+1));//右子树递归
    cout<<root;
}
int main1827()
{
    string in,fro;
    cin>>in>>fro;
    dfs(in,fro);
    return 0;
}

void dfs1(string in,string pos)
{
    if(in.empty()||pos.empty())
        return;
    char root=pos.back();
    int rootpos=in.find(root);
    pos.pop_back();
    cout<<root;
    dfs1(in.substr(0,rootpos),pos.substr(0,rootpos));
    dfs1(in.substr(rootpos+1),pos.substr(rootpos));
}

int mainp()
{
    string in,pos;
    cin>>in>>pos;
    dfs1(in,pos);
    return 0;
}
int main20()
{
    int n;
    while(cin>>n&&n)
    {
        string in,fro;
        cin>>fro>>in;
        dfs(in,fro);
        cout<<endl;
    }
    return 0;
}

struct tree
{
    int num=0;
    int left=0;
    int right=0;
};

tree b[10000000];
void in(tree a)
{
    int root=a.num;
    cout<<root<<' ';
    if(a.left!=0)
       in(b[a.left]);
    if(a.right!=0)
    in(b[a.right]);
}

void zhong(tree a)
{
    int root=a.num;
    if(a.left!=0)
        zhong(b[a.left]);
    cout<<root<<' ';
    if(a.right!=0)
        zhong(b[a.right]);
}

void hou(tree a)
{
    int root=a.num;
    if(a.left!=0)
        hou(b[a.left]);
    if(a.right!=0)
        hou(b[a.right]);
    cout<<root<<' ';
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].left>>b[i].right;
        b[i].num=i;
    }
    in(b[1]);
    cout<<endl;
    zhong(b[1]);
    cout<<endl;
    hou(b[1]);
    return 0;
}
