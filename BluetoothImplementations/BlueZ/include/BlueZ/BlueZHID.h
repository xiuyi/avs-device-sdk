/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_CLIENT_SDK_BLUETOOTHIMPLEMENTATIONS_BLUEZ_INCLUDE_BLUEZ_BLUEZHID_H_
#define ALEXA_CLIENT_SDK_BLUETOOTHIMPLEMENTATIONS_BLUEZ_INCLUDE_BLUEZ_BLUEZHID_H_

#include <memory>

#include <AVSCommon/SDKInterfaces/Bluetooth/Services/HIDInterface.h>
#include <AVSCommon/Utils/Bluetooth/SDPRecords.h>

namespace alexaClientSDK {
namespace bluetoothImplementations {
namespace blueZ {

/**
 * BlueZ implementation of @c HIDInterface interface
 */
class BlueZHID : public avsCommon::sdkInterfaces::bluetooth::services::HIDInterface {
public:
    /**
     * Factory method to create a new instance of @c BlueZHID
     *
     * @return A new instance of @c BlueZHID, nullptr if there was an error creating it.
     */
    static std::shared_ptr<BlueZHID> create();

    /// @name BluetoothServiceInterface functions.
    /// @{
    std::shared_ptr<avsCommon::sdkInterfaces::bluetooth::services::SDPRecordInterface> getRecord() override;
    void setup() override;
    void cleanup() override;
    /// @}

private:
    /**
     * Private constructor
     */
    BlueZHID();

    /// Bluetooth service's SDP record containing the common service information.
    std::shared_ptr<avsCommon::utils::bluetooth::HIDRecord> m_record;
};

}  // namespace blueZ
}  // namespace bluetoothImplementations
}  // namespace alexaClientSDK

#endif  // ALEXA_CLIENT_SDK_BLUETOOTHIMPLEMENTATIONS_BLUEZ_INCLUDE_BLUEZ_BLUEZHID_H_App