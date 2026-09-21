#include <iostream>
using namespace std;

int main()
{
    int n,e;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter number of edges: ";
    cin>>e;

    int a[20][3];

    cout<<"Enter edges and weights:\n";

    for(int i=0;i<e;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];

    for(int i=0;i<e-1;i++)
        for(int j=0;j<e-i-1;j++)
            if(a[j][2]>a[j+1][2])
                for(int k=0;k<3;k++)
                {
                    int t=a[j][k];
                    a[j][k]=a[j+1][k];
                    a[j+1][k]=t;
                }

    int p[20];

    for(int i=0;i<n;i++)
        p[i]=i;

    int sum=0,c=0;

    cout<<"Edges in MST:\n";

    for(int i=0;i<e && c<n-1;i++)
    {
        int x=a[i][0];
        int y=a[i][1];

        while(p[x]!=x)
            x=p[x];

        while(p[y]!=y)
            y=p[y];

        if(x!=y)
        {
            cout<<a[i][0]<<" - "
                <<a[i][1]<<" = "
                <<a[i][2]<<endl;

            sum+=a[i][2];

            p[x]=y;

            c++;
        }
    }

    cout<<"Minimum Cost = "<<sum;

    return 0;
}