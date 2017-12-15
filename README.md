Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers, The Forknote developers  
Copyright (c) 2017, The Bitcoinote developers

# Bitcoinote GUI Wallet

This is a GUI wallet for usage with the Bitcoinote (BTCN) cryptocurrency.

## Build

Currently, build is supported out of the box only on Linux. Tested with Ubuntu 16.04.

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.58.

You may download them from:  
[http://gcc.gnu.org/](http://gcc.gnu.org/)  
[http://www.cmake.org/](http://www.cmake.org/)  
[http://www.boost.org/](http://www.boost.org/)  
Alternatively, it may be possible to install them using a package manager.

You first need to clone the Bitcoinote Core repository. Then, create a symlink named `cryptonote` to the repository you just cloned, for example:

```
ln -s ../Bitcoinote-Core cryptonote
```

To build, run the following commands in the project's root directory:

```
mkdir build
cd build
cmake ..
make
```

## Usage Notes

To run the GUI wallet, the Bitcoinote Core daemon is not required to run. If a daemon already runs, it will be used - otherwise the wallet will use its own "internal daemon" instead.

Note that mining without a mining pool is **not** possible with this wallet. For direct mining, use the `miner` tool from Bitcoinote Core instead.

The wallet includes a block explorer. It can be used only with the "internal daemon" mode, i.e. if the Bitcoinote Core daemon is not running in parallel.

**Important:** The GUI wallet uses a new format for wallet files. Wallet files created by the GUI wallet cannot be read by the Bitcoinote Core command-line wallet. Furthermore, when you open a wallet file created by the Bitcoinote Core command-line wallet in the GUI wallet, it will **automatically convert it** to the new format, and afterwards it will **no longer be readable** by the Bitcoinote Core command-line wallet! When a wallet file is converted, a backup file (`<name>.wallet.backup`) with the old format is created next to the wallet file. Don't throw away the backup file if you intend to use the command-line wallet in the future.
