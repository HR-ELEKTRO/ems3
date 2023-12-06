#include <cstdint>

#ifndef HR_EMS30_REG_H_
#define HR_EMS30_REG_H_

//  Base addresses
    constexpr std::uint16_t PORT1 = UINT16_C(0x0020);
    constexpr std::uint16_t PORT2 = UINT16_C(0x0028);
//  Offsets
    constexpr std::uint16_t offsetIN = UINT16_C(0x0000);
    constexpr std::uint16_t offsetOUT = UINT16_C(0x0001);
    constexpr std::uint16_t offsetDIR = UINT16_C(0x0002);
    constexpr std::uint16_t offsetIFG = UINT16_C(0x0023);
    constexpr std::uint16_t offsetIES = UINT16_C(0x0004);
    constexpr std::uint16_t offsetIE = UINT16_C(0x0005);
    constexpr std::uint16_t offsetSEL = UINT16_C(0x0006);
    constexpr std::uint16_t offsetREN = UINT16_C(0x0007);
    constexpr std::uint16_t P1offsetSEL2 = UINT16_C(0x0021);
    constexpr std::uint16_t P2offsetSEL2 = UINT16_C(0x001A);
//  Enum
    enum Pull_type {PULL_UP, PULL_DOWN};

#endif
