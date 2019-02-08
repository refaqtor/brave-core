/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_H_
#define BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_H_

#include "content/public/browser/browser_main_parts.h"

#include <memory>

namespace content {
class ServiceManagerConnection;
}

class BraveBrowserMainParts : public content::BrowserMainParts {
 public:
  BraveBrowserMainParts(content::BrowserMainParts* parts);
  ~BraveBrowserMainParts() override;

  // BrowserMainParts overrides:
  int PreEarlyInitialization() override;
  void PostEarlyInitialization() override;
  void PreMainMessageLoopStart() override;
  void PostMainMessageLoopStart() override;
  void ToolkitInitialized() override;
  int PreCreateThreads() override;
  void PostCreateThreads() override;
  void ServiceManagerConnectionStarted(
      content::ServiceManagerConnection* connection) override;
  void PreMainMessageLoopRun() override;
  bool MainMessageLoopRun(int* result_code) override;
  void PreDefaultMainMessageLoopRun(base::OnceClosure quit_closure) override;
  void PostMainMessageLoopRun() override;
  void PreShutdown() override;
  void PostDestroyThreads() override;

 private:
  std::unique_ptr<content::BrowserMainParts> parts_;
};

#endif  // BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_H_
