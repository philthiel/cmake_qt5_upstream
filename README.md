# cmake_qt5_upstream

### Test project to demonstrate transitive link problems for CMake project using Qt5

---

- Project 1: mylib 

  Tiny library using QtString from Qt5::Core that generates CMake package configuration files to be used with find_package() by upstream projects


- Project 2: myapp

  Tiny app that uses mylib as an IMPORTED target
  
---

- Examplary build in build.sh taking two arguments:

  1. Path to Qt5 installation
  
  2. Installation prefix for mylib

---

CMake configuration run of myapp complains like this:
  
  
`CMake Error at CMakeLists.txt:11 (add_executable):
   Target "MyAPP" links to target "Qt5::Core" but the target was not found.
   Perhaps a find_package() call is missing for an IMPORTED target, or an
   ALIAS target is missing?
`

The reason is that in MyLIBTargets.cmake the INTERFACE_LINK_LIBRARY entry for Qt5 Core is the Qt5::Core symbol
which cannot be resolved by default. Can somebody tell my what is the correct way to deal with this situation?
