
# Cat command for windows 🐱

Cat command is very usefull command in linux operating system. We can print the content of multiple files in different ways using cat command. But this command is not present in windows operating system. So the main goal of this project is to make cat command for windows operating system.However this will also work in linux operating system.


## Features of cat command :-
- to print the content of multiple files.

```linux
cat file1.txt file2.tx
```
- to copy the content of multiple files in a single file.

```linux
cat file1.txt file2.tx > result.txt
```
- to append the content of multiple files in an existing file

```linux
cat file1.txt file2.tx >> file3.txt
```

## Options :-

- -n : for printing the content of the file in which each file will be followed by the line number.
```linux
cat -n file.txt
```
- -s : for removing multiple continuous blank lines.
```linux
cat -s file.txt
```
- -top c : for printing c lines from the starting. 
```linux
cat -top 5 file.txt
```
- -down c : for printing c lines from the end.
```linux
cat -down 5 file.txt
```

- -help : for printing instruction that how to use this command
```linux
cat -help
```
  
## Design :-

As cat command is all about displaying the content of multiple files, I am using "stdio.h" header file which contains a predefined "FILE" datatype that help us to work with files and inorder to make it work like a command i used command line arguments. 


## Author 

- [@Harsh_Garg](https://github.com/Harsh-garg-coder)

  
## 🚀 About Me 
I'm a learner...

  
