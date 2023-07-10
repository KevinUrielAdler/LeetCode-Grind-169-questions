#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> pare, brac, sqbr;
        size_t tam = s.size();
        for (size_t i = 0; i < tam; i++)
        {
            if (s[i] == '(')
                pare.push(i);
            else if (s[i] == '{')
                brac.push(i);
            else if (s[i] == '[')
                sqbr.push(i);
            else if (s[i] == ')')
            {
                if (pare.empty())
                    return false;
                if (!brac.empty() && brac.top() >= pare.top())
                    return false;
                if (!sqbr.empty() && sqbr.top() >= pare.top())
                    return false;
                pare.pop();
            }
            else if (s[i] == '}')
            {
                if (brac.empty())
                    return false;
                if (!pare.empty() && pare.top() >= brac.top())
                    return false;
                if (!sqbr.empty() && sqbr.top() >= brac.top())
                    return false;
                brac.pop();
            }
            else
            {
                if (sqbr.empty())
                    return false;
                if (!brac.empty() && brac.top() >= sqbr.top())
                    return false;
                if (!pare.empty() && pare.top() >= sqbr.top())
                    return false;
                sqbr.pop();
            }
        }
        if (pare.empty() && brac.empty() && sqbr.empty())
            return true;
        return false;
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
