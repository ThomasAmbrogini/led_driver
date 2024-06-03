#ifndef __UTIL_RUNTIME_ERROR_MOCK_H__
#define __UTIL_RUNTIME_ERROR_MOCK_H__

void runtimeErrorMockReset(void);
const char * runtimeErrorMockGetLastError(void);
int runtimeErrorMockGetLastParameter(void);

#endif /* __UTIL_RUNTIME_ERROR_MOCK_H__ */

