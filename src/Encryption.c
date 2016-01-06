#include "Encryption.h"
#include <stdint.h>
#include <stdio.h>
#include "string.h"
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"
#include "malloc.h"
#include "ErrorObject.h"
#include "CException.h"


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

void printfStateInChar(uint8_t state[][4]){
  int row;
  for(row = 0 ; row < 4 ; row++){
    printf("%.*c %.*c %.*c %.*c\n",2,state[row][0],2,state[row][1],2,state[row][2],2,state[row][3]);
  }
}

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



void printEncrypOut(char* encrypOut){
  int i;
  for( i = 0 ; i < 16 ; i++){
    printf("0x%x ",encrypOut[i]);
  }
  printf("\n");
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
