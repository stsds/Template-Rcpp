# Template-Rcpp Package

### Overview
The `Template-Rcpp package` is a template R package that provides a structured foundation for creating R packages with Rcpp modules.
This template integrates the CMake build system and includes a convenient setup for running both C++ and R code.
Additionally, the package incorporates the catch2 library for simplified unit testing of C++ code.

---

### Features:
- Rcpp Modules: Easily expose C++ classes and functions to R using Rcpp modules.
- CMake Build System: A modern and flexible build system for building and packaging the C++ code, including cmake files for searching and linking to R and Rcpp.
- Integrated Run Option: Run both C++ and R code from a unified interface.
- Catch2 Testing Framework: Streamlined unit testing of C++ code using the Catch2 testing framework.
- Cach2 Library Integration: Included Catch2 library for efficient and concise C++ code.

---

# Getting Started

### Clone the Repository:

```bash
git clone https://github.com/stsds/Template-Rcpp.git
```

### Building and Installing:

```bash
./config.sh -t
./clean_build.sh
```

### Run C++ Tests:

```bash
cd bin/
ctest -v
```
### Building R Library:
```bash
R CMD build .
```

### Installing R Library:
```bash
R CMD INSTALL .
```

---

### Directory Structure

- src/: Contains C++ source files.
- R/: Contains R code files.
- inst/include/: Header files to be included in the package.
- tests/cpp-tests/: Unit tests using the Catch2 framework.
- tests/R-tests/: Unit tests and examples using the package in R.
- cmake/: Contains all the modules needed for finding and linking to R and Rcpp.
- CMakeLists.txt: CMake configuration file.
- prerequisites/: Contains Catch2 library headers, needed for the unit testing.
- man/: Contains all the documentation needed for the exposed functions and classes in R.

---

### Bash Scripts Description

- `config.sh` : Script needed for configuring the package as C++ library.
- `clean_build.sh` : Script needed for automatically building the library.
- `configure` : Script needed for configuring the package as R package. This file is automatically called when installing the package in R.
- `cleanup` : Script needed for deleting all the unnecessary files and directories during the R package build. This file is automatically called when running `R CMD build` command
---


### Why Would you use this package skeleton over native Rcpp ?

- The main difference between this skeleton and the native Rcpp skeleton, is that, this package utilizes CMake build system instead of using the native R building system, offering
more flexibility and ease in integrating any external library.
- A complete C++ testing environment using Catch2 library. Offering the ability to create a pipeline for efficient testing and development process.
- Fast and easy development process for R package, since you need near to none experience in Rcpp and how to use it.
- The ability to use the package in any C++ project as a separate module.

---

### This package utilizes the following libraries:
Rcpp: Seamless R and C++ integration.
CMake: Cross-platform build system.
Catch2: C++ testing framework.

### Contributing
If you find any issues or have suggestions for improvement, please open an issue or create a pull request on the GitHub repository.

#### License
This project is licensed under the GPL License - see the LICENSE file for more details.

## For a real-life application that utilize this package structure, you can check [MPCR Package](https://github.com/stsds/MPCR).

