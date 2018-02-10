# battleShip


                                                      User Stories

Game Board

Description: Create a game board in SFML that shows the Game grid.  Rows 1-10 columns A-J  One copy showing your ships other copy showing where you bombed.

Acceptance Test: The SFML grid is created when the game starts at a quality comparable to the checkers board.

Estimate: 2 hours

Computer AI

Description:  The computer will make moves that could potentially defeat and challenge a player.  The computers ships will be automatically placed and the computer’s bombing will threaten to sink the players ships.

Acceptance Test:  The computer can win on it’s own.  The computer’s ship placements are unpredictable and make sense for the rules of the game.  Computer does not break rules.

Estimate 2 hours

Click Based Input 

Description: The player clicks on the board to place their ships.  The player clicks on the squares that it wants to bomb in order to bomb the enemy.  

Acceptance Test: The player uses a GUI to play the game.  No text input is necessary.  The player should not have to repeatedly try to enter a command.  Everything should work the first time.

Estimate 2 hours

Real-Time Graphics Reflect Game State

Description: Basic background is blue squares.  Ships are represented as grey squares.  Hits are represented as red squares.  Misses are represented as white squares.  The end game has a special screen.  When A ship is sunk “YOU SUNK MY BATTLESHIP” flashes on the screen.

Acceptace Test:  A player’s moves are accurately reflected by the graphics described through the full course of a game.

Estimate: 4 hours

Sound

Description: There will be some simple sound effects played in response to hitting/missing ships as well as in response to other button presses.

Acceptance Test: Most player actions should provide some sort of audio feedback.

Estimate: 2 hours

Mini Games

Description: The game should include some sort of side games in order to make our version of battleship less generic/ more memorable. Will be much smaller in scope to actual game.  

Acceptance Test: Game should include at least one feature not necessarily related to a regular battleship game.

Estimate: 4 hours.

Save Mode

Description:  The player is able to save and load an old game. 

Acceptance Test:  The board state is loaded into a txt file written into the same folder that can populate a game state upon loading.

Estimate 2 hours

Career Mode 

Description:  The player can progress through waves of enemy battleships.  After each wave the player receives bonuses of some sort and the amount of enemy’s and the difficulty of the computer increases at each level of the game.

Acceptance Test:  At least 3 levels that are distinct from each other exist of the game.  The number of enemy ships increases by 50% each level.  And the computer gets an extra guess per turn at each level.  

Estimate 4 hours

Multiplayer Networks

