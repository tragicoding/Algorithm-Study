#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());
    int startPoint = 0;
    int endPoint = people.size() - 1;
    int count = 0;

    while (startPoint <= endPoint)
    {
        if (people[startPoint] + people[endPoint] <= limit)
        {
            startPoint++;
        }

        endPoint--;
        count++;
    }

    return count;
}
