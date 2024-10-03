About: 
    Atlas Shell V2 is a simple Unix command-line interpreter written in C. It includes the core functionalities of a shell like command parsing and tokenization, interactive and non interactive mode, as well as executes command with arguments.

Installation:
    These are the steps needed to set up the project locally.

    1. Clone the repository to your local machine 
        git clone https://github.com/TrippyVaultBoy/atlas-shell_v2

    2. Navigate to the project directory
        cd atlas-shell_v2

    3. Compile the shell
        make hsh

Usage:
    Run the shell in inteactive mode with:
        ./hsh

    Then type commands into the prompt:
        shellv2: ls
        shellv2: cd /bin
        shellv2: pwd

    Run the shell in non-interactive mode with:
        echo "cd /bin" | ./hsh

Files:
    Makefile: Automates compilation for the project
    main.c: contains the main loop of the shell
    main.h: includes all of the libraries and functions this project uses
    read_command.c: Handles reading input from the user
    tokenize.c : Splits the command into tokens for parsing
    handle_cd.c: Implements the cd builtin function
    handle_env.c: Implements the env bultin function
    parse_command.c: forks the process and executed commands
    _strcmp.c: custom strcmp() function
    _strcspn.c: custom strcspm() function
    _strcpy.c: custom strcpy() function

Contributors:
    see AUTHORS.md

Licence:
    This project is licensed under the MIT License
