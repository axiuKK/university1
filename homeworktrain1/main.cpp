#include <bits/stdc++.h>

using namespace std;

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

int main2()//开关与灯（前缀和）
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

int main4()//字符串反转3（reverse,cin.get()的运用）
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

int main5()//n,还是n（字符串查找->数字极大时）
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
        if(s.find(sn)!=string::npos)cout<<a<<' ';//find没找到时返回-1，找到时返回所在位置
        a++;
    }
    return 0;
}

int main7()//三角形的面积（公式）
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

int main8()//循环数
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
        if(ss.find(aa)==string::npos)
            {
                cout<<"No";
                return 0;
            }
        if(i==n)cout<<"Yes";
    }
    return 0;
}

int main13()//错误的里程表（8进制）
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

//19.买方与选房--不会写（文件读写）

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

int main()
{
    string in,pos;
    cin>>in>>pos;
    dfs1(in,pos);
    return 0;
}
int main20()//二叉树遍历，从前序、中序到后序
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

int main99()
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
