#include <iostream>
#include <vector>
using namespace std;
int n;
vector<string> gray;
int arr[32]={0};
int i=1;

//Taking Input
void input()
{
    cin>>n;
}


//Finding Binary form 
void find_binary(int n)
{
    
    while(n>2)
    {   
        arr[i]=n%2;
        if(n%2==0)       
            n=n/2;
        else
            n=(n+1)/2;
        i++;
    }
  /* for (int j = i ; j >0; j--) 
        cout << arr[j]; */
}


// Print Array
void print()
{
    if(n%2==0)
    {
        cout << "Gray Code of Length "<<n<<" is :"<<endl;
       for (int p = 0 ; p < gray.size() ; p++ ) 
          cout<<gray[p] << endl; 
    }
    else
    {
        cout << "Open Gray Code of Length "<<n<<" is :"<<endl;
          if(n==1)
             {
                 cout<<0;
             }
        for (int p = 0 ; p < gray.size() ; p++ ) 
          cout<<gray[p] << endl;
    }
 
}


//Code for Open Gray Code
int open_gray_code()
{
   
    
        int size = gray.size();
        //cout<<size<<endl;
        for (int k = size-1 ; k >= 0 ; k--) 
            gray.push_back(gray[k]); 
  
        // append 0 to the first half 
        for (int k = 0 ; k < size ; k++) 
            gray[k] = "0" + gray[k]; 
  
        // append 1 to the second half 
        for (int k = size ; k < 2*size ; k++) 
            gray[k] = "1" + gray[k]; 
            
        gray.pop_back();
    
}


//Code for gray Code
int gray_code()
{
    
    
        int size = gray.size();
        //cout<<size<<endl;
        for (int k = size-1 ; k >= 0 ; k--) 
            gray.push_back(gray[k]); 
  
        // append 0 to the first half 
        for (int k = 0 ; k < size ; k++) 
            gray[k] = "0" + gray[k]; 
  
        // append 1 to the second half 
        for (int k = size ; k < 2*size ; k++) 
            gray[k] = "1" + gray[k]; 
    
}

//checking for gray code and open gray code
void find_gray_code()
{
    // base case 
    if (n <= 1) 
        return; 
        
    // start with 2 legth pattern 
    
    gray.push_back("0"); 
    gray.push_back("1"); 
    
    
    for(int j=i-1;j>0;j--)
    {
        if(arr[j]==0)
            gray_code();
        else
            open_gray_code();
    }

}

int main() {
	input();
	find_binary(n);
	find_gray_code();
	if(n<1)
	    cout<<"Not exist"<<endl;
	else
	    print();
	return 0;
}