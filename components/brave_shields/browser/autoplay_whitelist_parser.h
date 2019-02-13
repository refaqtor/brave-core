/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_AUTOPLAY_WHITELIST_PARSER_H_
#define BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_AUTOPLAY_WHITELIST_PARSER_H_

#include <memory>

#include "brave/components/brave_shields/browser/autoplay_whitelist_data.h"

template<class T>
class HashSet;

namespace brave_shields {

class AutoplayWhitelistParser {
public:
  AutoplayWhitelistParser();
  ~AutoplayWhitelistParser();

  void addHost(const char *inputHost);
  bool matchesHost(const char *inputHost);

  // Serializes the parsed data into a single buffer.
  // The returned buffer should be deleted.
  char* serialize(unsigned int* totalSize);

  // Deserializes the buffer, a size is not needed since a serialized
  // buffer is self described
  bool deserialize(char *buffer);

private:
  bool exists(const char *partialHost);

  std::unique_ptr<HashSet<ST_AUTOPLAY_WHITELIST_DATA> > mHosts;
};

}  // namespace brave_shields

#endif  // BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_AUTOPLAY_WHITELIST_PARSER_H_
