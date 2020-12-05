#include <iostream>
using namespace std;

    int n;
	int* ar = NULL;   
	int* is_present = NULL;             //tell if the element will be in the subset or not
	int* mapped_elements = NULL;       //number of elements mapped to a elements


    void take_input()
	{         
		cin >> n;       
		ar = new int[n];
		is_present = new int[n];
		mapped_elements = new int[n];
	
		for(int i=1; i<=n; i++)
		{
			cin >> ar[i];
			mapped_elements[i]=0;
			is_present[i]=0;
		}
	}
	
    void numberof_antimapping_and_take_bijective()									//create co-doamain to domain mapping 
	{												// step 1 and 2
		int k;
		for(int i=1; i<=n; i++)
		{
			k = ar[i];	
			mapped_elements[k]+=1;	
			
			if(ar[i] == i)
				is_present[i]=1;
			else if(ar[k] == k)
				is_present[i]=-1;							//
			
		}
	}


	void delete_element(int x)
	{
		int k = ar[x];
		mapped_elements[k] = mapped_elements[k] - 1;
		if(mapped_elements[k] == 0 && is_present[k] == 0)
		{
			is_present[k] = -1;
			delete_element(k);
		}
	}

	void remove_null()
	{
		for(int i=1; i<=n; i++)
		{
			if(mapped_elements[i] == 0 && is_present[i] == 0)
			{
				is_present[i] = -1;
				delete_element(i);
			}
		}
	}



int main() {
	
	take_input();
	numberof_antimapping_and_take_bijective();
    remove_null();
    for(int i=1; i<=n; i++)
		if(is_present[i] != -1)
			cout <<  " " << i;
	
	return 0;
}
