Currently the program is fairly simple, ergo running it shouldn't be of difficulty

You do however need to pass a couple of prerequisites, such as:

  - GCC 13.3, 
  - Ubuntu 24.04
  - CMake 3.28
  - git 2.43.0
  
Building is fairly simple as well:

```bash
cmake -S . -B build
```

Then build the binaries using:

```bash
cmake --build build
```

Running currently is also pretty simple as well:

```bash
./build/first
```

Debugging: Visual Studio 2022 (Open Folder → breakpoint → F5)