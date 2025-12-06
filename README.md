# Learn Dobby Hooking

Function hooking example using Dobby framework to bypass authentication in a crackme program.

Following this post: [Function hooking using dobby](https://0x41337.medium.com/function-hooking-77f11d311bd5)
## Build

### 1. Build Dobby library

```bash
cd Dobby
mkdir build && cd build
cmake ..
make -j4
cd ../..
```

### 2. Copy Dobby artifacts

```bash
mkdir -p lib include
cp Dobby/build/libdobby.so lib/
cp Dobby/build/libdobby.a lib/
cp Dobby/include/dobby.h include/
```

### 3. Build crackme (with -rdynamic flag)

```bash
g++ -rdynamic -o crackme crackme.cpp
```

### 4. Build hook library

```bash
mkdir -p build && cd build
cmake ..
make
cd ..
```

## Test

Run crackme with the hook library preloaded:

```bash
cd build
LD_PRELOAD=./libhook.so ../crackme
```

Enter any token - it will be accepted because the hook bypasses the verification function.

## How it works

The hook intercepts the `verify()` function and always returns `true`, bypassing the hardcoded token check.
