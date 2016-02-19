#pragma once

#include <stdlib.h>

typedef unsigned char bool;

typedef unsigned char byte;

typedef unsigned char uint8;
typedef char int8;

typedef short int16;
typedef unsigned short uint16;

typedef int int32;
typedef unsigned int uint32;

typedef long int64;
typedef unsigned long uint64;

#define True 1
#define False 0

#define STRING_END '\0'

#define true (bool)1
#define false (bool)0

#define null NULL

#define printLine(msg) printf("%s\n", msg)

//masks from 1 to 8
uint8 mask0 = 0x00;
uint8 mask1 = 0x01;
uint8 mask2 = 0x02;
uint8 mask3 = 0x04;
uint8 mask4 = 0x08;
uint8 mask5 = 0x10;
uint8 mask6 = 0x20;
uint8 mask7 = 0x40;
uint8 mask8 = 0x80;