#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        size_t tam = s.size();
        for (auto i : s)
        {
            if (i == '(')
                brackets.push(')');
            else if (i == '[')
                brackets.push(']');
            else if (i == '{')
                brackets.push('}');
            else
            {
                if (brackets.empty() || brackets.top() != i)
                    return false;
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};

int main()
{
    Solution sol;
    string s = "({()}){[]}()";
    bool ans = sol.isValid(s);
    cout << boolalpha << ans;
    return 0;
}
