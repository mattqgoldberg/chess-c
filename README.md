# Chess game CLI for player vs player

## Usage

Compile with cmake:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

Run with `./chess`

## User input

Moves are expected in the follow format (without quotes) "E2E4"

When promotion is implemented, it will be read as "E7E8Q" or "E7E8N"

## Rules implemented

 - White moves first, alternates each turn.
 - Cannot capture a piece of your own color.
 - Must move a piece according to its moveset.
 - Cannot start a move on an empty square.

## To-do

 - Queens, bishops, rooks, pawns cannot move through other pieces
 - Castling
 - En passant
 - Check/checkmate
 - Promotion

## Future plans/possibilities

 - Computer engine to play against
 - Graphical interface mode
 - Read games from a file of moves
