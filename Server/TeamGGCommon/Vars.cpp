﻿#include "stdafx.h"

#include <new>

#include "ProudNetClient.h"
#include "Vars.h"

using namespace std;
using namespace Proud;

// Protocol version that you define.
// Your server app and client app must have the same value below..
//PNGUID guid =
//{ 0xafa3c0c, 0x77d7, 0x4b74,{ 0x9d, 0xdb, 0x1c, 0xb3, 0xd2, 0x5e, 0x1e, 0x64 } };
//PNGUID guid = { 0xafa3c0c, 0x77d7, 0x4b74, { 0x9d,0xdb,0x1c,0xb3,0xd2,0x5e,0x1e,0x64 } };
PNGUID guid = {0x3ae33249,0xecc6,0x4980,{0xbc,0x5d,0x7b,0xa,0x99,0x9c,0x7,0x39}};
Guid g_Version = Guid(guid);

// TCP listening port number.
int g_ServerPort = 52425;