#include <stdio.h>
#include <string.h>

#define MAX 150

struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

void searchByName(struct details entry[], int storedEntries)
{
    int i, j, k, l;
    char substring[21];
    int len; 
    int ctr = 0, entryCtr = 0, substringCtr = 0;

    printf("Search Name: ");
    getchar();    gets(substring);
    len = strlen(substring);
    
    char arr[len + 1]; // array to access the substrings
    int entries[storedEntries];

    for(i = 0; i < storedEntries; i++) // searching the array of strings
    {
        substringCtr = 0;
        if(strlen(entry[i].name20) >= len)
        {
            for(j = 0; j < strlen(entry[i].name20) - len + 1; j++) // searching each character of a given string
            {
                l = j;
                ctr = 0;
                for(k = 0; k < len; k++) // for the new array
                {
                    *(arr + k) = entry[i].name20[l]; 
                    l++;
                    ctr++; // count the number of elements inside the string to determine the index of the null value
                }
                arr[ctr + 1] = '\0';

                if(strcmp(substring, arr) == 0)
                {
                    if(substringCtr == 0)
                    {
                        printf("\nEntry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n\n", (i + 1), entry[i].name20, entry[i].type20, entry[i].description50);
                        entryCtr++;
                        substringCtr++;
                    }
                }
            }
        }
    }

    if(entryCtr == 0)
    {
        printf("No entries found\n");
    }

    KeyContinue();
}

int main()
{
    int storedEntries; // assign a value 

    struct details entry[MAX];
    searchByName(entry, storedEntries);

    return 0;
}

