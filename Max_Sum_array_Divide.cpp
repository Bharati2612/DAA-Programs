#include <iostream>
#include <vector>
using namespace std;
int n;
int *arr = NULL;

//Taking Input
void input()
{
    cin>>n;
    arr = new int[n];
    for(int i=1; i<=n; i++)
        cin>>arr[i];
}


vector<int> maxsum_mid_subarray(int left,int mid, int right)
{
    //Left Part
    int sum=0;
    int left_sum=0;
    int st=mid,Left_end=mid,Right_end=mid;
    vector<int> sumCrossingMid;
    for(int i=mid;i>=left;i--)
    {
        sum=sum+arr[i];
        if(sum>=left_sum){
            left_sum=sum;
            Left_end=i;
        }
    }
    
    //Right Part
    sum=0;
    int right_sum=0;
    for(int i=mid+1;i<=right;i++)
    {
        sum=sum+arr[i];
        if(sum>=right_sum){
            right_sum=sum;
            Right_end=i;
        }
    }

    if(left_sum>= right_sum && left_sum >= left_sum+right_sum)
    {
        sumCrossingMid.push_back(Left_end);
        sumCrossingMid.push_back(mid);
        sumCrossingMid.push_back(left_sum);
    }
    if(right_sum>= left_sum && right_sum >= left_sum+right_sum)
    {
        sumCrossingMid.push_back(mid+1);
        sumCrossingMid.push_back(Right_end);
        sumCrossingMid.push_back(right_sum);
    }
    else
    {
        sumCrossingMid.push_back(Left_end);
        sumCrossingMid.push_back(Right_end);
        sumCrossingMid.push_back(left_sum+right_sum);
    }
    
    return sumCrossingMid;
}
int leftStart,leftEnd,leftMax,rightStart,rightEnd,rightMax,midStart,midEnd,midMax;

vector<int> maxsum_subarray(int left,int right)
{
    vector<int> final;
    if(left==right){
        vector<int> base;
        base.push_back(left);
        base.push_back(right);
        base.push_back(arr[left]);
        return base;
    }
    int mid=(left+right)/2;
    vector<int> leftMax = maxsum_subarray(left,mid);
    vector<int> rightMax = maxsum_subarray(mid+1,right);
    vector<int> midMax = maxsum_mid_subarray(left,mid,right);
    
  
    if(leftMax[2] >= rightMax[2] and leftMax[2] >= midMax[2])
    {
        final.push_back(leftMax[0]);
        final.push_back(leftMax[1]);
        final.push_back(leftMax[2]);
        
    }
    else if(rightMax[2] >= leftMax[2] and rightMax[2] >= midMax[2])
    {
        final.push_back(rightMax[0]);
        final.push_back(rightMax[1]);
        final.push_back(rightMax[2]);
    }
    else
    {
       final.push_back(midMax[0]);
       final.push_back(midMax[1]);
       final.push_back(midMax[2]);  
    }
       
return final;
}
int main() {
	input();
	vector<int> Max_Sum= maxsum_subarray(1,n);
	if(Max_Sum[2]!=0){
	    cout<<"Max sum is:"<<Max_Sum[2]<<endl;
	    cout<<"Index (i,j) is = ("<<Max_Sum[0]<<","<<Max_Sum[1]<<")";
	} 
	else
	    cout<< "-1";
	return 0;
}