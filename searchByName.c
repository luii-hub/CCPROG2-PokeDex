#include <stdio.h>
#include <string.h>

#define MAX 150

struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

void searchByName(struct details entry[], int *storedEntries)
{
    int i, j, k;
    char substring[21];
    int len; 
    int ctr = 0;

    printf("Search: ");
    gets(substring);
    len = strlen(substring);

    char arr[len]; // array to access the substrings

    for(i = 0; i < *storedEntries; i++) // searching the array of strings
    {
        if(strlen(entry[i].name20) >= len)
        {
            for(j = 0; j < strlen(substring); j++) // searching each character of a given string
            {
                if(substring[0] == entry[i].name20[j]) // searching for a character in the string that is equal to the first letter of the given substring
                {
                    for(k = 0; k < len; k++) // for the new array
                    {
                        arr[k] = entry[i].name20[j];   
                        ctr++; // count the number of elements inside the string to determine the index of the null value
                    }
                    substring[ctr + 1] = '\0';
                    if(strcmp(arr, substring) == 0)
                    {
                        printf("\nEntry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n\n", (i + 1), entry[i].name20, entry[i].type20, entry[i].description50);
                    }
                }
            }
        }
    }

}

int main()
{
    int *storedEntries; // assign a value 

    struct details entry[MAX];
    searchByName(entry, storedEntries);

    return 0;
}

// wala kang battlepass ble
// DI PA SIYA GUMAGANA T-T