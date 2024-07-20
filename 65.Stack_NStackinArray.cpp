#include<iostream>
using namespace std;
class NStack{
	int *a,*top,*next;
	int n;				//no. of stacks
	int size;			//size of main array
	int freeSpot;		//tells free space in main array
	public:
		NStack(int _n,int _s):n(_n),size(_s){
			freeSpot = 0;
			a=new int(size);
			top=new int(n);
			next=new int(size);
			
			for(int i=0;i<n;i++)
				top[i]=-1;
			for(int i=0;i<size-1;i++)
				next[i]=i+1;
			next[size-1]=-1;
		}
		bool push(int X,int M){
			if(freeSpot==-1){
				return false;//stack overflow
			}
			
			int index = freeSpot;
			
			freeSpot = next[index];
			
			a[index] = X;
			
			next[index] = top[M-1];
			
			top[M-1]=index;
			
			return true;	//push success
		}
		int pop(int M){
			if(top[M-1]==-1){
				return -1; //stack underflow
			}
			
			int index = top[M-1];
			
			top[M-1] = next[index];
			
			int popedElement = a[index];
			
			next[index] = freeSpot;
			
			freeSpot =index;
			return popedElement;
				
		}
		~NStack(){
			delete[] a;
			delete[] top;
			delete[] next;
		}
	
};

int main(){
	NStack s(3,6);
	cout<<s.push(10,1)<<endl;
	cout<<s.push(10,1)<<endl;
	cout<<s.push(10,1)<<endl;
	cout<<s.push(10,1)<<endl;
	cout<<s.push(10,1)<<endl;
	cout<<s.push(11,1)<<endl;
	cout<<s.push(10,1)<<endl;
	cout<<s.pop(1)<<endl;
}
