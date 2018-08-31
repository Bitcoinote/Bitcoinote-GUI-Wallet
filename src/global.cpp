#include "global.h"

namespace WalletGui {
    quint32 WalletGui::global::totalBlocks = 0;
    void global::setBlocks(quint32 _blocks) {
        global::totalBlocks = _blocks;
    }

    quint32 global::getBlocks() {
            return global::totalBlocks;        
    }

}