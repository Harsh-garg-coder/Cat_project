/*
 * Rewriting cat command 
 * 
 * @Harsh_Garg, 1910990582
 */

#include<stdio.h>
#include<string.h>

// Function to display the error
void show_error () {
    printf("Wrong Syntax : use -help option to know more about the command\n");
    
}

// Functio to show the syntax
void show_Syntax () {
    printf("----------------------------------------\n");
    printf("Command Name ---> cat command\n");
    printf("----------------------------------------\n\n");
    printf("Usage ---> to display the content of multiple files in multiple ways\n\n");
    printf("Available Options:-\n");
    printf("1. -help ---> to get the help to use this command\n");
    printf("2. -n ---> to display the content of the file with line number\n");
    printf("3. -s ---> ro display the content of the file in which ultiple lines are suppresed\n");
    printf("4. -top c ---> to display c lines from the top of the files\n");
    printf("5. -down c ---> to display c lines from the end of the file\n\n");
}

// Printing the message that not a file
void not_a_file () {
    printf("File not present\n");
}

// function to display the content of a single file
void show_content_of_single_file (char* file_name) {
    FILE* file_pointer = fopen(file_name, "r");
    
    // if the file is not present
    if (file_pointer == NULL) {
        not_a_file();
        return;
    }
    
    // Reading and printing the file character by character
    char ch = fgetc(file_pointer);
    
    while (!feof(file_pointer)) {
        printf("%c", ch);
        ch = fgetc(file_pointer);
    }
    
    printf("\n");
    fclose(file_pointer);
}

// function to check that whether the files are present or not
// this will return 1 if all files are present otherwise 0
int all_are_files (char** arguments, int starts_from, int argc) {
    for(int i = starts_from; i < argc; i++) {
        FILE* file_pointer = fopen(arguments[i], "r");
        
        if (file_pointer == NULL) {
            return 0;
        }
    }
    return 1;
}

// Function to display the content of multiple/single file with line number
void show_content_with_line_number (char** arguments, int starts_from, int argc) {
    
    for(int i = starts_from; i < argc; i++) {
        FILE* file_pointer = fopen(arguments[i], "r");
        
        // initial line number
        int line_number = 0;
        
        // read one character from the file
        char ch = fgetc(file_pointer);
        char previous_character;
        
        int start_of_file = 1;
        
        // Reading and printing the file character by character
        while (!feof(file_pointer)) {
            
            if(previous_character == '\n' || start_of_file) {
                line_number++;
                printf("%d ", line_number);
            }
            
            printf("%c", ch);
            start_of_file = 0;
            previous_character = ch;
            
            ch = fgetc(file_pointer);
        }
        printf("\n");
        fclose(file_pointer);
    }
}

// Function to display the content of multiple or single file
// such that multiple contiguous blanck lines are supressed
void show_content_after_supressing (char** arguments, int starts_from, int argc) {
    for(int i = starts_from; i < argc; i++) {
        FILE* file_pointer = fopen(arguments[i], "r");
        
        // read one character from the file
        char ch = fgetc(file_pointer);
        char previous_char;
        
        int start_of_file = 1;
        
        // Reading and printing the file character by character
        while (!feof(file_pointer)) {
            
            if(start_of_file) {
                printf("%c", ch);
                previous_char = ch;
                ch = fgetc(file_pointer);
                start_of_file = 0;
            } else {
                if(ch == '\n' && previous_char == '\n') {
                    previous_char = ch;
                    ch = fgetc(file_pointer);
                    continue;
                } else {
                    previous_char = ch;
                    printf("%c", ch);
                    ch = fgetc(file_pointer);
                }
            }
        }
        printf("\n");
        fclose(file_pointer);
    }
}

// Function to print c lines from top of the file
void print_c_lines_from_top (char** arguments, int argc) {
    // current line number
    int line_number = 0;
    
    // total lines to be printed
    int lines_to_print = 0;
    
    for(int i = 0; arguments[2][i] != '\0'; i++) {
        lines_to_print = lines_to_print * 10 + (arguments[2][i] - '0');
    }
    
    for(int i = 3; i < argc; i++) {
        FILE* file_pointer = fopen(arguments[i], "r");
        
        char ch = fgetc(file_pointer);
        
        while (!feof(file_pointer)) {
            printf("%c", ch);
            ch = fgetc(file_pointer);
            
            
            if (ch == '\n') {
                line_number++;
            }
            
            if (line_number == lines_to_print) {
                return;
            }
        }
        printf("\n");
        fclose(file_pointer);
    }
    
}

// Function to print c lines from end of the file
void print_c_lines_from_down (char** arguments, int argc) {
    int lines_to_print = 0;
    
    for(int i = 0; arguments[2][i] != '\0'; i++) {
        lines_to_print = lines_to_print * 10 + (arguments[2][i] - '0');
    }
    
    // calculating the total lines present
    int total_lines_present = 0;
    
    for(int i = 3; i < argc; i++) {
        FILE* file_pointer = fopen(arguments[i], "r");
        
        char ch = fgetc(file_pointer);
        
        while (!feof(file_pointer)) {
            if (ch == '\n') {
                total_lines_present++;
            }
            
            ch = fgetc(file_pointer);
        }
        fclose(file_pointer);
    }
    
    // if the total lines present is smaller then the lines
    // to print then simply print the complete content of the file
    if (total_lines_present <= lines_to_print) {
        for(int i = 3; i < argc; i++) {
            FILE* file_pointer = fopen(arguments[i], "r");
            
            char ch = fgetc(file_pointer);
            
            while (!feof(file_pointer)) {
                printf("%c", ch);
                ch = fgetc(file_pointer);
            }
            fclose(file_pointer);
        }
    }
    // if total lines present is greater then the lines to print
    // than print only c lines from the end
    else {
        for(int i = 3; i < argc; i++) {
            FILE* file_pointer = fopen(arguments[i], "r");
            
            char ch = fgetc(file_pointer);
            
            while (!feof(file_pointer)) {
                if(total_lines_present <= lines_to_print) {
                    printf("%c", ch);
                }
                
                if(ch == '\n') {
                    total_lines_present--;
                }
                
                ch = fgetc(file_pointer);
            }
            fclose(file_pointer);
        }
    }
    
}

// Function to display the content of multiple files
void display_content_of_multiple_files (char** arguments, int argc) {
    for(int i = 1; i < argc; i++) {
        FILE* file_pointer = fopen(arguments[i], "r");
        
        char ch = fgetc(file_pointer);
        
        while(!feof(file_pointer)) {
            printf("%c", ch);
            
            ch = fgetc(file_pointer);
        }
        
        fclose(file_pointer);
    }
}

// Driver program
int main (int argc, char** arguments) {
    
    // if forgot to give filename and option
    if (argc == 1) {
        show_error();
    }
    // to display the content of a single file
    // or to see the syntax to use the cat command
    else if (argc == 2) {
        // to see the syntax to use the sommand
        if (strcmp(arguments[1], "-help") == 0)
        {
            show_Syntax();
        }
        // to diaplay the content of the single file
        else {
            show_content_of_single_file(arguments[1]);
        }
    }
    // to display the content of single/multiple files
    // with some option or to display the content of multiple
    // files without option
    else if (argc >= 3)
    {
        char* option = arguments[1];
        
        // to display the content of the file with line number
        if (strcmp(option, "-n") == 0) {
            // if any of the file is not present
            if (!all_are_files(arguments, 2, argc)) {
                not_a_file();
            } else {
                show_content_with_line_number(arguments, 2,argc);
            }
            
        }
        // to display the content of the file in which
        // multiple blanck lines are supresed
        else if (strcmp(option, "-s") == 0) {
            // if any of the file is not present
            if (!all_are_files(arguments, 2, argc)) {
                not_a_file();
            } else {
                show_content_after_supressing(arguments, 2, argc);
            }
        }
        // to display c lines from the top
        else if (strcmp(option, "-top") == 0) {
            if (!all_are_files(arguments, 3, argc)) {
                not_a_file();
            } else {
                print_c_lines_from_top(arguments, argc);
            }
            
        }
        // to display c lines from the bottom
        else if (strcmp(option, "-down") == 0) {
            if (!all_are_files(arguments, 3, argc)) {
                not_a_file();
            } else {
                print_c_lines_from_down(arguments, argc);
            }

        }
        // to display the content of multiple files
        else {
            if (!all_are_files(arguments, 1, argc)) {
                not_a_file();
            } else {
                display_content_of_multiple_files(arguments, argc);
            }
        }
    }
    
    return 0;
}
