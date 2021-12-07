#include<iostream>
using namespace std;
#define MAX 100
class stack
{
    int stk[MAX];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    bool push(int t)
    {
        if(top>=MAX-1)
        {
            cout<<"stack is overflow"<<endl;
            return false;
        }
        else{
            top=top+1;
            stk[top]=t;
            return true;
        }
    }
    int pop()
    {
        if(top<0)
        {
            cout<<"stack is underflow";
            return 0;
        }
        else{
            int l=stk[top];
            top--;
            return l;
        }
    }
    bool isEmpty()
    {
        return(top<0);
    }
    int peak(){
        return stk[top];
    }
    
};
//a+b*(c-d)
//infix to postfix conversion
int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/'||c=='*')
    return 2;
    else if(c=='+'||c=='-')
    return 1;
    else 
    return -1;
}
string infixtopostfix(string s){
    string postfix;
    stack stk;
    for(int i=0;s[i];i++)
    {
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
        {
            postfix+=c;
        }
        else if(c=='(')
         stk.push(c);
        else if(c==')'){
            while(stk.peak()!='(')
            {
                postfix+=(stk.pop());
            }
            stk.pop();
        }
        else{
            while(!stk.isEmpty()&&prec(stk.peak())>=prec(s[i]))
             postfix+=(stk.pop());
             stk.push(c);
        }
    }
    while(!stk.isEmpty())
    {
        postfix+=(stk.pop());
    }
    return postfix;
}
int main()
{
    stack st;
    cout<<"\n infix to postfix="<<infixtopostfix("a+b*(c-d)");
}