#pragma once

/*Memory game

* Game Rules:
The player opens two cards one after the other.
When two identical cards are turned over, they remain face up and the player makes another choice from two other cards.
If the cards turned over are the same, they close and the player makes the next move by turning over two more cards.
The game ends when all the cards are revealed.

* Game Settings:
1. Player Name – should be able to be entered from the keyboard.
2. Fixed order time (1, 2:30, 5, etc. minutes) or unlimited time.
3. Dynamic size of playing area - 4x4, 6x6, 8x8 - randomly selected.
4. Statistics - records for each size of the playing area - player name, order time, number of mistakes, number of moves.

*Additional game requirements:
1. Sounds:
1.1. In case of wrong open pair;
1.2. In case of correctly opened pair;
1.3. After completing the game;
1.4. When completing the game with a new record;
1.5. When losing the game;

2. Button to hide / show already opened cards.

3. Button to hide/show informative panel for elapsed time, number of moves and mistakes.

4. Restoring the results of the current game if we exit it (moves, mistakes, elapsed time, options selected by the player)

5. Writing and reading the records from the file.
*/
