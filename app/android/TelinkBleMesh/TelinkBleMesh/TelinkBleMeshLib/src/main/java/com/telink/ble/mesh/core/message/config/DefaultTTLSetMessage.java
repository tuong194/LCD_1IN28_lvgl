/********************************************************************************************************
 * @file DefaultTTLSetMessage.java
 *
 * @brief for TLSR chips
 *
 * @author telink
 * @date Sep. 30, 2017
 *
 * @par Copyright (c) 2017, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *******************************************************************************************************/
package com.telink.ble.mesh.core.message.config;

import com.telink.ble.mesh.core.message.Opcode;

/**
 * The Config Default TTL Set is an acknowledged message used to set the Default TTL state of a node
 * <p>
 * The response to a Config Default TTL Get message is a Config Default TTL Status message {@link DefaultTTLStatusMessage}.
 */

public class DefaultTTLSetMessage extends ConfigMessage {

    /**
     * New Default TTL value, difference with {@link com.telink.ble.mesh.core.message.MeshMessage#ttl}
     */
    public byte newTTL;

    public DefaultTTLSetMessage(int destinationAddress) {
        super(destinationAddress);
    }

    public static DefaultTTLSetMessage getSimple(int destinationAddress, byte newTTL) {
        DefaultTTLSetMessage instance = new DefaultTTLSetMessage(destinationAddress);
        instance.newTTL = newTTL;
        return instance;
    }

    @Override
    public int getOpcode() {
        return Opcode.CFG_DEFAULT_TTL_SET.value;
    }

    @Override
    public int getResponseOpcode() {
        return Opcode.CFG_DEFAULT_TTL_STATUS.value;
    }

    @Override
    public byte[] getParams() {
        return new byte[]{newTTL};
    }
}
