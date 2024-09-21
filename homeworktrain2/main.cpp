#include <bits/stdc++.h>

using namespace std;

int main0()//字符串反转2（使用stack--如何输入循环）
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

int main8()//数圈（从后往前输入，遇到边框就变方向）
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

int main11()//最小的K个数（学习使用set->去除重复的数+从小到大排列->其实map应该也行）
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

bool similar(string lonStr, string shorStr); //判断单词相似函数
int main121()//拼写检查
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

int main14() {//缺席考试的是谁（考虑重名的特殊情况）
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

    int N;
    int max_size=1;
    char a[2005][2005];
    int mark[2005];

void expand(int row,int col,int size){
	if(a[row][col]!='1')//棋盘最开始的条件
		return;
	int flag=0;
	for(int i=row;i<row+size;i++){
		for(int j=col;j<col+size;j++){
			if((i-row+j-col)%2==0&&a[i][j]=='0')//剪枝
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
			expand(row,col,size+1);//继续递归
	}
}

int main18()//DFS，棋盘
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

//19.Engine字符串
//20.字符串压缩
//21.新型冠状病毒传播