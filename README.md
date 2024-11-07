# King's Table
This game is also known as Tablut, a Viking board game whose rules were recorded in Lapland. It is asymmetric and very quick to play.
The game is written in C++ and uses the [Simple and Fast Multimedia Library](https://www.sfml-dev.org/index.php).

It is played on a 9x9 board:

<img src="https://github.com/user-attachments/assets/a36b0351-6ad9-47ed-b752-ab34bb81679d" width="500" height="500">

## The Pieces
The King: ![Screenshot from 2024-11-06 16-58-46](https://github.com/user-attachments/assets/8ba049e9-dfce-464f-a7d9-41b1641f841c)

The Defenders:![Screenshot from 2024-11-06 16-58-27](https://github.com/user-attachments/assets/c07f3d68-ab24-4b01-b0a6-4d8f53be88b4)

The Attackers:![Screenshot from 2024-11-06 16-59-11](https://github.com/user-attachments/assets/7f49f8fa-7d37-40f8-a459-e4fec42e8821)

## The Rules
The attackers move first.
### Attackers Objective
The attackers win if they surround the king horizontally and vertically, either with four of their units, with one on each side:

![Screenshot from 2024-11-07 19-20-49](https://github.com/user-attachments/assets/e2e36523-9b96-40c7-a80d-d0654235c7a9)

or with three of them if the King is against the edge of the board:

![Screenshot from 2024-11-07 19-19-33](https://github.com/user-attachments/assets/c4b2ee4d-d993-4820-86fc-e30acb7bc302)

### Defenders Objective
The defenders win if their king manages to get to one of the four corners of the board.
### Movement
All pieces move as far as they want in either the horizontal or vertical direction, as long as the path is clear and the destination square is unoccupied.
### Capturing Pieces
To capture a piece, you must flank it on two opposite sides, either horizontally or vertically.
For example:

Before Capture: 

![Screenshot from 2024-11-07 19-30-28](https://github.com/user-attachments/assets/b4169c43-a0e9-4faf-a94a-1d20146c3cc5)

The attacker can capture by moving his left piece up one square.

After Capture: 

![Screenshot from 2024-11-07 19-30-39](https://github.com/user-attachments/assets/8cb80b2b-04b2-4958-8c0a-8cd3f75370b1)

The King can assist with captures if paired with another defender. The King cannot be captured in this way.

#### Corner Captures:
If an attacker or defender piece is in one of the four corners, you can capture it by placing one of your pieces on both the two adjacent squares (one horizontal and one vertical). This is an exception to the normal capture rules. 
Here is an example.

Before corner capture:

![Screenshot from 2024-11-07 19-25-32](https://github.com/user-attachments/assets/9dd6556c-6bbf-467c-96be-76052b20ad60)

After corner capture:

![Screenshot from 2024-11-07 19-25-50](https://github.com/user-attachments/assets/966e6e21-96fd-4256-a8e3-84e8c3733b0a)

Captures happen only at the end of a movement (meaning you can safely move between two enemies that are already in a flanking position; they can only capture you in that situation if they move away and come back).
## Controls
Select the piece you want with the left mouse button. If you change your mind you can either right click anywhere or left click the piece to deselect it. Then click where you want to move.

## OS Requirements
This was written and tested on Ubuntu Linux and Linux Mint. It should also work on Windows. 

## Compilation Instructions
You'll need to make sure the relevant dependencies are met. Once you have run the two cmake commands mentioned below, you can go to ./build and run make from there. The executable will be at ./build/bin/KingsTable.

1. If you use Linux, install SFML's dependencies using your system package manager. On Ubuntu and other Debian-based distributions you can use the following commands:
    ```
    sudo apt update
    sudo apt install \
        libxrandr-dev \
        libxcursor-dev \
        libudev-dev \
        libfreetype-dev \
        libopenal-dev \
        libflac-dev \
        libvorbis-dev \
        libgl1-mesa-dev \
        libegl1-mesa-dev
    ```
    Be sure to run these commands in the root directory of the project you just created.

    ```
    cmake -B build
    cmake --build build
    ```
    The game will then be available from ```./build/bin/KingsTable```.
   ### SFML Template
   Thanks to the template at [https://github.com/SFML/cmake-sfml-project](https://github.com/SFML/cmake-sfml-project) this was fairly easy to get started with. I recommend using this template if you are new to SFML or cmake.
