/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/brave_browser_main_parts.h"
#include "brave/browser/browsing_data/brave_clear_browsing_data.h"

BraveBrowserMainParts::BraveBrowserMainParts(content::BrowserMainParts* parts) {
  DCHECK(parts);
  parts_.reset(parts);
}

BraveBrowserMainParts::~BraveBrowserMainParts() {}

// BrowserMainParts overrides: all purely pass-through, except for PreShutdown.
int BraveBrowserMainParts::PreEarlyInitialization() {
  return parts_->PreEarlyInitialization();
}

void BraveBrowserMainParts::PostEarlyInitialization() {
  parts_->PostEarlyInitialization();
}

void BraveBrowserMainParts::PreMainMessageLoopStart() {
  parts_->PreMainMessageLoopStart();
}

void BraveBrowserMainParts::PostMainMessageLoopStart() {
  parts_->PostMainMessageLoopStart();
}

void BraveBrowserMainParts::ToolkitInitialized() {
  parts_->ToolkitInitialized();
}

int BraveBrowserMainParts::PreCreateThreads() {
  return parts_->PreCreateThreads();
}

void BraveBrowserMainParts::PostCreateThreads() {
  parts_->PostCreateThreads();
}

void BraveBrowserMainParts::ServiceManagerConnectionStarted(
    content::ServiceManagerConnection* connection) {
  parts_->ServiceManagerConnectionStarted(connection);
}

void BraveBrowserMainParts::PreMainMessageLoopRun() {
  parts_->PreMainMessageLoopRun();
}

bool BraveBrowserMainParts::MainMessageLoopRun(int* result_code) {
  return parts_->MainMessageLoopRun(result_code);
}

void BraveBrowserMainParts::PreDefaultMainMessageLoopRun(
    base::OnceClosure quit_closure) {
  parts_->PreDefaultMainMessageLoopRun(std::move(quit_closure));
}

void BraveBrowserMainParts::PostMainMessageLoopRun() {
  parts_->PostMainMessageLoopRun();
}

void BraveBrowserMainParts::PreShutdown() {
  content::BraveClearBrowsingData::ClearOnExit();
  parts_->PreShutdown();
}

void BraveBrowserMainParts::PostDestroyThreads() {
  parts_->PostDestroyThreads();
}
