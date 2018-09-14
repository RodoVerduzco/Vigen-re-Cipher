/*
*
*   Program :   main.c
*
*   Authors  : María Fernanda Delgado Radillo
*              A01366101
*              Jose Rodolfo Verduzco Torres
*              A01366134
*
*   Purpose :
*              This program receives the  necessary input by the user
*              to perform a correct 'Vigenère Cipher encryption and
*              finaly prints the result.
*
*   Usage  :
*              The program reads the input text and the key given by
*              the user to be encrypted
*              Finally, the result is printed.
*
*   Restrictions:
*              Any character apart from the english alphabet  (not
*              containing numbers, or special characters will remain
*              the same).
*
*   Error handling:
*               On any unrecoverable error, the program shows an error
*               message, and exits.
*
*/

#include "vigenere_cipher.h"


/*   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*                   Main Entry Point                    */
/*   *   *   *   *   *   *   *   *   *   *   *   *   *   */
int main()
{
  char message[MSIZE] = "";
  char key[MSIZE] = "";

  printf("WELCOME TO THE VIGENERE CIPHER ENCRYPTION PROGRAM\n\n");

  /* Message */
  printf("Enter the phrase you like to encode: ");
  fgets(message, MSIZE, stdin);

  /* Key */
  printf("Enter the Key to encode: ");
  fgets(key, MSIZE, stdin);
  correct_format(key);

  /* Encode the message and get the result */
  char * encoded_message = encode(key, message);

  /* Show the result */
  printf("The encoded message is: %s\n", encoded_message);

  return EXIT_SUCCESS;
}
