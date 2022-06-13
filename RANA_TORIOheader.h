/*********************************************************************************************************
This is to certify that this project is our own work, based on our personal efforts in studying and applying the concepts
learned. We have constructed the functions and their respective algorithms and corresponding code by ourselves. The
program was run, tested, and debugged by our own efforts. We further certify that We have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.

RANA, Luis Miguel, DLSU ID# 12179124
TORIO, Ysobella, DLSU ID# 12172030
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> 
#include <windows.h> 
#include <unistd.h> 

#define YELLOW "\033[0;33m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define RED "\033[1;31m"
#define GREY "\033[38;5;8m"
#define RESET "\033[0m"
#define RED8 "\033[48;5;160m\033[38;5;160m"
#define WHITE8 "\033[48;5;15m\033[38;5;15m"
#define BLACK8 "\033[48;5;0m\033[38;5;0m"
#define YELLOW8 "\033[48;5;160m\033[38;5;214m"
#define CYAN8 "\033[48;5;15m\033[38;5;27m"

/* Maximum Number of Entries */
#define MAX 150

/* Struct Data Type for Pokemon Entry */
typedef struct AddOns
{
    char researchDesc[21];
    int researchCount;
} ExtraTasks;

struct details
{
    char name20[21];
    char type20[21];
    char description50[51];
    int seen;
    int defeated;
    ExtraTasks researchTasks[5];
};

/* Functions for Interaction */
void KeyContinue();
void printPokeBall();
void printPikachu();

/* Functions under Manage Data */
void addEntry();
void modifyEntry();
void deleteEntry();
void displayAllEntries();
void searchByName();
void searchByType();
void deleteSubstring();
void importFile();
void exportFile();

/* Functions under Research Tasks */
void updateTask();
void reviewTaskPkmn();
void reviewTaskType();
void pokemonRank();
void addResearchTask();
void showAdditionalTasks();
void updateAddOnsPerPkmn();
void showAddOnsPerPkmn();

/* Pokedex Main Menu */
void manageData();
void researchTasks();


/* Function that clears the terminal screen after pressing any Key */
void KeyContinue()
{
	printf("Press any key to continue...");    
	getch();
	printf("\n");
	system("cls");
} 

/* Function that prints a PokeBall */
void printPokeBall()
{
    printf("\t\t\t\t"BLACK8"```````````````````````````````````````````````\n");
    printf("\t\t\t\t``````````````````          ,``````````````````\n");
    printf("\t\t\t\t````````````     "RED8"*************"RESET"     "BLACK8"````````````\n");
    printf("\t\t\t\t````````/   "RED8"***********************"RESET"   "BLACK8"&````````\n");
    printf("\t\t\t\t``````   "RED8"****"YELLOW8"Hello Pokemon Trainer!"RED8"***"RESET"   "BLACK8"``````\n");
    printf("\t\t\t\t````/  "RED8"*********************************"RESET"  "BLACK8"#````\n");
    printf("\t\t\t\t```  "RED8",***************,   ,****************"RESET"   "BLACK8"```\n");
    printf("\t\t\t\t``  "RED8",************ "RESET"           "RED8" ************,"RESET" "BLACK8" ``\n");
    printf("\t\t\t\t`/  "RED8"***********"RESET"    @@     @@    "RED8"***********"RESET"  "BLACK8"&`\n");
    printf("\t\t\t\t"BLACK8"`                "RESET"/@ @@@@@@@ @*                "BLACK8"`\n");
    printf("\t\t\t\t"BLACK8"`                "RESET"&@ @@@@@@@ @$                "BLACK8"`\n");
    printf("\t\t\t\t`*  "WHITE8",&&&&&&&&&$"RESET"   @@ *@@@, @&   "WHITE8"&&&&&&&&&&,"RESET" "BLACK8"(`\n");
    printf("\t\t\t\t``  "WHITE8"@@@@@@@@@@@@"RESET"     &@@@$     "WHITE8"@@@@@@@@@@@@"RESET"  "BLACK8"``\n");
    printf("\t\t\t\t```  "WHITE8"@@@@@@@@@@@@@@"RESET"         "WHITE8"@@@@@@@@@@@@@@"RESET"  "BLACK8"```\n");
    printf("\t\t\t\t````  "WHITE8"$@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("RESET"  "BLACK8"````\n");
    printf("\t\t\t\t`````#  "WHITE8"@@@@"CYAN8"Welcome to the PokeDex!"RESET""WHITE8"@@@&"RESET"  "BLACK8"$`````\n");
    printf("\t\t\t\t```````&   "WHITE8"@@@@@@@@@@@@@@@@@@@@@@@@ "RESET"   "BLACK8"&```````\n");
    printf("\t\t\t\t`````````$    "WHITE8"@@@@@@@@@@@@@@@@@  "RESET"   "BLACK8"&``````````\n");
    printf("\t\t\t\t"BLACK8"```````````````                ,```````````````\n");
    printf("\t\t\t\t```````````````````````````````````````````````"RESET"\n\n");
}

/* Function that prints Pikachu */
void printPikachu()
{
    printf(GREY"*******"RESET"```````````````````````````````````&"CYAN",,,,,,\n");
    printf(GREY"************"RESET"`````````````````````````&"CYAN",,,,,,,,,,,\n");
    printf(GREY"#*******$$$$***"RESET"````````````````````"GREEN",,,"YELLOW"$$$$"CYAN",,,,,,,\n");
    printf("`"GREY"******$$$$$$$,*******/#"YELLOW"$$"GREY"#/,,,,,,,,"YELLOW"$$$$$$$"CYAN",,,,,"GREY"*\n");
    printf("``****$$$$"YELLOW"$$#**$$$$$$$$$$$$$$$$$$$$"GREY"*,"YELLOW"#$$$$$#"GREEN",,,.`\n");
    printf(GREY"````**/$$**$$$$$$"YELLOW"$$$$$$$$$$$$$$$$$$$$$#,,$$*,,"RESET"```\n");
    printf("``````"GREY"/***#$$$$$"YELLOW"$$$$$$$$$$$$$$$$$$$$$$$#,,,/"RESET"`````\n");
    printf("```````"GREY"**#$$$$$"YELLOW"$$$$$$$$$$$$$$$$$$$$$$$$$(,,"RESET"``````\n");
    printf("``````"GREY"#**$$$$$$"YELLOW"#$$$$$$$$$$$$$$$$$#($$$$$$,,&"RESET"`````\n");
    printf("``````"GREY"**$$$$(*,/"RESET"@"GREY"$*"YELLOW"$$$$$$$$$$$$"GREY",#"RESET"@"GREY"(,,#"YELLOW"$$$$,,"RESET"`````\n");
    printf("``````"GREY"**$$$$"YELLOW"$"GREY",,,,,"YELLOW"$$$$$$$$$$$$$$"GREEN",,,"CYAN",,"YELLOW"$$$$$,,"RESET"`````\n");
    printf("`````"GREY"**$$$"YELLOW"$$$$$$$$$$$$$,,,,$$$$$$$$$$$$$$$$,,"RESET"````\n");
}

/*  manageData Function contains all options for managing and accessing pokemon entries  
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored 
        @param addOnCounter - pointer that points to the address of the # of task add-ons stored 
*/
void manageData(struct details entry[], int* storedEntries, int* addOnCounter)
{
    system("cls");
    /* User Input */
    int nChoice; 

    /* Stay at Manage Data Menu until User exits to Main Menu (9) */
    do
    {   /* Manage Data Menu */
        /* printf("Stored Entries: %d\n",*storedEntries); printf("AddOnCOunt: %d\n",*addOnCounter); */ 
        printf( CYAN "\n------------------------ [MANAGE DATA] ------------------------\n\n" RESET);
        printf(YELLOW"[1]"RESET" Add Entry       "YELLOW"[4]"RESET" Display All Entries     "YELLOW"[7]"RESET" Import Data\n");
        printf(YELLOW"[2]"RESET" Modify Entry    "YELLOW"[5]"RESET" Search Pokemon Name     "YELLOW"[8]"RESET" Export Data\n");
        printf(YELLOW"[3]"RESET" Delete Entry    "YELLOW"[6]"RESET" Search Pokemon Type     "YELLOW"[9]"RESET" Return Menu\n");
        printf( CYAN "\n---------------------------------------------------------------\n\n" RESET);
        printf("Console: ");
        scanf("%d", &nChoice); printf("\n");
        /* Validation Checker */
        while(nChoice <= 0 || nChoice > 9)
        {
            printf(RED "Invalid input. Please try again.\n" RESET);
            printf("Console: ");
            scanf("%d", &nChoice); printf("\n");
        }

        switch(nChoice)
        {
            case 1: //Add Entry
                    addEntry(entry, storedEntries); KeyContinue();
                    break;
            case 2: //Modify Entry
                    modifyEntry(entry, storedEntries); KeyContinue();
                    break;
            case 3: //Delete Entry 
                    deleteEntry(entry, storedEntries); KeyContinue();
                    break;
            case 4: //Display All Entries 
                    displayAllEntries(entry, storedEntries); KeyContinue();
                    break;
            case 5: //Search and Display ALL Pokemon by Substring Name
                    searchByName(entry, storedEntries); KeyContinue();
                    break;
            case 6: //Search and Display All Pokemon by Type
                    searchByType(entry, storedEntries); KeyContinue();
                    break;
            case 7: //Import data  from a .txt file to the Pokedex
                    importFile(entry, storedEntries); KeyContinue();
                    break;
            case 8: //Export data as a .txt file
                    exportFile(entry, storedEntries); KeyContinue();
                    break;    
            case 9: //Return to Main Menu
                    system("cls");
                    break;    
        }
    }while(nChoice != 9);
}

/*  addEntry Function lets the user add a Pokemon Entry N number of times depending on the user-input
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void addEntry(struct details entry[], int* storedEntries)
{   
    int entryNum; // number of entries to be added
    int i, j; // for loop variables for counting the entries
    int addedEntries = 0, duplicateEntry = 0; 
    int entriesLeft = MAX - *storedEntries; // size of remaining space in entry[]
    char temp20[21]; // temporary string variable for the Pokemon name before it gets stored in entry[]
    char type; //User Input for Pokemon Type

    // Entry Checking, Ask user for Pokemon Name, Type, Description
    if(entriesLeft != 0)
    {

        printf("Input the number of entries you wish to add | Entries Left: " YELLOW "%d\n" RESET, entriesLeft);
        do
        {
            printf("Number of entries to be added: ");
            scanf("%d", &entryNum);

            if(entryNum <= 0 || entryNum > entriesLeft)
            {
                printf(RED "Invalid Entry! Try Again!\n" RESET);
            }
        }while(entryNum <= 0 || entryNum > entriesLeft);
        
        for(i = *storedEntries; i < *storedEntries + entryNum; i++)
        {   
            //Validate Character Count for Name
            do
            {
                printf(CYAN "\nPokemon Name: " RESET);
                scanf(" %[^\n]s", temp20);
                if(strlen(temp20) > 20)
                {
                    printf(RED "Error: Pokemon Name must not exceed 20 Characters.\n" RESET);
                }
            }while(strlen(temp20) > 20);

            //Validate for Duplicate Pokemon Entries
            for(j = 0; j <= *storedEntries; j++)
            {
                if(strcmp(entry[j].name20,temp20) == 0)
                {
                    printf(RED "Error: Pokemon %s is already in the list of entries\n" RESET, temp20);
                    duplicateEntry++;
                }
            }

            //Validate Character Count for Type & Description
            if(duplicateEntry <= 0)
            {
                duplicateEntry = 0;
                
		        strcpy(entry[i].name20, temp20);

                do
                {
                    printf("Selection: " RED"[F]ire "RESET CYAN"[W]ater "RESET GREEN"[G]rass "RESET YELLOW"[E]lectic\n"RESET);
                    printf(YELLOW "Pokemon Type: " RESET);
                    scanf(" %c", &type);
                    type = toupper(type);
                }while(type != 'F' && type != 'W' && type != 'G' && type != 'E' );
                switch(type)
                {
                    case 'F':  strcpy(entry[i].type20, "Fire"); break;
                    case 'W':  strcpy(entry[i].type20, "Water"); break;
                    case 'G':  strcpy(entry[i].type20, "Grass"); break;
                    case 'E':  strcpy(entry[i].type20, "Electric"); break;
                }
                do
                {
                    printf(GREEN "Pokemon Description: " RESET); getchar();
                    scanf(" %[^\n]s", entry[i].description50);
                    if(strlen(entry[i].description50) > 50)
                    {
                        // printf("Strlen: %d\n", strlen(entry[i].description50));
                        printf(RED "Error: Pokemon Description must not exceed 50 Characters\n" RESET);
                    }
                }while(strlen(entry[i].description50) > 50);
                addedEntries++;
            }
            else
            {
                i--;
            }
            duplicateEntry = 0;
        }
    }
    else
    {
        printf( RED "Error: You have reached the Maximum Entry Count! Going back to Main Menu will reset the Entry Data Count\n" RESET);
    }

    //Add newly added entries to existing number of entries 
    *storedEntries += addedEntries;
}

/*  modifyEntry Function lets the user change a specific pokemon entry and its contents
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void modifyEntry(struct details entry[], int* storedEntries){
    
    int category; // user input
    int modifyIndex = 0; // entry index to be modified
    int i = 0; // variable for while loop
    char modify20[21], modify50[51], type; // temp string variables for name, type, and description

    //Validate before Modifying Entry
    if(*storedEntries == 0)
    {
        printf(RED "No Existing Entries Found!\n" RESET);
    }
    else
    {
        //Display All Entries
        displayAllEntries(entry, storedEntries);

        //Ask User Input
        while(modifyIndex <= 0 || modifyIndex > *storedEntries)
        {
            printf("Which Entry would you wish modify: ");
            scanf(" %d", &modifyIndex); printf("\n");
        }
        modifyIndex--;
        do
        {
            printf("Which Category would you wish to modify:\n"CYAN"[1]"RESET" Pokemon Name\n"CYAN"[2]"RESET" Pokemon Type\n"CYAN"[3]"RESET" Pokemon Description\n\nConsole: ");
            scanf("%d", &category); 
            printf("\n");
        }while(category <= 0 || category > 3);
 
        while(i <= *storedEntries)
        {
            if(modifyIndex == i)
            {
                if(category == 1)
                {
                    do
                    {
                        printf(YELLOW"Note: Pokemon Name must not exceed more than 20 Characters!\n\n"RESET"New Pokemon Name: ");
                        scanf(" %[^\n]s", modify20); printf("\n");
                        strcpy(entry[i].name20, modify20);
                        if(strlen(entry[i].name20) > 20)
                        {
                            printf(RED "Error: Pokemon Type must not exceed 20 Characters\n" RESET);
                        }
                    }while(strlen(entry[i].name20) > 20);
                }
                else if(category == 2)
                {
                    do
                    {
                        printf("Selection: " RED"[F]ire "RESET CYAN"[W]ater "RESET GREEN"[G]rass "RESET YELLOW"[E]lectic\n"RESET);
                        printf(YELLOW "Pokemon Type: " RESET);
                        scanf(" %c", &type);
                        type = toupper(type);
                    }while(type != 'F' && type != 'W' && type != 'G' && type != 'E' );
                    switch(type)
                    {
                        case 'F':  strcpy(entry[i].type20, "Fire"); break;
                        case 'W':  strcpy(entry[i].type20, "Water"); break;
                        case 'G':  strcpy(entry[i].type20, "Grass"); break;
                        case 'E':  strcpy(entry[i].type20, "Electric"); break;
                    }
                }
                else if(category == 3)
                {
                    do
                    {
                        printf(YELLOW"Note: Pokemon Description must not exceed more than 50 Characters!\n\n"RESET"New Pokemon Description: ");
                        scanf(" %[^\n]s", modify50); printf("\n");
                        strcpy(entry[i].description50, modify50);
                        if(strlen(entry[i].description50) > 20)
                        {
                            printf(RED "Error: Pokemon Type must not exceed 50 Characters\n" RESET);
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
    int index; // index of the entry to be deleted
    int i; // while loop variable indicating the position

    if(*storedEntries == 0)
    {
        printf(RED "No Existing Entries Found!\n" RESET);
    }
    else
    {
        displayAllEntries(entry, storedEntries);
        while(index <= 0 || index > *storedEntries)
        {
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
    int i; // for loop variable for the position

    if(*storedEntries == 0)
    {
        printf(RED"No Existing Entries Found!\n"RESET);
    }else
    {
        printf("Number of Pokemon Entries: %d\n", *storedEntries);
        printf("Number of Pokemon Left: %d\n\n", 150 - *storedEntries);
        for(i = 0; i < *storedEntries; i++)
        {
            printf("Entry Index: " RED "%d\n" RESET "Pokemon Name: " CYAN "%s\n" RESET "Pokemon Type: " GREEN "%s\n" RESET "Description: " YELLOW "%s\n\n" RESET, (i+1), entry[i].name20, entry[i].type20, entry[i].description50);
        }
    }
}

/*  searchByName Function lets the user search all existing pokemon entries based on the substring
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void searchByName(struct details entry[], int *storedEntries)
{
    int i, j, k, l; // loop variables
    char substring[21]; // user input
    int len; // length of the substring
    int ctr = 0, entryCtr = 0, substringCtr = 0; // counter variables

    if(*storedEntries == 0)
    {
        printf(RED "No Existing Entries Found!\n" RESET);
    }
    else{
        printf("Stored Entries: %d\n", *storedEntries);
        printf("Search Name: ");
        getchar(); gets(substring);
        len = strlen(substring);
        
        char arr[len]; // array to access the substrings

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
                            printf("Entry Index: " RED "%d\n" RESET "Pokemon Name: " CYAN "%s\n" RESET "Pokemon Type: " GREEN "%s\n" RESET "Description: " YELLOW "%s\n\n" RESET, (i+1), entry[i].name20, entry[i].type20, entry[i].description50);
                            entryCtr++;
                            substringCtr++;
                        }
                    }
                }
            }
        }
        if(entryCtr == 0)
        {
            printf(RED"No entries found!\n"RESET);
        }
    }
}

/*  searchByType Function lets the user search all existing pokemon entries based on its type
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void searchByType(struct details entry[], int *storedEntries)
{
    int i; // loop variable for position
    char cType;
    char PokemonType[21];
    int found = 0;
    if(*storedEntries == 0)
    {
        printf(RED"No Existing Entries Found!\n"RESET);
    }
    else
    {
        do
        {
            printf("Selection: " RED"[F]ire "RESET CYAN"[W]ater "RESET GREEN"[G]rass "RESET YELLOW"[E]lectic\n"RESET);
            printf(YELLOW "Pokemon Type: " RESET);
            scanf(" %c", &cType);
            cType = toupper(cType);
        }while(cType != 'F' && cType != 'W' && cType != 'G' && cType != 'E' );
        switch(cType)
        {
            case 'F':  strcpy(PokemonType, "Fire"); break;
            case 'W':  strcpy(PokemonType, "Water"); break;
            case 'G':  strcpy(PokemonType, "Grass"); break;
            case 'E':  strcpy(PokemonType, "Electric"); break;
        }
        for(i = 0; i < *storedEntries; i++){
            if(strcmp(PokemonType, entry[i].type20) == 0)
            {
                printf("Entry Index: " RED "%d\n" RESET "Pokemon Name: " CYAN "%s\n" RESET "Pokemon Type: " GREEN "%s\n" RESET "Description: " YELLOW "%s\n\n" RESET, (i+1), entry[i].name20, entry[i].type20, entry[i].description50);
                found++;
            }
        }

        if(found <= 0){
            printf(RED"No Entries Found!\n"RESET);
        }
    }

}

/*  deleteSubstring Function lets the user delete a substring from the string imported from a text file
        @param string[] - the string imported from the text file
        @param substr[] - the substring to be deleted from the given string
*/
void deleteSubstring(char string[], char substr[])
{
    int i = 0; // while loop variable
    int j; // for loop variable
    int stringLength = strlen(string);
    int subLength = strlen(substr);

    while(i < stringLength)
    {
        if (strstr(&string[i], substr) == &string[i]) // searching for a substring
        {
            stringLength -= subLength;

            for (j = i; j < stringLength; j++)
            {
                string[j] = string[j + subLength]; // removing the substring
            }
        }
        else
        {
            i++;
        }
    }

    string[i] = '\0';

}

/*  importFile Function lets the user import Data as existing data into the PokeDex
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void importFile(struct details entry[], int *storedEntries)
{
    char tempName[27], tempType[27], tempDesc[64], tempSpace[64]; // temporary storage of the entries imported
    int entriesLeft = MAX - *storedEntries; // size left of entry[]
    int i; // for loop variable for searching for a duplicate entry
    char cInput; // user input when adding to the list of entries
    int duplicateEntry; // counter for duplicate entry
    int entryCtr = 0;
    int dupCtr = 0;

    if(entriesLeft == 0)
    {
        printf(RED"Error: You have reached the Maximum Entry Count!\n"RESET);
    }
    else
    {
        printf(YELLOW"\nImport File Externally\n\n"RESET);

        FILE *fp; // file pointer
        char filename[31];

        printf("Enter the name or location of the file to be imported: ");
        scanf("%s", filename);

        fp = fopen(filename, "r"); // open file

        if(fp == NULL)
        {
            printf(RED "ERROR: Filename does not exist.\n" RESET);
        }
        else
        {
            printf(YELLOW"File opened successfully!\n"RESET);

            while(!feof(fp) || entriesLeft == 0) // while EOF is not reached or the maximum entry limit is reached
            {
                duplicateEntry = 0;
                
                fgets(tempName, 27, (FILE*)fp);
                fgets(tempType, 27, (FILE*)fp);
                fgets(tempDesc, 64, (FILE*)fp);
                fgets(tempSpace, 64, (FILE*)fp);

                entryCtr++;
            
                // delete substring from the string imported from the file
                deleteSubstring(tempName, "Name: ");
                deleteSubstring(tempType, "Type: ");
                deleteSubstring(tempDesc, "Description: ");

                //delete newline from the string
                deleteSubstring(tempName, "\n");
                deleteSubstring(tempType, "\n");
                deleteSubstring(tempDesc, "\n");

                for(i = 0; i <= *storedEntries; i++)
                {   // duplicate entry
                    if(strcmp(entry[i].name20,tempName) == 0)
                    {
                        duplicateEntry++;
                        dupCtr++;
                    }
                }
                
                if(duplicateEntry == 0) // adding to the list of entries
                {
                    printf("Name: %s\nType: %s\nDescription: %s\n\n", tempName, tempType, tempDesc);
                    printf("Add to the list of entries?\n["GREEN"Y"RESET"]es\n["RED"N"RESET"]o\n");
                    scanf(" %c", &cInput);
                    cInput = tolower(cInput);

                    while(cInput != 'y' && cInput != 'n') 
                    {
                        printf(RED"Invalid input. Please try again.\n"RESET);
                        scanf(" %c", &cInput);
                        cInput = tolower(cInput);
                    }

                    if(cInput == 'y') // adding to the main array
                    {
                        strcpy(entry[*storedEntries].name20, tempName);
                        strcpy(entry[*storedEntries].type20, tempType);
                        strcpy(entry[*storedEntries].description50, tempDesc);

                        *storedEntries += 1;
                        entriesLeft -= 1;
                    }
                }
            }

            if(entryCtr == dupCtr)
            {
                printf(GREEN"\nAll entries from the file are already present in the PokeDex.\n\n"RESET);
            }

            fclose(fp); // close file

        }
    }
}

/*  exportFile Function lets the user exxport existing data as a .txt file
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void exportFile(struct details entry[], int *storedEntries)
{
    char fileName[31]; // name of the file to be exported
    FILE  *fp; // file pointer
    int i; // for loop variable

    if(*storedEntries == 0)
    {
        printf(RED "No existing entries found! Redirecting back to Manage Data...\n" RESET);
    }
    else
    {
        printf(YELLOW"\nExport File Internally\n\n"RESET);
        printf("Enter the filename (excluding the extension): ");
        scanf("%s", fileName);

        while(strlen(fileName) > 26)
        {
            printf(RED"You reached the character limit. Please try again:"RESET);
            scanf("%s", fileName);
        }

        strcat(fileName, ".txt");
        
        printf("Opening file "CYAN"%s"RESET"...\n", fileName);

        fp = fopen(fileName, "w"); // open file

        for(i = 0; i < *storedEntries; i++) // exporting all the entries
        {
            fprintf(fp, "Name: %s\nType: %s\nDescription: %s\n\n", entry[i].name20, entry[i].type20, entry[i].description50);
        }

        fclose(fp); // close file

        printf(GREEN"File successfully exported!\n"RESET);

    }
}

/*  researchTasks Function contains all the options for updating and accesing research tasks
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
        @param addOnCounter - pointer that points to the address of the # of task add-ons stored
        @param researchAddOns[][21] - 
*/
void researchTasks(struct details entry[], int* storedEntries, int* addOnCounter, char researchAddOns[][21])
{   
    system("cls");
    int nChoice; // user input

    /* Stay at Research Tasks Menu until user exits to Main Menu */
    do
    { /*Research Tasks Menu */
        // printf("Stored Entries: %d\n", *storedEntries);
        // printf("AddOnCOunt: %d\n", *addOnCounter); DEBUGGING
        printf(CYAN "\n------------------- RESEARCH TASKS -------------------\n\n" RESET);
        printf(GREEN"[1]"RESET" Update Research Tasks\n"GREEN"[2]"RESET" Review Research Task per Pokemon\n"GREEN"[3]"RESET" Review Research Task per Task Type\n"GREEN"[4]"RESET" Pokemon Ranking\n\n");
        printf(YELLOW"Add-Ons:\n"GREEN"[5]"RESET" Add Additional Research Task\n"GREEN"[6]"RESET" Show Additional Research Task\n"GREEN"[7]"RESET" Update Research Task Add-On\n"GREEN"[8]"RESET" Show Research Task Add-on Per Pokemon\n"GREEN"[9]"RESET" Exit\n");
        printf(CYAN "\n------------------------------------------------------\n\n" RESET);
        printf("Console: ");
        scanf("%d", &nChoice); printf("\n");
        while(nChoice <= 0 || nChoice > 9)
        {
            printf(RED "Invalid input. Please try again.\n" RESET);
            printf("Console: ");
            scanf("%d", &nChoice);
        }
        switch(nChoice)
        {
            case 1: /* Update Research Task */
                    updateTask(entry, storedEntries);
                    KeyContinue();
                    break;
            case 2: /* Review Research Task Per Pokemon */
                    reviewTaskPkmn(entry, storedEntries);
                    KeyContinue();
                    break;
            case 3: /* Review Research Task Per Pkmn Type */
                    reviewTaskType(entry, storedEntries);
                    KeyContinue();
                    break;
            case 4: /* Pokemon Ranking */
                    pokemonRank(entry, storedEntries);
                    KeyContinue();
                    break;
            case 5: /* Add Research Task */
                    addResearchTask(entry, storedEntries, addOnCounter, researchAddOns);
                    KeyContinue();
                    break;
            case 6: /* Show Additional Tasks */
                    showAdditionalTasks(entry, storedEntries, addOnCounter, researchAddOns);
                    KeyContinue();
                    break;
            case 7: /* Update Task Add-Ons */
                    updateAddOnsPerPkmn(entry, storedEntries, addOnCounter, researchAddOns);
                    KeyContinue();
                    break;
            case 8: /* Show Task Add-Ons */
                    showAddOnsPerPkmn(entry, storedEntries, addOnCounter, researchAddOns);
                    KeyContinue();
                    break;
            case 9: /* Return to Main Menu */
                    system("cls");
                    break;
        }
    }while(nChoice != 9);
}

/*  updateTask Function lets the user update a specific research task of a Pokemon Entry
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void updateTask(struct details entry[], int *storedEntries){

    int updatePokemon, task, addTask;
    if(*storedEntries == 0)
    {
        printf(RED"No Existing Entries Found! Redirecting back to Research Task Menu!\n"RESET);
    }
    else
    {
        do
        {
            printf("What type of Research Task was completed?\n\n");
            printf(YELLOW"[1]"RESET" Seen \n"YELLOW"[2]"RESET" Defeated\nConsole: "); 
            scanf("%d", &task); 
            printf("\n");
            if(task <= 0 || task > 2)
            {
                printf(RED "Invalid Input! Try Again\n" RESET);
            }
        }while(task <= 0 || task > 2);
        
        //Print All Pokemon Entries
        printf(CYAN"Pokemon Entries:\n"RESET);

        for(int i = 0; i < *storedEntries; i++)
        {
            printf("(%d) %s\n", i+1, entry[i].name20);
        }

        printf("\nSelect the Entry Number of the Pokemon that you wish to update Research Task:\n");
        scanf("%d",&updatePokemon); printf("\n");

        if(updatePokemon-1 >= *storedEntries || updatePokemon-1 < 0)
        {
            printf(RED "Error: Invalid Entry Number! Redirecting back to the Research Task Menu!\n" RESET);
            //Terminate Void Function -> main()
        }
        else
        {
            updatePokemon--;
            if(task == 1)
            {
                do{
                    printf("How many "CYAN"%s"RESET" have you Seen?\n", entry[updatePokemon].name20);
                    printf("Console: "); 
                    scanf("%d", &addTask); 
                }while(addTask < 0);
                printf("\n");
                entry[updatePokemon].seen += addTask;
            }
            else if(task == 2)
            {
                do{
                    printf("How many "CYAN"%s"RESET" have you Defeated?\n", entry[updatePokemon].name20);
                    printf("Console: "); 
                    scanf("%d", &addTask); 
                }while(addTask < 0);
                printf("\n");
                entry[updatePokemon].defeated += addTask;
            }

            //Debugger
            // printf("Pokemon %s:\nSeen: %d\nDefeated: %d\n\n", entry[updatePokemon].name20, entry[updatePokemon].seen, entry[updatePokemon].defeated);
        }
    }   
}

/*  reviewTaskPkmn Function lets the user print-out the research task of a specific Pokemon 
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void reviewTaskPkmn(struct details entry[], int *storedEntries)
{
    int reviewPokemon;
    if(*storedEntries == 0)
    {
        printf(RED"No Existing Entries Found! Redirecting back to Research Task Menu!\n"RESET);
    }
    else
    {
        //Print All Pokemon Entries
        printf(YELLOW"List of All Pokemon Entries:\n"RESET);
        for(int i = 0; i < *storedEntries; i++)
        {
            printf(CYAN"(%d)"RESET" %s\n", i+1, entry[i].name20);
        }

        do
        {
            printf("Select the Pokemon Entry Number that you wish to Review:\n\n");
            printf("Console: "); 
            scanf("%d", &reviewPokemon); 
            printf("\n");
            if(reviewPokemon <= 0 || reviewPokemon > *storedEntries)
            {
                printf(RED "Invalid Input! Try Again\n" RESET);
            }
        }while(reviewPokemon <= 0 || reviewPokemon > *storedEntries);

        printf("Pokemon: "CYAN"%s\n"RESET"Seen: "YELLOW"%d\n"RESET"Defeated: "GREEN"%d\n\n"RESET, entry[reviewPokemon-1].name20, entry[reviewPokemon-1].seen, entry[reviewPokemon-1].defeated);
    }
}

/*  reviewTaskType Function lets the user print-out all the Pokemon depending on the research task
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void reviewTaskType(struct details entry[], int *storedEntries)
{
    int i, j, task, found;
    if(*storedEntries == 0)
    {
        printf(RED"No Entries Found! Redirecting back to Research Task Menu!\n"RESET);
        sleep(1);
    }
    else
    {
        do
        {
            printf(YELLOW"What type of Research Task will be displayed?\n\n");
            printf(CYAN"[1]"RESET" Seen \n"CYAN"[2]"RESET" Defeated\nConsole: "); 
            scanf("%d", &task); 
            printf("\n");

            if(task <= 0 || task > 2)
            {
                printf(RED "Invalid Input! Try Again\n" RESET);
            }
        }while(task <= 0 || task > 2);

        if(task == 1)
        {
            
            printf(GREEN"Pokemon - Seen\n"RESET);
            for(i = 0; i < *storedEntries; i++)
            {
                if(entry[i].seen != 0)
                {
                    printf("%s - %d\n", entry[i].name20, entry[i].seen);
                    found = 1;
                }
                else if(i == *storedEntries - 1 && found != 1)
                {
                    //printf("J: %i and found: %d\n", i, found);
                    printf(RED "No Entries found\n" RESET);
                }
            }
        }
        else if(task == 2)
        {
            printf(GREEN"Pokemon - Defeated\n"RESET);
            for(j = 0; j < *storedEntries; j++)
            {
                if(entry[j].defeated != 0)
                {
                    printf("%s - %d\n", entry[j].name20, entry[j].defeated);
                    found = 1;
                }
                else if(j == *storedEntries - 1 && found != 1)
                {
                    //printf("J: %d and found: %d\n", j, found);
                    printf(RED "No Entries found\n" RESET);
                }
            }
        }
        if(found == 1)
        {
            printf(GREEN"\n-End of List-\n\n"RESET);
        }
    }
}

/*  pokemonRank Function produces the top 5 Pokemon based on the total of their research progress
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
*/
void pokemonRank(struct details entry[], int *storedEntries)
{
    struct rank
    {
        int index;
        int total;
    } pokemon[MAX];

    int maxRank = 5;
    int i, j, max, tempTotal, tempIndex;        
    
    if(*storedEntries == 0)
    {
        printf(RED "No Existing Entries Found! Redirecting back to Research Task Menu!\n" RESET);
    }
    else
    {
        if(*storedEntries < 5)
        {
            maxRank = *storedEntries;
        }

        // initialize values for index
        for(i = 0; i < *storedEntries; i++)
        {
            pokemon[i].index = i;
        }

        // initialize values for total
        for(i = 0; i < *storedEntries; i++)
        {
            pokemon[i].total = entry[i].seen + entry[i].defeated;
        }

        // sorting
        for(i = 0; i < *storedEntries - 1; i++)
        {
            max = i;
            for(j = i + 1; j < *storedEntries; j++)
            {
                if(pokemon[max].total < pokemon[j].total)
                {
                    max = j;
                }
            }

            // swapping
            if(i != max)
            {
                // total
                tempTotal = pokemon[i].total;
                pokemon[i].total = pokemon[max].total;
                pokemon[max].total = tempTotal;
                // index
                tempIndex = pokemon[i].index;
                pokemon[i].index = pokemon[max].index;
                pokemon[max].index = tempIndex;
            }
        }

        for(i = 0; i < maxRank; i++)
        {
            printf(RED "TOP %d\n"RESET"Pokemon Name: "CYAN"%s\n"RESET"Pokemon Type: %s\nDescription: %s\nSeen: "YELLOW"%d\n"RESET"Defeated: "GREEN"%d\n\n" RESET, (i+1), entry[pokemon[i].index].name20, entry[pokemon[i].index].type20, entry[pokemon[i].index].description50, entry[pokemon[i].index].seen, entry[pokemon[i].index].defeated);
        }
    }
}

/*  addResearchTask Function lets the user add an integer-based Research Task depending on the trainer's needs (Max 5) 
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
        @param addOnCounter - a variable that tracks the number of Research Task Add-Ons added by the user
        @param researchAddOns - a character array that stores the string name of the Research Task added by the user
*/
void addResearchTask(struct details entry[], int *storedEntries, int *addOnCounter, char researchAddOns[][21]){

    char cChoice;
    char modify20[21];
    // /*For Debugging*/ printf("AddOns: %d\n", *addOnCounter);

    //Entry Validation
    if(*storedEntries == 0)
    {
        printf(RED "No Existing Entries Found! Redirecting back to Research Task Menu!\n" RESET);
    }
    else
    {
        if(*addOnCounter > 4)
        {
            printf(RED "Error: You have reached the Maximum Number of Additional Tasks\n" RESET);
        }
        else
        {
            printf(GREEN"Note: You can only add up to five numerical Research Tasks\n"RESET);
            printf("Add-Ons Left: "YELLOW"%d\n\n"RESET, (5 - *addOnCounter));
            printf("Do you wish to add an additional Research Task?\n["GREEN"Y"RESET"]es ["RED"N"RESET"]o\n\nConsole: ");
            scanf(" %c", &cChoice);
            cChoice = tolower(cChoice);

            while(cChoice != 'y' && cChoice != 'n')
            {
                printf(RED "\nInvalid input. Please try again.\n" RESET);
                printf("Console: ");
                scanf(" %c", &cChoice);
                cChoice = tolower(cChoice);
            }

            if(cChoice == 'n')
            {
                printf("Returning to Research Task Menu...\n");
            }
            else
            {
                do
                {
                    printf(GREEN"Note: Research Task must not exceed more than 20 Characters!\n"RESET"Research Task Description: ");
                    scanf(" %[^\n]s", modify20); 
                    printf("\n");
                    strcpy(researchAddOns[*addOnCounter], modify20);
                    printf("addoncounter: %d", *addOnCounter);
                    if(strlen(researchAddOns[*addOnCounter]) > 20)
                    {
                        printf(RED "Error: Pokemon Type must not exceed 20 Characters\n" RESET);
                    }
                }while(strlen(researchAddOns[*addOnCounter]) > 20);

                printf(GREEN "Successfully added a Research Task\n" RESET);    
                printf("RT: %s\n", researchAddOns[*addOnCounter]);
                *addOnCounter += 1;
                printf("AddOnCOunt: %d\n", *addOnCounter); 
            }
        }
    }
}

/*  showAdditionalTasks Function lets the user check the number Research Task Add-Ons that the user added 
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
        @param addOnCounter - a variable that tracks the number of Research Task Add-Ons added by the user
        @param researchAddOns - a character array that stores the string name of the Research Task added by the user
*/
void showAdditionalTasks(struct details entry[], int *storedEntries, int* addOnCounter, char researchAddOns[][21]){
    int i;
    if(*storedEntries == 0)
    {
        printf(RED"No Existing Entries Found! Redirecting back to Research Task Menu!\n"RESET);
    }
    else
    {
        if(*addOnCounter == 0)
        {
            printf(RED "No Research Task Add-Ons Added\n" RESET);
        }
        else
        {
            printf(YELLOW "Additional Task Types:\n" RESET);
            for(i = 0; i < *addOnCounter; i++)
            {
                printf("(%d) %s\n", i+1, researchAddOns[i]);
            }
        }
    }
}

/*  Similar behavior to the updateTask Function, the updateAddOnsPerPkmn Function lets the user update his or her 
    "added" Research Task to a selected pokemon entry.
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
        @param addOnCounter - a variable that tracks the number of Research Task Add-Ons added by the user
        @param researchAddOns - a character array that stores the string name of the Research Task added by the user
*/
void updateAddOnsPerPkmn(struct details entry[], int *storedEntries, int* addOnCounter, char researchAddOns[][21])
{
    int updatePokemon, task, addTask;
    if(*storedEntries == 0)
    {
        printf(RED"No Existing Entries Found! Redirecting back to Research Task Menu!\n"RESET);
    }
    else
    {
        if(*addOnCounter == 0)
        {
            printf(RED "No Research Task Add-Ons Added\n" RESET);
        }
        else
        {
            printf(YELLOW "Research Task Add-Ons:\n" RESET);
            for(int j = 0; j < *addOnCounter; j++)
            {
                printf("%d. %s\n", j+1, researchAddOns[j]);
            }

            do
            {
                printf("\nWhat type of Research Task Add-On was completed?\n"); 
                scanf("%d", &task); printf("\n");
                if(task <= 0 || task > *addOnCounter)
                {
                    printf(RED "Invalid Input! Try Again\n" RESET);
                }
            }while(task <= 0 || task > *addOnCounter);

            //Print All Pokemon Entries
            printf(CYAN"Pokemon Entries:\n"RESET);
            for(int i = 0; i < *storedEntries; i++)
            {
                printf("(%d) %s\n", i+1, entry[i].name20);
            }

            switch(task)
            {
                case 1:
                    printf("\nSelect the Entry Number of the Pokemon that you wish to update Research Task:\n");
                    scanf("%d",&updatePokemon); 
                    printf("\n");

                    if(updatePokemon-1 >= *storedEntries || updatePokemon-1 < 0)
                    {
                        printf(RED "Error: Invalid Entry Number! Redirecting back to the Research Task Menu!\n" RESET);
                        //Terminate Void Function -> main()
                    }
                    else
                    {
                        updatePokemon--;
                        printf("%s: ", researchAddOns[0]);
                        scanf("%d", &addTask); 
                        printf("\n");
                        entry[updatePokemon].researchTasks[0].researchCount += addTask;
                    }
                    break;
                case 2:
                    printf("\nSelect the Entry Number of the Pokemon that you wish to update Research Task:\n");
                    scanf("%d",&updatePokemon); 
                    printf("\n");
                    if(updatePokemon-1 >= *storedEntries || updatePokemon-1 < 0)
                    {
                        printf(RED "Error: Invalid Entry Number! Redirecting back to the Research Task Menu!\n"RESET );
                        //Terminate Void Function -> main()
                    }
                    else
                    {
                        updatePokemon--;
                        printf("%s: ", researchAddOns[1]);
                        scanf("%d", &addTask); 
                        printf("\n");
                        entry[updatePokemon].researchTasks[1].researchCount += addTask;
                    }
                    break;
                case 3:
                    printf("\nSelect the Entry Number of the Pokemon that you wish to update Research Task:\n");
                    scanf("%d",&updatePokemon); 
                    printf("\n");

                    if(updatePokemon-1 >= *storedEntries || updatePokemon-1 < 0)
                    {
                        printf(RED "Error: Invalid Entry Number! Redirecting back to the Research Task Menu!\n" RESET);
                        //Terminate Void Function -> main()
                    }
                    else{
                        updatePokemon--;
                        printf("%s: ", researchAddOns[2]);
                        scanf("%d", &addTask); printf("\n");
                        entry[updatePokemon].researchTasks[2].researchCount += addTask;
                    }
                    break;
                case 4:
                    printf("\nSelect the Entry Number of the Pokemon that you wish to update Research Task:\n");
                    scanf("%d",&updatePokemon); 
                    printf("\n");
                    if(updatePokemon-1 >= *storedEntries || updatePokemon-1 < 0)
                    {
                        printf(RED "Error: Invalid Entry Number! Redirecting back to the Research Task Menu!\n" RESET);
                        //Terminate Void Function -> main()
                    }
                    else
                    {
                        updatePokemon--;
                        printf("%s: ", researchAddOns[3]);
                        scanf("%d", &addTask); 
                        printf("\n");
                        entry[updatePokemon].researchTasks[3].researchCount += addTask;
                    }
                    break;
                case 5:
                    printf("\nSelect the Entry Number of the Pokemon that you wish to update Research Task:\n");
                    scanf("%d",&updatePokemon); 
                    printf("\n");

                    if(updatePokemon-1 >= *storedEntries || updatePokemon-1 < 0)
                    {
                        printf(RED "Error: Invalid Entry Number! Redirecting back to the Research Task Menu!\n" RESET);
                        //Terminate Void Function -> main()
                    }
                    else
                    {
                        updatePokemon--;
                        printf("%s: ", researchAddOns[4]);
                        scanf("%d", &addTask); printf("\n");
                        entry[updatePokemon].researchTasks[4].researchCount += addTask;
                    }
                    break;
            }
        }
    }
}

/*  Similar behavior to displayAllEntries Function, the showAddOnsPerPkmn Function shows the list of all Pokemon
    and the data of each Research Task Add-Ons the that user added.
        @param entry[] - a data structure that contains all data of each Pokemon Entry       
        @param storedEntries - pointer that points to the address of the # of entries stored
        @param addOnCounter - a variable that tracks the number of Research Task Add-Ons added by the user
        @param researchAddOns - a character array that stores the string name of the Research Task added by the user
*/
void showAddOnsPerPkmn(struct details entry[], int *storedEntries, int* addOnCounter, char researchAddOns[][21])
{
    int i, j;

    if(*storedEntries == 0)
    {
        printf(RED "No Existing Entries Found!" YELLOW " Redirecting back to Research Task Menu!\n"RESET);
        sleep(1);
    }
    else
    {
        if(*addOnCounter == 0)
        {
            printf(RED "No Research Task Add-Ons Added\n" RESET);
        }
        else
        {
            printf(YELLOW "List of Pokemon & Research Task Add-Ons\n" RESET);

            for(i = 0; i < *storedEntries; i++)
            {
                printf("Pokemon: "CYAN"%s\n"RESET, entry[i].name20);
                for(j = 0; j < *addOnCounter; j++)
                {
                    printf("%s: %d\n", researchAddOns[j], entry[i].researchTasks[j].researchCount);
                }
                printf("\n");
            }
        }
    }
}

