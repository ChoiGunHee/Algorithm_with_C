#include <iostream>

using namespace std;

int board[10001];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];

    int answer = 0;

    int start = 0;
    int end = 0;
    int partial_sum = 0;

    while (end <= N)
    {
        if (partial_sum >= M)
            partial_sum -= board[start++];
        else if (partial_sum < M)
            partial_sum += board[end++];
        if (partial_sum == M)
            answer++;
    }

    cout << answer << "\n";
}