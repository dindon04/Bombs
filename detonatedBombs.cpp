#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

auto calculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int maxDetBombs(std::vector<std::vector<int>>& bombs) 
{
    int DetonatedBombsCounter = 0;

    int n = bombs.size();

    for (int i = 0; i < n; i++) 
    {
        int x1 = bombs[i][0];
        int y1 = bombs[i][1];
        int r1 = bombs[i][2];

        int bombsDetonated = 0;
        
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                double distance = calculateDistance(x1, y1, x2, y2);

                if (distance <= r1 + r2)
                {
                    bombsDetonated++;
                }
            }
        }
        DetonatedBombsCounter = std::max(DetonatedBombsCounter, bombsDetonated);
    }
    return DetonatedBombsCounter + 1;
}
