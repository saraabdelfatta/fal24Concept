// assigment2 question 3 
//3. Write a program a small lexical analyzer that takes strings and checks whether they abide by one of the regular expressions indicated in question (1) or not.


#include <iostream>

//library to apply the regular expression encapsulated in a regex to a target sequence of characters. The regex iterators are used to traverse the entire set of regular expression matches found within a sequence
#include <regex>
using namespace std;

regex first("0+1+(11)*0?");
regex second("[0-9]+((E|e)(\\+|\\-)?[0-9]+)?");
regex third("[a-z]([a-z0-9])*");

void checkString(const string& x)
{
    if (regex_match(x, first))
    {
        cout << "\"" << x << "\" matches the first regular expression which is (0+1+(11)*0?)" << endl;
    }
    else if (regex_match(x, second))
    {
        cout << "\"" << x << "\" matches the second regular expression which is [0-9]+((E|e)(\\+|\\-)?[0-9]+)?" << endl;
    }
    else if (regex_match(x, third))
    {
        cout << "\"" << x << "\" matches the third regular expression which is [a-z]([a-z0-9])* " << endl;
    }
    else
    {
        cout << "\"" << x << "\" does not match any of the regular expressions" << endl;
    }
}


int main() {

    string x;
    cout << " Enter the text that you want to cheek " << endl;


    while (cin >> x)
    {
        if (x == "stop")
        {
            break;
        }
        else
        {
            checkString(x);
            cout << " Try again or press s " << endl;

        }
    }





    return 0;
}