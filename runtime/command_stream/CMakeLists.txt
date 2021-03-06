#
# Copyright (C) 2018 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(RUNTIME_SRCS_COMMAND_STREAM
  ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_center.h
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_command_stream_receiver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_command_stream_receiver.h
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_command_stream_receiver_hw.h
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_command_stream_receiver_hw.inl
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_stream_provider.h
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_subcapture.h
  ${CMAKE_CURRENT_SOURCE_DIR}/aub_subcapture.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver.h
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver_hw.h
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver_hw.inl
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver_with_aub_dump.h
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver_with_aub_dump.inl
  ${CMAKE_CURRENT_SOURCE_DIR}/create_command_stream_impl.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/create_command_stream_impl.h
  ${CMAKE_CURRENT_SOURCE_DIR}/csr_definitions.h
  ${CMAKE_CURRENT_SOURCE_DIR}/definitions${BRANCH_DIR_SUFFIX}/command_stream_receiver_simulated_hw.h
  ${CMAKE_CURRENT_SOURCE_DIR}/definitions${BRANCH_DIR_SUFFIX}/engine_node.h
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver_simulated_common_hw.h
  ${CMAKE_CURRENT_SOURCE_DIR}/command_stream_receiver_simulated_common_hw.inl
  ${CMAKE_CURRENT_SOURCE_DIR}/device_command_stream.h
  ${CMAKE_CURRENT_SOURCE_DIR}/experimental_command_buffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/experimental_command_buffer.h
  ${CMAKE_CURRENT_SOURCE_DIR}/experimental_command_buffer.inl
  ${CMAKE_CURRENT_SOURCE_DIR}/linear_stream.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/linear_stream.h
  ${CMAKE_CURRENT_SOURCE_DIR}/submissions_aggregator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/submissions_aggregator.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tbx_command_stream_receiver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tbx_command_stream_receiver.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tbx_command_stream_receiver_hw.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tbx_command_stream_receiver_hw.inl
  ${CMAKE_CURRENT_SOURCE_DIR}/tbx_stream.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/thread_arbitration_policy.h
  ${CMAKE_CURRENT_SOURCE_DIR}/preemption.h
  ${CMAKE_CURRENT_SOURCE_DIR}/preemption.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/preemption.inl
)
target_sources(${NEO_STATIC_LIB_NAME} PRIVATE ${RUNTIME_SRCS_COMMAND_STREAM})
set_property(GLOBAL PROPERTY RUNTIME_SRCS_COMMAND_STREAM ${RUNTIME_SRCS_COMMAND_STREAM})
