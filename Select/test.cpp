#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Binsearch()
{
    int target;
    vector<int> a;
    while (cin >> target)
    {
        a.push_back(target);
        if (cin.get() == '\n')
            break;
    }
    cin >> target;
    int high = a.size() - 1;
    int low = 0;
    while (low < high)
    {
        int mid = (low + high + 1) / 2;
        if (a[mid] < target)
            low = mid;
        else
            high = mid - 1;
    }
    return a[low] < target ? low : -1;
}

int main()
{
    cout << Binsearch();
}
