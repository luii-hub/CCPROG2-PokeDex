#include <stdio.h>
#include <string.h>
#include <ctype.h>

void mainMenu();
void manageData();
void researchTasks();

// manageData
void entryOptions();
void searchOptions();
void importExport();

// functions under entry options
void addEntry();
void modifyEntry();
void deleteEntry();
void displayAllEntries();

// researchTasks
void reviewRT();
void updateRT();


/* ---------------------------main function */
int main()
{
    char cMainMenu;

    printf("\n[M]ain Menu\n");
    printf("[E]xit\n");
    scanf(" %c", &cMainMenu);
    cMainMenu = tolower(cMainMenu);

    while(cMainMenu != 'm' && cMainMenu != 'e')
    {
        printf("Invalid input. Please try again.\n");
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
    }

    return 0;
}

/* ---------------------------mainMenu function */
void mainMenu()
{
    char cChoice;

    printf("\nM A I N   M E N U\n\n");

    printf("[M]anage Data\n[R]esearch Tasks\n[E]xit\n");
    scanf(" %c", &cChoice);
    cChoice = tolower(cChoice);

    while(cChoice != 'm' && cChoice != 'r' && cChoice != 'e')
    {
        printf("Invalid input. Please try again.\n");
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

/* ---------------------------manageData function under mainMenu */
void manageData()
{
    int nChoice;

    printf("\nM A N A G E   D A T A\n\n");

    printf("1 | Entry Options\n2 | Search Options\n3 | File\n4 | Exit\n");
    printf("Input: ");
    scanf("%d", &nChoice);

    while(nChoice < 1 || nChoice > 4)
    {
        printf("Invalid input. Please try again.\n");
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
        printf("[call search options func]\n"); // TEST
        break;
        case 3:
        // call file func
        printf("[call file func]\n"); // TEST
        break;
        case 4:
        // call mainMenu func 
        mainMenu();
        break;
    }
}

/* ---------------------------researchTasks function under mainMenu */
void researchTasks()
{
    int nChoice;

    printf("\nR E S E A R C H   T A S K S\n\n");

    printf("1 | Review Research Task\n2 | Update Research Tasks\n3 | Exit\n");
    printf("Input: ");
    scanf("%d", &nChoice);

    while(nChoice < 1 || nChoice > 3)
    {
        printf("Invalid input. Please try again.\n");
        scanf("%d", &nChoice);
    }

    switch(nChoice)
    {
        case 1:
        /* review research task 
            - per pokemon
            - per task type
        */
       printf("[review research task]\n"); // TEST
       break;
       case 2:
       // update research task
       printf("[update research task]\n"); // TEST
       break;
       case 3:
       // call mainMenu func
       mainMenu();
       break;
    }
}

/* ---------------------------entryOptions func under manageData */
void entryOptions()
{
    int nChoice;

    printf("\nE N T R Y   O P T I O N S\n\n");

    printf("1 | Add Entry \n2 | Modify Entry\n3 | Delete Entry\n4 | Display All Entries\n5 | Return\n");
    printf("Input: ");
    scanf("%d", &nChoice);

    while(nChoice < 1 || nChoice > 5)
    {
        printf("Invalid input. Please try again.\n");
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
    printf("\n[S E A R C H   O P T I O N S]\n\n");

}
void importExport()
{
    printf("\n[F I L E]\n\n");

}

void addEntry()
{
    printf("\nA D D   E N T R Y\n\n");

}
void modifyEntry()
{
    printf("\nM O D I F Y   E N T R Y\n\n");

}
void deleteEntry()
{
    printf("\nD E L E T E   E N T R Y\n\n");

}
void displayAllEntries()
{
    printf("\nD I S P L A Y   A L L   E N T R I E S\n\n");

}
