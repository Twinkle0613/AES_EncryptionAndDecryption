#include "Decryption.h"
#include "Encryption.h"
#include "stdint.h"
#include "stdio.h"
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"   
#include "malloc.h"
#include "ErrorObject.h"
#include "CException.h"


/**
 * Decryption is the process of decoding messages or information that was encoded by Encryption.
 *
 * 
 * Decryption Concept Diagram:
 *
 *                      -------------
 *   cipherKey  -----> | Decryption | ----->  plainText
 *                     -------------
 *                           ^
 *                           |
 *    Key -------------------
 *
 *  -----------------
 * | Function List: |
 * -----------------
 *
 * >>> Main Function <<<
 * char* decrypStr(char* str,char* key, int AESmode);
 * void decryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int sizeofAES);
 * void invCipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound);
 *
 *
 *  ------------------------
 * | Explaination Function |
 * ------------------------
 * >>> Main Function <<<
 * The decrypStr(...) function is used for decoding a string 
 * The decryp_16byte(...) function is used for decoding a 16-byte state
 * The invCipher(...) function is basic function of decryp_16byte.
 * 
 *  ---------------------------------
 * | Explaination Input Of Function |
 * ---------------------------------
 *
 *  decrypStr(char* str,char* key, int AESmode):
 *    str - store the string was typed by users.
 *    key - store the encrypt key was typed by users.
 *    AESmode - store the mode of AES such as AES_128, AES_192 and AES_256 was selected by users.
 *  
 *  decryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int AESmode):
 *    plainText - store the 2-D array was typed by users
 *    key - store the encrypt key was typed by users.
 *    encrypOut - store the output from encryp_16byte function.
 *    AESmode - store the mode of AES such as AES_128, AES_192 and AES_256 was selected by users.
 *
 *  void invCipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound):
 *    in - store data in 2-D array was typed by users
 *    out - store the output from encryp_16byte function.
 *    word - store the array is set by KeyExpansion Function.
 *    NumOfRound - store the number of round that depend on the AES mode.
 *
 */

void invCipher(uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound){
  int i;
  uint8_t state[4][4];
  copyState(in,state);
  addRoundKey(state,word,(NumOfRound+1)*Nb-1);
  for( i =  NumOfRound - 1 ; i >= 1 ; i--){
    invShiftRow(state);
    invSubBytes(state);
    addRoundKey(state,word, (i+1)*Nb-1 );
    invMixColumns(state);
  }
    invShiftRow(state);
    invSubBytes(state);
    addRoundKey(state,word,3);
    copyState(state,out);
}

void decryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int sizeofAES){
  int wordSize;
  int round;
  int keySize;
  configureAES(sizeofAES,&keySize,&wordSize,&round);
  uint32_t word[wordSize];
  keyExpansion(key,word,keySize,round);
  invCipher(plainText,encrypOut,word,round);
}

uint8_t* decrypStr(uint8_t* str,char* key,int AESmode){
  if(str == NULL){
    throwError("Error: Input plainText cannot be NULL!",ERR_STR_CANNOT_BE_NULL);
  }
  if(key == NULL){
    throwError("Error: Decrypt Key cannot be NULL!",ERR_KEY_CANNOT_BE_NULL);
  }
  if(AESmode != AES_128 && AESmode != AES_192 && AESmode != AES_256){
    throwError("Erorr: Please key in correct AES mode!",ERR_AES_MODE_CANNOT_BE_NULL);
  }
 
  int i;
  int decrypTimes = (reserveChipherLen(str)/16);
  uint8_t state[4][4];
  uint8_t decrypState[4][4];
  uint8_t *decrypOut = malloc(sizeof(char*)*reserveChipherLen(str));
  char* newKey = optimizeKey(key,AESmode);
 
  for(i = 0; i< decrypTimes ; i++){
    convStrToStateWithIndex(str,state,i);
    decryp_16byte(state,newKey,decrypState,AESmode);
    convStateToStrWithIndex(decrypState,decrypOut,i);
  }
  return decrypOut;
}





