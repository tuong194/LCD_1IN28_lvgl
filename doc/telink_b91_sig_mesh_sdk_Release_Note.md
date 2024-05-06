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

* updated from version 3.1.0.0.

### CodeSize

* Flash and RAM (default target):

  - 8258_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - 8258_mesh_LPN:____Flash 113 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - 8258_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - 8258_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


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

  - 8258_mesh:_________Flash 120 KB, I-RAM (38 KB + 4K stack), D-RAM (0 KB).
  - 8258_mesh_LPN:____Flash 113 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).
  - 8258_mesh_gw:_____Flash 126 KB, I-RAM (45 KB + 4K stack), D-RAM (0 KB).
  - 8258_mesh_switch:__Flash 108 KB, I-RAM (33 KB + 4K stack), D-RAM (0 KB).


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