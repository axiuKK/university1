#include <bits/stdc++.h>

using namespace std;


int main011()
{
    string s;
    while(getline(cin,s)&&!s.empty())
    {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string str;
        while(ss>>str)
        {
            reverse(str.begin(),str.end());
            cout<<str<<' ';
        }
        cout<<endl;
    }
    return 0;
}

int main012()
{
    stack<string> a;
    string s;
    while(cin>>s)//ctrlz退出
    {

        a.push(s);//写在前面，mi+\n会被一起读入
        if(cin.get()=='\n')
        {
            while(!a.empty())
        {
            cout<<a.top()<<' ';
            a.pop();
        }
            cout<<endl;
        }
    }
    return 0;
}

struct st
{
    int id;
    int t;
    int s;
    int flag=0;
};

bool cmp(st& a,st& b)
{
    if(a.t!=b.t)return a.t<b.t;
    else return a.s>b.s;
}

bool cmp1(st& a,st& b)
{
    return a.id<b.id;
}
int main0()//测试一第二题
{
    int n;
    cin>>n;
    st*a=new st[n];//一定要定义成动态数组，否则n太大会输出错误
    for(int i=0;i<n;i++)
    {
        cin>>a[i].t>>a[i].s;
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);
    int smax=a[0].s;
    int tm=a[0].t;
    for(int i=0;i<n;i++)
    {
        if(a[i].s<smax&&i!=0)a[i].flag=1;
        if(a[i].s==smax&&a[i].t!=tm)a[i].flag=1;
        if(a[i].s>smax){smax=a[i].s;tm=a[i].t;}
    }
    sort(a,a+n,cmp1);
    for(int i=0;i<n;i++)
    {
        if(a[i].flag==0)cout<<a[i].id<<endl;
    }
    return 0;
}

int main2()
{
    int n;
    while(cin>>n)
    {
        if(n==0)return 0;
        int k=0;
        while(n!=1)
        {
            if(n%2==0)
        {
            n/=2;
            k++;
        }
        else{
            n=3*n+1;
            n/=2;
            k++;
        }
        }

        cout<<k<<endl;
    }

    return 0;
}

int main3()
{
    int n;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int Max=a[n-1],Min=a[0];
    int s=abs(abs(a[0]-Max)-(a[0]-Min));
    int sm=s;
    int k=0;
    for(int i=1;i<n;i++)
    {
        s=abs(abs(a[i]-Max)-(a[i]-Min));
        if(s<sm){k=i;sm=s;}
    }
    cout<<a[k];
    return 0;
}

int main4()
{
    int A,B;
    while(cin>>A>>B)
    {
        int sum=0;
        for(int i=1;i<A;i++)
        {
            if(A%i==0)sum+=i;
        }
        if(sum!=B)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sum=0;
        for(int i=1;i<B;i++)
        {
            if(B%i==0)sum+=i;
        }
        if(sum==A)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

int main5()
{
    int n;
    while(cin>>n)
    {
        int sum=0;
        int day=0;
        for(int i=1;i<=n;i++)
        {
            int m=i;
            for(int k=1;k<=m;k++)
            {
                sum+=m;
                day++;
                if(day==n)break;
            }
            if(day==n)break;
        }
        cout<<day<<' '<<sum<<endl;
    }
    return 0;
}

int tran(char s)
{
    if(s=='a')return 0;
    if(s=='b')return 1;
    if(s=='c')return 2;
    if(s=='d')return 3;
    if(s=='e')return 4;
    if(s=='f')return 5;
    if(s=='g')return 6;
    if(s=='h')return 7;
    if(s=='i')return 8;
    if(s=='j')return 9;
    if(s=='k')return 10;
    if(s=='l')return 11;
    if(s=='m')return 12;
    if(s=='n')return 13;
    if(s=='o')return 14;
    if(s=='p')return 15;
    if(s=='q')return 16;
    if(s=='r')return 17;
    if(s=='s')return 18;
    if(s=='t')return 19;
    if(s=='u')return 20;
    if(s=='v')return 21;
    if(s=='w')return 22;
    if(s=='x')return 23;
    if(s=='y')return 24;
    if(s=='z')return 25;
}

char ftran(int a)
{
    if(a==0)return 'a';
    if(a==1)return 'b';
    if(a==2)return 'c';
    if(a==3)return 'd';
    if(a==4)return 'e';
    if(a==5)return 'f';
    if(a==6)return 'g';
    if(a==7)return 'h';
    if(a==8)return 'i';
    if(a==9)return 'j';
    if(a==10)return 'k';
    if(a==11)return 'l';
    if(a==12)return 'm';
    if(a==13)return 'n';
    if(a==14)return 'o';
    if(a==15)return 'p';
    if(a==16)return 'q';
    if(a==17)return 'r';
    if(a==18)return 's';
    if(a==19)return 't';
    if(a==20)return 'u';
    if(a==21)return 'v';
    if(a==22)return 'w';
    if(a==23)return 'x';
    if(a==24)return 'y';
    if(a==25)return 'z';
}
int main6()
{
    int N;
    cin>>N;
    stack<char> p;
    while(N--)
    {
        string x,y;
        cin>>x>>y;
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        int n=x.length();//更短的字符
        int m=y.length();
        int k=0;
        //警告if(y.length()<n)
        {
            n=m;
            m=x.length();
            k=1;
        }
        int b=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum=tran(x[i])+tran(y[i])+b;
            b=0;
            while(sum>25)
            {
                b++;
                sum-=26;
            }
            p.push(ftran(sum));
        }
        if(k==0)
        {
            for(int i=n;i<m;i++)
            {
                sum=tran(y[i])+b;
                b=0;
                while(sum>25)
            {
                b++;
                sum-=26;
            }
            p.push(ftran(sum));
            }
            if(b!=0)p.push(ftran(b));
        }
        else
        {
            for(int i=n;i<m;i++)
            {
                sum=tran(x[i])+b;
                b=0;
                while(sum>25)
            {
                b++;
                sum-=26;
            }
            p.push(ftran(sum));
            }
            if(b!=0)p.push(ftran(b));
        }
        while(!p.empty())
        {
            cout<<p.top();
            p.pop();
        }
        cout<<endl;
    }
    return 0;
}

int main7()
{
    int n=0;
    int p=1;
    while(cin>>n)
    {
        if(n==0)break;
        cout<<"set-"<<p<<endl;
        string*s1=new string[n];
        string*s2=new string[n];
        for(int i=0;i<n;i++)
        {
            cin>>s1[i];
        }
        int k=0;
        for(int i=0;i<n;i+=2)
        {
            if(i+1<n)
            {
                s2[k]=s1[i];
                s2[n-1-k]=s1[i+1];
                k++;
            }
            if(i+1==n) {s2[k]=s1[i];break;}
        }
        for(int i=0;i<n;i++)
        {
            cout<<s2[i]<<endl;
        }
        p++;
    }
    return 0;
}

int main8()
{
    int n;
    cin>>n;
    int a[n+2][n+2];//加边框***
    for(int i=0;i<n+2;i++)
        {
            for(int j=0;j<n+2;j++)
            {
                a[i][j]=0;
            }
        }
    for(int i=0;i<n+2;i++)
    {
        a[i][0]=-1;
        a[i][n+1]=-1;
    }
    for(int j=0;j<n+2;j++)
        {
            a[0][j]=-1;
            a[n+1][j]=-1;
        }
        int x=1,y=1,value=n*n;
        string dir;
        if(n%2==1)//奇数
        {
            x=1;
            y=n;
            dir="left";
        }
        else
            {
                x=n;
                y=1;
                dir="right";
            }
        while(value>0)
        {
            a[x][y]=value;
            value--;
            if(dir=="left")
            {
                if(a[x][y-1]==0)y--;
                else {dir="down";x++;}
            }
            else if(dir=="down")
            {
                if(a[x+1][y]==0)x++;
                else
                {
                    dir="right";
                    y++;
                }
            }
            else if(dir=="right")
            {
                if(a[x][y+1]==0)y++;
                else
                {
                    dir="up";
                    x--;
                }
            }
            else if(dir=="up")
            {
                if(a[x-1][y]==0)x--;
                else
                {
                    dir="left";
                    y--;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    return 0;
}

int main9()
{
    int n;
    int a[3]={0},b[3]={0},a1[3]={0},b1[3]={0};//布锤子剪刀\赢平输
    cin>>n;
    while(n--)
    {
        char x,y;
        cin>>x>>y;
        if(x=='C')
        {
            if(y=='C')
            {
                a[1]++;
                b[1]++;
            }
            else if(y=='J')
            {
                a[0]++;
                b[2]++;
                a1[1]++;
            }
            else if(y=='B')
            {
                a[2]++;
                b[0]++;
                b1[0]++;
            }
        }
        if(x=='J')
        {
            if(y=='C')
            {
                a[2]++;
                b[0]++;
                b1[1]++;
            }
            else if(y=='J')
            {
                a[1]++;b[1]++;
            }
            else if(y=='B')
            {
                a[0]++;
                b[2]++;
                a1[2]++;
            }
        }
        if(x=='B')
        {
            if(y=='C')
            {
                a[0]++;b[2]++;
                a1[0]++;
            }
            else if(y=='J')
            {
                a[2]++;b[0]++;
                b1[2]++;
            }
            else if(y=='B')
            {
                a[1]++;b[1]++;
            }
        }

    }
    for(int i=0;i<3;i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
        for(int i=0;i<3;i++)
        {
            cout<<b[i]<<' ';
        }
        cout<<endl;
    if(a1[0]>=a1[1]&&a1[0]>=a1[2])cout<<'B'<<' ';
        else if(a1[1]>=a1[0]&&a1[1]>=a1[2])cout<<'C'<<' ';
        else cout<<'J'<<' ';
        if(b1[0]>=b1[1]&&b1[0]>=b1[2])cout<<'B';
        else if(b1[1]>=b1[0]&&b1[1]>=b1[2])cout<<'C';
        else cout<<'J';
    return 0;
}
float tra(float a)
{
    if(a>=90)return 4.0;
    else if(a>=85)return 3.7;
    else if(a>=82)return 3.3;
    else if(a>=78)return 3.0;
    else if(a>=75)return 2.7;
    else if(a>=72)return 2.3;
    else if(a>=68)return 2.0;
    else if(a>=64)return 1.5;
    else if(a>=60)return 1.0;
    else return 0;
}
int main10()
{
    int n;
    cin>>n;
    float a[n][2];
    int x=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        x+=a[i][0];
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][1];
        sum+=tra(a[i][1])*a[i][0];
    }

    sum/=x;
    cout<<fixed<<setprecision(2)<<sum;
    return 0;
}

int main11()
{
    int n,k;
    set<int> a;//set容器
    cin>>n>>k;
    int s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        a.insert(s);
    }
    set<int>::iterator it;
    int flag=0;
    if(a.size()<k)k=a.size();//(如果不存在k个不同的数，则按照实际数量进行输出)
    for(it=a.begin();flag<k;flag++)
    {
        cout<<*it<<' ';
        it++;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool similar(string lonStr, string shorStr); //判断单词相似函数
int main121()
{
    vector<string> dictionary;      //存储字典单词
    vector<string>::iterator iter;  //迭代器
    string word;                    //需要检查的单词
    string dic;
    bool flag = false;
    int sub =0;

    while(1)                        //读入字典单词
    {
        cin >> dic;
        if(dic == "#")
        {
            break;
        }
        dictionary.push_back(dic);
    }
    while(1)                            //依次判断
    {
        cin >> word;
        if(word == "#")
        {
            break;
        }
        flag = false;
        for(iter = dictionary.begin(); iter != dictionary.end(); iter++) //判断字典中是否存在该单词
        {
            dic = *iter;
            if(dic == word)
            {
                cout << word << " is correct";
                flag = true;
            }
        }
        if(!flag)    //如果字典中不存在，则查找是否有相似的单词
        {
            cout << word << ":";
            for(iter = dictionary.begin(); iter != dictionary.end(); iter++) //遍历字典，判断是否相似
            {
                dic = *iter;
                sub = dic.length() - word.length();     //获取两个单词长度之差，如果 <=1,则符合条件，如果>1则不可能匹配成功
                if( sub== 0)                            //两个单词长度相同
                {
                    for(int i=0; i< dic.length(); i++)
                    {
                        if(dic[i] != word[i])
                        {
                            string temp = word;         //注意需要新建一个中间变量temp，不能直接修改单词word，因为之后还会用到word
                            temp[i] = dic[i];           //将不相等的单词替换为相等的单词，重新比较
                            if(temp == dic)
                            {
                                cout << " "<< dic ;
                            }
                            break;
                        }
                    }
                }else if(abs(sub) == 1)                  //两个单词长度相差1个字母
                {
                    if(dic.length() < word.length())
                    {
                        if(similar( word , dic ))        //判断单词是否相似的函数similar（）。
                        {
                            cout  << " "<< dic;
                        }
                    }
                    else
                    {
                        if(similar(dic,word))
                        {
                            cout << " "<< dic ;
                        }
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}

bool similar(string lonStr, string shorStr)  //判断单词是否相似
{
    int lon, shor;
    lon = lonStr.length();
    shor = shorStr.length();
    string temp;
    for(int i=0; i<shor; i++)
    {
        if(lonStr[i] != shorStr[i])         //遍历每个字母，找到不想等的字母位置
        {
            temp = shorStr.substr(0,i);
            temp = temp + lonStr[i] + shorStr.substr(i,shor-i); //在较短的单词中插入不想等的字母，然后判断是否相等。
            if(temp == lonStr)
            {
                return true;
            }
        }
    }
    temp = shorStr + lonStr[lon-1];     //以上判断会漏掉最后一个字母不想等的情况，这里补上。
    if(temp == lonStr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main122()
{
    vector<string> words;
    string s;
    while(cin>>s)
    {
        if(s=="#")break;
        words.push_back(s);
    }
    while(cin>>s)
    {
        if(s=="#")break;
        bool flag=false;//设置判断标识
        for(int i=0;i<words.size();i++)
        {
            if(s==words[i])//如果能查找到
            {
                flag=true;
                cout<<s<<" is correct"<<endl;
            }
        }
        if(!flag)
        {
            cout<<s<<':';
            for(int i=0;i<words.size();i++)
            {
                int sub=s.length()-words[i].length();//剪枝函数
                if(sub==0)//如果长度相同，判断是否只相差一个字母
                {
                    int num=0;
                    for(int j=0;j<s.length();j++)
                    {
                        if(s[j]!=words[i][j])num++;
                    }
                    if(num==1)cout<<' '<<words[i];
                }
                if(sub==1)//s更长->删除s的一个字母
                {
                    int num=0;
                    for(int j=0;j<s.length();j++)
                    {
                        if(s[j]!=words[i][j])
                        {
                            j++;//跳过这个字母，相当于删除
                            for(;j<s.length();j++)
                            {
                                if(s[j]!=words[i][j-1])num++;
                            }
                        }
                    }
                    if(num==0)cout<<' '<<words[i];
                }
                if(sub==-1)//s更短->增加一个字母
                {
                    int num=0;
                    for(int j=0;j<s.length();j++)
                    {
                        if(s[j]!=words[i][j])
                        {
                            while(j<s.length())
                            {
                                if(s[j]!=words[i][j+1])num++;//跳过words中多的字母
                                j++;
                            }
                        }
                    }
                    if(num==0)cout<<' '<<words[i];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

/*struct tel
{
    string num;
    int time=0;
};*/
int main13()
{
    int n;
    cin>>n;
    map<string,int>a;

    for(int k=0;k<n;k++)
    {
        string s,s1;
        s1="";
        cin>>s;
        stringstream ss(s);
        string str;
        while(getline(ss,str,'-'))
        {
            s1+=str;
        }
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]<'0'||s1[i]>'9')
            {
                if(s1[i]=='A'||s1[i]=='B'||s1[i]=='C')s1[i]='2';
                else if(s1[i]=='D'||s1[i]=='E'||s1[i]=='F')s1[i]='3';
                else if(s1[i]=='G'||s1[i]=='H'||s1[i]=='I')s1[i]='4';
                else if(s1[i]=='J'||s1[i]=='K'||s1[i]=='L')s1[i]='5';
                else if(s1[i]=='M'||s1[i]=='N'||s1[i]=='O')s1[i]='6';
                else if(s1[i]=='P'||s1[i]=='R'||s1[i]=='S')s1[i]='7';
                else if(s1[i]=='T'||s1[i]=='U'||s1[i]=='V')s1[i]='8';
                else if(s1[i]=='W'||s1[i]=='X'||s1[i]=='Y')s1[i]='9';
                else s1.erase(i,1);
            }
        }
            if(a.count(s1)!=1)a[s1]=1;
            else a[s1]++;
    }
    map<string,int>::iterator it;
    for(it=a.begin();it!=a.end();it++)
    {
        if(it->second>1)
        {
            for(int i=0;i<7;i++)
            {
                if(i==3)cout<<'-';
                cout<<it->first[i];
            }
            cout<<' '<<it->second<<endl;
        }
    }
    return 0;
}

int main14() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n && n) {
        map<string, int> a;
        string s;
        for (int i = 0; i < 2 * n - 1; ++i) {//不用判断是否存在，初始为0
            cin >> s;
            a[s]++;
        }
        map<string, int>::iterator it;
        for (it = a.begin(); it != a.end(); ++it) {
            if (it->second %2== 1) {//考虑重名的情况，所以为单数时
                cout << it->first << endl;
                break;
            }
        }
        a.clear();
    }
    return 0;
}

struct people
{
    int num=0;
    //string tele="";
    vector<string>tele;
};

void in(people& a,string b)
{
    int k=0;
    /*stringstream ss(a.tele);
    string str;
    while(ss>>str)
    {
        if(str.rfind(b)!=string::npos&&str.length()-str.rfind(b)==b.length())
        {
            k=1;
            break;
        }
    }*/
    for(unsigned int i=0;i<a.tele.size();i++)//这两步要分开，否则重复的无法录入
    {
        if(b.rfind(a.tele[i])!=string::npos&&(int)b.rfind(a.tele[i])+a.tele[i].length()==b.size())//不能把size改成end
           {
               //vector<string>::iterator it=a.tele[i];
                a.tele.erase(a.tele.begin()+i);
                a.num--;
           }
    }
    for(unsigned int i=0;i<a.tele.size();i++)
    {
        if(a.tele[i].rfind(b)!=string::npos&&a.tele[i].rfind(b)+(int)b.length()==a.tele[i].size())//a.tele[i].length()-a.tele[i].rfind(b)==b.length())
        {
            k=1;break;
        }
    }
    if(k==0)
    {
        //a.tele+=b;
        //a.tele+=" ";
        a.tele.push_back(b);
        a.num++;
    }

}

bool cmp2(string a,string b)
{
    if(a.length()!=b.length())return a.length()<b.length();
    else return a<b;
}

int main15()
{
    int n;
    int d;
    cin>>n;
    map<string,people>a;
    map<string,people>::iterator it;
    string s,p;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        cin>>d;
        while(d--)
        {
            cin>>p;
            in(a[s],p);
        }
    }
    cout<<a.size()<<endl;
    for(it=a.begin();it!=a.end();it++)
    {
        cout<<it->first<<' '<<it->second.num<<' ';//<<it->second.tele<<endl;
        sort(it->second.tele.begin(),it->second.tele.end(),cmp2);
        for(unsigned int i=0;i<it->second.tele.size();i++)
        {
            cout<<it->second.tele[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
int main16()
{
    int N;
    while(cin>>N&&N!=0)
    {
        string*s=new string [N];
        string a="",b="";
        int a1=0,b1=0;
        cin.ignore();
        int p=0;
        for(int i=0;i<N;i++)
        {
            getline(cin,s[i]);
            if(i%2==0)
            {
                p++;
                if(s[i].find("no good")!=-1)a+="X ";
                else {a+="O ";a1++;}
                if(i==N-1)b+="- ";
            }
            else
            {
                if(s[i].find("no good")!=-1)b+="X ";
                else {b+="O ";b1++;}
            }
        }
        for(int i=0;i<p;i++)
        {
            cout<<i+1<<' ';
        }
        cout<<"Score"<<endl;
        cout<<a<<a1<<endl<<b<<b1<<endl;
    }
    return 0;
}

int main17()
{
    int n,a,b,c;
    int f0,f1;
    while(cin>>n>>a>>b>>c)
    {
        int lele=0,yueyue=0;
        string*s=new string[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        f1=c;
        while(lele!=n-1&&yueyue!=n-1)
        {
            f0=(a*f1+b)%6+1;
            lele+=f0;
            while(0>lele||lele>=n)
            {
                if(lele<0)lele=-lele;
                if(lele>=n)lele=2*(n-1)-lele;
            }
            if(s[lele]!="N")lele=(int)s[lele][1]-'0';
            if(lele==yueyue)yueyue=0;
            if(lele==n-1)break;
            f1=(a*f0+b)%6+1;
            yueyue+=f1;
            while(0>yueyue||yueyue>=n)
            {
                if(yueyue<0)yueyue=-yueyue;
                if(yueyue>=n)yueyue=2*(n-1)-yueyue;//yueyue-=(n+1);条件写错了，计算不对
            }
            if(s[yueyue]!="N")yueyue=(int)s[yueyue][1]-'0';
            if(yueyue==lele)lele=0;
        }
        if(lele==n-1)cout<<"Lele"<<endl;
        else cout<<"Yueyue"<<endl;
    }
    return 0;
}

    int N;
    int max_size=1;
    char a[2005][2005];
    int mark[2005];

void expand(int row,int col,int size){
	if(a[row][col]!='1')
		return;
	int flag=0;
	for(int i=row;i<row+size;i++){
		for(int j=col;j<col+size;j++){
			if((i-row+j-col)%2==0&&a[i][j]=='0')
			{
				flag=1;
				break;
			}
			else if((i-row+j-col)%2==1&&a[i][j]=='1')
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	if(!flag){
		if(size>=max_size)
		{
			max_size=size;
			mark[max_size]++;
		}
		if(row+size<=N&&col+size<=N)
			expand(row,col,size+1);
	}
}

int main()//DFS
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            expand(i,j,1);
        }
    }
    cout<<max_size<<' '<<mark[max_size]<<endl;
    return 0;
}

