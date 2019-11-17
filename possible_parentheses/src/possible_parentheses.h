#include <list>
# define MAX_SIZE 100

// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n


void _printParenthesis(int pos, int n, int open, int close, std::list<std::string> & result);

void possibleParenthesis(int n, std::list<std::string> & result)
{
    if(n > 0)
        _printParenthesis(0, n, 0, 0, result);
    return;
}

void _printParenthesis(int pos, int n, int open, int close, std::list<std::string> & result)
{
    static char str[MAX_SIZE];

    if(close == n)
    {
        result.push_back(str);
        return;
    }
    else
    {
        if(open > close)
        {
            str[pos] = '}';
            _printParenthesis(pos+1, n, open, close+1, result);
        }

        if(open < n)
        {
            str[pos] = '{';
            _printParenthesis(pos+1, n, open+1, close, result);
        }
    }
}


