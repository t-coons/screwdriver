#ifndef CastString_h
#define CastString_h

#include <Arduino.h>

class CastString : public String {
  public:
  CastString(const String &str);
  bool toBool(void) const;
  byte toByte(void) const;
  char toChar(void) const;
  long toLong(void) const;
  short toShort(void) const;
  size_t toSize_t(void) const;
  unsigned char toUnsignedChar(void) const;
  unsigned int toUnsignedInt(void) const;
  unsigned long toUnsignedLong(void) const;
  word toWord(void) const;
};


#endif
