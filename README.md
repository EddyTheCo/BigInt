# Esterv.Crypto.BigInt 


[TOC]

This repo implements a simple library for working with uint256, uint128 types and it is based 
from [here](https://github.com/bitcoin/bitcoin/blob/master/src/arith_uint256.h).

## Installing the library 

### From source code
```
git clone https://github.com/EddyTheCo/BigInt.git 

mkdir build
cd build
qt-cmake -G Ninja -DCMAKE_INSTALL_PREFIX=installDir -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF -DBUILD_DOCS=OFF ../BigInt

cmake --build . 

cmake --install . 
```
where `installDir` is the installation path.
One can choose to build or not the tests and the documentation with the `BUILD_TESTING` and `BUILD_DOCS` variables.

### From GitHub releases
Download the releases from this repo. 

## Adding the libraries to your CMake project 

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
cmake -DBUILD_DOCS=ON ../
cmake --build . --target doxygen_docs
```

## Contributing

We appreciate any contribution!

You can open an issue or request a feature.
You can open a PR to the `develop` branch and the CI/CD will take care of the rest.
Make sure to acknowledge your work, and ideas when contributing.

