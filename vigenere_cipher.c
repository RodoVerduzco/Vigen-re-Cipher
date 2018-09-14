/*
*
*   Program :   vigenere_cipher.c
*
*   Authors  : María Fernanda Delgado Radillo
*              A01366101
*              Jose Rodolfo Verduzco Torres
*              A01366134
*
*   Purpose :
*              This program has the complete set of functions needed
*              to perform the Vigenere Cipher encryptionn.
*
*   Usage  :
*              Every function receives it's own input either from
*              main.c or other methods inside this program.
*
*   Restrictions:
*              Any character apart from the english alphabet (not containing
*              numbers, or special characters will remain the same)
*
*   Error handling:
*               On any unrecoverable error, the program shows an error message,
*               and exits
*/

 #include "vigenere_cipher.h"



/*
 *
 *  Function: encode
 *
 *  Purpose: This Function performs the Vigenere Chipher
 *           encode operation of a received input.
 *
 *  Parameters:
 *           Input   Strings with the key to be encoded,
 *                   and the message to be decoded
 *
 *           Output  Returns the encoded message.
*/

char * encode(char key[], char  message[])
{
    int keyLength     = strlen(key)-1;
    int messageLength = strlen(message);
    char * encodedMsg = message;

    char ref = 'a';

    for (int i = 0, j = 0; i < messageLength; i++)
    {
      /* To ignore the non-alphabetic characters */
      if (isalpha(message[i]))
      {
          if(isupper(message[i])) {
            message[i] = tolower(message[i]);
          }

          /* Encode the message (Encode Formula -> (Ei + Ki) % 26) */
          encodedMsg[i] = ((message[i]-ref) + (key[(j % keyLength)]-ref)) % 26;
          encodedMsg[i] += ref;      /* convert to an Ascii character */

          /* Advance the key reference */
          j++;
       }
       /* non-alphabetic character found */
       else{
           encodedMsg[i] = message[i];
       }
    }
    return encodedMsg;
}

/*
 *
 *  Function: correct_format
 *
 *  Purpose: Gets the user input for the key to be used to
 *           encode or decode a text, also checks for any
 *           illegal character (non alphabetic)
 *
 *  Parameters:
 *           Input   The variable to store the key entered by
 *                   the user.
 *
 *           Output  Doesn't return anything.
*/

void correct_format(char string[])
{
    for(int i = 0, j = strlen(string)-1; i < j; i++)
    {
      /* Found illegal character for the key */
        if (!isalpha(string[i]))
        {
            ErrorMsg("correct_format", "Non-alphabetic characters given within the key");
            exit(EXIT_FAILURE);
        }
    }
}

/*
 *
 *  Function: ErrorMsg
 *
 *  Purpose: Prints an error message and then gracefully
 *           terminates the program.
 *
 *  Parameters:
 *           Input   Strings indicating the error message
 *                   and the function where the error was
 *                   found
 *
 *           Output  Prints the error in standard output and
 *                   exits
*/

void ErrorMsg(char *function, char *message)
{
  printf("\n\nError in function: %s\n", function);
  printf("%s\n", message);
  printf("\nThe program will terminate.\n\n");
}
