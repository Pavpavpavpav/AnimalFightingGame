# Animal Fighting Game
### For the Hack Club Terra Program

A text-based game where animals ~~fight~~ play with eachother until they are exausted.
Reesmbles games like Pokemon (without the story part)

<sub>***NO ANIMALS WERE HARMED!1!!11!!***</sub>

## How do I play the game???

Playing the game is really simple, as it consists of 3 main phases:

1. Making your character by writing your name and selecting your animals or *loading your save file* (more on this later)
2. Intermission, using items or starting the "play-offs"
3. Engaging in ~~combat~~ playing with opponents until one emerges victorious   

The process is repeated until all your pets are exausted and unable to play anymore.

## What are the different items in the game and what do they do???

The game (*so far*) has 3 unique items: 

1. Small treats - Feeds your animal and lets them play longer! 50 exaustion is subtracted from the exaustion meter
2. Big treats - Like small treats, though they subtract more! 150 exaustion to be exact
3. Toys - Rare item to recieve, has the ability to set the exaustion bar to 0 even for *fully exausted* animals.

Small and Big treats cannot be used on animals that have their exaustion bar full because ~~I said so~~ of balancing reasons.

Items are recieved once after completing the first phase of the game (Making your character) and after each won battle. The drop rates are as follows:
- Small and Big treats
    - 0: 60%, 1: 30%, 2: 10%
- Toys
    - 0: 70%, 1: 30%

## Why are my pets already at 0/### exaustion??? Is this a bug?

Unlike in other games, where similar healthbar mechanics start at 100%, the exaustion mechanic works the opposite in this game.

In this game, the animals start with no exaustion at all, slowly gaining exaustion as they play with other pets. The items are there to lower the exaustion.

## How does my progress save?

The progress of the player is saved in the GameSave.txt file, if one is missing, the game will automatically make one for the player.

Additionally, the animals are saved in the Animals.txt file, which is accessed frequently to get the information about all the animals

## Can I edit the files?

Yes! But be aware, both files follow a strict format when writing data:

- The GameSave.txt file follows this format:
    - Line 1: Name of the User
    - Line 2: The number of wins the player has
    - Line 3: ID of the 1st animal the player owns 
    - Line 4: Current Exaustion of the 1st animal
    - Line 5: ID of the 2nd animal the player owns
    - Line 6: Current Exaustion of the 2nd animal
    - Line 7: ID of the 3rd animal the player owns
    - Line 8: Current Exaustion of the 3rd animal
    - Line 9: ID of the 4th animal the player owns
    - Line 10: Current Exaustion of the 4th animal
    - Line 11: The number of small treats the player has
    - Line 12: The number of big treats the player has
    - Line 13: The number of toys the player has

- The Animals.txt follows this format: (N is a number between 0 & 11)
    - Line (N*5+1): The name of the animal (The line # is also its ID)
    - Line (N*5+2): The maximum exaustion of the animal
    - Line (N*5+3): The class of the animal
    - Line (N*5+4): The minimum exaustion the animal can give to others
    - Line (N*5+5): The maximum exaustion the animal can give to others

***!The Animals.txt file must end at line 60, otherwise an error will happen!***

## (I think) My files are corrupted! What do I do???

If the game is showing an error code due to corruption of the files, or the game is outputting nonsense (Such as the exaustion of an animal being "Anastasia"), the files are most likely corrupted.

If the problem exists within the GameSave.txt file, it can be deleted safely, as the game will recreate it with the start of a new game.

If the problem is in the Animals.txt file, the program needs to be redownloaded as there is not a backup of the file within the program (Yet)

If any file is shorter than intended, the game will show an Segmentation Fail Code Dump error.