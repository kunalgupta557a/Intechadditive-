/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
            remove a digit to print the largest number possible
            
            
so we will use greedy approach and remove the smallest number 
as the size of number formed after removing one digit will always be same 
its best to remove smallest number
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int min=INT_MAX;
    int n;
    cin>>n;
    int nn=n;
    //find the min element
    while(n!=0){
        int x=n%10;
        if(x<=min) min=x;
        n=n/10;
    }
    char m=char(min+48);

    string s=to_string(nn);
    //remove the min element
    for(int i=0;i<s.size();i++){
        if(s[i]==m){
            s.erase(s.begin()+i);
            break;
        }
    }
    n=stoi(s);
    cout<<n;
    
    return 0;
}
