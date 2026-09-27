#include <iostream>

using namespace std;

int fact(int n)
{
    //탈출조건
    if (n == 1 || n ==0)
    {
        return n;
    }

    //로직
    //재귀호출
    return n * fact(n-1); 

}

int main()
{
    int number;

    cin >> number;

    cout << "factorial of " << number << " is" << fact(number) << endl; 

    return 0;
}