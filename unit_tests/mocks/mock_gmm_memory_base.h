/*
 * Copyright (C) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "gmm_memory.h"
#include "runtime/os_interface/windows/windows_defs.h"
#include "gmock/gmock.h"

namespace OCLRT {

class MockGmmMemoryBase : public GmmMemory {
  public:
    ~MockGmmMemoryBase() = default;

    MockGmmMemoryBase() = default;

    bool configureDeviceAddressSpace(GMM_ESCAPE_HANDLE hAdapter,
                                     GMM_ESCAPE_HANDLE hDevice,
                                     GMM_ESCAPE_FUNC_TYPE pfnEscape,
                                     GMM_GFX_SIZE_T SvmSize,
                                     BOOLEAN BDWL3Coherency) override {
        return true;
    }
};

class GmockGmmMemoryBase : public GmmMemory {
  public:
    ~GmockGmmMemoryBase() = default;

    GmockGmmMemoryBase() = default;

    MOCK_METHOD5(configureDeviceAddressSpace,
                 bool(GMM_ESCAPE_HANDLE hAdapter,
                      GMM_ESCAPE_HANDLE hDevice,
                      GMM_ESCAPE_FUNC_TYPE pfnEscape,
                      GMM_GFX_SIZE_T SvmSize,
                      BOOLEAN BDWL3Coherency));
};
} // namespace OCLRT
