#ifndef VAR_h
#define VAR_h

#include "CastString.h"

struct VAR {
  enum TAG {
    UNSET,
    BOOL,
    BYTE,
    CHAR,
    DOUBLE,
    FLOAT,
    INT,
    LONG,
    SHORT,
    UINT,
    ULONG
  } tag;
  union {
    bool* pBool;
    byte* pByte;
    char* pChar;
    double* pDouble;
    float* pFloat;
    int* pInt;
    long* pLong;
    short* pShort;
    unsigned int* pUInt;
    unsigned long* pULong;
  };
  VAR() {
    this->tag = TAG::UNSET;
  }
  VAR(bool* pBool) {
    this->tag = TAG::BOOL;
    this->pBool = pBool;
  }
  VAR(byte* pByte) {
    this->tag = TAG::BYTE;
    this->pByte = pByte;
  }
  VAR(char* pChar) {
    this->tag = TAG::CHAR;
    this->pChar = pChar;
  }
  VAR(double* pDouble) {
    this->tag = TAG::DOUBLE;
    this->pDouble = pDouble;
  }
  VAR(float* pFloat) {
    this->tag = TAG::FLOAT;
    this->pFloat = pFloat;
  }
  VAR(int* pInt) {
    this->tag = TAG::INT;
    this->pInt = pInt;
  }
  VAR(long* pLong) {
    this->tag = TAG::LONG;
    this->pLong = pLong;
  }
  VAR(short* pShort) {
    this->tag = TAG::SHORT;
    this->pShort = pShort;
  }
  /* Same as unsigned int
  VAR(size_t* pSize_t) {
    this->tag = TAG::SIZE_T;
    this->pSize_t = pSize_t;
  }
  */
  /* Same as byte
  VAR(unsigned char* pUChar) {
    this->tag = TAG::UCHAR;
    this->pUChar = pUChar;
  }
  */
  VAR(unsigned int* pUInt) {
    this->tag = TAG::UINT;
    this->pUInt = pUInt;
  }
  VAR(unsigned long* pULong) {
    this->tag = TAG::ULONG;
    this->pULong = pULong;
  }
  /* Same as unsigned int
  VAR(word* pWord) {
    this->tag = TAG::WORD;
    this->pWord = pWord;
  }
  */
  bool IsSet() {
    switch(tag) {
      case TAG::BOOL:
        return (pBool == NULL ? false : true);
      case TAG::BYTE:
        return (pByte == NULL ? false : true);
      case TAG::CHAR:
        return (pChar == NULL ? false : true);
      case TAG::DOUBLE:
        return (pDouble == NULL ? false : true);
      case TAG::FLOAT:
        return (pFloat == NULL ? false : true);
      case TAG::INT:
        return (pInt == NULL ? false : true);
      case TAG::LONG:
        return (pLong == NULL ? false : true);
      case TAG::SHORT:
        return (pShort == NULL ? false : true);
      case TAG::UINT:
        return (pUInt == NULL ? false : true);
      case TAG::ULONG:
        return (pULong == NULL ? false : true);
    }
    return false;
  }
  void Set(String s) {
    CastString cs = CastString(s);
    if (IsSet()) {
      switch(tag) {
        case TAG::BOOL:
          *pBool = cs.toBool();
          break;
        case TAG::BYTE:
          *pByte = cs.toByte();
          break;
        case TAG::CHAR:
          *pChar = cs.toChar();
          break;
        case TAG::DOUBLE:
          *pDouble = cs.toDouble();
          break;
        case TAG::FLOAT:
          *pFloat = cs.toFloat();
          break;
        case TAG::INT:
          *pInt = cs.toInt();
          break;
        case TAG::LONG:
          *pLong = cs.toLong();
          break;
        case TAG::SHORT:
          *pShort = cs.toShort();
          break;
        case TAG::UINT:
          *pUInt = cs.toUnsignedInt();
          break;
        case TAG::ULONG:
          *pULong = cs.toUnsignedLong();
          break;
      }
    }
  }
  void Print() {
    if (!IsSet()) {
      Serial.print("NULL");
    }
    switch(tag) {
      case TAG::BOOL:
        Serial.print(*pBool);
        break;
      case TAG::BYTE:
        Serial.print(*pByte);
        break;
      case TAG::CHAR:
        Serial.print(*pChar);
        break;
      case TAG::DOUBLE:
        Serial.print(*pDouble);
        break;
      case TAG::FLOAT:
        Serial.print(*pFloat);
        break;
      case TAG::INT:
        Serial.print(*pInt);
        break;
      case TAG::LONG:
        Serial.print(*pLong);
        break;
      case TAG::SHORT:
        Serial.print(*pShort);
        break;
      case TAG::UINT:
        Serial.print(*pUInt);
        break;
      case TAG::ULONG:
        Serial.print(*pULong);
        break;
    }
  }
  
  void PrintType() {
    switch(tag) {
      case TAG::BOOL:
        Serial.print("bool");
        break;
      case TAG::BYTE:
        Serial.print("byte");
        break;
      case TAG::CHAR:
        Serial.print("char");
        break;
      case TAG::DOUBLE:
        Serial.print("double");
        break;
      case TAG::FLOAT:
        Serial.print("float");
        break;
      case TAG::INT:
        Serial.print("int");
        break;
      case TAG::LONG:
        Serial.print("long");
        break;
      case TAG::SHORT:
        Serial.print("short");
        break;
      case TAG::UINT:
        Serial.print("unsigned int");
        break;
      case TAG::ULONG:
        Serial.print("unsigned long");
        break;
      default: 
        Serial.print("UNSET");
        break;
    }
  }
};

#endif
  
  
