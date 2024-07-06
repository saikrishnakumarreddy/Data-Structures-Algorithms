// Tabulation based approach
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 
int fib(int n) {
    vector<int> tab(n+1);
    
    tab[0]=0;
    tab[1]=1;
    
    for(int i=2; i<=n; i++) {
        tab[i] = fib(n-1) + fib(n-2);
    }

    return tab[n];
}


int main() {
    cout<<fib(4);
    return 0;
}
