#include <stdio.h>
#include <string.h>

#define MAX 150

struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

void addEntry(struct details entry[])
{
    int entryNum; 
    int i, storedEntries; // ?? pano to makukuha hjhdkjskj (current number of entries stored in the pokedex before adding)
    int entriesLeft = MAX - storedEntries;

    printf("Number of entries to be added: ");
    scanf("%d", entryNum);

    // TO DO: count the number of stored entries and validate the number of entries left before proceeding to add
    // if(entryNum <= entriesLeft) proceed

    for(i = storedEntries; i < storedEntries + entryNum; i++) // ?? not sure if i = storedEntries OR i = (storedEntries + 1) indexing is a bitch
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
    // ?? anong gagawin pag kumulang or lumabis sa characters?
}

int main()
{
    struct details entry[MAX];
    addEntry(entry);

    return 0;
}