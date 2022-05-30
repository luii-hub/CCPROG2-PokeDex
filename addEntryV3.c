#include <stdio.h>
#include <string.h>

#define MAX 150

struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

void addEntry(struct details entry[], int* storedEntries)
{   

    int entryNum; 
    int entriesLeft = MAX - *storedEntries;
    int addedEntries = 0;
    int duplicateEntry = 0;
    int i, j;
    char temp20[21];
    //Entry Checking, Ask user for Pokemon Name,Type,Description
    if(entriesLeft != 0){
        printf("[ADD ENTRY] Input the number of entries you wish to add, you only have %d Entries Left\n", entriesLeft);
        printf("Number of entries to be added: ");
        scanf("%d", &entryNum);
        for(i = *storedEntries; i < *storedEntries + entryNum; i++)
        {   
            //Validate Character Count for Name
            do{
                printf("\nPokemon Name: ");
                scanf("%s", &temp20);
                if(strlen(temp20) > 20){
                    printf("Error: Pokemon Name must not exceed 20 Characters\n");

                }
            }while(strlen(temp20) > 20);

            //Validate for Duplicate Pokemon Entries
            for(j = 0; j <= *storedEntries; j++){
                if(strcmp(entry[j].name20,temp20) == 0)
                {
                    printf("Error: Pokemon %s, is already in the list of entries\n");
                    duplicateEntry++;
                }
            }
            if(duplicateEntry <= 0){
                duplicateEntry = 0;
                printf("Entry Index[%d] String temp20 to Name20: %s\n", i, temp20);
                strcpy(entry[i].name20, temp20);
                printf("Entry Index[%d] in Function after Copying: %s\n\n", i, entry[i].name20);
                //Validate Character Count for Type & Description
                do{
                    printf("Pokemon Type: ");
                    scanf("%s", entry[i].type20);
                    if(strlen(entry[i].type20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                }while(strlen(entry[i].type20) > 20);
                do{
                    printf("Pokemon Description: "); getchar();
                    gets(entry[i].description50);
                    if(strlen(entry[i].description50) > 50){
                        printf("Error: Pokemon Description must not exceed 50 Characters\n");
                    }
                }while(strlen(entry[i].description50) > 50);
                    
                addedEntries++;
            }
            else{
                i--;
            }
            /*  For Checking
                printf("Count: %d\n", count);
                printf("Index: %d\nName: %s\nType: %s\nDesc:%s\n\n", i, entry[i].name20, entry[i].type20, entry[i].description50);
            */
            duplicateEntry = 0;
        }
    }
    else
    {
        printf("Error: You have reached the Maximum Entry Count! Going back to Main Menu will reset the Entry Data Count\n");
        //Call entryOptionFunctions After void Function
    }
    *storedEntries += addedEntries;
}

//For Testing
void printEntries(struct details entry[], int storedEntries){
    for(int i = 0; i < storedEntries; i++){
        printf("\nEntry Index%d:\nPokemon Name:%s\nPokemon Type:%s\nDescription:%s\n\n", i, entry[i].name20, entry[i].type20, entry[i].description50);
    }
}

int main()
{
    struct details entry[MAX];
    int storedEntries = 0;
    // For Testing
    int alis;
    do{
        printf("[1] AddEntry\n[2] PrintEntries\n[3] Exit\n");
        scanf("%d", &alis);
        if(alis == 1){
            addEntry(entry, &storedEntries);
        }
        else if(alis == 2){
            printEntries(entry, storedEntries);
        }
        else{
           return 0; 
        }
    }while(alis != '3');
    
}