#include "runtime_error_mock.h"

#include <stddef.h>

#include "runtime_error.h"

static const char * message = "No Error";
static int parameter = -1;
static const char * file = NULL;
static int line = -1;

void runtimeErrorMockReset(void) {
    message = "No Error";
    parameter = -1;
}

const char * runtimeErrorMockGetLastError(void) {
    return message;
}

int runtimeErrorMockGetLastParameter(void) {
    return parameter;
}

void runtimeError(const char * _message, int _parameter, const char * _file,
                  int _line) {
    message = _message;
    parameter = _parameter;
    file = _file;
    line = _line;
}

