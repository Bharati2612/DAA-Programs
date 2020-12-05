#include <iostream>
#include <vector>
#include<algorithm> // for sort()
using namespace std;
int n;
vector< vector<int> > Tasks;
int* start;
int* finish;

// Driver function to sort the 2D vector on basis of a particular column 
bool sortcol( const vector<int>& v1, 
			const vector<int>& v2 ) { 
return v1[1] < v2[1]; 
} 

void input()
{
    cin>>n;
    start = new int[n];
    finish = new int[n];
    for(int i=0;i<n;i++)
    {   vector<int> row;
        for(int j=0;j<2;j++)
        {
            int value; 
		    cin >> value; 
			row.push_back(value); 
        }
      Tasks.push_back(row); 
    }
    sort(Tasks.begin(), Tasks.end(),sortcol);
    for (int i=0; i<n; i++) 
	{ 
		start[i]= Tasks[i][0]; 
		finish[i]= Tasks[i][1]; 
	} 
}

//Finding compatibility
void find_max_compatible()
{
    int i, j; 
  
    cout<<"Following activities are compatible subset of requests of maximum possible size"<<endl; 
  
    // The first activity always gets selected 
    i = 0; 
    cout<<"("<<start[i]<<","<<finish[i]<<") "; 
    // Consider rest of the activities 
    for (j = 1; j < n; j++) 
    { 
      // If this activity has start time greater than or 
      // equal to the finish time of previously selected 
      // activity, then select it 
      if (start[j] >= finish[i]) 
      { 
          cout<<"("<<start[j]<<","<<finish[j]<<") "; 
          i = j; 
      } 
    } 
}


int main() {
    input();
    find_max_compatible();
	return 0;
}
