/*
 * Copyright (C) 2017-2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "runtime/command_queue/gpgpu_walker.h"
#include "runtime/command_queue/enqueue_barrier.h"
#include "runtime/command_queue/enqueue_copy_buffer.h"
#include "runtime/command_queue/enqueue_copy_buffer_rect.h"
#include "runtime/command_queue/enqueue_copy_buffer_to_image.h"
#include "runtime/command_queue/enqueue_copy_image_to_buffer.h"
#include "runtime/command_queue/enqueue_copy_image.h"
#include "runtime/command_queue/enqueue_fill_buffer.h"
#include "runtime/command_queue/enqueue_fill_image.h"
#include "runtime/command_queue/enqueue_kernel.h"
#include "runtime/command_queue/enqueue_svm.h"
#include "runtime/command_queue/enqueue_marker.h"
#include "runtime/command_queue/enqueue_migrate_mem_objects.h"
#include "runtime/command_queue/enqueue_read_buffer.h"
#include "runtime/command_queue/enqueue_read_buffer_rect.h"
#include "runtime/command_queue/enqueue_read_image.h"
#include "runtime/command_queue/enqueue_write_buffer.h"
#include "runtime/command_queue/enqueue_write_buffer_rect.h"
#include "runtime/command_queue/enqueue_write_image.h"
#include "runtime/command_queue/finish.h"
#include "runtime/command_queue/flush.h"

namespace OCLRT {
template <typename Family>
void CommandQueueHw<Family>::notifyEnqueueReadBuffer(Buffer *buffer, bool blockingRead) {
}
template <typename Family>
void CommandQueueHw<Family>::notifyEnqueueReadImage(Image *image, bool blockingRead) {
}
} // namespace OCLRT
