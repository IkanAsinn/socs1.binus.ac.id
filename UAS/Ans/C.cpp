#include <stdio.h>
#include <string.h>

int main() {

    FILE *fp = fopen("testdata.in", "r");

    int n;
    fscanf (fp, "%d\n", &n);

    int ctrB40 = 0, ctrM40 = 0;
    char nameM40[n][50], nameB40[n][50];

    for (int i = 0; i < n; i++)
    {
        char cat[4], name[50];
        int money;
        fscanf (fp, "%[^,],%[^,],%d\n", cat, name, &money);

        if (strcmp(cat, "B40") == 0)
            strcpy(nameB40[ctrB40++], name);

        else
            strcpy(nameM40[ctrM40++], name);
    }

    char target[4];
    fscanf (fp, "%s\n", target);

    if (strcmp(target, "B40") == 0)
    {
        for (int i = 0; i < ctrB40; i++)
            printf ("B40 %s 1000\n", nameB40[i]);

        printf ("Total Recipients: %d\n", ctrB40);
        printf ("Total Amount: %d\n", 1000 * ctrB40);
    }

    else
    {
        for (int i = 0; i < ctrM40; i++)
            printf ("M40 %s 600\n", nameM40[i]);

        printf ("Total Recipients: %d\n", ctrM40);
        printf ("Total Amount: %d\n", 600 * ctrM40);
    }
    
    return 0;
}

/*
6
B40,Sofea,1000
M40,Mikael,600
B40,Adam,1000
B40,Irene,1000
M40,Cyntia,600
B40,Alif,1000
B40
*/