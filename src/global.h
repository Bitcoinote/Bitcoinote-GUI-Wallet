
#include <QObject>
namespace WalletGui {
    class global : public QObject {
        static quint32 totalBlocks;
        public: 
            static quint32 getBlocks();
            static void setBlocks(quint32 _blocks);
    };
    
}