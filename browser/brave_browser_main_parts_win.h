/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_WIN_H_
#define BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_WIN_H_

#include "chrome/browser/chrome_browser_main_win.h"

class BraveBrowserMainPartsWin : public ChromeBrowserMainPartsWin {
 public:
  using ChromeBrowserMainPartsWin::ChromeBrowserMainPartsWin;
  ~BraveBrowserMainPartsWin() override = default;

 private:
  // ChromeBrowserMainParts overrides:
  void PreShutdown() override;
};

#endif  // BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_WIN_H_
