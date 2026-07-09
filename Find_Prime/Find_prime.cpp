#include <vector>

using namespace std;

int solution(int n)
{
    if (n < 2) { return 0; }

    vector<bool> isComposite(n, false); 

    //2는 짝수지만 소수
    //코드의 일관성을 위해 먼저 고려하고 시작.
    int count = 1;

    //홀수만 고려
    //에라토스테네스의 체
    //제곱근 까지만 순회
    for (int i = 3; i * i <= n ; i += 2)
    {
        if (!isComposite[i])
        {
            for (int j = i * i; j <= n; j += 2*i ) //홀수 짝수를 더할 때만 홀수
            {
                isComposite[j] = true;
            }
        }
    }

    for (int i = 3; i<=n; i++)
    {
        if (!isComposite[i]) {count++;}
    }

    return count;
}