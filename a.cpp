#include <iostream>
#include <fstream>
using namespace std;


class astar
{
    public:
    
    int max=0;
    string citys[10];
    int graph[10][10];
    
    int no(string* b,string a)
    {
        for(int i=0;i<sizeof(b);i++)
        {
            if(a==b[i])
            {
                return i;
            }
        }
    }
    
    void astar1()
    {
        cout<<"Enetr maximum citys:";
        cin>>max;
        for(int i=0;i<max;i++)
        {
            cout<<"\tEnter city no"<<i+1<<":";
            cin>>citys[i];
        }
        
        for(int i=0;i<max;i++)
        {
            cout<<i+1<<"."<<citys[i]<<endl;
        }
        cout<<"Now enter interconnection bet' citys.(ex <city_no_given abou><space><distance>):"<<endl;
        for(int i=0;i<max;i++)
        {
            int connections=0;
            cout<<i+1<<".no connections of :"<<citys[i];
            cin>>connections;
            while(connections>0)
            {
                int index=0;
                int dist=0;
                cout<<"\t"<<connections<<"th connection";
                cin>>index>>dist;
                graph[i][index-1]=dist;
                connections--;
            }
            
        }
    }
    
    void file()
    {
        string line;
        ifstream my_file("graph.txt");
        if (!my_file) 
        {
            cout << "Error opening the file." << endl;
        }
        else
        {
            getline(my_file, line);
            max=stoi(line);
            getline(my_file, line);
            string array[10];
            int i=0;
            string str;
            for(auto x:line) 
            {
                if(x==' ')
                {
                    citys[i]=str;
                    i++;
                    str.erase();
                }
                else
                {
                   str=str+x;
                }
            }
                int j=0;
            while (!my_file.eof()) 
            {
                getline(my_file, line);
                int i=0;
                string str;
                for(auto x:line) 
                {
                    if(x==' ')
                    {
                        graph[j][i]=stoi(str);
                        i++;
                         str.erase();
                    }
                    
                    else
                          str=str+x;
                }
                j++;
            }
        }
    }
    void algo()
    {
        string start,end;
        cout<<"Enter a starting:";
        cin>>start;
        cout<<"Enter a ending:";
        cin>>end;
        int current=1;//no(citys,start);
        cout<<current;
        cout<<citys[current]<<"-->";
        int endint=no(citys,end);
        while(current!=endint)
        {
            int min=graph[current][0];
            for(int j=0;j<max;j++)
            {
                if(min>graph[current][j])
                {
                    min=graph[current][j];
                    current=j;
                }
            }
        }
        
    }
    void display()
    {
        for(int i=0;i<max;i++)
        {
            cout<<i+1<<"."<<citys[i];
            for(int j=0;j<max;j++)
            {
                cout<<"\t"<<graph[i][j];
            }
            cout<<endl;
        }  
    }
};

int main()
{
    astar obj;
    obj.file();
    //obj.display();
    obj.algo();
    return 0;
}



