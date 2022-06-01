/*  Things to Change after  100% Finish of MP
    - While Loops when asking for character but int will infinite loop (refer to old MP for SOlution)

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <conio.h> 
#include <windows.h> 

//Maximum Number of Entries
#define MAX 150

//Struct Data Type for Entry
struct details{
    char name20[21];
    char type20[21];
    char description50[51];
};

/* Functions for Interaction */
void KeyContinue(){
	printf("Press any key to continue...");    
	getch();
	printf("\n");
	system("cls");
} 

/* Functions under Entry Options */
int validateEntry();
void printEntries(); //For Debugging
void addEntry();
void modifyEntry();
void deleteEntry();
void displayAllEntries();


/* Pokedex Main Menu */
void manageData();
void researchTasks();
void manageDataExit();
void researchTaskExit(); //undeclared

/* Family Functions under Manage Data */
void entryOptions();
void searchOptions();
void fileOptions();

/* Functions under Search Options */
void searchByType();
void searchByName();

/* Functions under File Options */
void importFile();
void exportFile();

/* Functions under Research Task */
void reviewTaskPkmn();
void reviewTaskType();
void updateTask();


/* --- Main Function --- */
int main()
{
    //Greet Trainer
    printf("Hello Pokemon Trainer! Welcome to the PokeDex!\n");
    KeyContinue();

    //System Variables
    struct details entry[MAX];
    int storedEntries =  0;
    char cMainMenu;
    
    do{

        printf("\n------------------- MAIN MENU -------------------\n\n");
        printf("[M]anage Data\n[R]esearch Tasks\n[E]xit PokeDex\n\n");
        printf("Console: ");
        scanf(" %c", &cMainMenu);
        cMainMenu = tolower(cMainMenu);

        while(cMainMenu != 'm' && cMainMenu != 'r' && cMainMenu != 'e')
        {
            printf("\nInvalid input. Please try again.\n\n");
            printf("Console: ");
            scanf(" %c", &cMainMenu);
            cMainMenu = tolower(cMainMenu);
        }
        
        switch(cMainMenu){
            case 'm':
                manageData(entry, &storedEntries);
                break;
            case 'r':
                researchTasks();
                break;
            case 'e':
                system("cls");
                return 0;
            break;
                //Terminate Program
        }
    }while(cMainMenu != 'e');
    return 0;
}


/* Family Function: mainMenu() */
void manageData(struct details entry[], int* storedEntries)
{
    system("cls");
    int nChoice;
    int i;

    do{

        printf("\n------------------------ [MANAGE DATA] ------------------------\n\n");
        printf("[1] Add Entry       [4] Display All Entries     [7] Import Data\n");
        printf("[2] Modify Entry    [5] Search Pokemon Name     [8] Export Data\n");
        printf("[3] Delete Entry    [6] Search Pokemon Type     [9] Return Menu\n\n");

        /* For Testing
        printf("Pokemon Entries:\n");
        for(i = 0; i < storedEntries; i++){
            printf("\nEntry Index%d:\nPokemon Name:%s\nPokemon Type:%s\nDescription:%s\n\n", i, entry[i].name20, entry[i].type20, entry[i].description50);
        } */

        printf("Console: ");
        scanf("%d", &nChoice); printf("\n");

        while(nChoice < 1 || nChoice > 9)
        {
            printf("Invalid input. Please try again.\n");
            printf("Console: ");
            scanf("%d", &nChoice);
            printf("\n");
        }

        switch(nChoice){
            case 1:
                    //Add Entry
                    addEntry(entry, storedEntries);
                    KeyContinue();
                    break;
            case 2:
                    //Modify Entry
                    modifyEntry(entry, storedEntries);
                    KeyContinue();
                    break;
            case 3:
                    //Delete Entry
                    deleteEntry(entry, storedEntries);
                    KeyContinue();
                    break;
            case 4:
                    //Display All Entries 
                    displayAllEntries(entry, storedEntries);
                    KeyContinue();
                    break;
            case 5:
                    //Search and Display ALL Pokemon by Substring Name
                    searchByName(entry, storedEntries);
                    //seachPokemonName();
                    break;
            case 6:
                    //Search and Display All Pokemon by Type
                    searchByType(entry, storedEntries);
                    break;
            case 7:
                    //Import Data (List of Entries)
                    //importData();
                    break;
            case 8:
                    //Export Data (List of Entries)
                    //exportData();
                    break;    
            case 9:
                    //Return to Main Function
                    system("cls");
                    break;    
        }

    }while(nChoice != 9);
}

void researchTasks()
{   
    system("cls");

    int nChoice;

    printf("\n------------------- RESEARCH TASKS -------------------\n\n");

    printf("[1] Review Research Task per Pokemon \n[2] Review Research Task per Task Type\n[3] Update Research Tasks\n[4] Exit\n\n");
    printf("Console: ");
    scanf("%d", &nChoice);

    while(nChoice < 1 || nChoice > 5)
    {
        printf("Invalid input. Please try again.\n");
        printf("Console: ");
        scanf("%d", &nChoice);
    }

    switch(nChoice)
    {
        case 1:
            /* review research task 
                - per pokemon
                - per task type
            */
            reviewTaskPkmn();
            KeyContinue();
            break;
       case 2:
            // update research task
            reviewTaskType();
            KeyContinue();
            break;
       case 3:
            // update research task function
            updateTask();
            KeyContinue();
       case 4:
            // Exit, go back to Main Menu
            break;
    }
}

/*
 Family Function: manageData() 
 Shows all Entry/Search/File Options of the PokeDex (Might Remove)
void entryOptions(struct details entry[], int* storedEntries)
{
    system("cls");

    int nChoice;

    printf("\n------------------- ENTRY OPTIONS -------------------\n\n");

    printf("[1] Add Entry \n[2] Modify Entry\n[3] Delete Entry\n[4] Display All Entries\n[5] Return\n\n");
    printf("Console: ");
    scanf("%d", &nChoice);

    while(nChoice < 1 || nChoice > 5)
    {
        printf("Invalid input. Please try again.\n");
        printf("Console: ");
        scanf("%d", &nChoice);
    }

    switch(nChoice)
    {
        case 1: addEntry(entry, &(*storedEntries)); break;
        case 2: modifyEntry(); break;
        case 3: deleteEntry(); break;
        case 4: displayAllEntries(); break;
        case 5: manageData(); break;
    }
}
void searchOptions()
{
    system("cls");
    int nChoice;

    printf("\n------------------- SEARCH OPTIONS -------------------\n\n");
    
    printf("[1] Search Pokemon by Name \n[2] Search Pokemon by Type\n[3] Return\n\n");
    printf("Console: ");
    scanf("%d", &nChoice);

    while(nChoice < 1 || nChoice > 4)
    {
        printf("Invalid input. Please try again.\n");
        printf("Console: ");
        scanf("%d", &nChoice);
    }

    switch(nChoice)
    {
        case 1: searchByName(); break;
        case 2: searchByType(); break;
        case 3: manageData(); break;
    }
}
void fileOptions()
{
    system("cls");
    int nChoice;

    printf("\n------------------- FILE OPTIONS -------------------\n\n");

    printf("[1] Import a File \n[2] Export a File\n[3] Return\n\n");
    printf("Console: ");
    scanf("%d", &nChoice);

    while(nChoice < 1 || nChoice > 4)
    {
        printf("Invalid input. Please try again.\n");
        printf("Console: ");
        scanf("%d", &nChoice);
    }

    switch(nChoice)
    {
        case 1: importFile(); break;
        case 2: exportFile(); break;
        case 3: manageData(); break;
    }
}
*/
/* Family Function: entryOptions() */
/* Description for each optnion*/
/* to Debug
int validateEntry(char originalEntry[], char nameEntry[], int* storedEntries){
    char existingEntry[21];
    char inputEntry[21];
    char original[21], name[21];
    int i, j;
    int duplicate = 0;

    for(i = 0; i < strlen(originalEntry); i++){
        original = tolower(originalEntry[i]);
        strcat(existingEntry, original);
    }
    for(j = 0; j < strlen(nameEntry); j++){
        name = tolower(nameEntry[j]);
        strcat(inputEntry, name);
    }
    
    if(strcmp(existingEntry,inputEntry) == 0){
        printf("Error: Pokemon %s, is already in the list of entries\n");
        duplicate++;
    }
    else{
        return duplicate;
    }

}
*/

void addEntry(struct details entry[], int* storedEntries){   

    int entryNum; 
    int entriesLeft = MAX - *storedEntries;
    int addedEntries = 0;
    int duplicateEntry = 0;
    int i, j, k;
    char temp20[21]; 
    //Entry Checking, Ask user for Pokemon Name,Type,Description
    if(entriesLeft != 0){
        printf("[ADD ENTRY] Input the number of entries you wish to add\nEntries Left: %d\n", entriesLeft);
        printf("Number of entries to be added: ");
        scanf("%d", &entryNum);
        for(i = *storedEntries; i < *storedEntries + entryNum; i++)
        {   
            //Validate Character Count for Name
            do{
                printf("\nPokemon Name: ");
                scanf("%s", temp20);
                if(strlen(temp20) > 20){
                    printf("Error: Pokemon Name must not exceed 20 Characters.\n");

                }
            }while(strlen(temp20) > 20);

            //Validate for Duplicate Pokemon Entries
            for(j = 0; j <= *storedEntries; j++){
                if(strcmp(entry[j].name20,temp20) == 0)
                {
                    printf("Error: Pokemon %s is already in the list of entries\n", temp20);
                    duplicateEntry++;
                }
            }
            if(duplicateEntry <= 0){
                duplicateEntry = 0;
                /*For Checking (Delete once MP Finish)
                printf("Entry Index[%d] String temp20 to Name20: %s\n", i, temp20);
                
                printf("Entry Index[%d] in Function after Copying: %s\n\n", i, entry[i].name20);
                */
                //Validate Character Count for Type & Description
		        strcpy(entry[i].name20, temp20);
		    
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
                    else if(strlen(entry[i].description50) < 1)
                    {
                        printf("Error: Pokemon Description must be at least 1 Character\n");
                    }
                }while(strlen(entry[i].description50) > 50 || strlen(entry[i].description50) < 1 );
                    
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
    }
    *storedEntries += addedEntries;
}

void modifyEntry(struct details entry[], int* storedEntries){
    
    int modifyIndex, category, i, j = 0;
    char modify20[21], modify50[51];
    int length;
    //Validate before Modifying Entry
    if(*storedEntries == 0){
        printf("Error: No Entries Available!\n");
        //ManageData
    }
    else{
        //Display All Entries
        displayAllEntries(entry, storedEntries);
        //Ask User Inputs
        do{
            printf("Which Entry would you wish modify: ");
            scanf("%d", &modifyIndex); printf("\n");
            modifyIndex--;
        }while(modifyIndex > *storedEntries);
        do{
            printf("Which Category would you wish to modify:\n[1] Pokemon Name\n[2] Pokemon Type\n[3] Pokemon Description\n\nConsole: ");
            scanf("%d", &category); printf("\n");
        }while(category < 0 || category > 3);
 
        while(j < *storedEntries){
            if(modifyIndex == j){
                if(category == 1){
                    do{
                    printf("Note: Pokemon Name must not exceed more than 20 Characters!\nNew Pokemon Name: ");
                    getchar(); gets(modify20); printf("\n");
                    strcpy(entry[j].name20, modify20);
                    if(strlen(entry[j].name20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                    }while(strlen(entry[j].name20) > 20);
                }
                else if(category == 2){
                    do{
                    printf("Note: Pokemon Type must not exceed more than 20 Characters!\nNew Pokemon Type: ");
                    getchar(); gets(modify20); printf("\n");
                    strcpy(entry[j].type20, modify20);
                    if(strlen(entry[j].type20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                    }while(strlen(entry[j].type20) > 20);
                }
                else if(category == 3){
                    do{
                    printf("Note: Pokemon Description must not exceed more than 50 Characters!\nNew Pokemon Description: ");
                    getchar(); gets(modify50); printf("\n");
                    strcpy(entry[j].description50, modify50);
                    if(strlen(entry[j].description50) > 20){
                        printf("Error: Pokemon Type must not exceed 50 Characters\n");
                    }
                    }while(strlen(entry[j].description50) > 50);
                }
                else{
                }
            }
            j++;
        }
    }
}

void deleteEntry(struct details entry[], int* storedEntries)
{
    if(*storedEntries == 0)
    {
        printf("No entries to delete\n");
    }
    else
    {
        printf("\nDelete Pokemon Entry\n\n");

        int index, pos = 0, stored = *storedEntries;

        displayAllEntries(entry, storedEntries);

        printf("Index of entry to be deleted: ");
        scanf("%d", &index);

        while(index < 1 || index > stored)
        {
            printf("Invalid entry! Please try again: ");
            scanf("%d", &index);
        }

        /*---- locating the position of i in the array -------*/
        while(pos != (index - 1))
        {
            pos++;
        }

        /*---- the position of i in the array will be replaced by the value of its right */
        while(pos < stored)
        {
            entry[pos] = entry[pos + 1];
            pos++;
        }

        *storedEntries -= 1;

        printf("stored: %d\n", *storedEntries);
    }

}

void displayAllEntries(struct details entry[], int* storedEntries){
    int i;
    printf("Number of Pokemon Entries: %d\n", *storedEntries);
    printf("Number of Pokemon Left: %d\n", 150 - *storedEntries);
    for(i = 0; i < *storedEntries; i++){
        printf("Entry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n\n", (i+1), entry[i].name20, entry[i].type20, entry[i].description50);
    }
}

void searchByName(struct details entry[], int *storedEntries)
{
    int i, j, k, l;
    char substring[21];
    int len; 
    int ctr = 0, entryCtr = 0, substringCtr = 0;
    printf("Stored Entries: %d\n", *storedEntries);
    printf("Search Name: ");
    getchar();    gets(substring);
    len = strlen(substring);
    
    char arr[len + 1]; // array to access the substrings
    int entries[*storedEntries];

    for(i = 0; i < *storedEntries; i++) // searching the array of strings
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


/* Family Function: searchOptions() */
/* Description for each option*/
void searchByType(struct details entry[], int *storedEntries)
{
    int i;
    char PokemonType[21];
    int found = 0;
    printf("Stored Entries: %d\n", *storedEntries);
    printf("Search Type: ");
    getchar();    gets(PokemonType);
    for(i = 0; i < *storedEntries; i++){
        if(strcmp(PokemonType, entry[i].type20) == 0)
        {
            printf("\nEntry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n\n", (i + 1), entry[i].name20, entry[i].type20, entry[i].description50);
            //entryCtr++;
            found++;
        }
    }
    if(found <= 0){
        printf("No Entries Found!\n");
    }

}

/* Family Function: fileOptions() */
/* Description for each option*/
void importFile()
{
    printf("\nImport File Externally\n\n");
    KeyContinue();
    //fileOptions();
}
void exportFile()
{
    printf("\nExport File Internally\n\n");
    KeyContinue();
    //fileOptions();
}

/* Family Function: MangeData() */
/* Description for each option*/
void manageDataExit(){

}

/* Family Function: researchTasks() */
/* Description for each option*/
void reviewTaskPkmn()
{
    printf("\nShow Pokemon Research Tasks\n\n");
    KeyContinue();
    researchTasks();
}
void reviewTaskType()
{
    printf("\nShows Research Type\n\n");
    KeyContinue();
    researchTasks();
}
void updateTask(){
    printf("\nUpdate Task\n\n");
    KeyContinue();
    researchTasks();
}