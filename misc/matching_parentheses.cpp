#include <stack>
#include <iostream>
using namespace std;

bool matching_parentheses(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty()) return false;
            if (c == ')' && st.top() != '(') return false;
            if (c == ']' && st.top() != '[') return false;
            if (c == '}' && st.top() != '{') return false;
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    string expr1 = "{()}[]";
    cout << "Q: Are parentheses balanced? : " << expr1 << endl;
    matching_parentheses(expr1) ? cout << "A: Yes" << endl :  cout << "A: No" << endl;

    string expr2 = "{([]))";
    cout << "Q: Are parentheses balanced? : " << expr2 << endl;
    matching_parentheses(expr2) ? cout << "A: Yes" << endl :  cout << "A: No" << endl;

    return 0;
}
