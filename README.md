Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers, The Forknote developers  
Copyright (c) 2017-2018, The BitcoiNote developers

# BitcoiNote GUI Wallet

This is a GUI wallet for usage with the BitcoiNote (BTCN) cryptocurrency.

## Build

Currently, build is supported out of the box only on Linux (tested with Ubuntu 16.04) and Windows (64-bit only). Mac OS should theoretically work but is untested.


You first need to clone the BitcoiNote Core repository. Then, create a symlink named `cryptonote` to the repository you just cloned.

### Linux

Tested only with Ubuntu 16.04.

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, Boost 1.58 and Qt5 (<5.8).

You may download them from:  
[http://gcc.gnu.org/](http://gcc.gnu.org/)  
[http://www.cmake.org/](http://www.cmake.org/)  
[http://www.boost.org/](http://www.boost.org/)  
[https://www.qt.io/](https://www.qt.io/)  
Alternatively, it may be possible to install them using a package manager.

To create the symlink to the core directory, use:

```
ln -s ../Bitcoinote-Core cryptonote
```

To build, run the following commands in the project's root directory:

```
mkdir build
cd build
cmake -DPORTABLE=1 ..
make
```

The resulting executables can be found in `build` directory which will be created. (For Windows, look in subfolder `Release` or `Debug` respectively.)

### Windows 64bit

Dependencies:
```
Qt5 version < 5.8 (Tested with 5.6)
libboost 1.58 or greater (Tested with 1.65.1)
cmake 2.8.6 or greater (Tested with 3.10.2)
Microsoft Visual Studio 2013 (Tested with VS2015)
Visual C++ Build Tools v120 (Tested with v140)
```

To create the symlink to the core directory, use:

```
mklink /D cryptonote ..\Bitcoinote-Core
```

To build, run the following commands in the project's root directory, but make sure to substitute the Visual Studio version for the one that you use, and that the `CMAKE_PREFIX_PATH` points to your Qt files, and to replace the VCTargetsPath with one that works for you:

```
mkdir build
cd build
set PATH="c:\Program Files (x86)\Windows Kits\10\bin\10.0.15063.0\x64";%PATH%
set VCTargetsPath=C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\v140
cmake -G "Visual Studio 14 Win64" -DCMAKE_PREFIX_PATH="C:\Qt\5.6\msvc2015_64" -DPORTABLE=1 -DCMAKE_BUILD_TYPE=Release ..
msbuild Bitcoinote.sln /m /p:Configuration=Release
```

In your build folder there should now be a new folder named `Release`, with the binaries.
You still need to copy some library files into that folder (replace `<Qt>` with the path to your Qt files):

```
<Qt>\bin\Qt5Core.dll
<Qt>\bin\Qt5Gui.dll
<Qt>\bin\Qt5Network.dll
<Qt>\bin\Qt5Widgets.dll
C:\Windows\System32\msvcp140.dll
C:\Windows\System32\msvcrt.dll
C:\WINDOWS\system32\ucrtbase.dll
C:\WINDOWS\system32\vcruntime140.dll
```

To compile the debug version, omit the `/p:Configuration=Release` parameter. Then you need to copy the debug dlls instead of the normal ones. These have the same name, only with a `d` at the end (e.g. `Qt5Cored.dll`), and are in the same location, except for `ucrtbased.dll` which you can find in `C:\Program Files (x86)\Windows Kits\10\bin\x64\ucrt\ucrtbased.dll`.

### macOS

Tested only with macOS High Sierra 10.13.6.

Dependencies: `clang 9.1.0` or later, `CMake 3.5.2` or later, `Boost 1.67` or later and `Qt5` (tested with `Qt 5.10.1`).

* Use [Homebrew](https://brew.sh/) to install `cmake` and `boost`.
* Use [qt.io](https://www.qt.io/) to install QtCreator.

To create the symlink to the core directory, use:

```
ln -s ../Bitcoinote-Core cryptonote
```

To build, open the `CMakeLists.txt` in QtCreator. Also you can turn on `PORTABLE` flag in the project settings tab.

The resulting package `Bitcoinote.app` can be found in `build` directory which will be created.
In order to run it on other machines you should run the following command (exchange the path with the path where you installed Qt):

`$ ~/Qt/5.10.1/clang_64/bin/macdeployqt Bitcoinote.app`

This command will find all required dependencies and copy them into the `Bitcoinote.app` directory.

To build `.dmg` file we recommend to use [node-appdmg](https://github.com/LinusU/node-appdmg) project.
Just place the `BitcoinoteDmg.json`, `Bitcoinote.icns` and `Bitcoinote.app` in one directory and run the following command:

`$ appdmg BitcoinoteDmg.json Bitcoinote.dmg`

## Usage Notes

To run the GUI wallet, the BitcoiNote Core daemon is not required to run. If a daemon already runs, it will be used - otherwise the wallet will use its own "internal daemon" instead.

Note that mining without a mining pool is **not** possible with this wallet. For direct mining, use the `miner` tool from BitcoiNote Core instead.

**Important:** The GUI wallet uses a new format for wallet files. Wallet files created by the GUI wallet cannot be read by the BitcoiNote Core command-line wallet. Furthermore, when you open a wallet file created by the BitcoiNote Core command-line wallet in the GUI wallet, it will **automatically convert it** to the new format, and afterwards it will **no longer be readable** by the BitcoiNote Core command-line wallet! When a wallet file is converted, a backup file (`<name>.wallet.backup`) with the old format is created next to the wallet file. Don't throw away the backup file if you intend to use the command-line wallet in the future.
