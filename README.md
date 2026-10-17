# AnimalFightingGame
A text-based game where you can make animals play with eachother (fight) until they are exausted (defeated)
A project for the Hack Club Terra

# AI Statement
99% of the code of the project is human-written, AI was used to aid in debugging when all other measures did not work.

# How to Play?
Think of this game as a battle simulator similar to popular titles such as Pokemon
Because the main theme of the game is the animals playing instead of fighting, familiar items have been renamed into variants that fit the theme better:

Small Treat - Functions like a small health potion, removes 50 exaustion.
Big Treat - Functions like a big health potion, removes 150 exaustion.
Fast-Nap - Restores a pet's exaustion to 0 even if it has been exausted fully

The exaustion system functions similarly to the health system in similar battle games, but instead of starting at a base value (Masimum health points), and falling to 0, every animal starts with 0 exaustion and gains exaustion trough playing (fighting), and lasts until it hits the game's equivalent of Max HP, Maximum Exaustion. Once a animal hits maximum exaustion it cannot be brught back into playing without using a Fast-Nap with it

After each play, the player gains one win, and each of the animals which are not fully exausted lose 25 exaustion. The player also gains a random amount of items.

The animals are also divided into 3 classes:
    Light - Have a high maximum exaustion but give out little exaustion themselves, 1.25 times the exaustion taken from Medium class animals, 0.75x from heavy animals
    Medium - Moderate maximum exaustion and the amount of exaustion they give out, 1.25 times the exaustion taken from Heavy class Animals, 0.75x from light class animals
    Heavy - Low high exaustion but also give out a lot of exaustion to other animals, 1.25 times the exaustion taken from Light class animals, 0.75 from moderate class animals.

# How does the game progress?

Title screen - New Game or (WIP) Load Game

New Game 
    Input your name
    Select your animals (4)
    Recieve a starter set of items

(Repeats from now on until defeat or exiting the game)

Choose to save the game, quit, or play with an AI opponent
The AI opponent is assigned a random number of animals between 2 and 4
The "play-off" begins
    On your turn, you can choose to:
        Switch your current animal
        Open your inventory and use an item
        Use an ability of the pet (Adds exaustion to the opponents animal)
    After your turn, the AI opponent commands their animal to use its ability
        For now, the opponents animal will only be able to use their abillity, with the usage of items being planned for another date 
    This cycle repats until one person has all their animals enter a state of exaustion
    
<<<<<<< HEAD
 After (if) the player has won the "play-off", the player gains more items that are put into their inventory and the cycle continues repeating
=======
After (if) the player has won the "play-off", the player gains more items that are put into their inventory and the cycle continues repeating
>>>>>>> 8d297791d13347546eddff235a744824be4ad2d4

# Editing the file saves

The game saves its data about the player and the different animals available using text files.

The Gamesave.txt file saves the data of the player and their animals in the following format:
    Line 1: Name of the player
    Line 2: Number of wins
    Line 3: Animal 1 ID
    Line 4: Animal 1 Exaustion
    Line 5: Animal 2 ID
    Line 6: Animal 2 Exaustion
    Line 7: Animal 3 ID
    Line 8: Animal 3 Exaustion
    Line 9: Animal 4 ID
    Line 10: Animal 4 Exaustion
    Line 11: Number of Small Treats
    Line 12: Number of Big Treats
    Line 13: Number of Fast-Naps

The Animals.txt file saves the data of the all the different animals available to the player in this format:
    Line 1: Animal Name (Line # is the id of the animal)
    Line 2: Animal Maximum Exaustion
    Line 3: Animal Class (Light, Medium or Heavy)
    Line 4: Lowest possible dealt exaustion of the Animal
    Line 5: Highest possible dealt exaustion of the Animal
    (The format is repeated for every animal)

You can edit the animals freely but the amount cannot be changed for now.

# ! WARNING !

Changing the values manually risks corruption, there is currently no system to prevent these corruptions, so be careful!

If a problem happens when editing the Gamesave.txt document, it can be deleted alltogether, as the game makes the document when it is first ran.

Before editing the Animals.txt document to add your own animals, create a back-up, as the document is not recreated when the game starts, in the case of the corruption of this document, the game might need to be re-installed.

