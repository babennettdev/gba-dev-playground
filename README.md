# gba-dev-playground
A development playground for Game Boy Advance development using TONC as a guide.

## Table of Contents
- [gba-dev-playground](#gba-dev-playground)
- [Table of Contents](#table-of-contents)
- [Dependencies](#dependencies)
- [Getting Started](#getting-started)
    - [Setting Up the Environment](setting-up-the-environment)
    - [Running the Examples](#running-the-examples)

## Dependencies
- [DevKitPro](https://devkitpro.org/wiki/Getting_Started)
- [tonclib](https://www.coranac.com/projects/#tonc)

## Getting Started
The following instructions will help the user set up an environment to develop, compile, and clean Gameboy Advance games for a Windows PC. 

### Setting Up the Environment
1. Go to the DevKitPro [Getting Started](https://devkitpro.org/wiki/Getting_Started) page.
1. Install the latest graphical installer.
1. Follow the prompts, making sure to select the `GBA Development` checkbox, to install DevKitPro and necessary tools.
1. Download the current version of the [TONC code](https://www.coranac.com/projects/#tonc).
1. Extract it, and take the `tonclib` folder and copy it into a `/libs` folder at the root of this project. 

> NOTE: I know the library is packaged with the `DevKitPro`. I personally have not tested it, nor do I know if it's the most up-to-date version of the library. Try at your own risk, ensuring you rename the folder as necessary to match the `LIBDIRS` in the Makefiles.

6. Add `C:\devkitPro\tools\bin` to your `PATH` to grant access to some of DevKitPro's tools (like `gbafix` and `grit`).
6. Close your terminal or editor to let `PATH` changes take effect.
6. At this point, your environment should be ready.

### Running the Examples
1. Open any folder within `/src`.
1. Execute `make` in the terminal to compile your `.gba` file.
1. Execute `make clean` to remove the executables and `/build` folder.