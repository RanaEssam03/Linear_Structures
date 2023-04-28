//@author: Nour El-din
//@date: 27 April 2023

#include "../stack/Stack.cpp"
#include <bits/stdc++.h>

using namespace std;

string infixToPostfix(string input){
    map<char, int> priority;
    Stack<char> st;
    int sz = input.size();
    string output;

    priority['-'] = 0;
    priority['+'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    priority['%'] = 1;
    priority['^'] = 2;
    priority['('] = 3;
    priority[')'] = 3;

    for(int i = 0; i < sz; i++){
        string num;
        while (isdigit(input[i]) || isalpha(input[i]))
        {
            num+= input[i];
            i++;
        }
        if(num != ""){
            output += num;
            output += " ";
        }
        if(input[i] == ' '){
            continue;
        }
        else{
            if(input[i] == ')'){
                while (st.top() != '(')
                {
                    output+= st.top();
                    output+= " ";
                    st.pop();
                }
                st.pop();
            }
            else if(input[i] == '('){
                st.push('(');
            }
            else if(st.isEmpty() || priority[input[i]] > priority[st.top()])
                st.push(input[i]);
            else{
                while(!st.isEmpty() && st.top() != '('){
                    output += st.top();
                    output += " ";
                    st.pop();
                }
                st.push(input[i]);
            }
        }
    }
    while (!st.isEmpty())
    {
        output+= st.top();
        output+= " ";
        st.pop();
    }
    return output;
}

int main(){
    cout << infixToPostfix("X^Y / (5*Z) + 2") << endl;
    cout << infixToPostfix("A + B * C + D") << endl;
    cout << infixToPostfix("(A + B) * (C + D)") << endl;
}