/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

//this function will compress the string aaabbb into a3b3
//and this will also take care of cases where a char happen more than 9 times
//for ex aaabbbcccccccccc will give a3b3c10
string compress(string s){
    string res;
    int count=1;  //counts that holds the frequencey of charachter
    res+=s[0];
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) count++;
        else{
            res+=to_string(count);
            count=1;
            res+=s[i+1];
        }
    }
    //for frequency of final charachter
    if(s[s.size()-1]==s[s.size()-2]){
        res+=to_string(count);
    }
    else{
        //res+=s[s.size()-1];
        res+="1";
    }
    
    return res;
}


string secondcomp(string s){
    string res;
    res+=s[0];
    vector<char> cha; // stores the charachter in a vector
    vector<int> freq; // stores the frequencey of each charachter
    //we are using these method instead of simply traversing the array inorder to take care of cases where a char occurs more than 9 times
    
    
    for(int i=0;i<s.size();i++){
        int x=int(s[i]);
        if(x>=97 && x<=122) cha.push_back(s[i]);
        else{
            string f;
            while(x>=48 && x<=57 && i<s.size()){
                f+=s[i];
                ++i;
                x=int(s[i]);
            }
            i--;
            int num=stoi(f);
            freq.push_back(num);
        }
    }
    
  //filling our result string by mentioned condition
    for(int i=0;i<freq.size()-1;i++){
        if(freq[i]==freq[i+1]){    // if frequency same then add charachter
            res+=cha[i+1];
        }
        else{
            res+=to_string(freq[i]);  // if frequency not same then add char as well as frequency
            res+=cha[i+1];
        }
    }
    //adding final left out frequecy
    res+=to_string(freq[freq.size()-1]);
    return res;
}

string decompress(string s){
    string res;
    vector<char> cha;
    vector<int> freq;
    int j=0;
    for(int i=0;i<s.size();i++){
        int x=int(s[i]);
        if(x>=97 && x<=122){ cha.push_back(s[i]);
            j++;
        }
        else{
            string f;
            while(x>=48 && x<=57 && i<s.size()){
                f+=s[i];
                ++i;
                x=int(s[i]);
            }
            i--;
            int num=stoi(f);
            while(j--){
            freq.push_back(num);
            }
            j=0;
        }
    }
    
    //normally printing char from cha vector with number of time as given in freq vector
    for(int i=0;i<cha.size();i++){
        int x=freq[i];
        
        while(x){
            res+=cha[i];
            x--;
        }
    }
    return res;
}


int main()
{
    string s;
    cin>>s;
    string x=compress(s);
    cout<<x<<endl;
    string y=secondcomp(x);
    cout<<y<<endl;
    string z=decompress(y);
    cout<<z<<endl;
    return 0;
}
