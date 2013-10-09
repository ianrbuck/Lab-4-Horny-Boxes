#include <stdio.h>
#include <stdbool.h>
#include "file_disemvowel.h"

#define BUF_SIZE 1024

bool is_vowel(char c) {
  /* Returns true if c is a vowel (upper or lower case), and false otherwise. */
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
      return true;
    }
    return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  /*
   * Copy all the non-vowels from in_buf to out_buf. num_chars indicates how many
   * characters are in in_buf, and this should return the number of non-vowels that
   * that were copied over.
   */
    int count = 0;
    int i;
    for(i = 0; i < num_chars; i++) {
        if(!is_vowel(in_buf[i])) {
            out_buf[count] = in_buf[i];
            count++;
        }
    }
    return count;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  /* 
   * Copy all the non-vowels from inputFile to outputFile.
   * Create input and output buffers, and use fread() to repeatedly read
   * in a buffer of data, copy the non-vowels to the output buffer, and
   * use fwrite to write that out.
   */
  //get number of chars in input
  int size = 0;
  char* in_buf = calloc(BUF_SIZE, sizeof(char));
  fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
  char a = 'a';
  while(a != NULL){
    a = in_buf[size];
    size++;
  }
  size--;
  char* out_buf = calloc(size, sizeof(char));
  int numNonVowels = copy_non_vowels(size, in_buf, out_buf);
  fwrite(out_buf, sizeof(char), numNonVowels, outputFile);
}

int main(int argc, char *argv[]) {
  FILE *inputFile;
  FILE *outputFile;

  /* Code that processes the command line arguments and sets up inputFile and outputFile */
  if(argc == 3) {
    inputFile = fopen( argv[1], "r" );
    outputFile = fopen( argv[2], "w" );
    if (inputFile == 0 ) {
      printf( "Could not open input file\n" );
    }
    if (outputFile == 0){
      printf( "Could not open output file\n");
    }
  } else if(argc == 2) {
    //Read from argv[1], output to stdout
    inputFile = fopen(argv[1], "r");
    outputFile = stdout;
  } else {
    inputFile = stdin;
    outputFile = stdout;
  }

  disemvowel(inputFile, outputFile);

  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
