//@author: Nour El-din
//@date: 28 April 2023

#include "../stack/Stack.cpp"
#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s) {
    Stack<int> st;
    int sz = s.size();
    int ans = 0;
    int strt= 1e5, end= 0;
    vector<bool> rghtPlcd(sz, true);
    for(int i = 0; i < sz; i++){
        if(s[i] == '(') st.push(i);
        else{
            if(st.isEmpty()){
                rghtPlcd[i] = false;
                continue;
            }
            st.pop();
        }
    }
    while (!st.isEmpty())
    {
        rghtPlcd[st.top()] = false;
        st.pop();
    }
    for(int i = 0; i < sz; i++){
        if(!rghtPlcd[i]) 
            ans = max(ans, end-strt+1), strt = 1e5, end = 0;
        if(s[i] == '(') st.push(i);
        else{
            if(st.isEmpty()){
                ans = max(ans, end-strt+1), strt = 1e5, end = 0;
                continue;
            }
            else{
                strt = min(strt, st.top());
                end = max(end, i);
                st.pop();
            }
        }
    }
    ans = max(ans, end-strt+1);
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << longestValidParentheses(s);
    return 0;
}