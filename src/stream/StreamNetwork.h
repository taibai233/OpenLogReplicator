/* Header for StreamNetwork class
   Copyright (C) 2018-2022 Adam Leszczynski (aleszczynski@bersler.com)

This file is part of OpenLogReplicator.

OpenLogReplicator is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

OpenLogReplicator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenLogReplicator; see the file LICENSE;  If not see
<http://www.gnu.org/licenses/>.  */

#include <netinet/in.h>

#include "Stream.h"

#ifndef STREAMNETWORK_H_
#define STREAMNETWORK_H_

namespace OpenLogReplicator {
    class StreamNetwork : public Stream {
    protected:
        int socketFD;
        int serverFD;
        struct sockaddr_storage address;
        std::string host;
        std::string port;
        uint8_t readBuffer[READ_NETWORK_BUFFER];
        uint64_t readBufferLen;
        struct addrinfo* res;

    public:
        StreamNetwork(Ctx* ctx, const char* uri);
        ~StreamNetwork() override;

        void initialize() override;
        [[nodiscard]] std::string getName() const override;
        void initializeClient() override;
        void initializeServer() override;
        void sendMessage(const void* msg, uint64_t length) override;
        uint64_t receiveMessage(void* msg, uint64_t length) override;
        uint64_t receiveMessageNB(void* msg, uint64_t length) override;
        [[nodiscard]] bool isConnected() override;
    };
}

#endif
