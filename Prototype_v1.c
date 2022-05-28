#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <conio.h> 
#include <windows.h> 

/* Pokedex Main Menu */
void mainMenu();
void manageData();
void researchTasks();

/* Family Functions under Manage Data */
void entryOptions();
void searchOptions();
void fileOptions();

/* Functions under Entry Options */
void addEntry();
void modifyEntry();
void deleteEntry();
void displayAllEntries();

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

    printf("\n------------------- MANAGE DATA -------------------\n\n");

    printf("[1] Entry Pokemon\n[2] Search Pokemon\n[3] File Options\n[4] Exit\n\n");
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
        // call entry options func
        entryOptions();
        break;
        case 2:
        // call search options func
        searchOptions();
        break;
        case 3:
        // call file func
        fileOptions();
        break;
        case 4:
        // call mainMenu func 
        mainMenu();
        break;
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
            printf("Review Research Task per Pokemon\n");
            printf("Execute Research Task per Pokemon Function\n\n"); // TEST Function
            KeyContinue();
            break;
       case 2:
            // update research task
            printf("Review Research Task per Pokemon\n");
            printf("Execute Research Task per Task Type Function\n\n"); // TEST Function
            KeyContinue();
            break;
       case 3:
            // update research task function
            printf("Update Research Task \n");
            printf("Execute Update Function\n\n"); // TEST Function
            KeyContinue();
       case 4:
            // Exit, go back to Main Menu
            mainMenu();
       break;
    }
}

/* Family Function: manageData() */
/* Shows all Entry/Search/File Options of the PokeDex */
void entryOptions()
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
        case 1: addEntry(); break;
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

/* Family Function: entryOptions() */
/* Description for each opt\nion*/
void addEntry()
{
    printf("\nAdd Pokemon Entry\n\n");
    KeyContinue();
    entryOptions();
}
void modifyEntry()
{
    printf("\nModify Pokemon Entry\n\n");
    KeyContinue();
    entryOptions();
}
void deleteEntry()
{
    printf("\nDelete Pokemon Entry\n\n");
    KeyContinue();
    entryOptions();
}
void displayAllEntries()
{
    printf("\nDisplay All Pokemon recorded in the Pokedex\n\n");
    KeyContinue();
    entryOptions();
}

/* Family Function: searchOptions() */
/* Description for each option*/
void searchByType()
{
    printf("Search Pokemon by Element Type: [Example]\n");
    printf("Show List of Pokemon by Element Type\n\n");
    KeyContinue();
    searchOptions();
}
void searchByName()
{
    printf("Search Pokemon according to Pokemon Name: [Example]\n");
    printf("Show List of Pokemon according to Pokemon Name\n\n");
    KeyContinue();
    searchOptions();
};

/* Family Function: fileOptions() */
/* Description for each option*/
void importFile()
{
    printf("\nImport File Externally\n\n");
    KeyContinue();
    fileOptions();
}
void exportFile()
{
    printf("\nExport File Internally\n\n");
    KeyContinue();
    fileOptions();
}
