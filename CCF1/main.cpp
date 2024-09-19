#include <bits/stdc++.h>

using namespace std;

int main1()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=0,m=0;
        cin>>n>>m;
        vector<long long int>a(n);
        vector<long long int>b(m);
        long long int kk=0,pp=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            kk+=a[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            pp+=b[i];
        }
        if(kk>pp)
            cout<<"Alice"<<endl;
        else if(kk==pp)
            cout<<"Draw"<<endl;
        else
            cout<<"Bob"<<endl;
        /*sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(!a.empty()&&!b.empty())
        {
            int aa=a[0]-b[0],bb=b[0]-a[0];
            if(aa<=0)
                a.erase(a.begin());
            else
                a[0]=aa;
            if(bb<=0)
                b.erase(b.begin());
            else
                b[0]=bb;
        }
        if(a.empty()&&b.empty())
            cout<<"Draw"<<endl;
        else if(a.empty()&&!b.empty())
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;*/

    }
    return 0;
}

int main2()
{
    int n,p;
    cin>>n>>p;
    vector<int>k(n-1);
    for(int i=0;i<n-1;i++)
    {
        cin>>k[i];
    }
    vector<int>dp(n,INT_MAX);
    for(int i=0;i<p;i++)
        dp[i]=1;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n-1;i++)
    {
        if(i+k[i]<n&&dp[i]!=INT_MAX)
            dp[i+k[i]]=min(dp[i+k[i]],dp[i]+1);
        if(i-k[i]>=0&&dp[i]!=INT_MAX)
        {
            dp[i-k[i]]=min(dp[i-k[i]],dp[i]+1);
        }
    }
    }
    if(dp[n-1]==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<dp[n-1]<<endl;
    return 0;
}

int main3()
{
    stack<string>flag;
    string s;
    while(cin>>s)
    {
        if(s=="begin"||s=="loop")
            flag.push(s);
        if(s=="end")
            flag.pop();
        if(flag.empty())
            break;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// 解析表达式，返回表达式的值
long long parseExpression(const string& expr) {
    if (expr == "n") return -1; // 用-1代表未知数n
    stringstream ss(expr);
    long long val;
    ss >> val;
    return val;
}

// 计算多项式的时间复杂度
map<long long, long long> calculateComplexity(const string& code) {
    map<long long, long long> result; // 存储多项式的系数
    string token;
    stringstream ss(code);

    while (ss >> token) {
        if (token == "begin") {
            auto subResult = calculateComplexity(ss);
            for (auto& p : subResult) {
                result[p.first] += p.second;
            }
        } else if (token == "end") {
            break;
        } else if (token == "op") {
            long long val = parseExpression(ss);
            if (val != -1) {
                result[0] += val;
            } else {
                result[1] += 1;
            }
        } else if (token == "loop") {
            long long times = parseExpression(ss);
            if (ss >> token && token != "begin") {
                ss.putback(' ');
            } else {
                auto subResult = calculateComplexity(ss);
                if (times != -1) {
                    for (auto& p : subResult) {
                        result[p.first] += p.second * times;
                    }
                } else {
                    for (auto& p : subResult) {
                        result[p.first + 1] += p.second;
                    }
                }
            }
        } else if (token == "break") {
            // 遇到break，跳出当前循环
            return result;
        } else if (token == "continue") {
            // 遇到continue，跳过当前循环的余下语句
            while (ss >> token && token != "end");
        }
    }
    return result;
}

// 输出多项式
void printPolynomial(const map<long long, long long>& poly) {
    for (auto it = poly.rbegin(); it != poly.rend(); ++it) {
        if (it->second != 0) {
            if (it->first == -1) {
                cout << it->second << "n";
            } else if (it->first == 0) {
                if (it->second != 1 || poly.size() == 1) {
                    cout << it->second;
                }
            } else {
                cout << it->second << "n^" << it->first;
            }
            if (next(it) != poly.rend()) {
                cout << "+";
            }
        }
    }
    cout << endl;
}

int main() {
    string code;
    getline(cin, code);
    auto complexity = calculateComplexity(code);
    printPolynomial(complexity);
    return 0;
}
