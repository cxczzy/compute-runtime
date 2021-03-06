/*
 * Copyright (C) 2017-2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "runtime/command_queue/command_queue_hw.h"

////////////////////////////////////////////////////////////////////////////////
// MockCommandQueue - Core implementation
////////////////////////////////////////////////////////////////////////////////

namespace OCLRT {
class MockCommandQueue : public CommandQueue {
  public:
    using CommandQueue::device;
    using CommandQueue::obtainNewTimestampPacketNodes;
    using CommandQueue::timestampPacketContainer;

    void setProfilingEnabled() {
        commandQueueProperties |= CL_QUEUE_PROFILING_ENABLE;
    }
    void setOoqEnabled() {
        commandQueueProperties |= CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE;
    }
    MockCommandQueue() : CommandQueue(nullptr, nullptr, 0) {}
    MockCommandQueue(Context *context, Device *device, const cl_queue_properties *props)
        : CommandQueue(context, device, props) {
    }

    LinearStream &getCS(size_t minRequiredSize) override {
        requestedCmdStreamSize = minRequiredSize;
        return CommandQueue::getCS(minRequiredSize);
    }

    void releaseIndirectHeap(IndirectHeap::Type heap) override {
        releaseIndirectHeapCalled = true;
        CommandQueue::releaseIndirectHeap(heap);
    }

    cl_int enqueueWriteBuffer(Buffer *buffer, cl_bool blockingWrite, size_t offset, size_t size, const void *ptr,
                              cl_uint numEventsInWaitList, const cl_event *eventWaitList, cl_event *event) override {
        writeBufferCounter++;
        writeBufferBlocking = (CL_TRUE == blockingWrite);
        writeBufferOffset = offset;
        writeBufferSize = size;
        writeBufferPtr = const_cast<void *>(ptr);
        return writeBufferRetValue;
    }

    bool releaseIndirectHeapCalled = false;

    cl_int writeBufferRetValue = CL_SUCCESS;
    uint32_t writeBufferCounter = 0;
    bool writeBufferBlocking = false;
    size_t writeBufferOffset = 0;
    size_t writeBufferSize = 0;
    void *writeBufferPtr = nullptr;
    size_t requestedCmdStreamSize = 0;
};

template <typename GfxFamily>
class MockCommandQueueHw : public CommandQueueHw<GfxFamily> {
    typedef CommandQueueHw<GfxFamily> BaseClass;

  public:
    using BaseClass::commandStream;
    using BaseClass::obtainNewTimestampPacketNodes;
    using BaseClass::timestampPacketContainer;

    MockCommandQueueHw(Context *context,
                       Device *device,
                       cl_queue_properties *properties) : BaseClass(context, device, properties) {
    }

    cl_int enqueueWriteImage(Image *dstImage,
                             cl_bool blockingWrite,
                             const size_t *origin,
                             const size_t *region,
                             size_t inputRowPitch,
                             size_t inputSlicePitch,
                             const void *ptr,
                             cl_uint numEventsInWaitList,
                             const cl_event *eventWaitList,
                             cl_event *event) override {
        EnqueueWriteImageCounter++;
        return BaseClass::enqueueWriteImage(dstImage,
                                            blockingWrite,
                                            origin,
                                            region,
                                            inputRowPitch,
                                            inputSlicePitch,
                                            ptr,
                                            numEventsInWaitList,
                                            eventWaitList,
                                            event);
    }

    cl_int enqueueWriteBuffer(Buffer *buffer, cl_bool blockingWrite, size_t offset, size_t size,
                              const void *ptr, cl_uint numEventsInWaitList, const cl_event *eventWaitList, cl_event *event) override {
        EnqueueWriteBufferCounter++;
        blockingWriteBuffer = blockingWrite == CL_TRUE;
        return BaseClass::enqueueWriteBuffer(buffer, blockingWrite, offset, size, ptr, numEventsInWaitList, eventWaitList, event);
    }

    void enqueueHandlerHook(const unsigned int commandType, const MultiDispatchInfo &dispatchInfo) override {
        lastCommandType = commandType;
        for (auto &di : dispatchInfo) {
            lastEnqueuedKernels.push_back(di.getKernel());
        }
    }

    void notifyEnqueueReadBuffer(Buffer *buffer, bool blockingRead) override {
        notifyEnqueueReadBufferCalled = true;
    }
    void notifyEnqueueReadImage(Image *image, bool blockingRead) override {
        notifyEnqueueReadImageCalled = true;
    }

    unsigned int lastCommandType;
    std::vector<Kernel *> lastEnqueuedKernels;
    size_t EnqueueWriteImageCounter = 0;
    size_t EnqueueWriteBufferCounter = 0;
    bool blockingWriteBuffer = false;
    bool notifyEnqueueReadBufferCalled = false;
    bool notifyEnqueueReadImageCalled = false;
    uint32_t completionStampTaskCount = 0;
    uint32_t deltaTaskCount = 0;

    LinearStream *peekCommandStream() {
        return this->commandStream;
    }

    void updateFromCompletionStamp(const CompletionStamp &completionStamp) override {
        BaseClass::updateFromCompletionStamp(completionStamp);
        const uint32_t &referenceToCompletionStampTaskCount = completionStamp.taskCount;
        uint32_t &nonConstReferenceToCompletionStampTaskCount = const_cast<uint32_t &>(referenceToCompletionStampTaskCount);
        nonConstReferenceToCompletionStampTaskCount += deltaTaskCount;
        completionStampTaskCount = referenceToCompletionStampTaskCount;
    }
};
} // namespace OCLRT
