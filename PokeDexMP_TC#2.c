/*  First Major Testing of PokeDex MP | 6-2-2022 */

/*  Things to Change after  100% Finish of MP
    - While Loops when asking for character but int will infinite loop
    - SearchByType as a Multiple Choice 
    - Additional Features that make sense(tbd)

    Unknown if Bug or Feature:
    - AddEntry should be case insensitive (e.g. Pikachu and pikachu should be the same)
    - SearchByName should be case insensitive (e.g. Bella, scholarBELLA, bEllAbigbrain ; keyword "Bella"
    - Modify Entry if it also modifies tasks
    - Does Import/Export also exists in Research Tasks since it only affects the Pokemon Entry
    
    Minor Bugs:
    - Manage Data Input Validation (int = yes but char = no) (Fixed 6-4-2022)
    - AddEntry Data Input Validation (int = yes but char = no)
    - Modify Data input Validation (int = yes but char = no)
    - Delete Entry input Validation (int = yes but char = no)
    - Research Task input Validation (int = yes but char = no) (Fixed 6-4-2022)
    - Update Research Task input Validation (int = yes but char = no)
    - Review Task per Pokemon input Validation (int = yes but char = no)
    - Review Task per Type input Validation (int = yes but char = no)

    Done:
    - Main Menu (Good)

    - Manage Data (1 Minor Bug)
    - Add Entry (1 Minor Bug, Unknown)
    - Modify Entry (1 Minor Bug)
    - Delete Entry (1 Minor Bug)
    - Display All Entries (Good)
    - Search Pokemon Name (Unknown)
    - Search Pokemon Type (Good)

    - Research Task (1 Minor Bug)
    - Update Research Task (1 Minor Bug)
    - Review Task per Pokemon (1 Minor Bug)
    - Rewview Task per Type (1 Minor Bug)

    Unfinished:
    - Import Data
    - Export Data

*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> 
#include <windows.h> 

/* Maximum Number of Entries */
#define MAX 150

/* Struct Data Type for Pokemon Entry */
struct details{
    char name20[21];
    char type20[21];
    char description50[51];
    int seen;
    int defeated;
};

/* Functions for Interaction */
void KeyContinue();

/* Functions under Manage Data */
void addEntry();
void modifyEntry();
void deleteEntry();
void displayAllEntries();
void searchByType();
void searchByName();
void importFile();
void exportFile();
/* Functions under Research Tasks */
void reviewTaskPkmn();
void reviewTaskType();
void updateTask();

/* Pokedex Main Menu */
void manageData();
void researchTasks();



/* --- Main Function --- */
int main()
{
    //Greet Trainer
    printf("\nHello Pokemon Trainer! Welcome to the PokeDex!\n");
    KeyContinue();

    //System Variables
    struct details entry[MAX];
    for(int i = 0; i < MAX; i++){
        entry[i].defeated = 0;
        entry[i].defeated = 0;
    }
    int storedEntries =  0;
    char cMainMenu;

    /* Keep Pokedex running until User terminates the program (E) */
    do{ /* Main Menu */
        printf("\n------------------- MAIN MENU -------------------\n\n");
        printf("[M]anage Data\n[R]esearch Tasks\n[E]xit PokeDex\n\n");
        printf("Console: ");
        scanf(" %c", &cMainMenu);
        cMainMenu = tolower(cMainMenu);
        while(cMainMenu != 'm' && cMainMenu != 'r' && cMainMenu != 'e')
        {
            printf("\nInvalid input. Please try again.\n");
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
                //Terminate Program
                system("cls");
                return 0;
            break;
        }
    }while(cMainMenu != 'e');
    return 0;
}

/* Function that clears the terminal screen after pressing any Key */
void KeyContinue(){
	printf("Press any key to continue...");    
	getch();
	printf("\n");
	system("cls");
} 

/*  manageData Function contains all options for managing and accessing pokemon entries  
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored 
*/
void manageData(struct details entry[], int* storedEntries)
{
    system("cls");
    int i;
    char cChoice;

    /* Stay at Manage Data Menu until User exits to Main Menu (9) */
    do{ /* Manage Data Menu */
        printf("\n------------------------ [MANAGE DATA] ------------------------\n\n");
        printf("[1] Add Entry       [4] Display All Entries     [7] Import Data\n");
        printf("[2] Modify Entry    [5] Search Pokemon Name     [8] Export Data\n");
        printf("[3] Delete Entry    [6] Search Pokemon Type     [9] Return Menu\n\n");
        printf("Console: ");
        scanf(" %c", &cChoice); printf("\n");
        while(cChoice != '1' && cChoice != '2' && cChoice != '3' && cChoice != '4' && cChoice != '5' && cChoice != '6' && cChoice != '7' && cChoice != '8' && cChoice != '9')
        {
            printf("Invalid input. Please try again.\n");
            printf("Console: ");
            scanf(" %c", &cChoice); printf("\n");
        }
        switch(cChoice){
            case '1': //Add Entry
                    addEntry(entry, storedEntries); KeyContinue();
                    break;
            case '2': //Modify Entry
                    modifyEntry(entry, storedEntries); KeyContinue();
                    break;
            case '3': //Delete Entry 
                    deleteEntry(entry, storedEntries); KeyContinue();
                    break;
            case '4': //Display All Entries 
                    displayAllEntries(entry, storedEntries); KeyContinue();
                    break;
            case '5': //Search and Display ALL Pokemon by Substring Name
                    searchByName(entry, storedEntries); KeyContinue();
                    break;
            case '6': //Search and Display All Pokemon by Type
                    searchByType(entry, storedEntries); KeyContinue();
                    break;
            case '7': //Import data  from a .txt file to the Pokedex
                    //importData();
                    break;
            case '8': //Export data as a .txt file
                    //exportData();
                    break;    
            case '9': //Return to Main Menu
                    system("cls");
                    break;    
        }
    }while(cChoice != '9');
}

/*  researchTasks Function contains all the options for updating and accesing research tasks
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void researchTasks(struct details entry[], int* storedEntries)
{   
    system("cls");
    char cChoice;

    /* Stay at Research Tasks Menu until user exits to Main Menu */
    do{ /*Research Tasks Menu */
        printf("\n------------------- RESEARCH TASKS -------------------\n\n");
        printf("[1] Update Research Tasks\n[2] Review Research Task per Pokemon\n[3] Review Research Task per Task Type\n[4] Exit\n\n");
        printf("Console: ");
        scanf(" %c", &cChoice); printf("\n");
        while(cChoice != '1' && cChoice != '2' && cChoice != '3' && cChoice != '4')
        {
            printf("Invalid input. Please try again.\n");
            printf("Console: ");
            scanf(" %c", &cChoice);
        }
        switch(cChoice)
        {
            case '1': /* Update Research Task */
                    updateTask(entry, storedEntries);
                    KeyContinue();
                    break;
            case '2': /* Review Research Task Per Pokemon */
                    reviewTaskPkmn(entry, storedEntries);
                    KeyContinue();
                    break;
            case '3': /* Review Research Task Per Pkmn Type */
                    reviewTaskType(entry, storedEntries);
                    KeyContinue();
            case '4': /* Return to Main Menu */
                    system("cls");
                    break;
        }
    }while(cChoice != '4');
}

/*  addEntry Function lets the user add a Pokemon Entry N number of times depending on the user-input
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void addEntry(struct details entry[], int* storedEntries)
{   
    int entryNum, i, j; 
    int addedEntries = 0, duplicateEntry = 0;
    int entriesLeft = MAX - *storedEntries;
    char temp20[21]; 
    //Entry Checking, Ask user for Pokemon Name,Type,Description
    if(entriesLeft != 0){
        printf("Input the number of entries you wish to add | Entries Left: %d\n", entriesLeft);
        do{
            printf("Number of entries to be added: ");
            scanf("%d", &entryNum);
            if(entryNum <= 0 || entryNum > entriesLeft){printf("Invalid Entry! Try Again!\n");}
        }while(entryNum <= 0 || entryNum > entriesLeft);
        
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
            //Validate Character Count for Type & Description
            if(duplicateEntry <= 0){
                duplicateEntry = 0;
                /*For Checking (Delete once MP Finish)
                printf("Entry Index[%d] String temp20 to Name20: %s\n", i, temp20);
                printf("Entry Index[%d] in Function after Copying: %s\n\n", i, entry[i].name20);
                */
		        strcpy(entry[i].name20, temp20);
                do{
                    printf("Pokemon Type: ");
                    scanf(" %[^\n]s", entry[i].type20);
                    if(strlen(entry[i].type20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                }while(strlen(entry[i].type20) > 20);
                do{
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
            duplicateEntry = 0;
        }
    }
    else
    {
        printf("Error: You have reached the Maximum Entry Count! Going back to Main Menu will reset the Entry Data Count\n");
    }
    //Add newly added entries to existing number of entries 
    *storedEntries += addedEntries;
}

/*  modifyEntry Function lets the user change a specific pokemon entry and its contents
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void modifyEntry(struct details entry[], int* storedEntries){
    
    int category; int modifyIndex = 0;
    int i = 0;
    char modify20[21], modify50[51];
    //Validate before Modifying Entry
    if(*storedEntries == 0)
    {
        printf("No Existing Entries Found!\n");
    }
    else
    {
        //Display All Entries
        displayAllEntries(entry, storedEntries);
        //Ask User Inputs
        while(modifyIndex <= 0 || modifyIndex > *storedEntries){
            printf("Which Entry would you wish modify: ");
            scanf(" %d", &modifyIndex); printf("\n");
        }
        modifyIndex--;
        do{
            printf("Which Category would you wish to modify:\n[1] Pokemon Name\n[2] Pokemon Type\n[3] Pokemon Description\n\nConsole: ");
            scanf("%d", &category); printf("\n");
        }while(category <= 0 || category > 3);
 
        while(i <= *storedEntries){
            if(modifyIndex == i){
                if(category == 1){
                    do{
                    printf("Note: Pokemon Name must not exceed more than 20 Characters!\nNew Pokemon Name: ");
                    scanf(" %[^\n]s", modify20); printf("\n");
                    strcpy(entry[i].name20, modify20);
                    if(strlen(entry[i].name20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                    }while(strlen(entry[i].name20) > 20);
                }
                else if(category == 2){
                    do{
                    printf("Note: Pokemon Type must not exceed more than 20 Characters!\nNew Pokemon Type: ");
                    scanf(" %[^\n]s", modify20); printf("\n");
                    strcpy(entry[i].type20, modify20);
                    if(strlen(entry[i].type20) > 20){
                        printf("Error: Pokemon Type must not exceed 20 Characters\n");
                    }
                    }while(strlen(entry[i].type20) > 20);
                }
                else if(category == 3){
                    do{
                    printf("Note: Pokemon Description must not exceed more than 50 Characters!\nNew Pokemon Description: ");
                    scanf(" %[^\n]s", modify50); printf("\n");
                    strcpy(entry[i].description50, modify50);
                    if(strlen(entry[i].description50) > 20){
                        printf("Error: Pokemon Type must not exceed 50 Characters\n");
                    }
                    }while(strlen(entry[i].description50) > 50);
                }
            }
            i++;
        }
    }
}

/*  deleteEntry Function removes an Existing Pokemon Entry
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void deleteEntry(struct details entry[], int *storedEntries)
{
    int index, i;

    if(*storedEntries == 0){
        printf("No Existing Entries Found!\n");
    }
    else{
        displayAllEntries(entry, storedEntries);
        while(index <= 0 || index > *storedEntries){
            printf("Which Entry Index will be deleted: ");
            scanf("%d", &index);
        }
        index--;
        /*---- locating the position of i in the array -------*/
        while(i != index)
        {
            i++;
        }
        /*---- the position of i in the array will be replaced by the value of its right */
        while(i < *storedEntries)
        {
            entry[i] = entry[i + 1];
            i++;
        }
        *storedEntries -= 1;
    }
}

/*  displayAllEntries Function display all existing pokemon entries that the user added or imported
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void displayAllEntries(struct details entry[], int* storedEntries){
    int i;
    if(*storedEntries == 0){
        printf("No Existing Entries Found!\n");
    }else{
        printf("Number of Pokemon Entries: %d\n", *storedEntries);
        printf("Number of Pokemon Left: %d\n", 150 - *storedEntries);
        for(i = 0; i < *storedEntries; i++){
            printf("Entry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n\n", (i+1), entry[i].name20, entry[i].type20, entry[i].description50);
        }
    }
}

/*  searchByName Function lets the user search all existing pokemon entries based on the substring
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void searchByName(struct details entry[], int *storedEntries)
{
    int i, j, k, l;
    char substring[21];
    int len; 
    int ctr = 0, entryCtr = 0, substringCtr = 0;
    if(*storedEntries == 0){
        printf("No Existing Entries Found!\n");
    }
    else{
        printf("Stored Entries: %d\n", *storedEntries);
        printf("Search Name: ");
        getchar(); gets(substring);
        len = strlen(substring);
        
        char arr[len]; // array to access the substrings
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
                    arr[ctr] = '\0';

                    if(strcmp(substring, arr) == 0)
                    {
                        if(substringCtr == 0)
                        {
                            printf("\nEntry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n", (i + 1), entry[i].name20, entry[i].type20, entry[i].description50);
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
    }
}

/*  searchByType Function lets the user search all existing pokemon entries based on its type
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void searchByType(struct details entry[], int *storedEntries)
{
    int i;
    char PokemonType[21];
    int found = 0;
    if(*storedEntries == 0){
        printf("No Existing Entries Found!\n");
    }
    else{
        printf("Stored Entries: %d\n", *storedEntries);
        printf("Pokemon Type: ");
        scanf(" %[^\n]s", PokemonType);
        for(i = 0; i < *storedEntries; i++){
            if(strcmp(PokemonType, entry[i].type20) == 0)
            {
                printf("\nEntry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n\n", (i + 1), entry[i].name20, entry[i].type20, entry[i].description50);
                found++;
            }
        }
        if(found <= 0){
            printf("No Entries Found!\n");
        }
    }

}

/*  importFile Function lets the user import Data as existing data into the PokeDex
        @param     
        @param
*/
void importFile()
{
    printf("\nImport File Externally\n\n");
}

/*  exportFile Function lets the user exxport existing data as a .txt file
        @param     
        @param
*/
void exportFile()
{
    printf("\nExport File Internally\n\n");
}

/*  updateTask Function lets the user update a specific research task of a Pokemon Entry
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void updateTask(struct details entry[], int *storedEntries){

    int updatePokemon, task, addTask;
    if(*storedEntries == 0){
        printf("No Existing Entries Found! Redirecting back to Research Task Menu!\n");
    }
    else{
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
}

/*  reviewTaskPkmn Function lets the user print-out the research task of a specific Pokemon 
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void reviewTaskPkmn(struct details entry[], int *storedEntries)
{
    int task, reviewPokemon;
    if(*storedEntries == 0){
        printf("No Existing Entries Found! Redirecting back to Research Task Menu!\n");
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

/*  reviewTaskType Function lets the user print-out all the Pokemon depending on the research task
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void reviewTaskType(struct details entry[], int *storedEntries)
{

    int i, j, showPokemon, task, valid, found;
    if(*storedEntries == 0){
        printf("No Entries Found! Redirecting back to Research Task Menu!\n");
    }
    else{
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
                        found = 1;
                    }
                    else if(i == *storedEntries - 1 && found != 1){
                        //printf("J: %i and found: %d\n", i, found);
                        printf("No Entries found\n");
                    }
                }
        }
        else if(task == 2){
            printf("Pokemon - Defeated\n");
            for(j = 0; j < *storedEntries; j++){
                if(entry[j].defeated != 0){
                    printf("%s - %d\n", entry[j].name20, entry[j].defeated);
                    found = 1;
                }
                else if(j == *storedEntries - 1 && found != 1){
                    //printf("J: %d and found: %d\n", j, found);
                    printf("No Entries found\n");
                }
            }
        }
        if(found == 1){
            printf("-End of List-\n\n");
        }
    }
}