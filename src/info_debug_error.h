#ifndef INFO_DEBUG_ERROR_H__
#define INFO_DEBUG_ERROR_H__

#include <HardwareSerial.h>

// Set to 1 to enable debug output
#ifndef ENABLE_DEBUG_PRINT
#define ENABLE_DEBUG_PRINT 0
#endif


#define info_print(s) Serial.println(F(s))
#define info_print_sv(s,v) do { Serial.print(F(s " ")); \
                                Serial.println(v); } while (0)                           
#define info_print_hex(s,v) do { Serial.print(F(s " 0x")); \
                                 Serial.println(v, HEX); } while (0)

#define debug_print(s) do { if (ENABLE_DEBUG_PRINT) Serial.println(F(s)); } while (0)
#define debug_print_sv(s,v) do { if (ENABLE_DEBUG_PRINT) { \
                                   Serial.print(F(s " ")); \
                                   Serial.println(v); \
                                 } \
                            } while (0)                                          

#define debug_print_hex(s,v) do { if (ENABLE_DEBUG_PRINT) { \
                                   Serial.print(F(s " ")); \
                                   Serial.println(v, HEX); \
                                  } \
                             } while (0)                                          

#define error_print(s) info_print(s)
#define error_print_sv(s,v) info_print_sv(s,v)
#define error_print_hex(s,v) info_print_hex(s,v)

// template<typename T>
// size_t debug_get_address(std::function<void (void)> f) {
//     typedef void (fnType)(void);
//     fnType ** fnPointer = f.template target<fnType*>();
//     return (size_t) *fnPointer;
// }

#endif //INFO_DEBUG_ERROR_H__
