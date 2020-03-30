#include <iostream>

using namespace std;

int main()
{
    int y;
    cin >> y;
    //ÈòÄêÌØÕ÷
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        cout << 'Y' << endl;
    else
        cout << 'N' << endl;
    return 0;
}
