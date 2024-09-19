#include <bits/stdc++.h>

using namespace std;

int main1()
{
    string a,b;
    char aa,bb;
    cin>>a>>aa>>b>>bb;
    int na=a.length();
    int nb=b.length();
    int ta=0,tb=0;
    for(int i=0;i<na;i++)
    {
        if(a[i]==aa)ta++;
    }
    for(int i=0;i<nb;i++)
    {
        if(b[i]==bb)tb++;
    }
    int sa=0,sb=0;
    for(int i=0;i<ta;i++)
    {
        sa=sa*10+(int)aa-'0';
    }
    for(int i=0;i<tb;i++)
    {
        sb=sb*10+(int)bb-'0';
    }
    cout<<sa+sb;
    return 0;
}

int main2()
{
    map<char,int>m;
    string s="";
    string a;
    cin>>a;
    int n=a.length();
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i])==string::npos)
        {
            m.insert(pair<char,int>(a[i],1));
            s+=a[i];
        }
        else m[a[i]]++;
    }
    map<char,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<':'<<it->second<<endl;
    }
    return 0;
}

int main3()
{
    string a;
    int b;
    cin>>a>>b;
    int s=0;
    string p="";
    for(unsigned int i=0;i<a.length();i++)
    {
        s=s*10+(int)a[i]-'0';
        if(s<b&&i+1<a.length())
        {
            i++;
            s=s*10+(int)a[i]-'0';
            if(i!=1)p+=(char)(0+'0');
        }
        int k=s/b;
        p+=(char)(k+'0');
        s=s-k*b;
    }
    cout<<p<<' '<<s;
    return 0;
}

int main4()
{
    int n=0,w;
    int*a=new int[n];
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x=0,y=0;//初始化要注意，否则如果没更新，初始化的值会影响结果
    int temp=0;
    for(int i=0;i<n;i++)
    {
        temp+=a[i];
        if(temp>x)x=temp;
        if(temp<y)y=temp;
    }
    if(y>0&&w-x-y+1>0){cout<<w-x-y+1;return 0;}
    if(y<=0&&w-x+y+1>0){cout<<w-x+y+1;return 0;}
    cout<<0;
    return 0;
}

struct ST
{
    string name;
    string id;
    int grade;
};
bool cmp1(ST& a,ST& b)
{
    return a.grade>b.grade;
}
int main5()
{
    int n;
    cin>>n;
    ST*a=new ST[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].id>>a[i].grade;
    }
    sort(a,a+n,cmp1);
    cout<<a[0].name<<' '<<a[0].id<<endl<<a[n-1].name<<' '<<a[n-1].id;
    return 0;
}

    int a[10];

void tra(char b,string& s)
{
    if(s.find(b)!=string::npos)
    {
        if(b=='0')
            {s.replace(s.find(b),1,"(Zero)");
        a[0]++;}
        if(b=='1'){s.replace(s.find(b),1,"(One)");a[1]++;}
        if(b=='2'){s.replace(s.find(b),1,"(Two)");a[2]++;}
        if(b=='3'){s.replace(s.find(b),1,"(Three)");a[3]++;}
        if(b=='4'){s.replace(s.find(b),1,"(Four)");a[4]++;}
        if(b=='5'){s.replace(s.find(b),1,"(Five)");a[5]++;}
        if(b=='6'){s.replace(s.find(b),1,"(Six)");a[6]++;}
        if(b=='7'){s.replace(s.find(b),1,"(Seven)");a[7]++;}
        if(b=='8'){s.replace(s.find(b),1,"(Eight)");a[8]++;}
        if(b=='9'){s.replace(s.find(b),1,"(Nine)");a[9]++;}
    }
}
int main6()
{
    memset(a,0,sizeof(a[0])*10);//函数只能放在main函数里？？放外面会报错
    string s;
    getline(cin,s);

        while(s.find('0')!=string::npos)
        {
            tra('0',s);
        }
while(s.find('1')!=string::npos)
        {
            tra('1',s);
        }while(s.find('2')!=string::npos)
        {
            tra('2',s);
        }

while(s.find('3')!=string::npos)
        {
            tra('3',s);
        }
        while(s.find('4')!=string::npos)
        {
            tra('4',s);
        }
while(s.find('5')!=string::npos)
        {
            tra('5',s);
        }
while(s.find('6')!=string::npos)
        {
            tra('6',s);
        }
while(s.find('7')!=string::npos)
        {
            tra('7',s);
        }
while(s.find('8')!=string::npos)
        {
            tra('8',s);
        }
while(s.find('9')!=string::npos)
        {
            tra('9',s);
        }


    cout<<s<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}

int main7()
{
    string n;
    cin>>n;
    int a=n.length();
    int sum=0;
    for(int i=0;i<a;i++)
    {
        sum+=((int)n[i]-'0');
    }
    stack<int>b;
    while(sum>9)
    {
        b.push(sum%10);
        sum/=10;
    }
    b.push(sum);
    while(!b.empty())
    {
        if(b.top()==0)
        {
            cout<<"ling"<<' ';
        }
        if(b.top()==1)
        {
            cout<<"yi"<<' ';
        }
        if(b.top()==2)
        {
            cout<<"er"<<' ';
        }
        if(b.top()==3)
        {
            cout<<"san"<<' ';
        }
        if(b.top()==4)
        {
            cout<<"si"<<' ';
        }
        if(b.top()==5)
        {
            cout<<"wu"<<' ';
        }
        if(b.top()==6)
        {
            cout<<"liu"<<' ';
        }
        if(b.top()==7)
        {
            cout<<"qi"<<' ';
        }
        if(b.top()==8)
        {
            cout<<"ba"<<' ';
        }
        if(b.top()==9)
        {
            cout<<"jiu"<<' ';
        }
        b.pop();
    }
    return 0;
}

int main8()
{
    int a[128]={0},b[128]={0};//用ASCII表示并初始化
    string s;
    cin>>s;
    for(unsigned int i=0;i<s.length();i++)
    {
        //a[s[i]]++;
        a[static_cast<int>(s[i])]++;
    }
    string s2;
    cin>>s2;
    for(unsigned int i=0;i<s2.length();i++)
    {
        //b[s2[i]]++;
        b[static_cast<int>(s2[i])]++;
    }
    int sum1=0,sum2=0;
    for(int i=0;i<128;i++)
    {
        if(a[i]>b[i])sum1+=(a[i]-b[i]);
        if(a[i]<b[i])sum2+=(b[i]-a[i]);
    }
    if(sum2==0)cout<<"Yes"<<' '<<sum1;
    else cout<<"No"<<' '<<sum2;
    return 0;
}

int main9()
{
    int n;
    cin>>n;
    map<int,int>mp;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(mp.find(a)!=mp.end())
        {
            mp[a]+=b;
        }
        else mp[a]=b;
    }
    int aa=0,bb=0;
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>bb)
        {
            bb=it->second;
            aa=it->first;
        }
    }
    cout<<aa<<' '<<bb;
    return 0;
}

struct rule{
 bool operator()(int a,int b){
    return a>b;
 }
};

int main10()
{
    int a,b;
    map<int,int,rule>mp;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)break;
        if(mp.find(a)!=mp.end())
        {
            mp[a]+=b;
        }
        else mp[a]=b;
    }
    while(cin>>a>>b)
    {
        if(a==0&&b==0)break;
        if(mp.find(a)!=mp.end())
        {
            mp[a]+=b;
        }
        else mp[a]=b;
    }
    map<int,int,rule>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second!=0)//计算后可能该项为0
            cout<<it->first<<' '<<it->second<<endl;
    }
    return 0;
}

string tran1(int temp)
{
    string res;
    if(temp==0)
        res="1110111";
    else if(temp==1)
        res="0010010";
    else if(temp==2)
        res="1011101";
    else if(temp==3)
        res="1011011";
    else if(temp==4)
        res="0111010";
    else if(temp==5)
        res="1101011";
    else if(temp==6)
        res="1101111";
    else if(temp==7)
        res="1010010";
    else if(temp==8)
        res="1111111";
    else if(temp==9)
            res="1111011";
    return res;
}

string tran2(string a,string b)
{
    string res="0000000";
    for(int i=0;i<7;i++)
    {
        if(a[i]=='1'&&b[i]=='1')
            res[i]='1';
    }
    return res;
}
int main11()//利用位运算----思想
{
    int a[10];
    string s[10];
    while(1)
    {
        for(int i=0;i<10;i++)
        {
            cin>>a[i];
            if(a[0]==-1)
                break;
            s[i]=tran1(a[i]);
        }
        if(a[0]==-1)
            break;
       int num=0;
       for(int i=0;i<9;i++)
       {
           string temp=tran2(s[i],s[i+1]);
           if(s[i]==temp||s[i+1]==temp)
            num++;
       }
       if(num==9)
        cout<<"YES"<<endl;
       else
        cout<<"NO"<<endl;
    }
    return 0;
}

int day1(string s)
{
    int day=0;
    if(s=="pop")
        day=0;
    else if(s=="no")
        day=20;
    else if(s=="zip")
        day=40;
    else if(s=="zotz")
        day=60;
    else if(s=="tzec")
        day=80;
    else if(s=="xul")
        day=100;
    else if(s=="yoxkin")
        day=120;
    else if(s=="mol")
        day=140;
    else if(s=="chen")
        day=160;
    else if(s=="yax")
        day=180;
    else if(s=="zac")
        day=200;
    else if(s=="ceh")
        day=220;
    else if(s=="mac")
        day=240;
    else if(s=="kankin")
        day=260;
    else if(s=="muan")
        day=280;
    else if(s=="pax")
        day=300;
    else if(s=="koyab")
        day=320;
    else if(s=="cumhu")
        day=340;
    else if(s=="uayet")
        day=360;
    return day;
}

string mon(int a)
{
    int n=a-1;
    string m;
    if(n==0)
        m="imix";
    else if(n==1)
        m="ik";
    else if(n==2)
        m="akbal";
    else if(n==3)
        m="kan";
    else if(n==4)
        m="chicchan";
    else if(n==5)
        m="cimi";
    else if(n==6)
        m="manik";
    else if(n==7)
        m="lamat";
    else if(n==8)
        m="muluk";
    else if(n==9)
        m="ok";
    else if(n==10)
        m="chuen";
    else if(n==11)
        m="eb";
    else if(n==12)
        m="ben";
    else if(n==13)
        m="ix";
    else if(n==14)
        m="mem";
    else if(n==15)
        m="cib";
    else if(n==16)
        m="caban";
    else if(n==17)
        m="eznab";
    else if(n==18)
        m="canac";
    else if(n==19)
        m="ahau";
    return m;
}
int main12()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int day=0;
        string s1;
        int a1;
        cin>>s1>>a1;
        stringstream ss(s1);
        string str;
        int flag=0;
        while(getline(ss,str,'.'))
        {
            if(flag==0)
            {
                stringstream p(str);
                p>>day;
                day++;
                flag++;
            }
            else
            {
                day+=day1(str);
            }
        }
        day+=(a1*365);
        int year=day/260;
        int date=day%13;
        if(date==0)//输出格式不正确，不输出0而是输出13
            date=13;
        string mont=mon(day%20);
        cout<<date<<' '<<mont<<' '<<year<<endl;
    }
    return 0;
}

int main13()//动态规划
{
    int k=0;
    cin>>k;
    vector<int> a(k);//用vector更好，且是用（）而不是中括号
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    vector<int> b(k,1);
    for(int i=1;i<k;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>=a[i])
                b[i]=max(b[i],b[j]+1);
        }
    }
    int mh=*max_element(b.begin(),b.end());
    cout<<mh;

    return 0;
}

int main14()
{
    map<string,string>m;
    string a,b,c;
    while(1)
    {
        getline(cin,a);//魔咒内也可能有空格
        if(a=="@END@")
            break;
        c=a.substr(0,a.find(']')+1);
        int h=a.length()-c.length()-1;
        b=a.substr(a.find(']')+2,h);
        m[c]=b;
    }
    int n;
    cin>>n;
    map<string,string>::iterator it;
    cin.ignore();
    while(n--)
    {
        string s;
        getline(cin,s);
        int flag=0;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->first.find(s)!=string::npos)
            {
                cout<<it->second<<endl;
                flag++;
                break;
            }
            else if(it->second.find(s)!=string::npos)
            {
                int k=it->first.length();
                for(int i=1;i<k-1;i++)
                {
                    cout<<it->first[i];
                }
                cout<<endl;
                flag++;
                break;
            }
        }
        if(flag==0)
            cout<<"what?"<<endl;
    }
    return 0;
}

int main15()
{
    string s;
    cin>>s;
    int a[10];
    memset(a,0,sizeof(a));
    for(unsigned int i=0;i<s.length();i++)
    {
        int k=(int)s[i]-'0';
        a[k]++;
    }
    int t;
    while(cin>>t)
    {
        int flag=0;
        if(t<10)
        {
            for(int i=t+1;i<10;i++)
            {
                if(a[i]>0)
                {
                    if(flag==0)
                        {
                            flag++;
                            cout<<"YES"<<' ';
                        }
                    cout<<i<<' ';
                }
            }
        }
        else if(t<100)
        {
            for(int i=t%10+1;i<10;i++)
            {
                if(a[i]>1)
                {
                    if(flag==0)
                    {
                        flag++;
                        cout<<"YES"<<' ';
                    }
                    cout<<i<<i<<' ';
                }
            }
        }
        else if(t<1000)
        {
            for(int i=t%10+1;i<10;i++)
            {
                if(a[i]>2)
                {
                    if(flag==0)
                    {
                        flag++;
                        cout<<"YES"<<' ';
                    }
                    cout<<i<<i<<i<<' ';
                }
            }
        }
        else if(t<10000)
        {
            for(int i=t%10+1;i<10;i++)
            {
                if(a[i]>3)
                {
                    if(flag==0)
                    {
                        flag++;
                        cout<<"YES"<<' ';
                    }
                    cout<<i<<i<<i<<i<<' ';
                }
            }
        }
        else
        {
            for(int i=t/10000+1;i+4<10;i++)
            {
                if(a[i]>0&&a[i+1]>0&&a[i+2]>0&&a[i+3]>0&&a[i+4]>0)
                {
                    if(flag==0)
                    {
                        flag++;
                        cout<<"YES"<<' ';
                    }
                    cout<<i<<i+1<<i+2<<i+3<<i+4<<' ';
                }
            }
        }
        if(flag==0)
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}

int main16()//0-1背包问题
{
    double q=0;
    int n=1;
    while(cin>>q>>n)
    {
        if(n==0)
            break;
        vector<int> price(n);
        int qq=(int)(q*100);
        vector<int> maxp(qq+1);
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                string s;
                cin>>s;
                string str;
                stringstream ss(s);
                int flag=0;
                int p=0;
                while(getline(ss,str,':'))
                {
                    if(flag==0)
                    {
                        if(str!="A"&&str!="B"&&str!="C")
                        {
                            flag=2;
                        }
                        else
                            flag++;
                    }
                    else
                    {
                        if(str.length()>3)str.erase(str.end()-3);//考虑输入整数时没有.00
                        else str.append("00");
                        stringstream pp(str);
                        pp>>p;
                    }
                }
                if(p>60000)flag=2;
                price[i]+=p;
                if(flag==2)
                {
                    price[i]=0;
                    break;
                }
            }
            if(price[i]>100000)
                price[i]=0;
        }
        /*for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(maxp[i]+maxp[j]<=q)
                    maxp[i]=max(maxp[i],maxp[i]+maxp[j]);
                cout<<maxp[i]<<' '<<maxp[j]<<endl;
            }
        }*/
        for(int i=0;i<n;i++)
        {
            for(int j=qq;j>=price[i];j--)//滚动数组，从后开始算
            {
                if(price[i]==0)
                    break;
                if(maxp[j-price[i]]+price[i]<=qq)
                maxp[j]=max(maxp[j],maxp[j-price[i]]+price[i]);
            }
        }
        string res = to_string(maxp[qq]);
        if(res.length()>3)//要考虑为0时，没有足够的数字长度
            {
                res.insert(res.end() - 2, '.');
                cout << res << endl;
            }
        else
        {
            cout<<res<<'.'<<"00"<<endl;
        }
    }
    return 0;
}

int main122()
{
    double a;
    int b;
    while(cin>>a>>b)
    {
        cout<<a<<' '<<b<<endl;
    if(b==0)break;
    for(int i=0;i<b;i++)
    {

        int k;
        cin>>k;
        string s;
        cin.ignore();
        getline(cin,s);
        cout<<k<<' '<<s<<endl;
    }
    }
    return 0;
}

int main17()//暴力计算最大差值
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int sum=0;
        int all=0,used=0;
        int n=s1.length();
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='?')
                all++;
        }
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='?')//若为？则将其看成9计算最大差值
            {
                used++;
                sum+=pow(10,all-used)*(9-s2[i]+'0');
            }
            else if(s1[i]>s2[i])
            {
                sum+=pow(10,all-used);
                break;
            }
            else if(s1[i]<s2[i])
            {
                break;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

int main18()//只用计算B左边的数据，不用全部计算
{
    string s;
    while(cin>>s)
    {
        stack<char>az;
        int flag=0;
        for(int i=0;i<(int)s.length();i++)
        {
            if(s[i]=='B')
                flag++;
            if(flag==0)
            {
                if(s[i]=='(')
                   az.push('(');
                else
                   az.pop();
            }
            else
            {
                cout<<az.size()<<endl;
                break;
            }
        }
    }
    return 0;
}

int main19()//前缀和
{
    string s;
    cin>>s;
    int n=s.length();
    vector<int>a(n);
    vector<int>b(n);
    a[0]=(s[0]=='a')?1:0;
    b[0]=(s[0]=='b')?1:0;
    for(int i=1;i<n;i++)
    {
        a[i]=(s[i]=='a')?a[i-1]+1:a[i-1];
        b[i]=(s[i]=='b')?b[i-1]+1:b[i-1];
    }
    if(a[n-1]==0)//全为b时
    {
        cout<<b[n-1]<<endl;
        return 0;
    }
    else if(b[n-1]==0)
        {
            cout<<a[n-1]<<endl;
            return 0;
        }
    int ml=0,ans=0;
    for(int i=0;i<n;i++)//遍历中间子串b的长度-b起点
    {
        for(int j=i+1;j<n;j++)//b终点
        {
            if(i==0)
                ans=a[i]+a[n-1]-a[j]+b[j];//b数量+a数量（前+后）
            else
                ans=a[i-1]+a[n-1]-a[j]+b[j]-b[i-1];
            if(ans>ml)
                ml=ans;
        }
    }
    cout<<ml<<endl;
}

int main()
{
    int n=0,m=0,k=0;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {

    }
    return 0;
}
