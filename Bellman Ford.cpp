#include<bits/stdc++.h>

using namespace std;

int edgsrc[1000000],edgdst[1000000],dis[1000000],weight[1000000],cnt;

void Bellmanford(int node,int edge,int source)
{
    for(int i=0; i<=node; i++)
    {
        dis[i]=100000010;
    }
    dis[source]=0;
    for(int i=1; i<node; i++)
    {
        for(int j=0; j<edge; j++)
        {
            int u=edgsrc[j];
            int v=edgdst[j];
            int w=weight[j];
            if(w+dis[u]<dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }

    }
    for(int j=0; j<edge; j++)
    {
        int u=edgsrc[j];
        int v=edgdst[j];
        int w=weight[j];
        if(w+dis[u]<dis[v])
        {
            dis[v]=dis[u]+w;
            cnt=1;
            break;
        }
    }
}

int main()
{
    int edge,node,source;
    cin>>node>>edge>>source;
    for(int i=0; i<edge; i++)
    {
        cin>>edgsrc[i];
        cin>>edgdst[i];
        cin>>weight[i];
    }
    Bellmanford(node,edge,source);
    if(cnt==1)
    {
        cout<<"Negetive cycle detected"<<endl;
        return 0;
    }
    for(int i=1; i<=node; i++)
    {
        cout<<i<<" = "<<dis[i]<<endl;
    }
    return 0;
}
