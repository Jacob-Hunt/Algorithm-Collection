/*
    * File Name: recover.c
    * Author: Jacob Hunt
    * Author Email: jacobhuntemail@gmail.com
    *
    * Notes:
    * My solution to the "recover" portion of problem set 4 of Harvard
    * University's cs50 (introduction to computer science) MOOC.
    * Recovers a set of contiguous JPEG files deleted from a FAT-
    * formatted disc-image file.
    *
    * Known bugs/issues:
    *
    * -Though program meets all the specifications of the problem set
    *  which it was designed for, it lacks a mechanism for definitively
    *  detecting the end of a JPEG file and relies on the assumption
    *  that the files are all stored contiguously until the end of the
    *  disc file.
    *
    * -Upon a test run using a sample disc image, Valgrind reports
    *  28,400 bytes of memory as still reachable at end of program
    *  execution.
*/

// *** INCLUDES ***

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// *** TYPEDEFS ***

// unsigned 8-bit integer
typedef uint8_t BYTE;

// boolean variable
typedef int BOOL;

// struct to contain both an initialized file pointer as well as
// an exitcode to verify that the file was initialized
// successfully
typedef struct
{
    int exitCode;
    FILE *filePtr;
}
FILE_INIT;

// *** CONSTANT DEFINITIONS ***

// boolean values for boolean typedef to use
#define TRUE 1
#define FALSE 0

// number of bytes in data-block
#define BLOCK_SIZE 512

// number of characters in file names minus file extension
#define FILENAME_CHARS 3

// file extension of extracted files
#define FILE_EXTENSION ".jpg"

// *** FUNCTION PROTOTYPES ***

int scan_block(FILE *inptr, FILE **current_file, BYTE *buffer, int *file_number);
BOOL isJpgHeader(BYTE *buffer);
void switch_files(int *file_number, FILE *current_file, FILE_INIT *outstruct);
FILE* new_file(int file_number);

// *** START OF PROGRAM EXECUTION ***

int main(int argc, char *argv[])
{
    // check usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover disc_image\n");
        return 1;
    }
    
    // open disc image file
    FILE *inptr = fopen(argv[1], "r");
    
    // if file could not be opened
    if (inptr == NULL)
    {
        // print error message and exit program
        fprintf(stderr, "ERROR: could not open the file \"%s\"\n", argv[1]);
        return 2;
    }
    
    // pointer to temporarily store a copy of the data block
    // which is currently being processed at any given iteration
    // of main program loop
    BYTE *buffer = malloc(BLOCK_SIZE);
    // if there is a null pointer error
    if (buffer == NULL)
    {
        // print error message and exit program
        fprintf(stderr, "MEMORY ALLOCATION ERROR: null pointer.  Make sure there is memory available to run program.\n");
        return 3;
    }
    
    // counter to keep track of which file is being extracted
    int *file_number = malloc(sizeof(int));
    if (file_number == NULL)
    {
        // print error message and exit program
        fprintf(stderr, "MEMORY ALLOCATION ERROR: null pointer.  Make sure there is memory available to run program.\n");
        return 3;
    }
    *file_number = -1;
    
    // empty file to feed first iteration of scanning loop so as
    // not to throw off algorithm; gets deleted at end of program
    // execution
    FILE *current_file = fopen("pilot.null", "w");
    // check for null file pointer error
    if (current_file == NULL)
    {
        // print error message and exit program
        fprintf(stderr, "ERROR: could not create necessary files.  Please ensure that there is available disk space.\n");
        return 4;
    }
    
    // variable to store exit codes at various points of error
    // checking
    int exit_code = 0;
    
    // iterate over data blocks until end of disc image is
    // reached
    while (feof(inptr) == FALSE)
    {
        // scan the current data block for jpegs and extract if
        // found
        exit_code = scan_block(inptr, &current_file, buffer, file_number);
        
        // if program has encountered an error
        if (exit_code != 0)
        {
            // delete pilot.null
            remove("pilot.null");
            
            // free memory
            free(file_number);
            free(buffer);
            
            // stop program
            return exit_code;
        }
    }
    
    // close output file pointer
    fclose(current_file);
    
    // free memory
    free(file_number);
    free(buffer);
    
    // close disc image file
    fclose(inptr);
    
    // delete pilot.null
    remove("pilot.null");
    
    // exit program
    return 0;
}

// scan an individual block of data and write to designated
// output file pointer, splitting the jpegs into separate files 
int scan_block(FILE *inptr, FILE **current_file, BYTE *buffer, int *file_number)
{
    // variable to store fread returns
    BOOL is_not_eof;
    
    // put data in current block into buffer
    is_not_eof = fread(buffer, BLOCK_SIZE, 1, inptr);
    
    // if current iteration is the start of a jpeg file
    if (isJpgHeader(buffer) == TRUE)
    {
        // switch to next file and close last file
        FILE_INIT *file_switch = malloc(sizeof(FILE_INIT));
        // check for null pointer error
        if (file_switch == NULL)
        {
            // print error message and exit program
            fprintf(stderr, "MEMORY ALLOCATION ERROR: null pointer.  Make sure there is memory available to run program.\n");
            return 3;
        }
        switch_files(file_number, *current_file, file_switch);
        
        // check to make sure that file switch was a success
        // and return an error code if not
        if(file_switch->exitCode != 0)
        {
            int exit_code = file_switch->exitCode;
            free(file_switch);
            return exit_code;
        }
        
        // assign current_file the filePtr in struct created by
        // switch_files()
        *current_file = file_switch->filePtr;
        
        // free memory
        free(file_switch);
    }
    
    // if end of file has not been reached and first file has
    // been found
    if (is_not_eof == TRUE && *file_number > -1)
    {
        // write to current file
        fwrite(buffer, BLOCK_SIZE, 1, *current_file);
    }
    
    return 0;
}

// checks a block of disc space and returns true if it starts
// with a jpeg header; algorithm provided by Harvard University
BOOL isJpgHeader(BYTE *buffer)
{
    if (buffer[0] == 0xFF &&
        buffer[1] == 0xD8 &&
        buffer[2] == 0xFF &&
        (buffer[3] & 0xF0) == 0xE0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// opens new file in write mode; rewrites FILE_INIT struct
// pointed to in third argument to reflect new file
void switch_files(int *file_number, FILE *current_file, FILE_INIT *outstruct)
{
    // incriment file_number counter
    (*file_number)++;
    
    // open a new file in write mode
    current_file = new_file(*file_number);
    
    // verify that program has not opened a null file
    if (current_file == NULL)
    {
        outstruct->exitCode = 3;
        return;
    }
    else
    {
        // assign new file pointer to the FILE_INIT struct
        // passed as argument 3 and also assign an exit code
        // of 0 to indicate success
        outstruct->filePtr = current_file;
        outstruct->exitCode = 0;
        return;
    }
}

// returns a file pointer to a new jpg file
FILE* new_file(int file_number)
{
    // allocate memory for filename string
    char *filename = malloc(((FILENAME_CHARS + strlen(FILE_EXTENSION)) * sizeof(char)) + 1);
    // check for null pointer error
    if (filename == NULL)
    {
        // print error message and exit program
        fprintf(stderr, "MEMORY ALLOCATION ERROR: null pointer.  Make sure there is memory available to run program.\n");
        return NULL;
    }
    
    // assign name to file and store at address of *fileName
    sprintf(filename, "%0*i%s", FILENAME_CHARS, file_number, FILE_EXTENSION);
    
    FILE *outfile = fopen(filename, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "ERROR: Could not create new file.  Make sure that drive has sufficient space available.\n");
        free(filename);
        return NULL;
    }
    
    // free memory
    free(filename);
    
    return outfile;
}
