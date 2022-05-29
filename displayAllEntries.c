#include <stdio.h>
#include <string.h>

#define MAX 150

struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

void displayAllEntries(struct details entry[], int *storedEntries)
{
    int i;

    for(i = 0; i < *storedEntries; i++)
    {
        printf("Entry %d", i + 1);
        printf("Name: %s\n Type: %s\nDescription: %s", entry[i].name20, entry[i].type20, entry[i].description50);
    }
}

int main()
{
    int *storedEntries; // ?

    struct details entry[MAX];
    displayAllEntries(entry, storedEntries);

    return 0;
}