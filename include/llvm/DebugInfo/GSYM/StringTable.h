//===- StringTable.h --------------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_DEBUGINFO_GSYM_STRINGTABLE_H
#define LLVM_DEBUGINFO_GSYM_STRINGTABLE_H

#include "llvm/ADT/Optional.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/DebugInfo/GSYM/Range.h"
#include <stdint.h>
#include <string>


namespace llvm {
namespace gsym {

/// String tables in GSYM files are required to start with an empty 
/// string at offset zero. Strings must be UTF8 NULL terminated strings.
struct StringTable {
  StringRef Data;
  StringTable() : Data() {}
  StringTable(StringRef D) : Data(D) {}
  StringRef operator[](size_t Offset) const { return getString(Offset); }
  StringRef getString(uint32_t Offset) const {
    if (Offset < Data.size()) {
      auto End = Data.find('\0', Offset);
      return Data.substr(Offset, End - Offset);
    }
    return StringRef();
  }
  void clear() { Data = StringRef(); }
};

inline raw_ostream &operator<<(raw_ostream &OS, const StringTable &S) {
  OS << "String table:\n";
  uint32_t Offset = 0;
  const size_t Size = S.Data.size();
  while (Offset < Size) {
    StringRef Str = S.getString(Offset);
    OS << HEX32(Offset) << ": \"" << Str << "\"\n";
    Offset += Str.size() + 1;
  }
  return OS;
}

} // namespace gsym
} // namespace llvm
#endif // #ifndef LLVM_DEBUGINFO_GSYM_STRINGTABLE_H
