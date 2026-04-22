# SharedCLib
Shared library of functions and data types for C

## Building

### Using Visual Studio
Open `SharedCLib.sln` in Visual Studio and build the project.

### Using CMake
Ensure CMake is installed.

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Using Make (requires MinGW/MSYS2)
Ensure GCC and make are installed (via MSYS2 or MinGW).

Add to PATH: `C:\msys64\mingw64\bin` and `C:\msys64\usr\bin`

```bash
mingw32-make.exe
```

Run the executable: `./sharedclib.exe`
