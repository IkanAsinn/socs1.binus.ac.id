#include <stdio.h>

int main() {

    int tc;
    scanf("%d", &tc); getchar();

    for (int q = 1; q <= tc; q++)
    {
        int n;
        scanf ("%d", &n);

        int front = 1, sheet = 1, back = 0;
        bool isFront = true;

        printf("Case #%d:\n", q);

        while (back < n)
            back += 4;

        if (n == 1)
            printf ("Sheet 1, front: Blank, 1\nSheet 1, back: Blank, Blank\n");
        
        else
        {
            while (front < back)
            {
                printf ("Sheet %d, ", sheet);
                printf (isFront ? "front: " : "back: ");

                if (isFront)
                {
                    printf (back > n ? "Blank, " : "%d, ", back);
                    printf ("%d\n", front++);
                    back--;
                }

                else
                {
                    printf ("%d, ", front++);
                    printf (back > n ? "Blank\n" : "%d\n", back);
                    back--;
                    sheet++;
                }

                isFront = !isFront;
            }
        }
        
    }

    return 0;
}

/*
3
4
14
1
*/