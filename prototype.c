#include <stdio.h>

/***Main Functions***

func AddEntry(){
    Front-End:
    - Ask for necessary Information [Name, Type, Description]
    
    Back-End:
    - Before FE1 , check if there is existing pokemon based on Name. If Y, prevent. Else create new entry.
    - All necessary information should have atleast 1 charcater.
}

func ModifyEntry(){
    Allow user to modify Pokedex Entries. 
    User Input:
    - a number referring to the i'th index of Pokemon's Entry 
    Example: 
    User Input: 1 (Which is Array[0])

    Front-End:
    - First display list of Pokemon Entries (Follow [Display All Entries] format)
    - Ask which entry user wants to modify. 
    - After user-input, ask user which information to edit. 
        (1 - Name , 2 - Type , 3 - Description)
    - After that, ask user to enter updated details and refresh
    - Ask user to double check before proceeding.

    Back-End:
    - Assume that function only accepts integers 1 <= n <= 150. Else invalid Input. At FE2
    - If Invalid Input, Display Message then go back to "Manage Data" Menu.
    - Assume that function only accepts integers 1 <= n <= 3. At FE3
}

func DeleteEntry(){
    Similar to ModifyEntry()
    Front-End:
    - First display list of Pokemon Entries (Follow [Display All Entries] format)
    - Ask which entry user wants to delete.
    Back-End:
    - Full proof of Bugs
}

func DisplayAllEntries(){
    Front-End:
    - Once called, provide a list of Pokedex Entries (Pokemon Name, Type and Description)
    - Garbage values are not displayed by the list.
    Back-End:
    -Display all entries depending on integer user-input
    Ex. Display Entries 5 (Display Array[0] to Array[4])
    -Full proof of Bugs
}

func SearchPokemonName(){
    Search Pokemon by Name
    Front-End:
    - Option 1: Asks for a string input. Pokedex show list of all entries with that string-input
    - Display is similar to how DisplayAllEntries() work.

    Back-End:
    - Implement a (View Next, Previous, and Exit) that mactches the string-input.

    Example User-Input: chu (case insensitive)
    -Display PikaCHU, RaiCHU, etc. 
    If no match, show pop-up message then go back to Manage Data Menu
}

func SearchPokemonType(){
    Similar to SearchPokemonName() but by type.
    Front-End:
    - Ask user for the element, (either multiple choice or they type it via string-input)
    - Must show all the pokemon under the "type" or "element" with (View Next, Previous, Exit)
    - Add a message like "These are all of the Water Type Pokemon" in the end of list.
    - If no match, show pop-up message and go back to Menu.
    Back-End
    -Full proof of bugs
}

func Export(){
    Allow data to be saved into a txt file.
    Allow User to modify filename (Max 30 characters)
    If File exists, data will be overwritten

}


*/