/* Definition of schema SYS.TAB$
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

#include "SysTab.h"

namespace OpenLogReplicator {
    SysTab::SysTab(typeRowId& rowId, typeObj obj, typeDataObj dataObj, typeCol cluCols, uint64_t flags1, uint64_t flags2,
                   uint64_t property1, uint64_t property2, bool touched) :
            rowId(rowId),
            obj(obj),
            dataObj(dataObj),
            cluCols(cluCols),
            flags(flags1, flags2),
            property(property1, property2),
            touched(touched) {
    }

    bool SysTab::operator!=(const SysTab& other) const {
        return other.rowId != rowId || other.obj != obj || other.dataObj != dataObj || other.cluCols != cluCols || other.flags != flags ||
                other.property != property;
    }

    bool SysTab::isBinary() {
        return property.isSet64(SYSTAB_PROPERTY_BINARY);
    }

    bool SysTab::isClustered() {
        return property.isSet64(SYSTAB_PROPERTY_CLUSTERED);
    }

    bool SysTab::isIot() {
        return property.isSet64(SYSTAB_PROPERTY_IOT1) || flags.isSet64(SYSTAB_PROPERTY_IOT2);
    }

    bool SysTab::isPartitioned() {
        return property.isSet64(SYSTAB_PROPERTY_PARTITIONED);
    }

    bool SysTab::isNested() {
        return property.isSet64(SYSTAB_PROPERTY_NESTED);
    }

    bool SysTab::isRowMovement() {
        return flags.isSet64(SYSTAB_PROPERTY_ROW_MOVEMENT);
    }

    bool SysTab::isDependencies() {
        return flags.isSet64(SYSTAB_PROPERTY_DEPENDENCIES);
    }

    bool SysTab::isInitial() {
        return flags.isSet64(SYSTAB_PROPERTY_INITIAL);
    }
}
