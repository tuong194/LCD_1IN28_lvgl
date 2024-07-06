## V4.1.0.0

### Version

* SDK Version: telink_b91_sig_mesh_sdk_V4.1.0.0
* Chip Version: TLSR921X/951X
* BLE Version: telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Features

* (Firmware)add Flash protection.set APP_FLASH_PROTECTION_ENABLE to 1 to enable. enable by default.
  - Flash protection is enabled by default, and it must be enabled in production.
  - During the development phase, user should click the "Unlock" button in Telink BDT tool to unlock before erase/write the Flash.
* (Firmware)support firmware size up to 864k bytes. The default maximum support is 384k, enable FIRMWARE_SIZE_EXCEED_512K_EN to support 864k. user guide for this function, please refer to "/doc/B91_spport_864k_firmware_user_guide.md".
* (Firmware/Android/iOS)support all features of mesh V1.1, mainly include:
  - enhance provision auth: set PROV_EPA_EN to 1 to enable. enable by default.
  - remote provision: provision the unprovision devices within one-hop or multi-hops. set MD_REMOTE_PROV to 1 to enable. disabled by default.
  - device firmware update: Upgrade the firmware of multiple nodes simultaneously through mesh. set MD_MESH_OTA_EN to 1 to enable. disabled by default.
  - directed forwarding: set MD_DF_CFG_SERVER_EN to 1 to enable. disabled by default.
  - certificate-base provisioning: set CERTIFY_BASE_ENABLE to 1 to enable. disabled by default.
  - private beacons: set MD_PRIVACY_BEA and PRIVATE_PROXY_FUN_EN to 1 to enable. disabled by default.
  - subnet bridge: set MD_SBR_CFG_SERVER_EN to 1 to enable. disabled by default.
  - Opcodes Aggregator: aggregate multiple messages into a single message to send. set MD_OP_AGG_EN to 1 to enable. disabled by default.
  - NLC profiles: Network Lighting Control profiles. set one of NLCP_BLC_EN, NLCP_DIC_EN, NLCP_BSS_EN, NLCP_TYPE_ALS, NLCP_TYPE_OCS and NLCP_TYPE_ENM to 1 to enable the corresponding NLC profile. disabled by default.

### Bug Fixes

* N/A

### Known issues

* use Telink_RDS_v323 IDE to compile, not support Telink IoT studio IDE currently.

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Royalty fee for certain Audio Codec:

* This SDK may include options for multiple audio codecs, it should be noted that use of certain Codecs may incur Royalty fees. It is the end product manufacturer's responsibility to sign license agreement with the license onwers and pay royalty fees. Telink as an IC provider cannot cover these charges.
* Use of LC3+ codec: If you choose to use LC3+ codec, please contact Fraunhofer/Ericsson (Fraunhofer IIS: lc3-licensing@iis.fraunhofer.de and Ericsson: lc3.licensing@ericsson.com) for proper license agreement and royalty fee information. A flat fee is charged by these License owners for product incorporating LC3+ codec. The royalty fee is open and transparent and charged per device (e.g. Headset, TV ,Box, …).
* Use of LC3 codec: LC3 usage is only free for product qualified as a Bluetooth product by Bluetooth SIG. If your product is not Bluetooth qualified and you choose to use LC3 codec, please contact Fraunhofer/Ericsson (Fraunhofer IIS: lc3-licensing@iis.fraunhofer.de and Ericsson: lc3.licensing@ericsson.com) for proper license agreement and royalty fee information. A flat fee is charged by these License owners for non-Bluetooth product incorporating LC3 codec. The royalty fee is open and transparent and charged per device (e.g. Headset, TV ,Box, …).

### Notes

* debugging tools: such as sig_mesh_tool.exe and Android apk, please make sure to use the tools of this release.
* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.
* for the release note contents of the BLE SDK and Driver SDK mentioned in "Version", please refer to the release note files of related SDKs.
* support SIG Mesh single connection app TelinkBleMesh.

### Flash

* P25Q80U
* P25Q16SU
* P25Q32SU

### CodeSize

  - B91_mesh:_________Flash 125.1 KB, I-RAM (37.8 KB + 4KB stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash  123.9 KB, I-RAM (41.8 KB + 4KB stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash  120.1 KB, I-RAM (33.6 KB + 4KB stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 113.7 KB, I-RAM (34.2 KB + 4KB stack), D-RAM (0 KB).

### Version

* SDK Version: telink_b91_sig_mesh_sdk_V4.1.0.0
* Chip Version: TLSR921X/951X
* BLE Version: telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Features

* (Firmware)添加Flash保护。设置 APP_FLASH_PROTECTION_ENABLE 等于 1来使能该功能，默认打开。
  - SDK 中默认开启 Flash 保护，在量产时必须启用。
  - 在开发阶段，用户在擦写Flash前应使用Telink BDT工具中的“Unlock”命令解锁Flash。
* (Firmware)支持最大 864k bytes的固件。默认最大支持 384k，使能 FIRMWARE_SIZE_EXCEED_512K_EN 后支持 864k，详细使用说明请参考 /doc/B91_support_864k_firmware_user_guide.md。
* (Firmware/Android/iOS)支持 mesh V1.1 的所有功能，主要包含：
  - enhance provision auth：组网认证增强，设置 PROV_EPA_EN 等于 1来使能该功能，默认打开。
  - remote provision：把距离provisioner一跳及多跳的未配网设备都能添加到网络中。设置 MD_REMOTE_PROV 等于 1来使能该功能，默认关闭。
  - device firmware update：通过mesh方式对多个节点同时进行固件升级，设置 MD_MESH_OTA_EN 等于 1来使能该功能，默认关闭。
  - directed forwarding：路由功能，设置 MD_DF_CFG_SERVER_EN 等于 1来使能该功能，默认关闭。
  - certificate-base provisioning：基于证书认证的组网模式，设置 CERTIFY_BASE_ENABLE 等于 1来使能该功能，默认关闭。
  - private beacons：私有信标，设置 MD_PRIVACY_BEA 和 PRIVATE_PROXY_FUN_EN 等于 1来使能该功能，默认关闭。
  - subnet bridge：子网桥接，设置 MD_SBR_CFG_SERVER_EN 等于 1来使能该功能，默认关闭。
  - Opcodes Aggregator：多个消息组合成一条消息的功能，设置 MD_OP_AGG_EN 等于 1来使能该功能，默认关闭。
  - NLC profiles: Network Lighting Control profiles, 分别设置 NLCP_BLC_EN, NLCP_DIC_EN, NLCP_BSS_EN, NLCP_TYPE_ALS, NLCP_TYPE_OCS, NLCP_TYPE_ENM 等于 1来使能对应功能，默认关闭。

### Bug Fixes

* N/A

### Known issues

* 用Telink_RDS_v323 IDE编译，暂不支持Telink IoT studio IDE。

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Royalty fee for certain Audio Codec:

此SDK可能包括多种音频编解码器的选项，需要注意的是，使用某些编解码器可能会产生版权费用。最终产品制造商有责任与许可所有者签订许可协议并支付版权费用。作为IC提供商的Telink无法承担这些费用。
使用LC3+编解码器：如果您选择使用LC3+编解码器，请联系Fraunhofer/Ericsson（Fraunhofer IIS：lc3-licensing@iis.fraunhofer.de 和 Ericsson：lc3.licensing@ericsson.com）以获得适当的许可协议和版权费用信息。这些许可所有者对采用LC3+编解码器的产品收取固定费用。版权费用是公开透明的，按设备收费（例如耳机、电视、盒子等）。
使用LC3编解码器：只有被蓝牙SIG认证为蓝牙产品的产品才可以免费使用LC3编解码器。如果您的产品未经蓝牙认证且选择使用LC3编解码器，请联系Fraunhofer/Ericsson（Fraunhofer IIS：lc3-licensing@iis.fraunhofer.de 和 Ericsson：lc3.licensing@ericsson.com）以获得适当的许可协议和版权费用信息。这些许可所有者对非蓝牙产品采用LC3编解码器收取固定费用。版权费用是公开透明的，按设备收费（例如耳机、电视、盒子等）。

### Notes

* 调试工具：比如sig_mesh_tool.exe和APP 安装包文件，请务必使用本次release的版本。
* 为避免编译错误以及功能丢失，升级SDK时，请确认更新全部SDK文件。
* “Version”里面提到的BLE SDK和Driver SDK的release note内容，请查阅对应SDK的release note文件。
* 支持SIG Mesh单连接app TelinkBleMesh。 

### Flash

* P25Q80U
* P25Q16SU
* P25Q32SU

### CodeSize

  - B91_mesh:_________Flash 125.1 KB, I-RAM (37.8 KB + 4KB stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash  123.9 KB, I-RAM (41.8 KB + 4KB stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash  120.1 KB, I-RAM (33.6 KB + 4KB stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 113.7 KB, I-RAM (34.2 KB + 4KB stack), D-RAM (0 KB).


## V3.1.0.5

### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* Add flash write protection, please refer to MESH_FLASH_PROTECTION_EN. disable as default. Note: 1M Flash Map has been changed, please pay attention to compatibility issues.

### Performance Improvements

* N/A

### BREAKING CHANGES

* 1M Flash Map has been changed, please pay attention to compatibility issues.

### Royalty fee for certain Audio Codec:

* This SDK may include options for multiple audio codecs, it should be noted that use of certain Codecs may incur Royalty fees. It is the end product manufacturer's responsibility to sign license agreement with the license onwers and pay royalty fees. Telink as an IC provider cannot cover these charges.
* Use of LC3+ codec: If you choose to use LC3+ codec, please contact Fraunhofer/Ericsson (Fraunhofer IIS: lc3-licensing@iis.fraunhofer.de and Ericsson: lc3.licensing@ericsson.com) for proper license agreement and royalty fee information. A flat fee is charged by these License owners for product incorporating LC3+ codec. The royalty fee is open and transparent and charged per device (e.g. Headset, TV ,Box, …).
* Use of LC3 codec: LC3 usage is only free for product qualified as a Bluetooth product by Bluetooth SIG. If your product is not Bluetooth qualified and you choose to use LC3 codec, please contact Fraunhofer/Ericsson (Fraunhofer IIS: lc3-licensing@iis.fraunhofer.de and Ericsson: lc3.licensing@ericsson.com) for proper license agreement and royalty fee information. A flat fee is charged by these License owners for non-Bluetooth product incorporating LC3 codec. The royalty fee is open and transparent and charged per device (e.g. Headset, TV ,Box, …).

### Notes

* debugging tools: such as sig_mesh_tool.exe and Android apk, please be sure to use the tools of this release.
* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.
* for the release note contents of the BLE SDK and Driver SDK mentioned in "Dependency Updates", please refer to the release note files of related SDKs.

* Flash and RAM (default target):

  - B91_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash 114 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* 增加 flash 写保护功能，请参考宏定义 MESH_FLASH_PROTECTION_EN，默认关闭。注意 1M Flash Map 有变更，请留意兼容性问题。

### Performance Improvements

* N/A

### BREAKING CHANGES

* 1M Flash Map 有变更，请留意兼容性问题

### Royalty fee for certain Audio Codec:

此SDK可能包括多种音频编解码器的选项，需要注意的是，使用某些编解码器可能会产生版权费用。最终产品制造商有责任与许可所有者签订许可协议并支付版权费用。作为IC提供商的Telink无法承担这些费用。
使用LC3+编解码器：如果您选择使用LC3+编解码器，请联系Fraunhofer/Ericsson（Fraunhofer IIS：lc3-licensing@iis.fraunhofer.de 和 Ericsson：lc3.licensing@ericsson.com）以获得适当的许可协议和版权费用信息。这些许可所有者对采用LC3+编解码器的产品收取固定费用。版权费用是公开透明的，按设备收费（例如耳机、电视、盒子等）。
使用LC3编解码器：只有被蓝牙SIG认证为蓝牙产品的产品才可以免费使用LC3编解码器。如果您的产品未经蓝牙认证且选择使用LC3编解码器，请联系Fraunhofer/Ericsson（Fraunhofer IIS：lc3-licensing@iis.fraunhofer.de 和 Ericsson：lc3.licensing@ericsson.com）以获得适当的许可协议和版权费用信息。这些许可所有者对非蓝牙产品采用LC3编解码器收取固定费用。版权费用是公开透明的，按设备收费（例如耳机、电视、盒子等）。

### Notes

* 调试工具：比如sig_mesh_tool.exe和APP 安装包文件，请务必使用本次release的版本。
* 为避免编译错误以及功能丢失，升级SDK时，请确认更新全部SDK文件。
* “Dependency Updates”里面提到的BLE SDK和Driver SDK的release note内容，请查阅对应SDK的release note文件。



## V3.1.0.4

### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* fix GPIO IRQ. Please refer to IRQ_GPIO_ENABLE, and this feature is not enabled by default.
* fix TIMER IRQ. Please refer to IRQ_TIMER1_ENABLE, and this feature is not enabled by default.
* fix gateway mesh ota b85.

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Notes

* debugging tools: such as sig_mesh_tool.exe and Android apk, please be sure to use the tools of this release.
* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.
* for the release note contents of the BLE SDK and Driver SDK mentioned in "Dependency Updates", please refer to the release note files of related SDKs.

* Flash and RAM (default target):

  - B91_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash 114 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* 修复 GPIO IRQ。代码请参考 IRQ_GPIO_ENABLE，默认未启用该功能。
* 修复 TIMER1 IRQ。代码请参考 IRQ_TIMER1_ENABLE，默认未启用该功能。
* 修复网关mesh ota b85设备。

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Notes

* 调试工具：比如sig_mesh_tool.exe和APP 安装包文件，请务必使用本次release的版本。
* 为避免编译错误以及功能丢失，升级SDK时，请确认更新全部SDK文件。
* “Dependency Updates”里面提到的BLE SDK和Driver SDK的release note内容，请查阅对应SDK的release note文件。



## V3.1.0.3

### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* (Firmware) Mesh Audio: add ENC (Environmental Noise Cancellation).
* (Firmware) Mesh Audio: support multiple nodes speaking simultaneously. enable AUDIO_MESH_MULTY_NODES_TX_EN for this function, disabled as default.
* (Firmware) Mesh Audio: support provision between nodes without an App and gateway. enable PAIR_PROVISION_ENABLE for this function, disabled as default.
* (Firmware) Mesh Audio: support I2S. enable AUDIO_I2S_EN for this function, disabled as default. if enable I2S, AUDIO_SAMPLE_RATE only support 8k now. next version will support 16K.

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Notes

* debugging tools: such as sig_mesh_tool.exe and Android apk, please be sure to use the tools of this release.
* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.
* for the release note contents of the BLE SDK and Driver SDK mentioned in "Dependency Updates", please refer to the release note files of related SDKs.

* Flash and RAM (default target):

  - B91_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash 114 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* (Firmware) Mesh Audio功能：增加 ENC 环境噪音降噪功能。(Environmental Noise Cancellation,环境降噪技术)。
* (Firmware) Mesh Audio功能：支持多节点同时讲话，打开 AUDIO_MESH_MULTY_NODES_TX_EN 即可，默认关闭。
* (Firmware) Mesh Audio功能：支持在没有App和网关情况下, 节点和节点之间进行配对组网的功能。打开 PAIR_PROVISION_ENABLE 即可，默认关闭。
* (Firmware) Mesh Audio功能：支持I2S。打开 AUDIO_I2S_EN 即可，默认关闭。使能AUDIO_I2S_EN后，AUDIO_SAMPLE_RATE 目前仅支持 8k模式, 下个版本再支持 16k.

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Notes

* 调试工具：比如sig_mesh_tool.exe和APP 安装包文件，请务必使用本次release的版本。
* 为避免编译错误以及功能丢失，升级SDK时，请确认更新全部SDK文件。
* “Dependency Updates”里面提到的BLE SDK和Driver SDK的release note内容，请查阅对应SDK的release note文件。



## V3.1.0.2

### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* N/A

### Performance Improvements

* delete some unused APIs which name has typo.

### BREAKING CHANGES

* N/A

### Notes

* updated base on version 3.1.0.0.

### CodeSize

* Flash and RAM (default target):

  - B91_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash 113 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* N/A

### Performance Improvements

* 删除一些未正确拼写名称且未使用的接口。

### BREAKING CHANGES

* N/A

### Notes

* 基于 3.1.0.0 版本进行更新。


## V3.1.0.1

### Dependency Updates

* N/A

### Bug Fixes

* N/A

### Features

* (Firmware) add software PA function.
* (Firmware) add SBC algorithm for mesh audio.

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Notes

* debugging tools: such as sig_mesh_tool.exe and Android apk, please be sure to use the tools of this release.
* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.
* for the release note contents of the BLE SDK and Driver SDK mentioned in "Dependency Updates", please refer to the release note files of related SDKs.

* Flash and RAM (default target):

  - B91_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash 113 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


### Dependency Updates

* N/A

### Bug Fixes

* N/A

### Features

* (Firmware) 增加 软件PA功能。
* (Firmware) mesh audio增加SBC算法。

### Performance Improvements

* N/A

### BREAKING CHANGES

* N/A

### Notes

* 调试工具：比如sig_mesh_tool.exe和APP 安装包文件，请务必使用本次release的版本。
* 为避免编译错误以及功能丢失，升级SDK时，请确认更新全部SDK文件。


## V3.1.0.0

### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* (Firmware/Android/iOS) support all SIG Mesh functions of telink_sig_mesh_sdk V3.3.3.5.
* (Firmware) add project of B91_mesh_gw, B91_mesh_LPN and B91_mesh_switch.
* (Firmware) support local voice control. enable SPEECH_ENABLE for this function, disabled by default.
* (Firmware) add Mesh Audio function. enable AUDIO_MESH_EN for this function, disabled by default.
* (Firmware) update b91 to support protection code.

### Performance Improvements

* (Firmware) all D-RAM is reserved for customer by default. if need to place global variables to D-RAM, add _attribute_data_dlm_ or _attribute_bss_dlm_ before global variables.

### BREAKING CHANGES

* N/A

### Notes

* debugging tools: such as sig_mesh_tool.exe and Android apk, please be sure to use the tools of this release.
* to avoid compilation errors or loss of functionality, please update all files when upgrading the SDK.
* for the release note contents of the BLE SDK and Driver SDK mentioned in "Dependency Updates", please refer to the release note files of related SDKs.

* Flash and RAM (default target):

  - B91_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_LPN:____Flash 113 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - B91_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


### Dependency Updates

* telink_b91m_ble_single_connection_sdk_v3.3.0.0

### Bug Fixes

* N/A

### Features

* (Firmware/Android/iOS) 支持 telink_sig_mesh_sdk V3.3.3.5 对应的 SIG Mesh 协议栈功能。
* (Firmware) 增加 B91_mesh_gw，B91_mesh_LPN，B91_mesh_switch编译选项。
* (Firmware) 支持本地语音命令控制功能。设置 SPEECH_ENABLE为 1 开启此功能，默认关闭。
* (Firmware) 增加 Mesh Audio 功能。设置 AUDIO_MESH_EN 为 1 开启此功能，默认关闭。
* (Firmware) 更新b91以支持保护码。

### Performance Improvements

* (Firmware) 默认不使用D-RAM，全部留给客户使用。在变量定义时，加_attribute_data_dlm_或者_attribute_bss_dlm_即可把变量定义在D-RAM区。

### BREAKING CHANGES

* N/A

### Notes

* 调试工具：比如sig_mesh_tool.exe和APP 安装包文件，请务必使用本次release的版本。
* 为避免编译错误以及功能丢失，升级SDK时，请确认更新全部SDK文件。
* “Dependency Updates”里面提到的BLE SDK和Driver SDK的release note内容，请查阅对应SDK的release note文件。





## V4.1.0
### Bug Fixes
* N/A

### Features
* add the support to the dongle board(C1T21_3A_1_1).
* add the support for the local voice control, disabled by default(SPEECH_ENABLE).
* support gatt_ota, the firmware size is up to 440k.

### BREAKING CHANGES
* N/A

### Bug Fixes
* N/A

### Features
* 添加对C1T21_3A_1_1的eagle的dongle板的支持。
* 支持mesh的本地语音控制的功能，缺省关闭(SPEECH_ENABLE)。
* 支持gatt_ota，固件最大可支持到440k。

### BREAKING CHANGES
* N/A

## V4.0.0
### Bug Fixes
* N/A

### Features
* Based on sig-mesh version 3.2.3 for chip A0 of eagle.
* Support normal sig-mesh node in the sig-mesh protocol.
* Support to operate by sig-mesh tools ,android app and ios app.

### BREAKING CHANGES
* N/A

### Bug Fixes
* N/A

### Features
* 基于 sdk：sig-mesh version 3.2.3 + chip A0 of eagle。
* 支持mesh协议中的普通mesh的节点。
* 支持使用sig-mesh的vc工具，android和ios工具来操作。

### BREAKING CHANGES
* N/A