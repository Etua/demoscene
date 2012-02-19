#ifndef __STD_DEBUG_H__
#define __STD_DEBUG_H__

#ifdef NDEBUG
#define LOG(...)
#define PANIC(...) _exit();
#else
#include <stdio.h>
#define _LINE() printf("%s:%d:%s: ", __FILE__, __LINE__, __FUNCTION__)
#define _EOL() putchar('\n')
#define LOG(...) { _LINE(); printf(__VA_ARGS__); _EOL(); }
#define PANIC(...) { LOG(__VA_ARGS__); _exit(); }
#endif

#endif
