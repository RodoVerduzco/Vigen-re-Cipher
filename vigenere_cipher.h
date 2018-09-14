/*
 *
 *   File name: vigenere_cipher.h
 *
 *   Authors  : María Fernanda Delgado Radillo
 *              A01366101
 *              Jose Rodolfo Verduzco Torres
 *              A01366134
 *
 *   Purpose: Support routines that handle the Vignere Cipher Encryption
 */

#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

   #include <stdio.h>      /* For printf, scanf functions */
   #include <string.h>     /* For every handling string function*/
   #include <stdlib.h>     /* For exit, malloc and free */
   #include <ctype.h>      /* For isalpha */

   #define MSIZE 100000

  /* Handling functions */
    char * encode(char * key, char * message);

  /* Error Handling Function */
    void correct_format(char string[]);
    void ErrorMsg(char *function, char *message);

#endif
