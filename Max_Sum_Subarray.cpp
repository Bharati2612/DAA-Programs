#include <iostream>
#include<climits>
using namespace std;
int n;
int *arr = NULL;
//Taking Input
void input()
{
    cin>>n;
    arr = new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
}

int maxsum_subarray()
{
    int start=0,end=0,max_till_now=INT_MIN,max_now=0,s=0,i;
    for(i=0;i<n;i++)
    {
        max_now=max_now+arr[i];
        if(max_till_now<max_now)
        {
            max_till_now=max_now;
            start=s;
            end=i;
        }
        if(max_now<0)
        {
            max_now=0;
            s=i+1;
        }
    }
    if(max_till_now>0)
    {
        cout<<"Max Sum is: "<<max_till_now<<endl;
        cout<<" Index (i,j) = ("<<start<<","<<end<<")";
    }
    else
        cout<<-1;
    
}
int main() {
	input();
	maxsum_subarray();
	return 0;
}
