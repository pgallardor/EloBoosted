#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

vector <int> kmpPreprocess(string t){
    int i = 0, j = -1;
    int n = t.size();
    vector <int> prefix(n);
    prefix[0] = -1;
    
    while(i < n){
        while(j >= 0 && t[i] != t[j]){
            j = prefix[j];
        }

        i++; j++;
        prefix[i] = j;
    }

    return prefix;
}


int main() 
{ 
    int n,q;

    string txt;

    while(cin >> txt){

        string str = txt;

        reverse(txt.begin(), txt.end());

        string tmp = txt + "$" + str;
        
        vector<int> prefix = kmpPreprocess(tmp);

        n = tmp.size();

        q = prefix[n];

        cout << str + txt.substr(q) << endl;
    }
    
    return 0; 
} 