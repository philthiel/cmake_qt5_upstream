cmake_policy(SET CMP0048 NEW)
project("MyLIB" VERSION 0.1)


cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)


find_package(Qt5Core 5.5 REQUIRED)



# Build and install configuration for MyLIB

set(MYLIB_SOURCES ${PROJECT_SOURCE_DIR}/mylib.C ${PROJECT_SOURCE_DIR}/mylib.h)
add_library(MyLIB SHARED ${MYLIB_SOURCES})
target_link_libraries(MyLIB PUBLIC Qt5::Core)


install(TARGETS MyLIB EXPORT MyLIBTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(FILES ${PROJECT_SOURCE_DIR}/mylib.h
	DESTINATION include
	COMPONENT   devel
)



# Generate package configuration files

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/cmake/MyLIBConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(EXPORT MyLIBTargets
  FILE "${PROJECT_BINARY_DIR}/cmake/MyLIBTargets.cmake"
    NAMESPACE Upstream::
)

configure_file(MyLIBConfig.cmake
  "${PROJECT_BINARY_DIR}/cmake/MyLIBConfig.cmake"
  COPYONLY
)



# Install package configuration files

set(ConfigPackageLocation lib/cmake/MyLIB)
install(EXPORT MyLIBTargets
	FILE   MyLIBTargets.cmake
	DESTINATION ${ConfigPackageLocation}
)

install(FILES ${PROJECT_BINARY_DIR}/cmake/MyLIBConfig.cmake
	      ${PROJECT_BINARY_DIR}/cmake/MyLIBConfigVersion.cmake
	DESTINATION ${ConfigPackageLocation}
	COMPONENT devel
)

