Bfs:

#include<bits/stdc++.h>
using namespace std;

vector<int> vec [100000];
int visited[1000000];

void BFS(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                visited[v]=1;
            }
        }

    }

}

int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;

    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int s;
    cin>>s;
    BFS(s);
    return 0;
}

/*
6 7
1 2
1 3
2 4
2 5
3 5
4 6
5 6
1
*/
///Output:1 2 3 4 5 6

Bfs Level:

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int visited[1000];
int level[1000];

void BFS(int s)
{
    memset(level,0,sizeof visited);
    queue<int>Q;
    Q.push(s);
    level[s]=0;
    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                level[v]=level[u]+1;
                Q.push(v);
                visited[v]=1;
            }
        }

    }
}

int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    cin>>s;
    BFS(s);
    for(int i=1; i<=node; i++)
    {
        cout<<"level of node "<<i<<" is "<<level[i]<<endl;
    }
    return 0;
}


Bfs shortest path:

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
int visited[1000];
int parent[1000];
vector<int>v;

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    parent[s]=-1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);
                parent[v]=u;
            }
        }
    }
}

int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;
    for(int i=0; i<edge; i++ )
    {
        cin>>a>>b;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
    int s;
    cin>>s;
    BFS(s);
    int d;
    cin>>d;
    int x=d;
    v.push_back(x);
    while(x!=-1)
    {
        x=parent[x];
        v.push_back(x);
    }
    v.erase(v.end()-1);
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
/*
directional
6 7
1 4
1 2
2 3
4 5
3 5
4 5
5 6
1 6
*/
///Output:1 4 5 6

/*
Not directional
10 10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
0 6
*/
///Output:2 1 0 3 4 6


Bfs subgraph:

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[10000];
int visited[10000];

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                Q.push(v);
                visited[v]=1;
            }
        }
    }
}

int main()
{
    int node,edge;
    int a,b;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    int cnt=0;
    for(int i=1; i<=node; i++)
    {
        if(visited[i]==0)
        {
            cnt++;
            BFS(i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}

/*
4 4
1 2
1 3
4 2
4 3
*/
///Output:2


Dfs:

#include<bits/stdc++.h>

using namespace std;

vector<int>vec[10000];

int visit[10000];

void makeFalse();
{
    memset(visit,0,sizeof visit);
}

void dfs(int s)
{
    if(visit[s]==1)
    {
        return;
    }
    else
    {
        visit[s]=1;
        cout<<s<<" ";
    }

    int siz=vec[s].size();

    for(int i=0; i<siz; i++)
    {
        dfs(vec[s][i]);
    }
}

int main()
{
    int n,a,b,s;
    cin>>n;
    makeFalse();
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    cin>>s;
    dfs(s);
    return 0;

}

/*
5
0 1
0 2
0 3
1 2
2 4
0
*/
///Output:0 1 2 4 3,,,starting with 0

/*
7
0 1
0 4
1 2
1 3
1 4
3 4
2 3
0
*/
///Output:0 1 2 3 4,,,starting with 0


Dfs subgraph:

#include<bits/stdc++.h>
using namespace std;

vector<int>vec[10000];

int visit[10000];

void makeFalse()
{
    memset(visit,0,sizeof visit);
}

void dfs(int s)
{
    if(visit[s]==1)
    {
        return;
    }
    else
    {
        visit[s]=1;
    }

    int len=vec[s].size();

    for(int i=0; i<len; i++)
    {
        dfs(vec[s][i]);
    }
}

int main()
{
    int node,edge,a,b;
    cin>>node>>edge;
    makeFalse();
    for(int i=0; i<edge; i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        // vec[b].push_back(a);
    }
    int cnt=0;

    for(int i=0; i<node; i++)
    {
        if(visit[i]==0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
