#ifndef __UTIL_RUNTIME_ERROR_H__
#define __UTIL_RUNTIME_ERROR_H__

void runtimeError(const char * message, int parameter, const char * file,
                  int line);

#define RUNTIME_ERROR(description, parameter)\
    runtimeError(description, parameter, __FILE__, __LINE__)

#endif /* __UTIL_RUNTIME_ERROR_H__ */

