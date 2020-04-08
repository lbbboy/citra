// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/ac/ac_i.h"

namespace Service::AC {

AC_I::AC_I(std::shared_ptr<Module> ac) : Module::Interface(std::move(ac), "ac:i", 10) {
    static const FunctionInfo functions[] = {
        {0x00010000, &AC_I::CreateDefaultConfig, "CreateDefaultConfig"},
        {0x00015004, nullptr, "ExclusiveAsync"},
        {0x00020042, nullptr, "DebugSetApType"},
        {0x00030042, nullptr, "DebugSetNetworkArea"},
        {0x00040006, &AC_I::ConnectAsync, "ConnectAsync"},
        {0x00050002, &AC_I::GetConnectResult, "GetConnectResult"},
        {0x000600C6, nullptr, "DebugSetNetworkSetting1"},
        {0x00070002, nullptr, "CancelConnectAsync"},
        {0x00080004, &AC_I::CloseAsync, "CloseAsync"},
        {0x00090002, &AC_I::GetCloseResult, "GetCloseResult"},
        {0x000A0000, nullptr, "GetLastErrorCode"},
        {0x000B0000, nullptr, "GetLastDetailErrorCode"},
        {0x000C0000, nullptr, "GetStatus"},
        {0x000D0000, &AC_I::GetWifiStatus, "GetWifiStatus"},
        {0x000E0042, nullptr, "GetCurrentAPInfo"},
        {0x000F0000, nullptr, "GetConnectingInfraPriority"},
        {0x00100042, nullptr, "GetCurrentNZoneInfo"},
        {0x00110042, nullptr, "GetNZoneApNumService"},
        {0x00120042, nullptr, "GetConnectingHotspot"},
        {0x00130042, nullptr, "GetConnectingHotspotSubset"},
        {0x00140002, nullptr, "GetConnectingLocation"},
        {0x00160002, nullptr, "GetExclusiveResult"},
        {0x00170004, nullptr, "UnExclusiveAsync"},
        {0x00180002, nullptr, "GetUnExcusiveResult"},
        {0x00190004, nullptr, "CloseAllASync"},
        {0x001A0002, nullptr, "GetCloseAllResult"},
        {0x001B0004, nullptr, "LogoutHotspotAsync"},
        {0x001C0002, nullptr, "GetLogoutHotspotResult"},
        {0x001D0042, nullptr, "ScanAPs"},
        {0x001E0042, nullptr, "ScanNintendoZone"},
        {0x001F0042, nullptr, "ScanNintendoZoneSubset"},
        {0x00200005, nullptr, "BeginScanUsbAccessPoint"},
        {0x00210002, nullptr, "EndScanUsbAccessPoint"},
        {0x00220042, nullptr, "SetAllowApType"},
        {0x00230042, nullptr, "AddAllowApType"},
        {0x00240042, nullptr, "AddDenyApType"},
        {0x00270002, &AC_I::GetInfraPriority, "GetInfraPriority"},
        {0x00280042, nullptr, "SetPowerSaveMode"},
        {0x00290002, nullptr, "GetPowerSaveMode"},
        {0x002A0004, nullptr, "SetBssidFilter"},
        {0x002B0004, nullptr, "SetApNumFilter"},
        {0x002C0042, nullptr, "SetFromApplication"},
        {0x002D0082, &AC_I::SetRequestEulaVersion, "SetRequestEulaVersion"},
        {0x002E00C4, nullptr, "ConvertPassphraseToPsk"},
        {0x002F0004, nullptr, "GetNZoneBeaconNotFoundEvent"},
        {0x00300004, &AC_I::RegisterDisconnectEvent, "RegisterDisconnectEvent"},
        {0x00340000, nullptr, "GetConnectingSsid"},
        {0x00350000, nullptr, "GetConnectingSsidLength"},
        {0x00360000, nullptr, "GetConnectingProxyEnable"},
        {0x00370000, nullptr, "GetConnectingProxyAuthType"},
        {0x00380000, nullptr, "GetConnectingProxyPort"},
        {0x00390000, nullptr, "GetConnectingProxyHost"},
        {0x003A0000, nullptr, "GetConnectingProxyUserName"},
        {0x003B0000, nullptr, "GetConnectingProxyPassword"},
        {0x003C0042, nullptr, "GetAPSSIDList"},
        {0x003E0042, &AC_I::IsConnected, "IsConnected"},
        {0x00400042, &AC_I::SetClientVersion, "SetClientVersion"},
        /// exclusive
        {0x04010040, nullptr, "LoadNetworkSetting"},
        {0x04020040, nullptr, "UpdateNetworkSetting"},
        {0x04030040, nullptr, "RemoveNetworkSetting"},
        {0x04040000, nullptr, "FlushNetworkSetting"},
        {0x04050084, nullptr, "ConvertNetworkSettingNdsTo3ds"},
        {0x04060040, nullptr, "InitializeNetworkSetting"},
        {0x04070000, nullptr, "GetNetworkSettingVersion"},
        {0x04080040, nullptr, "SetNetworkSettingVersion"},
        {0x04090000, nullptr, "GetNetworkSetting_Crc"},
        {0x040A0040, nullptr, "SetNetworkSetting_Crc"},
        {0x040B0000, nullptr, "GetNetworkWirelessEnable"},
        {0x040C0040, nullptr, "SetNetworkWirelessEnable"},
    };
    RegisterHandlers(functions);
}

} // namespace Service::AC

SERIALIZE_EXPORT_IMPL(Service::AC::AC_I)
