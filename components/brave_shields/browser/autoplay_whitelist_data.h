/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_AUTOPLAY_WHITELIST_DATA_H_
#define BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_AUTOPLAY_WHITELIST_DATA_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>

namespace brave_shields {

struct ST_AUTOPLAY_WHITELIST_DATA {
public:
    ST_AUTOPLAY_WHITELIST_DATA():
      sHost(nullptr) {
    }

    ST_AUTOPLAY_WHITELIST_DATA(const ST_AUTOPLAY_WHITELIST_DATA &other) {
        if (nullptr == other.sHost) {
            return;
        }

        sHost = new char[strlen(other.sHost) + 1];
        strcpy(sHost, other.sHost);
    }

    ~ST_AUTOPLAY_WHITELIST_DATA() {
        if (nullptr != sHost) {
            delete []sHost;
        }
    }

    uint64_t GetHash() const;

    bool operator==(const ST_AUTOPLAY_WHITELIST_DATA &rhs) const {
        int hostLen = static_cast<int>(strlen(sHost));
        int rhsHostLen = static_cast<int>(strlen(rhs.sHost));

        if (hostLen != rhsHostLen) {
            return false;
        }

        return !memcmp(sHost, rhs.sHost, hostLen);
    }

    // Nothing needs to be updated when a host is added multiple times
    void Update(const ST_AUTOPLAY_WHITELIST_DATA &) {}

    uint32_t Serialize(char* buffer) {
        uint32_t size = 0;

        char sz[32];
        uint32_t dataLenSize = 1 + snprintf(sz, sizeof(sz), "%x", (unsigned int)strlen(sHost));

        if (buffer) {
            memcpy(buffer + size, sz, dataLenSize);
        }
        size += dataLenSize;

        if (buffer) {
            memcpy(buffer + size, sHost, strlen(sHost));
        }
        size += static_cast<uint32_t>(strlen(sHost));

        return size;
    }

    uint32_t Deserialize(char *buffer, uint32_t bufferSize) {
        uint32_t size = 0;

        if (!buffer || 0 == bufferSize) {
            return size;
        }
        unsigned int hostLength = 0;
        sscanf(buffer, "%x", &hostLength);
        if (sHost) {
            delete []sHost;
        }
        size = static_cast<uint32_t>(strlen(buffer) + 1);
        sHost = new char[hostLength + 1];
        if (!sHost) {
            return size;
        }
        memcpy(sHost, buffer + size, hostLength);
        sHost[hostLength] = '\0';
        size += hostLength;

        return size;
    }

    char* sHost;
};

}  // namespace brave_shields

#endif  // BRAVE_COMPONENTS_BRAVE_SHIELDS_BROWSER_AUTOPLAY_WHITELIST_DATA_H_
