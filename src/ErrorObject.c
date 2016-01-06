#include "ErrorObject.h"
#include "CException.h"
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>

void throwError(char *message, ErrorCode errCode){
  ErrorObject *errObj = malloc(sizeof(ErrorObject));
  errObj->errorMsg = message;
  errObj->errorCode = errCode;
  Throw(errObj);
  }

  
void freeError(ErrorObject* errObj){
  free(errObj); //inside the free(address)
}