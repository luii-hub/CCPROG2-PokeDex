#include <stdio.h>
#include <string.h>

#define MAX 150

struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

void deleteEntry(struct details entry[], int *storedEntries)
{
    int index, i;

    printf("Index of entry to be deleted: ");
    scanf("%d", &index);

    /*---- locating the position of i in the array -------*/
    while(i != index - 1)
    {
        i++;
    }

    /*---- the position of i in the array will be replaced by the value of its right */
    while(i < *storedEntries)
    {
        entry[i] = entry[i + 1];
        i++;
    }

    *storedEntries--;
}
int main()
{
    int *storedEntries; // ?
    // int *ptr = &storedEntries;

    struct details entry[MAX];
    deleteEntry(entry, storedEntries);

    return 0;
}