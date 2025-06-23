#include <iostream>
using namespace std;

int main()
{
    int n;
    int value;
    int sum_of_squares = 0;

    cin >> n;

    for (int i = 0; i < n; ++i)
	{
        cin >> value;
        sum_of_squares += value * value;
    }

    cout << sum_of_squares << endl;

    return 0;
}