#	Nonogram-solver

The nonogram solver can solve any nonogram puzzle.

I have never solved puzzles above 15x15 because the program timeouts. If you have any idea to improve the algorithm, you are free to contribute.

- [How does it work?](#How-does-it-work)
- [Installation](#Installation)
- [How to use it?](#How-to-use-it)
- [Speed tests](#Speed-tests)

##	How does it work?

Here is an example of a nonogram grid from [this website](https://www.puzzle-nonograms.com/).

![nono-grid](/.github/nono-grid.png)

And here is how the program solves it step by step.

![demo5x5](/.github/demo5x5.gif)

The program tries every possibility on the grid, and stops either when the puzzle is solved or when it tried everything. It uses a recursive algorithm that put blocks of black squares, check if the puzzle is still solvable in this configuration, and recall the `ft_solve` function for the next block.

Once the program has put the last block, it checks everything. If the puzzle is solved, the function returns `1`, and so do the others, or it returns `0`, and the program keeps searching.

Then, the program returns or shows the grid according to the result.

##	Installation

Clone this repository on your computer.

```shell
git clone https://github.com/valfur03/Nonogram-solver.git
```

`cd` in the new directory and execute the `make` command.

```shell
cd Nonogram-solver
make
```

##	How to use it?

We are gonna use the grid at the top for this example.

The program takes one parameter, which is a string containing the numbers.

```shell
./nosolve "x y col1 col2 ... coln row1 row2 ... rown"
```

If there are multiple numbers in a row/column, just separate them with a `,`.

For this example, we are gonna use the grid at the top.

```shell
./nosolve "5 5 2 3 1,1,1 3 2 1,1 1 3 1,2 4"
```

And here is the output.

```
#.#..
#....
.###.
.#.##
.####
```

`#` are filled cells, `.` are empty cells.

##	Speed tests

I made some speed tests according to the size of the grid with an `i7-1065G7` CPU.

> I have never solved puzzles above 15x15 because the program timeouts. If you have any idea to improve the algorithm, you are free to contribute.

| Size  | Average time (in seconds) |
| ----- | :-----------------------: |
| 5x5   |           0.001           |
| 10x10 |           0,017           |
| 15x15 |           20.6            |

Solving 15x15 puzzles (and probably above too) can be very long or not. Some returned in 0.68s, and others in 43s.