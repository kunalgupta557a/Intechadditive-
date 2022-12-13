/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<float> input;
    // y=f{x}
    //so normal soloution for this will be for each cordinate calculate its max height on left and right and minus min of it to height of the cordinate
    // but as now we know height of each cordinate to predict the almost perfect answer we can enter as many heights of cordinate on very small interval in the input vector
    //here lets take the small interval as 0.1 and let equation given be y=mod(x);
    //y=abs(x); -1<=x<=1
    float i=-1;
    while(i<=1){
        input.push_back(abs(i));
        i+=0.1;    // we can also make this interval smaller but then time will increase
    }
    
    float ans =0;
    vector<float> left(input.size()),right(input.size());
    left[0]=input[0];
    
    for(int i=1;i<input.size();i++) {
        left[i]=max(input[i],left[i-1]);
    }
    
    right[input.size()-1]=input[input.size()-1];

    for(int i =input.size()-2;i>=0;i--) {
        right[i]=max(input[i], right[i+1]);
    }

    for (int i =1;i<input.size()-1;i++) {
        ans+=min(left[i],right[i])-input[i];
    }
    cout<<ans;
}
    
