#include <iostream>
#include <stack>
using namespace std;



class bfs
{
    int max=0;
    int v=0;
    char visit[10];
    stack<char> stack;
    char input[10][10];
    public:
    bfs()
    {
        cout<<"Enter no of max elements:";
        cin>>max;
        for(int i=0;i<max;i++)
        {
            cout<<"Enter a node:";
            cin>>input[i][0];
            cout<<"max no of node connected to this  node:";
            int maxj=0;
            cin>>maxj;
            for(int j=1;j<maxj;j++)
            {
                cout<<"/t connected node:";
                cin>>input[i][j];
            }
        }
    }
    void bfs1()
    {
        char start;
        int flag=0;
        /*cout<<"Enter root of bfs:";
        cin>>start;
        for(int i=0;i<max;i++)
        {
            if(input[i][0]==start)
            {

            }
        }*/
        stack.push(input[0][0]);
        while(!stack.empty())
        {
            visit[v]=stack.top();
            stack.pop();
            for(int i=0;i<max;i++)
                {
                    if(input[i][0]==visit[v])
                    {
                        int y=1;
                        while(input[i][y]!=NULL)
                        {
                            stack.push(input[i][y]);
                            y++;
                        }
                    }
                    break;
                }
        }
        for(int i=0;i<v;i++)
        {
            cout<<visit[i]<<"->";
        }
    }
    
};

int main()
{
    bfs obj;
    obj.bfs1();
    return 0;
}