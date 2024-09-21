#include <bits/stdc++.h>

using namespace std;

int main0()//�ַ�����ת2��ʹ��stack--�������ѭ����
{
    stack<string> a;
    string s;
    while(cin>>s)//ctrlz�˳�
    {
        a.push(s);//д��ǰ�棬mi+\n�ᱻһ�����
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

int main8()//��Ȧ���Ӻ���ǰ���룬�����߿�ͱ䷽��
{
    int n;
    cin>>n;
    int a[n+2][n+2];//�ӱ߿�***
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
        if(n%2==1)//����
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

int main11()//��С��K������ѧϰʹ��set->ȥ���ظ�����+��С��������->��ʵmapӦ��Ҳ�У�
{
    int n,k;
    set<int> a;//set����
    cin>>n>>k;
    int s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        a.insert(s);
    }
    set<int>::iterator it;
    int flag=0;
    if(a.size()<k)k=a.size();//(���������k����ͬ����������ʵ�������������)
    for(it=a.begin();flag<k;flag++)
    {
        cout<<*it<<' ';
        it++;
    }
    return 0;
}

bool similar(string lonStr, string shorStr); //�жϵ������ƺ���
int main121()//ƴд���
{
    vector<string> dictionary;      //�洢�ֵ䵥��
    vector<string>::iterator iter;  //������
    string word;                    //��Ҫ���ĵ���
    string dic;
    bool flag = false;
    int sub =0;

    while(1)                        //�����ֵ䵥��
    {
        cin >> dic;
        if(dic == "#")
        {
            break;
        }
        dictionary.push_back(dic);
    }
    while(1)                            //�����ж�
    {
        cin >> word;
        if(word == "#")
        {
            break;
        }
        flag = false;
        for(iter = dictionary.begin(); iter != dictionary.end(); iter++) //�ж��ֵ����Ƿ���ڸõ���
        {
            dic = *iter;
            if(dic == word)
            {
                cout << word << " is correct";
                flag = true;
            }
        }
        if(!flag)    //����ֵ��в����ڣ�������Ƿ������Ƶĵ���
        {
            cout << word << ":";
            for(iter = dictionary.begin(); iter != dictionary.end(); iter++) //�����ֵ䣬�ж��Ƿ�����
            {
                dic = *iter;
                sub = dic.length() - word.length();     //��ȡ�������ʳ���֮���� <=1,��������������>1�򲻿���ƥ��ɹ�
                if( sub== 0)                            //�������ʳ�����ͬ
                {
                    for(int i=0; i< dic.length(); i++)
                    {
                        if(dic[i] != word[i])
                        {
                            string temp = word;         //ע����Ҫ�½�һ���м����temp������ֱ���޸ĵ���word����Ϊ֮�󻹻��õ�word
                            temp[i] = dic[i];           //������ȵĵ����滻Ϊ��ȵĵ��ʣ����±Ƚ�
                            if(temp == dic)
                            {
                                cout << " "<< dic ;
                            }
                            break;
                        }
                    }
                }else if(abs(sub) == 1)                  //�������ʳ������1����ĸ
                {
                    if(dic.length() < word.length())
                    {
                        if(similar( word , dic ))        //�жϵ����Ƿ����Ƶĺ���similar������
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

bool similar(string lonStr, string shorStr)  //�жϵ����Ƿ�����
{
    int lon, shor;
    lon = lonStr.length();
    shor = shorStr.length();
    string temp;
    for(int i=0; i<shor; i++)
    {
        if(lonStr[i] != shorStr[i])         //����ÿ����ĸ���ҵ�����ȵ���ĸλ��
        {
            temp = shorStr.substr(0,i);
            temp = temp + lonStr[i] + shorStr.substr(i,shor-i); //�ڽ϶̵ĵ����в��벻��ȵ���ĸ��Ȼ���ж��Ƿ���ȡ�
            if(temp == lonStr)
            {
                return true;
            }
        }
    }
    temp = shorStr + lonStr[lon-1];     //�����жϻ�©�����һ����ĸ����ȵ���������ﲹ�ϡ�
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
        bool flag=false;//�����жϱ�ʶ
        for(int i=0;i<words.size();i++)
        {
            if(s==words[i])//����ܲ��ҵ�
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
                int sub=s.length()-words[i].length();//��֦����
                if(sub==0)//���������ͬ���ж��Ƿ�ֻ���һ����ĸ
                {
                    int num=0;
                    for(int j=0;j<s.length();j++)
                    {
                        if(s[j]!=words[i][j])num++;
                    }
                    if(num==1)cout<<' '<<words[i];
                }
                if(sub==1)//s����->ɾ��s��һ����ĸ
                {
                    int num=0;
                    for(int j=0;j<s.length();j++)
                    {
                        if(s[j]!=words[i][j])
                        {
                            j++;//���������ĸ���൱��ɾ��
                            for(;j<s.length();j++)
                            {
                                if(s[j]!=words[i][j-1])num++;
                            }
                        }
                    }
                    if(num==0)cout<<' '<<words[i];
                }
                if(sub==-1)//s����->����һ����ĸ
                {
                    int num=0;
                    for(int j=0;j<s.length();j++)
                    {
                        if(s[j]!=words[i][j])
                        {
                            while(j<s.length())
                            {
                                if(s[j]!=words[i][j+1])num++;//����words�ж����ĸ
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

int main14() {//ȱϯ���Ե���˭���������������������
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n && n) {
        map<string, int> a;
        string s;
        for (int i = 0; i < 2 * n - 1; ++i) {//�����ж��Ƿ���ڣ���ʼΪ0
            cin >> s;
            a[s]++;
        }
        map<string, int>::iterator it;
        for (it = a.begin(); it != a.end(); ++it) {
            if (it->second %2== 1) {//�������������������Ϊ����ʱ
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
	if(a[row][col]!='1')//�����ʼ������
		return;
	int flag=0;
	for(int i=row;i<row+size;i++){
		for(int j=col;j<col+size;j++){
			if((i-row+j-col)%2==0&&a[i][j]=='0')//��֦
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
			expand(row,col,size+1);//�����ݹ�
	}
}

int main18()//DFS������
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

//19.Engine�ַ���
//20.�ַ���ѹ��
//21.���͹�״��������