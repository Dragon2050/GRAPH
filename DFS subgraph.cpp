#include<bits/stdc++.h>
#define SQR(n) (n*n)
#define CHR getchar()
#define NL printf("\n")
#define PI 2.0*acos(0.0)
#define ll              long long int
#define ull             unsigned long long int
#define sc              scanf
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        ((a)*(b))/gcd(a,b)
#define pf              printf
#define MOD             1000000007
#define mx              123456789
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define ff first
#define D double
#define sz size()
#define ss second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define white 0
#define black 1
using namespace std;
vector<int>vec[10000010];
int visit[1000000];
void DFS(int source)
{
    if(visit[source]==black)
        return;
    visit[source]=black;
    int len=vec[source].size();
    for(int i=0; i<len; i++)
    {
        DFS(vec[source][i]);
    }
}
int main()
{
    int node, edge, u, v;
    cin>>node>>edge;
    for(int i=1; i<=edge; i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int cnt=0;
    for(int i=1; i<=node; i++)
    {
        if(visit[i]==white)
        {
            cnt++;
            DFS(i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
© 2018 GitHub, Inc.
