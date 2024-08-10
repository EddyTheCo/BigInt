cmake_minimum_required(VERSION 3.11)
include(${CMAKE_CURRENT_BINARY_DIR}/local_conf.cmake OPTIONAL)

include(FetchContent)
FetchContent_Declare(
  ccommon
  GIT_REPOSITORY https://github.com/EddyTheCo/Common.git
  GIT_TAG v0.4.1)
FetchContent_MakeAvailable(ccommon)
version_from_git(LOG OFF TIMESTAMP "%Y%m%d%H%M%S")

project(
  EstervBigInt
  VERSION ${VERSION}
  DESCRIPTION "uint256 uint128 library "
  LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
include(GNUInstallDirs)

find_package(Qt6 COMPONENTS Core)
if(Qt6_FOUND)
  qt_standard_project_setup()

  add_library(bigint src/bigint.cpp include/esterv/crypto/bigint.hpp include/esterv/crypto/arith_uint256.h
                      src/arith_uint256.cpp)
	      add_library(Esterv::bigint ALIAS bigint)
  set_target_properties(bigint PROPERTIES VERSION ${VERSION} SOVERSION
                                                              ${VERSION_MAJOR})

  target_link_libraries(bigint PUBLIC Qt6::Core)

  target_include_directories(
    bigint PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                   "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/>")

  install(
    TARGETS bigint
    EXPORT ${PROJECT_NAME}-config
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    COMPONENT ${PROJECT_NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT ${PROJECT_NAME})
  install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT ${PROJECT_NAME}-dev)

  build_exports()
  if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    build_cpack()
    if(BUILD_TESTING)
      include(CTest)
      add_subdirectory(tests)
    endif(BUILD_TESTING)
  endif(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
endif(Qt6_FOUND)
if(BUILD_DOCS)
  build_docs()
endif(BUILD_DOCS)
