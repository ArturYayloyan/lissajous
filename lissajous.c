#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main()
{
    printf("%*s", 22, "LISSAJOUS");
    printf("\n%*s", 18, "CREATIVE COMPUTING");
    printf("\n%*s", 16, "MORRISTOWN NEW JERSEY");
    printf("\n\n\n");
    double f1, f2, p2;
    int x1, y1, y2;

    printf("Relative freq. for x: ");
    scanf("%lf", &f1);
    if (f1 < 1 || f1 != (int)f1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Relative freq. for y: ");
    scanf("%lf", &f2);
    if (f2 < 1 || f2 != (int)f2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Y phase, multiple of pi: ");
    scanf("%lf", &p2);
    f1 = 2 * PI * f1;
    f2 = 2 * PI * f2;
    p2 = PI * p2;

    for (x1 = -18; x1 <= 18; x1++)
    {
        double x = x1 / 18.0;
        double t1 = x, t2 = PI - x;

        for (int i = 0; i < f1; i++)
        {
            double t3 = (t1 + 2 * i * PI) / f1;
            double t4 = (t2 + 2 * i * PI) / f1;
            y1 = 30 * sin(f2 * t3 + p2);
            y2 = 30 * sin(f2 * t4 + p2);
            y1 = (y1 > 0) ? (int)(y1 + 0.5) : (int)(y1 - 0.5);
            y2 = (y2 > 0) ? (int)(y2 + 0.5) : (int)(y2 - 0.5);

            // Sort and print y1 and y2
            if (y1 < y2)
            {
                printf("%*s*\n", 36 + y1, "");
                printf("%*s*\n", 36 + y2, "");
            }
            else
            {
                printf("%*s*\n", 36 + y2, "");
                printf("%*s*\n", 36 + y1, "");
            }
        }
    }

    return 0;
}
