/* Structure used to hold in memory basic information for OpCode
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

#include "RedoLogRecord.h"
#include "typeXid.h"

namespace OpenLogReplicator {
    std::ostream& operator<<(std::ostream& os, const RedoLogRecord& redo) {
        std::stringstream ss;
        ss << "O scn: " << PRINTSCN64(redo.scnRecord) <<
                " scn: " << std::dec << redo.scn <<
                " subScn: " << std::dec << redo.subScn <<
                " xid: " << redo.xid <<
                " op: " << std::setfill('0') << std::setw(4) << std::hex << redo.opCode <<
                " cls: " << std::dec << redo.cls <<
                " rbl: " << std::dec << redo.rbl <<
                " seq: " << std::dec << (uint64_t)redo.seq <<
                " typ: " << std::dec << (uint64_t)redo.typ <<
                " conId: " << std::dec << redo.conId <<
                " flgRecord: " << std::dec << redo.flgRecord <<
//                " vectorNo: " << std::dec << vectorNo <<
                " robj: " << std::dec << redo.recordObj <<
                " rdataObj: " << std::dec << redo.recordDataObj <<
//                " scn: " << PRINTSCN64(scn) <<
                " nrow: " << std::dec << (uint64_t)redo.nrow <<
                " afn: " << std::dec << redo.afn <<
                " length: " << std::dec << redo.length <<
                " dba: 0x" << std::hex << redo.dba <<
                " bdba: 0x" << std::hex << redo.bdba <<
                " obj: " << std::dec << redo.obj <<
                " dataObj: " << std::dec << redo.dataObj <<
                " tsn: " << std::dec << redo.tsn <<
                " undo: " << std::dec << redo.undo <<
                " usn: " << std::dec << redo.usn <<
                " uba: " << PRINTUBA(redo.uba) <<
                " slt: " << std::dec << (uint64_t)redo.slt <<
                " rci: " << std::dec << (uint64_t)redo.rci <<
                " flg: " << std::dec << (uint64_t)redo.flg <<
                " opc: 0x" << std::hex << redo.opc <<
                " op: " << std::dec << (uint64_t)redo.op <<
                " cc: " << std::dec << (uint64_t)redo.cc <<
//                " itli: " << std::dec << (uint64_t)itli <<
                " slot: " << std::dec << redo.slot <<
                " flags: 0x" << std::hex << (uint64_t)redo.flags <<
                " fb: 0x" << std::hex << (uint64_t)redo.fb <<
                " nrid: 0x" << std::hex << redo.nridBdba << "." << std::dec << redo.nridSlot;
        os << ss.str();
        return os;
    }
}
