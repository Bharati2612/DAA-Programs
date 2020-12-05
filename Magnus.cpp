#include <iostream>
using namespace std;
int n;
int** graph=NULL;

/* **** Taking Input **** */
void input()
{
	cin>>n;
	graph=new int*[n];
	for(int i = 1; i <= n; ++i)
      graph[i] = new int[n];
	
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        cin>>graph[i][j];
	    }
	}

}

/* ******** Checking for Sink******* */	
int IsMagnus(int i)
{
    //cout<<endl<<"HI"<<i;
    for(int j=1; j<=n;j++)
    {
        if(graph[i][j]!=2)
            return 0;
        if(graph[j][i]!=0 && i!=j) return 0;
    }
    return 1;
}

/* ****Finding Probable Magnus**** */
int Find_Probable_Magnus()     
{
    int i = 1;
    int j = 1;
    while (i <= n && j <= n)
     {   if (graph[i][j]==0)
             i = i + 1;
        else j = j + 1;
     }
     return i;
    
}

int main() {

	input();
    int Magnus = Find_Probable_Magnus();
    if (Magnus <= n && IsMagnus(Magnus)) cout<<"The Magnus is: "<<Magnus;
    else cout<<endl<<"No Magnus";
    return 0;

}