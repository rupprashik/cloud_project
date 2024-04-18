#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class basic
{
    public:
    int index(string a[],string city)
    {
        for(int i=0;i<25;i++)
        {
            if(a[i]==city)
            {
                return i;
                break;
            }
        }
    }
    string city(string a[],int index1)
    {
        return a[index1];
    }
    bool is_present(string a[],string city)
    {
        int flag=0;
        for(int i=0;i<25;i++)
        {
            if(a[i]==city)
            {
                flag=1;
                return true;
                break;
            }
        }
        if(flag==0)
        {
            return false;
        }
    }
};
 
class astar: private basic
{
    int graph[25][25];
    string nodes[25];
    int max=0;
    public:
    astar()
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                graph[i][j]=-1;
            }
            nodes[i]="null";
        }
    }
    void read_f()
    {   
        string name,s_name;
        int dist=0;
        ifstream fin;
        fin.open("romaniakamap.txt");
        while(fin)
        {   
            fin>>name>>s_name>>dist;
            if(!is_present(nodes,name))
            {   
                nodes[max]=name;
                max++;
            }
            if(!is_present(nodes,s_name))
            {
                nodes[max]=s_name;
                max++;
            }
            graph[index(nodes,name)][index(nodes,s_name)]=dist;
        }
        fin.close();
    }
    void read_m()
    {
        int no=0;
        string name,s_name;
        int dist=0;
        cout<<"no of edges you want to enter:";
        cin>>no;
        cout<<"enter <city> tab <city> tab <distance>:-"<<endl;
        for(int i=0;i<no;i++)
        {
            cin>>name;
            cout<<"\t";
            cin>>s_name;
            cout<<"\t";
            cin>>dist;
            if(!is_present(nodes,name))
                {
                    nodes[max]=name;
                    max++;
                }
            if(!is_present(nodes,s_name))
                {
                    nodes[max]=s_name;
                    max++;
                }
            graph[index(nodes,name)][index(nodes,s_name)]=dist;
            graph[index(nodes,s_name)][index(nodes,name)]=dist;
        }
    }
    void display()
    {
        cout<<"citys \t";
        for(int i=0;i<max;i++)
        {
            cout<<nodes[i]<<"\t";
        }
        for(int i=0;i<max;i++)
        {
            cout<<"\n"<<nodes[i]<<"\t";
            for(int j=0;j<max;j++)
            {
                cout<<graph[i][j]<<"\t";
            }
        }
    }
    void algo()
    {
        string visited[max];
        string start,end,curr;
        cout<<"\nenter start:";
        cin>>start;
        cout<<"Enter end :";
        cin>>end;
        curr=start;
        int next=-1,j=0,end_index=index(nodes,end);
        int min=100;
        cout<<start<<"-->";
        while(next!=end_index and !is_present(visited,curr))
        {
            cout<<is_present(visited,curr);
            for(int i=0;i<max;i++)
            {
                int value=graph[index(nodes,curr)][i];
                if(min>value and value!=-1)
                {cout<<i<<",";
                    min=value;
                    next=i;
                }
            }
            cout<<nodes[next]<<"-->";
            curr=nodes[next];
            visited[j]==nodes[next];
            min=100;
            j++;
        }       
    }
};
int main()
{
    astar obj;
    obj.read_f();
    obj.display();
    obj.algo();
    return 0;
}