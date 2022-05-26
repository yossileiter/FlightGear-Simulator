#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int olaviat(char c)
{
    /*************
     **Operator precedence
     *************/
    switch (c)
    {
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
double eval(char *exp)
{
    /*************
    **Convert to reverse polish
    *************/
    char n[50], o[50];
    static int nl = 0, ol = 0;

    while (*exp)
    {
        while (isspace(*exp))
            *exp++;
        if (*exp == '(')
        {
            o[ol++] = *exp++;
        }
        else if (*exp == ')')
        {
            while (o[--ol] != '(')
            {
                n[nl++] = o[ol];
                n[nl++] = ' ';
            }
            *exp++;
        }
        else if (isdigit(*exp))
        {
            while (isdigit(*exp))
            {
                n[nl++] = *exp++;
            }
            n[nl++] = ' ';
        }
        else if (strchr("+-*/^", *exp))
        {
            if (olaviat(*exp) > olaviat(o[ol - 1]))
            {
                o[ol++] = *exp++;
            }
            else
            {
                if (olaviat(*exp) == olaviat(o[ol - 1]) && olaviat(*exp) == 3)
                {
                    o[ol++] = *exp++;
                }
                else
                {
                    n[nl++] = o[ol - 1];
                    n[nl++] = ' ';
                    o[--ol] = '\0';
                }
            }
        }
    }

    for (int k = ol - 1; k >= 0; k--)
    {
        n[nl++] = o[k];
        n[nl++] = ' ';
    }
    /*******************************/
    // cout << "Reverse Polish" << endl ;
    // for (int i = 0 ; i < nl-1 ; i++){
    //         cout << n[i]  ;
    //     }
    // cout << endl ;
    n[nl + 1] = '\0';
    /*******************************
    **Calculate Result
    *******************************/
    double temp[50];
    char *e;
    ol = 0;
    int nol = 0;
    e = n;
    int digitcount = 0;
    while (*e)
    {
        while (isspace(*e))
            *e++;
        if (isdigit(*e))
        {
            while (isdigit(*e))
            {
                o[ol++] = *e++;
                digitcount++;
            }
            temp[nol++] = atof(o);
            for (int i = 0; i < digitcount; i++)
                o[i] = '\0';
            ol = 0;
            digitcount = 0;
        }
        else if (strchr("+-*/^", *e))
        {
            // char opr ;
            double tempAns = 0;
            switch (*e)
            {
            case '+':
                tempAns = temp[nol - 2] + temp[nol - 1];
                break;
            case '-':
                tempAns = temp[nol - 2] - temp[nol - 1];
                break;
            case '*':
                tempAns = temp[nol - 2] * temp[nol - 1];
                break;
            case '/':
                tempAns = temp[nol - 2] / temp[nol - 1];
                break;
            case '^':
                tempAns = pow(temp[nol - 2], temp[nol - 1]);
                break;
            default:
                cout << "\n ";
                continue;
            }
            *e++;
            nol--;
            temp[nol - 1] = tempAns;
            temp[nol] = NULL;
        }
        else
        {
            break;
        }
    }
    double ans = temp[0];

    return ans;
}

int main()
{

    char exp[100];
    char c;
start:
    cin.get(exp, 99);
    cout << eval(exp);
    cout << endl;
    // system("PAUSE");
    return 0;
}