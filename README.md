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

Then build the binaries for Release version using:

```bash
cmake --build --preset release
```

Once the project has been built, you can run the Debug executable using:

```bash
./build/debug/apps/first
```

### Running Tests
After building the project, run all available tests using:

```bash
ctest --test-dir build/debug --output-on-failure
```
If you would like to run a specific test, use:

```bash
ctest --test-dir build/debug -R SpeedConversion
```

Debugging: Visual Studio 2022 (Open Folder → breakpoint → F5)