#!/bin/bash
./create_ops ShortInt "short int" > ShortInt.hpp
./create_ops UnsignedShortInt "unsigned short int" > UnsignedShortInt.hpp
./create_ops UnsignedInt "unsigned int" > UnsignedInt.hpp
./create_ops LongInt "long int" > LongInt.hpp
./create_ops UnsignedLongInt "unsigned long int" > UnsignedLongInt.hpp
./create_ops LongLongInt "long long int" > LongLongInt.hpp
./create_ops UnsignedLongLongInt "unsigned long long int" > UnsignedLongLongInt.hpp
./create_ops SignedChar "signed char" > SignedChar.hpp
./create_ops UnsignedChar "unsigned char" > UnsignedChar.hpp
./create_ops Float "float" > Float.hpp
./create_ops LongDouble "long double" > LongDouble.hpp
./create_ops Bool "bool" > Bool.hpp
./create_ops WChar "wchar_t" > WChar.hpp

