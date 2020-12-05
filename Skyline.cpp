#include <iostream> 
#include <vector>
#include <bits/stdc++.h>
using namespace std; 
int n; 

// A structure for building 
struct Building { 
    int left; 
    int ht; 
    int right; 
}; 
Building* arr=NULL;

// A structure for x and y cordinate
struct Final_skyline { 
    int x_co; 
    int h;
  
};

//Taking input
void input()
{
    cin>>n;
    arr=new Building[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].left;
        cin>>arr[i].ht;
        cin>>arr[i].right;
    }
    
}


vector<Final_skyline> Result_final_skyline;

//merging skylines
vector<Final_skyline> MergeSL(vector<Final_skyline> LeftS, vector<Final_skyline> RightS)
{

    vector<Final_skyline> res;
    int pR=0,pL=0;
    int currY = 0,leftY  = 0,rightY = 0,prevY=0;

    while (pL < LeftS.size() && pR < RightS.size()) {
       
         if (LeftS[pL].x_co < RightS[pR].x_co) { 
            
            int x1 = LeftS[pL].x_co; 
            leftY = LeftS[pL].h; 
            currY = max(leftY,rightY);  // Choose height as max of two heights 
           if(currY != prevY){
                prevY = currY;
                Final_skyline z;
                z.x_co = x1;
                z.h=currY; 
                res.push_back(z);
              }
            pL++;
         }
         else if(LeftS[pL].x_co > RightS[pR].x_co)
         {
            int x2 = RightS[pR].x_co; 
            rightY = RightS[pR].h; 
            currY = max(leftY,rightY); 
             if(currY != prevY){
                prevY = currY;
                Final_skyline z;
                z.x_co = x2;
                z.h=currY; 
                res.push_back(z);
        
              }
            pR++; 
       
         }
        else if(LeftS[pL].x_co==RightS[pR].x_co){
            
            //leftY=max(LeftS[pL].h,RightS[pR].h);
             //rightY = max(LeftS[pL].h,RightS[pR].h);
             leftY=LeftS[pL].h;
             rightY = RightS[pR].h;
              int x2 = RightS[pR].x_co; 
              currY = max(leftY,rightY);
               if(currY != prevY){
                prevY = currY;
                Final_skyline z;
                z.x_co = x2;
                z.h=currY; 
                res.push_back(z);
              }
              pL++;
              pR++;
        }
    }
    
   while (pL<LeftS.size())
        res.push_back(LeftS[pL++]);

    while (pR<RightS.size())
        res.push_back(RightS[pR++]);
   
  return res;
}

//Dividing to get left and right skyline
vector<Final_skyline> skyline(int l, int r) 
{ 
  
    if(l==r){
    vector<Final_skyline> final_arr;
    Final_skyline f;
    f.x_co= arr[l].left;
    f.h= arr[l].ht;
    final_arr.push_back(f);
    f.x_co= arr[l].right;
    f.h= 0;
    final_arr.push_back(f);
    return final_arr;
    }
   
    int m=floor((l+r)/2);           // Same as (l+r)/2, but avoids overflow for large l and h 
    vector<Final_skyline> LeftS=skyline(l, m); //Sort first and second halves 
    vector<Final_skyline> RightS=skyline(m + 1, r); 
    vector<Final_skyline> Result_final_skyline = MergeSL(LeftS,RightS);
    return Result_final_skyline;
}

//Print Final skyline
void print_final_skyline()
{
   
    for(int i=0; i<Result_final_skyline.size(); i++){
   
        cout<<Result_final_skyline[i].x_co<<" ";
        cout<<Result_final_skyline[i].h<<" ";
    }
}

// Main Function 
int main() 
{ 
     input();
     Result_final_skyline=skyline(0, n - 1);
     print_final_skyline();
     return 0; 
}