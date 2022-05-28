#include <stdio.h>
#include <string.h>
#include <conio.h>

//Declare String Variable
typedef char string[21];

//Wala lang to
struct Pokemon{
    string name;
    string description;
    string type;
    int i, j;

};

int main(void){

    FILE *myFile;
    //Creates a text file called PokeDex.txt. If it exists, open the file and append & write
    myFile = fopen("PokeDex.txt", "a+");
    int i, j;
    string name;
    string description;
    string type;
    
    //Ask user input
    printf("Name of Pokemon: ");
    scanf("%s", &name);
    printf("Pokemon Type (Element): ");
    scanf("%s", &type);
    printf("Pokemon Description (Max 20 Characters): ");
    scanf("%s", &description);

    //Print to PokeDex.Txt
    fprintf(myFile,"%s, %s, %s", name, type, description);
    fprintf(myFile, "\n");

    //Close File
    fclose(myFile);

    return 0;

}
