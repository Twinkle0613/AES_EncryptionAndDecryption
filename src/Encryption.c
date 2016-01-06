//Library
#include "Encryption.h"
#include <stdint.h>
#include <stdio.h>
#include "malloc.h"
#include "string.h"
#include "CException.h"
//Modules
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"
#include "ErrorObject.h"

/**
 * Encryption is the process of encoding messages or information to protect the priviacy of messages or infomation when sending.
 * Only authorized parties with a decrypt key to decode and read it. In this project, the encryption program was writed by using C language.
 * 
 * Encryption Concept Diagram:
 *
 *                      -------------
 *   plainText  -----> | Encryption | -----> cipherKey
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
 * char* encrypStr(char* str,char* key, int AESmode);
 * void encryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int sizeofAES);
 * void cipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound);
 *
 * >>> Sub Function <<<
 * char* optimizeKey(char*key,int AESmode);
 * char* keyProcess(char* key,int keySizeofAES);
 * void fillZeroToStr(int keySize,char* str,int keySizeofAES);
 * char* optimizeStr(char* str);
 * int reserveChipherLen(char* str);
 * void convStateToStrWithIndex( uint8_t state[][4],char* str,int index);
 * void convStrToStateWithIndex(char* str, uint8_t state[][4], int index);
 * void configureAES(int sizeofAES,int* keySize,int* wordSize, int* round);
 * void copyState(uint8_t in[][4],uint8_t state[][4]);
 *
 *  ------------------------
 * | Explaination Function |
 * ------------------------
 * >>> Main Function <<<
 * The encrypStr(...) function is used for encoding a string 
 * The encryp_16byte(...) function is used for encoding a 16-byte state
 * The cipher(...) function is basic function of encryp_16byte.
 * 
 * >>> Sub Function <<<
 * The optimizeKey(...) function is used in encrypStr(...) for optimizing the input key.
 * The keyProcess(...) function is used in optimizeKey(...) for selecting the type of optimization 
 * The fillZeroToStr(...) function is used in keyProcess(...) for filling zero in which str its place haven't reach 16-byte.
 * The optimizeStr(...) function is used in encrypStr(...) for optimiziong the input str.
 * The reserveChipherLen(...) function is used in encrypStr(...) for calculating the space of cipher Key.
 * The convStateToStrWithIndex(...) function is used in encrypStr(...) for converting from state to string.
 * The convStrToStateWithIndex(...) function is used in encrypStr(...) for converting from string to state.
 * The configureAES(...) function is used in encryp_16byte(...) for setting the length of word and the number of round.
 * The copyState(...) function is used in cipher(...) for coyping the data of state to other state.
 *
 *  ---------------------------------
 * | Explaination Input Of Function |
 * ---------------------------------
 *
 *  encrypStr(char* str,char* key, int AESmode):
 *    str - store the string was typed by users.
 *    key - store the encrypt key was typed by users.
 *    AESmode - store the mode of AES such as AES_128, AES_192 and AES_256 was selected by users.
 *  
 *  encryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int AESmode):
 *    plainText - store the 2-D array was typed by users
 *    key - store the encrypt key was typed by users.
 *    encrypOut - store the output from encryp_16byte function.
 *    AESmode - store the mode of AES such as AES_128, AES_192 and AES_256 was selected by users.
 *
 *  void cipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound):
 *    in - store data in 2-D array was typed by users
 *    out - store the output from encryp_16byte function.
 *    word - store the array is set by KeyExpansion Function.
 *    NumOfRound - store the number of round that depend on the AES mode.
 *
 *  char* optimizeKey(char*key,int AESmode):
 *    key - store the encrypt key was typed by users.
 *    AESmode - store the mode of AES such as AES_128, AES_192 and AES_256 was selected by users.
 * 
 *  char* keyProcess(char* key,int keySizeofAES);
 *    key - store the encrypt key was typed by users.
 *    keySizeofAES - store the key size of AES that depend on the AES mode.
 *
 *  void fillZeroToStr(int keySize,char* str,int keySizeofAES);
 *    keySize - store the encrypt key size.
 *    str - store the string was typed by users.
 *    keySizeofAES - store the key size of AES that depend on the AES mode.
 *
 *  char* optimizeStr(char* str);
 *    str - store the string was typed by users.
 *
 *  int reserveChipherLen(char* str);
 *    str - store the string was typed by users.
 *
 *  void convStateToStrWithIndex( uint8_t state[][4],char* str,int index):
 *    state - that is 2D array for storing the output of encryp_16byte and decryp_16byte
 *    str - store the string was typed by users.
 *    index - store the index was set by program
 *
 *  void convStrToStateWithIndex(char* str, uint8_t state[][4], int index):
 *     str - store the string was typed by users.
 *     state - store the string in 2-D form.
 *     index - store the index was set by program
 *
 *  void configureAES(int AESmode,int* keySize,int* wordSize, int* round);
 *     AESmodes - store the mode of AES such as AES_128, AES_192 and AES_256 was selected by users.
 *     keySize - store the encrypt key size.
 *     wordSize - store the size of word that output from KeyExpansion.
 *     round - store the round of process that depend on AES mode.
 *  
 *  void copyState(uint8_t in[][4],uint8_t state[][4]);
 *     in - store data in 2-D array was typed by users
 *     state - store the string in 2-D form.
 */




void copyState(uint8_t in[][4],uint8_t state[][4]){
    int row,col;
  for(row = 0 ; row < 4 ; row++){
    for(col = 0; col < 4 ; col++){
    state[row][col] = in[row][col];
    }
  }
}

void cipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound){
  int i;
  uint8_t state[4][4];
  copyState(in,state);
  addRoundKey(state,word,3);
   for( i = 1 ; i <= NumOfRound - 1 ; i++){
     subBytes(state);
     shiftRow(state);
     mixColumns(state);
     addRoundKey(state,word, (i+1)*Nb-1 );
    }
    subBytes(state);
    shiftRow(state);
    addRoundKey(state,word,(NumOfRound+1)*Nb-1 );
    copyState(state,out);
}





void encryption_16byte(uint8_t plainText[][4],uint8_t key[],uint8_t result[][4]){

   uint32_t word[44];
   keyExpansion(key,word,4,10);
   cipher(plainText,result,word,10);
}
//.....................................................

void configureAES(int AESmode,int* keySize,int* wordSize, int* round){
    switch(AESmode){
    case AES_128:
    *keySize = 4;
    *wordSize = 44;
    *round = 10;
    break;
    
    case AES_192:
    *keySize = 6;
    *wordSize = 52;
    *round = 12;
    break;
    
    case AES_256:
    *keySize = 8;
    *wordSize = 60;
    *round = 14;
    break;
    default:break;
  }
}

void encryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int AESmode){
  int wordSize;
  int round;
  int keySize;
  configureAES(AESmode,&keySize,&wordSize,&round);
  uint32_t word[wordSize];
  keyExpansion(key,word,keySize,round);
  cipher(plainText,encrypOut,word,round);
}

//...........................................................



void convStrToStateWithIndex(char* str, uint8_t state[][4], int index){
  int row,col;                               
  for(col = 0; col < 4 ; col++){             
    for(row = 0; row < 4 ; row++){           
      state[row][col] = str[row + (4*col) + (16*index)];   
    }                                        
  }   
}

void convStateToStrWithIndex( uint8_t state[][4],char* str,int index){
   int row,col;            
   
  for(col = 0; col < 4 ; col++){             
    for(row = 0; row < 4 ; row++){           
      str[row + (4*col) + (16*index)] = (char)state[row][col];   
    }                                        
  }
  str[ 16 + (16*index) ] = '\0';
}


char* optimizeStr(char* str){
  int i;
  char* newStr = malloc( sizeof(char*)*reserveChipherLen(str) );
 int lenOfStr = strlen(str);
  strncpy(newStr,str,lenOfStr);
   int reminder = lenOfStr % 16;
  
  if( reminder > 0 ){
    for (i = lenOfStr; i < ( lenOfStr + (16 - reminder) ); i++){
      newStr[i] = '0';
    }
  }
  newStr[reserveChipherLen(str)] = '\0';
  return newStr;
}






int reserveChipherLen(char* str){
 return ( ((strlen(str)+15)/16) * 16 );
} 

void fillZeroToStr(int keySize,char* str,int keySizeofAES){
    int i;
  for(i = keySize ; i < keySizeofAES ; i++){
       str[i] = '0';
   }
   str[i] = '\0';
}

char* keyProcess(char* key, int keySizeofAES){
  char* tempKey = malloc(sizeof(char*)*(keySizeofAES+1));
  int keySize = strlen(key);
  if(keySize < keySizeofAES ){
     strncpy(tempKey,key,keySize);
     fillZeroToStr(keySize,tempKey,keySizeofAES);
  }else if (keySize > keySizeofAES){
     strncpy(tempKey,key,keySizeofAES);
     tempKey[keySizeofAES] = '\0';
  }else{
     strcpy(tempKey,key);
  }
  return tempKey;
}

char* optimizeKey(char*key,int AESmode){
  
  switch(AESmode){
    case AES_128:  return keyProcess(key,AES_128_KEYSIZE);
    break;
    case AES_192:  return keyProcess(key,AES_192_KEYSIZE);
    break;
    case AES_256:  return keyProcess(key,AES_256_KEYSIZE);
    break;
    default:break;    
  }
  
}

char* encrypStr(char* str,char* key, int AESmode){

  if(str == NULL){
    throwError("Error: Input plainText cannot be NULL!",ERR_STR_CANNOT_BE_NULL);
  }
  if(key == NULL){
    throwError("Error: Decrypt Key cannot be NULL!",ERR_KEY_CANNOT_BE_NULL);
  }
  if(AESmode != AES_128 && AESmode != AES_192 && AESmode != AES_256){
    throwError("Erorr: Please key in correct AES mode!",ERR_AES_MODE_CANNOT_BE_NULL);
  }
  
 char* encrypOut = malloc(sizeof(char*)*reserveChipherLen(str));
  int encrypTimes = (reserveChipherLen(str)/16);

  int i;
  uint8_t state[4][4];
  uint8_t encrypState[4][4];
  char* newStr = optimizeStr(str);
  char* newKey = optimizeKey(key,AESmode);
  for(i = 0; i< encrypTimes ; i++){
    convStrToStateWithIndex(newStr,state,i);
    encryp_16byte(state,newKey,encrypState,AESmode);
    convStateToStrWithIndex(encrypState,encrypOut,i);
  }
  return encrypOut;
}
