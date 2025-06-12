# Suduko generator & solver
This project is a console-based Sudoku Generator and Solver written in C. It allows users to generate Sudoku puzzles at varying difficulty levels and also solve custom Sudoku puzzles provided by the user.
## Features
- Sudoku Generator :
Randomly generates a fully solved Sudoku puzzle, then removes cells based on difficulty to create a playable puzzle.
- Sudoku Solver :
Solves both generated and user-input puzzles using backtracking.
- Difficulty Level :
Adjustable between 40 to 65 blank cells for customized challenge level.
- Validations Included :
Ensures that each generated puzzle has a unique solution.
## Technologies Used
- Language: C
- Libraries Used:
  - <stdio.h> – for input/output

  - <stdlib.h> – for memory management and random number generation

  - <stdbool.h> – for boolean logic

  - <time.h> – to seed the random number generator
 ## How to compile and run
 1. Clone the repository
    ```bash
    git clone https://github.com/05-Jagritii/Suduko.git
    cd Suduko
2. Compile the code using GCC
   ```bash
   gcc Suduko_final.c
   ```
   This generates `a.exe` file.
3. Run the program
   ```bash
    .\a.exe
## Project Structure
```
Suduko/
├── Suduko_final.c     
└── README.md 
```
## Author
Jagriti Kanwar
<br>
Mail : [kanwarjagriti21@gmail.com ](mailto:kanwarjagriti21@gmail.com)
<br>
LinkedIn : [Jagriti Kanwar](https://www.linkedin.com/in/jagriti-kanwar)
