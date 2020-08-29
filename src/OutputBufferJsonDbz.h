/* Header for OutputBufferJsonDbz class
   Copyright (C) 2018-2020 Adam Leszczynski (aleszczynski@bersler.com)

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

#include "OutputBufferJson.h"

#ifndef OUTPUTBUFFERJSONDBZ_H_
#define OUTPUTBUFFERJSONDBZ_H_

using namespace std;

namespace OpenLogReplicator {

    class OutputBufferJsonDbz : public OutputBufferJson {
    protected:
        void appendDbzCols(OracleObject *object);
        void appendDbzHead(OracleObject *object);
        void appendDbzTail(OracleObject *object, uint64_t time, typescn scn, char op, typexid xid);

    public:
        OutputBufferJsonDbz(uint64_t timestampFormat, uint64_t charFormat, uint64_t scnFormat, uint64_t unknownFormat, uint64_t showColumns);
        virtual ~OutputBufferJsonDbz();

        virtual void appendInsert(OracleObject *object, typedba bdba, typeslot slot, typexid xid);
        virtual void appendUpdate(OracleObject *object, typedba bdba, typeslot slot, typexid xid);
        virtual void appendDelete(OracleObject *object, typedba bdba, typeslot slot, typexid xid);
        virtual void appendDDL(OracleObject *object, uint16_t type, uint16_t seq, const char *operation, const uint8_t *sql, uint64_t sqlLength);
    };
}

#endif
