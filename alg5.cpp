int m[1001];
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

int task(int n, int visible)
{
    int first, second, best;
    if (n == 1)
    {
        if (visible) printf("%d\n", m[0]);
        return m[0];
    }
    else if (n == 2)
    {
        if (visible) printf("%d %d\n", m[0], m[1]);
        return m[1];
    }
    else if (n == 3)
    {
        if (visible)
        {
            printf("%d %d\n", m[0], m[1]);
            printf("%d\n", m[0]);
            printf("%d %d\n", m[0], m[2]);
        }
        return m[0] + m[1] + m[2];
    }
    first = m[0] + 2 * m[1] + m[n - 1];
    second = 2 * m[0] + m[n - 2] + m[n - 1];
    best = (first < second) ? first : second;
    if (visible)
    {
        if (best == first)
        {
            printf("%d %d\n", m[0], m[1]);
            printf("%d\n", m[0]);
            printf("%d %d\n", m[n - 2], m[n - 1]);
            printf("%d\n", m[1]);
        }
        else
        {
            printf("%d %d\n", m[0], m[n - 2]);
            printf("%d\n", m[0]);
            printf("%d %d\n", m[0], m[n - 1]);
            printf("%d\n", m[0]);
        }
    }
    return best + task(n - 2, visible);
}




int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++) scanf("%d", &m[i]);
        std::sort(m, m + n);  
        std::cout << "best time result : ";
        int res = task(n, 0);
        printf("%dsec\n", res);
        res = task(n, 1);
    }
    std::cout << std::endl;
}
