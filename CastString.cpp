#include "CastString.h"

CastString::CastString(const String &str):
String(str) {
}

bool CastString::toBool(void) const {
  if (equals("0") || equals("\0") || equalsIgnoreCase("false")) {
    return false;
  }
  return true;
}

byte CastString::toByte(void) const {
  if (buffer) return atoi(buffer);
  return 0;
}

char CastString::toChar(void) const {
  if (buffer) return buffer[0];
}

long CastString::toLong(void) const {
  if (buffer) return atol(buffer);
  return 0;
}

short CastString::toShort(void) const {
  if (buffer) return (short)atoi(buffer);
  return 0;
}

size_t CastString::toSize_t(void) const {
  if (buffer) return (size_t)strtoul(buffer, NULL, 0);
}

unsigned char CastString::toUnsignedChar(void) const {
  return (unsigned char)toChar();
}

unsigned int CastString::toUnsignedInt(void) const {
  return (unsigned int)toInt();
}

unsigned long CastString::toUnsignedLong(void) const {
  return (unsigned long)toLong();
}

word CastString::toWord(void) const {
  return (word)toUnsignedInt();
}
