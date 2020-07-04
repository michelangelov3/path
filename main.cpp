#include <iostream>

using namespace std;

void path(int track[101][101], int N)
{
    int help[101][101];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            help[i][j] = 0;
    }

    int w = 0, k = N-1;

    help[w][k] = 1; // top right included in the output, but not the loop

    while(w < N-1 || k > 0)
    {
        if(track[w][k] == 3) // 3 - came from the previous column k-1
        {
            help[w][k-1] = 1;
            k--;
        }
        else if(track[w][k] == 4) // 4 - came from the previous row w+1
        {
            help[w+1][k] = 1;
            w++;
        }

    }

    for(int i = N-1; i >= 0; i--)
    {
        for(int j = 0; j < N; j++)
        {
            if(help[i][j] != 0)
            cout << i << " " << j << endl;
        }
    }

}

int main()
{
     int tab[101][101], N, cost[101][101], backtrack[101][101];
    cout << "Podaj liczbe N (wymiary tablicy NxN):" << endl;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> tab[i][j];
            cost[i][j] = 0;
            backtrack[i][j] = 0;
        }
    }

    cost[N-1][0] = tab[N-1][0];
    int a = N-1;

     for(int i = N-2; i >= 0; i--)  // col 0 in matrix cost can be chosen in 1 way only
    {
        cost[i][0] = cost[i+1][0] + tab[i][0];
        backtrack[i][0] = 4; //up

    }
    for(int j = 1; j < N; j++)  // row N-1 in matrix cost can be chosen in 1 way only
    {
        cost[a][j] = cost[a][j-1] + tab[a][j];
        backtrack[a][j] = 3; //right
    }


 for(int i = N-2; i >= 0; i--)
        {
            for(int j = 1; j < N; j++)
            {
                if(cost[i][j-1] <= cost[i+1][j])
                {
                    cost[i][j] = tab[i][j] + cost[i][j-1];
                    backtrack[i][j] = 3;
                }

                else
                {
                    cost[i][j] = tab[i][j] + cost[i+1][j];
                    backtrack[i][j] = 4;
                }
            }
        }

   cout << "Koszt: " << cost[0][a] << endl;

   path(backtrack, N);


    return 0;
}
