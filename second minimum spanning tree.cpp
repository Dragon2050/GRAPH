#include<bits/stdc++.h>

using namespace std;

int node,edg,par[1000005];

struct edge
{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

vector<edge> e,p;

int find(int r)
{
    if(par[r]==r)
        return r;
    par[r]=find(par[r]);
    return par[r];
}

int smst()
{
    int mn = 100000000;
    for(int i=0; i<p.size(); i++)
    {
        for(int j=1; j<=node; j++)
        {
            par[j]=j;
        }
        int sum = 0,count = 0;
        for(int j=0; j<edg; j++)
        {
            if(e[j].u!=p[i].u and e[j].v!=p[i].v)
            {
                int u = find(e[j].u);
                int v = find(e[j].v);
                if(u!=v)
                {
                    par[u] = v;
                    count++;
                    sum+=e[j].w;
                    if(count == node-1)
                        break;
                }
            }
        }
        if(count == node-1)
            mn = min(sum,mn);

    }
    return mn;
}

void print()
{
    cout<<endl<<endl;
    for(int i=0; i<p.size(); i++)
    {
        cout<<p[i].u<<" "<<p[i].v<<" "<<p[i].w<<endl;
    }
}

int mst()
{
    for(int i=1; i<=node; i++)
        par[i] = i;
    sort(e.begin(),e.end());
    int sum = 0,count = 0;
    for(int i=0; i<edg; i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u!=v)
        {
            p.push_back(e[i]);
            par[u]=v;
            count++;
            sum+=e[i].w;
            if(count == node-1)
            {
                break;
            }
        }
    }
    return sum;
}

int main()
{
    scanf("%d%d",&node,&edg);
    for(int i=0; i<edg; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge get;
        get.u=u;
        get.v=v;
        get.w=w;
        e.push_back(get);
    }
    cout<<mst()<<endl;;///minimum cost spanning tree.
    ///smst() means second minimum cost spanning tree.
    if(smst() == 100000000)
        cout<<"THERE IS NO SECOND MINIMUM COST SPANNING TREE"<<endl;
    else
        cout<<smst()<<endl;///second minimum cost spanning tree.
    return 0;
}
