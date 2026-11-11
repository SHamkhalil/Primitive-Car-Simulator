## Building and Running the Project

The program is currently straightforward to build and run. However, make sure your development environment meets the following prerequisites:

  - GCC 13.3, 
  - Ubuntu 24.04
  - CMake 3.28
  - git 2.43.0

### Building 

Building is fairly simple as well:

#### Debug Build
```bash
cmake --preset debug
```

Build the Debug binaries:

```bash
cmake --build --preset debug
```

#### Release Build

```bash
cmake --preset release
```

Then build the binaries for release version using:

Build the Release binaries:

```bash
cmake --build --preset release
```



```bash
./build/debug/apps/first
```

Testing - After building from the source you can run the tests using:

```bash
ctest --test-dir build/debug --output-on-failure
```
If you would like to run a single test use, for example:

```bash
ctest --test-dir build/debug -R SpeedConversion
```

Debugging: Visual Studio 2022 (Open Folder → breakpoint → F5)