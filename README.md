**SIMPLE SHELL**

The main aim of this project is to write a simple UNIX shell.
The whole project was made possible by both **archdaisy[[https://github.com/achdaisy]] & Mk-0-wan[[https://github.com/Mk-0-wan]]**
Here is a list of system calls commands we have so far used.
***
    1. execvp() - executing shell commands passed to it
    2. strtok() - tokenizing string of chars passed on the shell prompt
    3. wait() - system call which waits for the child process to finish first before returning to the parent process.
    4. fork() - used to make new processes.

Will keep on updating the list as we add more and more mods to it.
Our simple shell currently will be able to handle some the system or builtin commands like of `ls` small and basic stuff.
Able to make it work with all the builtin commands and also one can now be be able to see the env variables
Our shell is able to handle both interactive mode and non-interactive mode, meaning you can pipe in commands to our shell and it will output the commands `cat file.txt | ./hsh`
All memory leaks are checked and handled well an exit to the shell will make sure all the memory allocated in the heap will be freed.





