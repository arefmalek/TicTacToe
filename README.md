# TicTacToe
A simple game that became way too complex  

## Basics


###### Grid
The board initializes with blank `[ ]` tokens in a 3 x 3 setup

###### Token Drops
Picking a slot 1-9 (aligns with a 3x3 format) will place an X or O token in the spot, ready

###### Win Conditions
I made this part pretty organized: one clean function that checks all ways to win in the game (horizontally, vertically, or diagonally) in one go, if any of the three ways to win are proven, the game ends and the winner is declared

## Add-ons
I finished the basic math parts of setting up the game quicker than I thought, so instead of doing something useful I just spent more and more time _optimizing_ the program

###### Turn counts and switching users
Every Turn begins with count of the turn, and a greeting to the player (either 1 or 2) and their token (`[X]` or `[O]`)

###### Ending and Restarting Game
After a win condition is found or it becomes a cat's game, the program will respond accordingly and ask the players whether or not they want to play another game, and if they do the game will reset (this can go on forever). 


## Input Validation(BETA)
This was one of the most boring things I have had to do in a while, and it still is not complete. I am developing the function that checks the input the players put in to make sure the game runs seamlessly (less crashes). Right now it works not allowing the user to put a token in a pot already occupied or pick a slot out of the 1-9 range. Right now the biggest bugs are if the user puts in text input instead of integers (whole game goes to trash). 
