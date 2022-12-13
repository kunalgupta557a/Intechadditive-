/*
Real word use case where stack is better than array

1) undo and redo in any text application
2) forward and backward stack in browser
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
public:
    int top;
    int min;  //this will store min element 
	int a[MAX]; // Maximum size of Stack
	Stack() { top = -1;
	min=INT_MAX; }
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
	int minele();
};

bool Stack::push(int x) // storing min element during push only
{
	if(top>=(MAX-1)){
		return false;
	}
	
	else{
	    a[++top]=x;
	    if(top==0){
		min=x;
		return true;}
	else{
	    if(x<=min){
	        min=x;
	        return true;
	    }
	    else return true;
	}
}}

int Stack::pop()
{
	if(top<0) return -1;
	else{
		int x=a[top--];
		return x;
	}
}

bool Stack::isEmpty()
{
	return top<0;
}
int Stack::peek()
{
	if(top<0) return -1;
	else{
		int x=a[top];
		return x;
	}
}

int Stack::minele(){  // to get min element just return min
    return min;
}

int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(5);
	s.push(30);
    int ans=s.minele();
    cout<<ans;
	return 0;
}
