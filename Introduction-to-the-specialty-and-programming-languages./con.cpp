#include <iostream>

using namespace std;

int main()
{

    try
    {

        try

        {
            throw 3.14;
        }

        catch (double)
        {
            cout << "Error 1 ";
        }
    }

    catch (...)

    {
        cout << "Error 2 ";
    }

    return 0;
}