/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <memory>
#include <vector>

#include <openxr/openxr.h>

#include <igl/Device.h>

namespace igl::shell::openxr::impl {
class XrSwapchainProviderImpl;
class XrAppImpl {
 public:
  virtual ~XrAppImpl() = default;
  virtual std::vector<const char*> getXrRequiredExtensions() const = 0;
  virtual void* getInstanceCreateExtension() = 0;
  virtual std::unique_ptr<igl::IDevice> initIGL(XrInstance instance, XrSystemId systemId) = 0;
  virtual XrSession initXrSession(XrInstance instance,
                                  XrSystemId systemId,
                                  igl::IDevice& device) = 0;
  virtual std::unique_ptr<impl::XrSwapchainProviderImpl> createSwapchainProviderImpl() const = 0;
};
} // namespace igl::shell::openxr::impl
