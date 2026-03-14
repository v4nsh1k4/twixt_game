# Twixt CLI Game

A command-line implementation of the classic board game **Twixt** written in C.

## About the Project

This project is a CLI version of the game Twixt. The game logic includes alternating turns between Red and Black players, placing pegs on the board, and checking for winning connections using efficient path detection algorithms.

- The board state is stored using custom data structures.
- The game alternates turns between players automatically.
- The program detects when a player wins by checking for connected paths across the board.
- The interface uses terminal output where:
  - `'r'` denotes a red player's peg,
  - `'b'` denotes a black player's peg,
  - the board index starts from 1 for easier reference.

### Learn more about Twixt:

- [Game rules overview (video)](https://youtu.be/dIyuVS3xRQ0?si=_qYFqihhfrxKRBRq)
- [Play online version](https://twixtlive.com/Play.aspx)

---

## How to Compile and Run

Make sure you have a C compiler (`gcc`) installed on your system.

1. **Compile the code:**

```bash
gcc main.c fn.c links.c win.c -o proj
```

2. **Run the program:**

```bash
./proj
