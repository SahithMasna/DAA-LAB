#include <iostream>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    int a[20][20];

    cout<<"Enter adjacency matrix:\n";

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    int v[20]={0};

    v[0]=1;

    int sum=0;

    cout<<"Edges in MST:\n";

    for(int k=0;k<n-1;k++)
    {
        int m=999;
        int u=-1;
        int w=-1;

        for(int i=0;i<n;i++)
            if(v[i])
                for(int j=0;j<n;j++)
                    if(!v[j] && a[i][j]!=0 && a[i][j]<m)
                    {
                        m=a[i][j];
                        u=i;
                        w=j;
                    }

        cout<<u<<" - "
            <<w<<" = "
            <<m<<endl;

        sum+=m;

        v[w]=1;
    }

    cout<<"Minimum Cost = "<<sum;

    return 0;
}