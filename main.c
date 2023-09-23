// program to copy a file to another file while capitalising each letter

#include <stdio.h>
#include <ctype.h>

int main(void) {

  int c;
  char inName[64], outName[64];
  FILE *in, *out;
  
  // Get file names from the user
  printf ("Enter file name to copy from: ");
  scanf ("%63s", inName);
  printf ("Enter file name to copy to: ");
  scanf ("%63s", outName);

  // Open input and output files
  if ( (in = fopen (inName, "r")) == NULL ) {
    printf ("Can't open %s for reading.\n", inName);
    return 1;
  }

  if ( (out = fopen (outName, "w")) == NULL ) {
    printf ("Can't open %s for writing.\n", outName);
    return 1;
  } 

  // Copy in to out
  while ( (c = getc (in)) != EOF ) {
    c = toupper(c);
    putc (c, out);
  }

  // Close files
  fclose (in);
  fclose (out);

  printf ("File has been copied\n");
  
  return 0;
}