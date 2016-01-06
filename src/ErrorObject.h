#ifndef ErrorObject_H
#define ErrorObject_H


typedef enum{
  ERR_AES_MODE_CANNOT_BE_NULL,
  ERR_STR_CANNOT_BE_NULL,
  ERR_KEY_CANNOT_BE_NULL
}ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
}ErrorObject;


void freeError(ErrorObject* errObj);
void throwError(char *message, ErrorCode errCode);
#endif // ErrorObject_H
