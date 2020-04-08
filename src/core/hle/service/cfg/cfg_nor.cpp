// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/cfg/cfg_nor.h"

SERIALIZE_EXPORT_IMPL(Service::CFG::CFG_NOR)

namespace Service::CFG {

CFG_NOR::CFG_NOR() : ServiceFramework("cfg:nor", 23) {
    static const FunctionInfo functions[] = {
        {0x00010040, nullptr, "Initialize"},
        {0x00020000, nullptr, "Shutdown"},
        {0x00050082, nullptr, "ReadData"},
        {0x00060082, nullptr, "WriteData"},
        {0x00090000, nullptr, "ReadIdentification"},
        {0x000E0000, nullptr, "ReadStatusRegister"},
        {0x000F0082, nullptr, "ReadDataOther"},
        {0x00100082, nullptr, "WriteDataOther"},
    };
    RegisterHandlers(functions);
}

} // namespace Service::CFG
