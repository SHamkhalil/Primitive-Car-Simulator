Currently the program is fairly simple, ergo running it shouldn't be of difficulty

You do however need to pass a couple of prerequisites, such as:

  - GCC 13.3, 
  - Ubuntu 24.04
  - CMake 3.28
  - git 2.43.0
  
Building is fairly simple as well:

```bash
cmake --preset debug
```

Then build the binaries for debuging using:

```bash
cmake --build --preset debug
```


Then build the binaries for release version using:

```bash
cmake --build --preset release
```

Running currently is also pretty simple as well:

```bash
./build/debug/apps/first
./build/debug/tests/tests
```

Debugging: Visual Studio 2022 (Open Folder → breakpoint → F5)