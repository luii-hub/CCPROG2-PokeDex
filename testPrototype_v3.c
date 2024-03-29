/*  Things to Change after  100% Finish of MP
    - While Loops when asking for character but int will infinite loop (refer to old MP for SOlution)

*/

//BUG SA SEARCHNAME
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
    int seen;
    int defeated;
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
    for(int i = 0; i < MAX; i++){
        entry[i].defeated = 0;
        entry[i].defeated = 0;
    }
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
                researchTasks(entry, &storedEntries);
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
                    deleteEntry();
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
                    KeyContinue();
                    //seachPokemonName();
                    break;
            case 6:
                    //Search and Display All Pokemon by Type
                    searchByType(entry, storedEntries);
                    KeyContinue();
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

void researchTasks(struct details entry[], int* storedEntries)
{   
    system("cls");

    int nChoice;

    do{

        printf("\n------------------- RESEARCH TASKS -------------------\n\n");

        printf("[1] Update Research Tasks\n[2] Review Research Task per Pokemon\n[3] Review Research Task per Task Type\n[4] Exit\n\n");
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
            case 1:
                /* review research task 
                    - per pokemon
                    - per task type
                */
                updateTask(entry, storedEntries);
                KeyContinue();
                break;
        case 2:
                // update research task
                reviewTaskPkmn(entry, storedEntries);
                KeyContinue();
                break;
        case 3:
                // update research task function
                reviewTaskType(entry, storedEntries);
                KeyContinue();
        case 4:
                // Exit, go back to Main Menu
                break;
        }
    }while(nChoice != 4);
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
                scanf(" %[^\n]s", temp20);
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
                    scanf(" %[^\n]s", entry[i].type20);
                    if(strlen(entry[i].type20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                }while(strlen(entry[i].type20) > 20);
                do{
                    //bug dito after  the next iteration
                    printf("Pokemon Description: "); getchar();
                    scanf(" %[^\n]s", entry[i].description50);
                    if(strlen(entry[i].description50) > 50){
                        printf("Strlen: %d\n", strlen(entry[i].description50));
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
                    scanf(" %[^\n]s", modify20); printf("\n");
                    strcpy(entry[j].name20, modify20);
                    if(strlen(entry[j].name20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                    }while(strlen(entry[j].name20) > 20);
                }
                else if(category == 2){
                    do{
                    printf("Note: Pokemon Type must not exceed more than 20 Characters!\nNew Pokemon Type: ");
                    scanf(" %[^\n]s", modify20); printf("\n");
                    strcpy(entry[j].type20, modify20);
                    if(strlen(entry[j].type20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                    }while(strlen(entry[j].type20) > 20);
                }
                else if(category == 3){
                    do{
                    printf("Note: Pokemon Description must not exceed more than 50 Characters!\nNew Pokemon Description: ");
                    scanf(" %[^\n]s", modify50); printf("\n");
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

void deleteEntry()
{
    printf("\nDelete Pokemon Entry\n\n");
    KeyContinue();
    //entryOptions();
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
    scanf(" %[^\n]s", PokemonType);
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
void updateTask(struct details entry[], int *storedEntries){

    int updatePokemon, task, addTask;

    do{
        printf("What type of Research Task was completed?\n\n");
        printf("[1] Seen \n[2] Defeated\nConsole: "); scanf("%d", &task); printf("\n");
        if(task <= 0 || task > 2){
            printf("Invalid Input! Try Again\n");
        }
    }while(task <= 0 || task > 2);
    //Print All Pokemon Entries
    printf("Pokemon Entries:\n");
    for(int i = 0; i < *storedEntries; i++){
        printf("(%d) %s\n", i+1, entry[i].name20);
    }
    printf("\nSelect the Entry Number of the Pokemon that you wish to update Research Task:\n");
    scanf("%d",&updatePokemon); printf("\n");
    if(updatePokemon-1 >= *storedEntries || updatePokemon-1 < 0){
        printf("Error: Invalid Entry Number! Redirecting back to the Research Task Menu!\n");
        //Terminate Void Function -> main()
    }
    else{
        updatePokemon--;
        if(task == 1){
            printf("How many %s have you Seen?\n", entry[updatePokemon].name20);
            printf("Console: "); scanf("%d", &addTask); printf("\n");
            entry[updatePokemon].seen += addTask;
        }
        else if(task == 2){
            printf("How many %s have you Defeated?\n", entry[updatePokemon].name20);
            printf("Console: "); scanf("%d", &addTask); printf("\n");
            entry[updatePokemon].defeated += addTask;
        }
        //Debugger
        printf("Pokemon %s:\nSeen: %d\nDefeated: %d\n\n", entry[updatePokemon].name20, entry[updatePokemon].seen, entry[updatePokemon].defeated);
    }

}

//Bug if no  entry, bug siya (infinite loop)  // I THINK NAAYOS NA?
void reviewTaskPkmn(struct details entry[], int *storedEntries)
{
    int task, reviewPokemon;
    if(*storedEntries == 0){
        printf("No Entries Available!\n Redirecting back  to Research Task Menu!\n");
    }
    else{
        //Print All Pokemon Entries
        printf("List of All Pokemon Entries:\n");
        for(int i = 0; i < *storedEntries; i++){
            printf("(%d) %s\n", i+1, entry[i].name20);
        }

        do{
            printf("Select the Pokemon Entry Number that you wish to Review?\n\n");
            printf("Console: "); scanf("%d", &reviewPokemon); printf("\n");
            if(reviewPokemon <= 0 || reviewPokemon > *storedEntries){
                printf("Invalid Input! Try Again\n");
            }
        }while(reviewPokemon <= 0 || reviewPokemon > *storedEntries);
        printf("Pokemon: %s\nSeen: %d\nDefeated: %d\n\n", entry[reviewPokemon-1].name20, entry[reviewPokemon-1].seen, entry[reviewPokemon-1].defeated);
    }
        
}

void reviewTaskType(struct details entry[], int *storedEntries)
{

    int i, j, showPokemon, task, valid;

    do{
        printf("What type of Research Task will be displayed?\n\n");
        printf("[1] Seen \n[2] Defeated\nConsole: "); scanf("%d", &task); printf("\n");
        if(task <= 0 || task > 2){
            printf("Invalid Input! Try Again\n");
        }
    }while(task <= 0 || task > 2);

    if(task == 1){
        printf("Pokemon - Seen\n");
        for(i = 0; i < *storedEntries; i++){
            if(entry[i].seen != 0){
                printf("%s - %d\n", entry[i].name20, entry[i].seen);
            }
        }
        printf("-End of List-\n\n");
    }
    else if(task == 2){
        printf("Pokemon - Defeated\n");
        for(j = 0; j < *storedEntries; j++){
            if(entry[j].defeated != 0){
                printf("%s - %d\n", entry[j].name20, entry[j].defeated);
            }
        }
        printf("-End of List-\n\n");
    }
    //researchTasks();
}

//add validation for each research  task pag wala pang entries tas ung entry found na ewan?