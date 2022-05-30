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

/* Functions under Entry Options */
void addEntry();
void printEntries(); //For Debugging
void modifyEntry();
void deleteEntry();
void displayAllEntries();

/* Pokedex Main Menu */
void mainMenu();
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

/* Functions for Interaction */
void KeyContinue(){
	printf("Press any key to continue...");    
	getch();
	printf("\n");
	system("cls");
} 

/* --- Main Function --- */
int main()
{
    char cMainMenu;

    printf("Hello Pokemon Trainer! Welcome to the PokeDex!\n");
    printf("\n[M]ain Menu\n");
    printf("[E]xit\n\n");
    printf("Console: ");
    scanf(" %c", &cMainMenu);
    cMainMenu = tolower(cMainMenu);

    while(cMainMenu != 'm' && cMainMenu != 'e')
    {
        printf("\nInvalid input. Please try again.\n\n");
        printf("Console: ");
        scanf(" %c", &cMainMenu);
        cMainMenu = tolower(cMainMenu);
    }

    if(cMainMenu == 'm')
    {
        // go to main menu
        mainMenu();
    }
    else
    {
        // exit program
        printf("[Exit]\n");
        return 0;
    }

    return 0;
}

/* ---------------------------mainMenu function */
void mainMenu()
{
    system("cls");

    char cChoice;
    
    printf("\n------------------- MAIN MENU -------------------\n\n");
    printf("[M]anage Data\n[R]esearch Tasks\n[E]xit PokeDex\n\n");
    printf("Console: ");
    scanf(" %c", &cChoice);
    cChoice = tolower(cChoice);

    while(cChoice != 'm' && cChoice != 'r' && cChoice != 'e')
    {
        printf("\nInvalid input. Please try again.\n");
        printf("Console: ");
        scanf(" %c", &cChoice);
        cChoice = tolower(cChoice);
    }

    if(cChoice == 'm')
    {
        // call manage data function
        manageData();
    }
    else if(cChoice == 'r')
    {
        // call research tasks function
        researchTasks();
    }
    else
    {
        // exit program
    }
}

/* Family Function: mainMenu() */
void manageData()
{
    system("cls");

    int nChoice;
    struct details entry[MAX];
    int i;
    int storedEntries = 0;


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
        scanf("%d", &nChoice);

        while(nChoice < 1 || nChoice > 9)
        {
            printf("Invalid input. Please try again.\n");
            printf("Console: ");
            scanf("%d", &nChoice);
        }

        switch(nChoice)
        {
            case 1:
                    //Add Entry
                    addEntry(entry, &storedEntries);
                    KeyContinue();
                    break;
            case 2:
                    //Modify Entry
                    modifyEntry();
                    break;
            case 3:
                    //Delete Entry
                    deleteEntry();
                    break;
            case 4:
                    //Display All Entries 
                    displayAllEntries(entry, &storedEntries);
                    KeyContinue();
                    break;
            case 5:
                    //Search and Display ALL Pokemon by Substring Name
                    //seachPokemonName();
                    break;
            case 6:
                    //Search and Display All Pokemon by Type
                    //searchPokemonType();
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
                    //Return to Main Menu and Delete all Existing Data
                    break;    
        }
    }while(nChoice != 9);
    if (nChoice == 9){
        mainMenu();
    }
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
            mainMenu();
       break;
    }
}

/* Family Function: manageData() */
/* Shows all Entry/Search/File Options of the PokeDex (Might Remove)
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
void addEntry(struct details entry[], int* storedEntries){   

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



void modifyEntry()
{
    printf("\nModify Pokemon Entry\n\n");
    KeyContinue();
    //entryOptions();
}
void deleteEntry()
{
    printf("\nDelete Pokemon Entry\n\n");
    KeyContinue();
    //entryOptions();
}

void displayAllEntries(struct details entry[], int *storedEntries){
    int i;
    printf("Pokemon Entries:\n");
    for(i = 0; i < *storedEntries; i++){
        printf("\nEntry Index: %d\nPokemon Name: %s\nPokemon Type: %s\nDescription: %s\n\n", (i+1), entry[i].name20, entry[i].type20, entry[i].description50);
    }
}

/* Family Function: searchOptions() */
/* Description for each option*/
void searchByType()
{
    printf("Search Pokemon by Element Type: [Example]\n");
    printf("Show List of Pokemon by Element Type\n\n");
    KeyContinue();
    //searchOptions();
}
void searchByName()
{
    printf("Search Pokemon according to Pokemon Name: [Example]\n");
    printf("Show List of Pokemon according to Pokemon Name\n\n");
    KeyContinue();
    //searchOptions();
};

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

