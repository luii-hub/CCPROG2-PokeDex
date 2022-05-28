#include <stdio.h>
#include <string.h>

#define MAX 150

struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

void modifyEntry(struct details entry[])
{
    int index, i;
    int storedEntries;

    // count number of stored entries (?)
    // call displayAllEntries()

    printf("Index of entry to be modified: ");
    scanf("%d", &index);

    for(i = 0; i < storedEntries; i++)
    {
        if(i == index - 1)
        {
            printf("Name (1 - 20 characters): ");
            get(entry[i].name20);
            // TO DO: check if there is existing pokemon
            // TO DO: validate the number of characters before proceeding to the next input
            printf("Type (1 - 20 characters): ");
            get(entry[i].type20);
            // TO DO: validate the number of characters before proceeding to the next input
            printf("Description (1 - 50 characters): ");
            get(entry[i].description50);
            // TO DO: validate the number of characters before proceeding to the next input
        }
    }
}

int main()
{
    struct details entry[MAX];
    modifyEntry(entry);

    return 0;
}