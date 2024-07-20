# Esterv.Crypto.BigInt 

[TOC]

This repo implements a simple library for working with uint256, uint128 types and it is based 
from [here](https://github.com/bitcoin/bitcoin/blob/master/src/arith_uint256.h).

## Configure, build, test, package ...
 
The project uses [CMake presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) as a way to share CMake configurations.
Refer to [cmake](https://cmake.org/cmake/help/latest/manual/cmake.1.html), [ctest](https://cmake.org/cmake/help/latest/manual/ctest.1.html) and [cpack](https://cmake.org/cmake/help/latest/manual/cpack.1.html) documentation for more information on the use of presets.

## Using the targets in your CMake project 

```CMake
include(FetchContent)
FetchContent_Declare(
	EstervBigInt	
	GIT_REPOSITORY https://github.com/EddyTheCo/BigInt.git
	GIT_TAG vMAJOR.MINOR.PATCH 
	FIND_PACKAGE_ARGS MAJOR.MINOR CONFIG  
	)
FetchContent_MakeAvailable(EstervBigInt)
target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> EstervBigInt::bigint)
```

You can read the [API reference](https://eddytheco.github.io/BigInt/) here, or generate it yourself like
```
cmake --workflow --preset default-documentation
```

## Contributing

We appreciate any contribution!

You can open an issue or request a feature.
You can open a PR to the `develop` branch and the CI/CD will take care of the rest.
Make sure to acknowledge your work, and ideas when contributing.

