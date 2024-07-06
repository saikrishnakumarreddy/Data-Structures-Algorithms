// Top down Approach - Memorization technique.
// Time complexity -> n+n-1 =2n-1 -> O(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> mem(100,-1);
 
int fib(int n) {
    if(mem[n] != -1){
        return mem[n];
    }
    if (n==0 || n==1) {
        mem[n]=n;
        return mem[n];
    }
    mem[n] = fib(n-1) + fib(n-2);
    return mem[n];
}

int main() {
    cout<<fib(4);
    return 0;
}
