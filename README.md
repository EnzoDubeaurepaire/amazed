# Amazed

## Description
Amazed is a program designed to simulate the movements of multiple robots within a maze. It takes input from stdin, where the first line specifies the number of robots, followed by the description of each room in the maze, and finally, the connections between rooms through tunnels. The program outputs the displacements of each robot within the maze.

## Input Format
The input format for Amazed is structured as follows:

- The first line contains an integer indicating the number of robots in the maze.
- For each room in the maze:
  - If the room is the starting room, it is preceded by `##start`.
  - If the room is the ending room, it is preceded by `##end`.
  - Otherwise, the room is described by its name, followed by its coordinates (x, y).
- Following the room descriptions, each line represents a tunnel connecting two rooms. Tunnels are represented as "room1-room2", where room1 and room2 are the names of the connected rooms.

## Example Input
```bash
2
##start
room1 0 0
room2 2 2
##end
room3 4 4
room1-room2
room2-room3
```

## Output Format
The output of Amazed consists of the displacements of each robot within the maze. The displacements are printed to stdout.

## How to Run
To run Amazed, compile the source code using a make and execute the binary file. Provide the input through stdin.

Example run:
```bash
make
./amazed < input.txt
```

## Dependencies
- This project requires a C compiler to build and run.

## Contributors
[Axel Desert](https://github.com/AxelDesert)
[Raphaël Goncalves-Dos-Santos](https://github.com/raphaelGONCALVESDOSSANTOS)
[Enzo Dubeaurepaire](https://github.com/EnzoDubeaurepaire)
