#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
  // Define stuff here
  if(typeflag == FTW_F){
   num_regular++;
  }
  if(typeflag == FTW_D){
    num_dirs++;
  }

  return 0;
}

int main(int argc, char** argv) {
  // Check arguments and set things up

if (argc != 2){
  printf("Wrong number of arguments given.\n");
  printf("Expects: 2\n");
  printf("Given: %d\n", argc);
}
  ftw(argv[1], callback, 16);

  // Print out the results

  printf("Processed all the files from <%s>.\n", argv[1]);
  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
