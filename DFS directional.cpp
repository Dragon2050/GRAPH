#include<iostream>
#include<vector>

using namespace std;

#define White 0
#define Black 1
#define Gray 2

vector<int> vec[1000010];

int visited[1000010];
int parent[1000010]; /// parent of the current node..initially all node has no parent..so initial value is 0..
int starttime[1000010]; /// starting time of the current node..(Gray)
int endtime[1000010]; ///ending time of the current node..(Black)
int time;

void DFS(int source)
{
    time = time + 1;
    starttime[source] = time;
    visited[source] = Gray;
    int len = vec[source].size();
    for(int i=0;i<len;i++)
    {
        int v = vec[source][i];
        if(visited[v] == White)
        {
            parent[v] = source;
            DFS(v);
        }
    }
    visited[source] = Black;
    time = time + 1;
    endtime[source] = time;
}

int main()
{
    int node,edge,u,v;
    cin>>node; ///number of nodes..
    cin>>edge; ///number of edges..
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v); ///  [u--->v]
    }
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==White)
        {
            DFS(i);
        }
    }
    for(int i=1;i<=node;i++)
    {
        cout<<"node = "<<i<<" visited = "<<visited[i]<<" parent = "<<parent[i]<<" starting time = "<<starttime[i]<<" ending time = "<<endtime[i]<<endl;
    }
    return 0;
}
