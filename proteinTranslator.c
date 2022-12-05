#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "file_utils.h"
#include "protein_utils.h"


int main(int argc, char **argv) {

  // if(argc != 2) {
  //   fprintf(stderr, "Usage: %s RNA\n", argv[0]);
  //   exit(1);
  // }



  char *dnaFiles = getFileContents(argv[1]);
  removeAllWhiteSpace(dnaFiles);
  replaceChar(dnaFiles, 'T', 'U');
  char **codons = lengthSplit(dnaFiles, 3);
  int length = strlen(dnaFiles);
  int total = length/3 + (length % 3 == 0 ? 0 : 1);
  char *proteins = (char *) malloc(sizeof(char) * (total));
  char protein;
    for(int i=0; i<total; i++) {

      protein = rnaToProtein(codons[i]);
      if(protein == 'x') {
        protein = '\0';
      }
      proteins[i] = protein;
    }
    proteins[total] = '\0';

    FILE *outputFile = fopen(argv[2], "w");
    fprintf(outputFile, "%s", proteins);
    fclose(outputFile);
  return 0;
}