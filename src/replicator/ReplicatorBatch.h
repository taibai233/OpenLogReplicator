/* Header for ReplicatorBatch class
   Copyright (C) 2018-2023 Adam Leszczynski (aleszczynski@bersler.com)

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

#include "Replicator.h"

#ifndef REPLICATOR_BATCH_H_
#define REPLICATOR_BATCH_H_

namespace OpenLogReplicator {
    class ReplicatorBatch final : public Replicator {
    protected:
        const char* getModeName() const override;
        bool continueWithOnline() override;
        void positionReader() override;
        void createSchema() override;
        virtual void updateOnlineRedoLogData();

    public:
        ReplicatorBatch(Ctx* newCtx, void (*newArchGetLog)(Replicator* replicator), Builder* newBuilder, Metadata* newMetadata,
                        TransactionBuffer* newTransactionBuffer, const std::string& newAlias, const char* newDatabase);
        ~ReplicatorBatch() override;
    };
}

#endif
