#include<bits/stdc++.h>

using namespace std;

#define white 0
#define black 1

int visited[1000][1000];

char s[1000][1000];

int fx[8]= {-1,+1,0,0,-1,-1,+1,+1};
int fy[8]= {0,0,+1,-1,-1,+1,-1,+1};

int iscorrect(int row,int col,int row1,int col1)
{
    if(row1>=0 and row1<row and col1>=0 and col1<col and visited[row1][col1] == white and s[row1][col1] == '#')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void BFS(int i,int j,int row,int col)
{
    queue< pair<int,int > > q;
    pair<int,int> pa;
    q.push(make_pair(i,j));
    //q.push(pa);
    visited[i][j] = black;
    while(!q.empty())
    {
        pa=q.front();
        q.pop();
        int x = pa.first;
        int y = pa.second;
        for(int k=0; k<8; k++)
        {
            int row1 = x+fx[k];
            int col1 = y+fy[k];
            int res = iscorrect(row,col,row1,col1);
            if(res == 1)
            {
                visited[row1][col1] = black;
                q.push(make_pair(row1,col1));
            }
        }
    }

}

int countislands(int row,int col)
{
    for(int i=0; i<1000; i++)
    {
        for(int j=0; j<1000; j++)
        {
            visited[i][j] = white;
        }
    }
    int cnt = 0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(s[i][j]=='#' and visited[i][j] == white)
            {
                cnt++;
                BFS(i,j,row,col);
            }
        }
    }
    return cnt;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int row,col;
        cin>>row>>col;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>s[i][j];
            }
        }
        int res=countislands(row,col);
        cout<<res<<endl;
    }
    return 0;
}
