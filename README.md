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

--------------------------------------------------------------------------------------------
Jesse Keller diary entries

2/7: (~1hr) In class meeting. Didn’t do much, just exchanged information and set up git Hub.

2/11: (~3hr) First Pair-Programming session. Did a few lower level graphical things such as setting up the board among other stuff. We also set up a plan for what to get done in the future.

2/15: (~4hr) Did more work setting up graphics.

2/18: (~3hr) Did some Paired Programming as well as solo work.

2/26: (~6hr) Did a lot of solo work trying to fix uncaught bugs, and trying to merge mine and Paul’s work. Up to this point, while we did our fair share of paired-programming, a lot of the conventions and what not was inconsistent across our two branches. Most of the time spent here was me rectifying these differences.

2/27: (~4hrs) Some paired programming as well as many last minute bug fixes. Mine and Paul’s code now actually work side by side.

2/28: (~5hrs) Wrote the last of the logic so that an actual game of battleship could be presented. Spent time writing diary entries.

Total hours:  26

Thoughts on Paired Programming: There were pros and cons that I found in regards to paired programming. As a tool for being able to understand my partner’s code, paired programming was excellent. As a tool for bug testing, paired programming was also excellent. Since I was less familiar with my partner’s code than they were, I questioned everything and tended to see possible issues before they did. The same was true regarding bugs in my code. 
The cons that I found with paired programming were that if we didn’t have specific goals and plans for the paired programming session, it tended to be a little bit of a waste in time. With only one of us doing actually coding, we ended up taking more than twice the amount of time to do some of the most trivial tasks. The pros and cons probably equaled out however in the long run since learning others code early on allowed for quicker fixes and rewrites later on.

Thoughts on Version Control: I used to be a little intimidated by version control since (by team projects in general actually) since code I wrote would be immediately messed by code written by other people (or alternatively, I would screw up other peoples’ code). These sorts of problems were fairly frequent here as well, except this time, I understood some of the tools git had to offer and was quickly able to remedy most issues caused by git merging or other such issues.
