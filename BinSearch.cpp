#include<iostream>
#include<algorithm>
using namespace std;
bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{  int mid=0;
  if(startIndex<=lastIndex)
  { mid=(startIndex+lastIndex-1)/2;
	if(array[mid]==element)
	return true;
	else if (array[mid]<element)
	return binarySearchReacursive(array,mid+1,lastIndex,element);
	else
	return binarySearchReacursive(array,startIndex,mid-1,element);     
  } 
  return false;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{  int mid=0; int k=0;
  while(startIndex<=lastIndex)
  {
  	mid=(startIndex+lastIndex-1)/2;
  	if(array[mid]==element)
  	{
  		k=1;
  		break;
	}
	else if (array[mid]<element)
	{
		startIndex=mid+1;
	}
	else
	lastIndex=mid-1;
  }
   if(k==1)
  return true;
  else 
  return false;
}

int main()
{  
  int size;
  cout<<"enter size of an array "<<endl;
  cin>>size; int i;
  int array[size];
  for(i=0;i<size;i++)
  {
  	 cout<<"enter element at "<<i<<" th index";
  	 cin>>array[i];
  }
  cout<<"enter element to be searched "<<endl;
  int x;
  cin>>x;
  sort(array,array+size);
  if(binarySearchReacursive(array,0,size-1,x)==true)
  cout<<"binary search using recursion successful "<<endl;
  else
  cout<<"ELEMENT NOT FOUND"<<endl;
  if(binarySearchIterative(array,0,size-1, x)==true)
   cout<<"binary search using iteration successful "<<endl;
   else
    cout<<"ELEMENT NOT FOUND"<<endl;
   
  return 0;
}
