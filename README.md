# DP11-403 Design Patterns in Modern C++ Exercises

Exercise solutions and cmake projects for:

   * DP11-403 Design Patterns in Modern C++

**Contents**
- [DP11-403 Design Patterns in Modern C++ Exercises](#dp11-403-design-patterns-in-modern-c-exercises)
- [Folder structure](#folder-structure)
  - [Templates](#templates)
  - [Solutions](#solutions)
- [Build Toolchain](#build-toolchain)
  - [Build the application](#build-the-application)
  - [Visual Studio shortcuts](#visual-studio-shortcuts)
  - [Command line builds](#command-line-builds)
  - [Building an exercise solution](#building-an-exercise-solution)
- [Disclaimer](#disclaimer)

# Folder structure

## Templates

A number of start project templates are provided as a basis for the exercise with each exercise
indicating which starter template to use.

When working with the Feabhas CMake host based projects these
starter projects can be configured as separate CMake projects using 
the `build-template.sh` script.

To create self contained workspaces for each starter template copy the `exercises` folder
from this project into your Feabhas C++ workspace - this will be the `docker-host` folder if you 
are using the Feabhas build enviroment discussed later under *Build Toolchain*.

Inside your workspace start a Linux command prompt run the following: 

```
$ bash ./build-template.sh
```

This will create one subfolder for each starter template and move the original workspace files
into a subfolder called `project`.

Each subfolder is a self-contained workspace including the exercise solution code ready for use
as described in the **Build Toolchain** section.

## Solutions

Solutions are provided for all exercises. 

# Build Toolchain

The primary build environment for Feabhas projects is Ubuntu Linux using
the Linux GNU Toolchain (for host based courses), or the Arm GNU Toolchain 
(for embedded courses), and the [CMake](https://cmake.org/) build system. 

GitHub projects supporting both toolchains are available to download for
users that can run [Docker](https://docs.docker.com/get-docker/) on 
Windows, macOs or Linux.  

The projects are configured for use with 
[Visual Studio Code](https://code.visualstudio.com/) and the 
[devcontainers](https://code.visualstudio.com/docs/devcontainers/containers)
extension.

The following GitHub projects are available:

   * Hosted courses: https://github.com/feabhas/docker-host
   * Embedded courses https://github.com/feabhas/docker-target

The projects download the `feabhas\ubuntu-projects` image from
[Docker Hub](https://hub.docker.com/r/feabhas/ubuntu-projects) and 
when started will configure the project workspace with the appropriate build 
environment.

Details for using the VS Code based projects are included in the
`README.md` files and are briefly described below.

## Build the application

Using CMake is a two step process: 
   1. generate build configuration files
   2. run the build 

To simplify  this and to allow you to add additional source and 
header files we have created a front end script `build.sh` to automate 
the build.

You should add additional C/C++ source and header files to the `src` 
directory. If you prefer you can place your header files in the `include`
directory.

## Visual Studio shortcuts

From within VS Code you can use the keyboard shortcut `Ctrl-Shift-B` 
to run one of the build tasks:
    * **Build** standard build
    * **Clean** to remove object and executable files
    * **Reset** to regenerate the CMake build files

To run the application without debugging:

   * in VS code press Ctrl-Shft-P and type `test task` 
   * in the popup list select **Tasks: Run Test task**
   * in the list of tasks select **Run Application**

## Command line builds

In the project root do:

```
$ ./build.sh
```

This will generate the file build/debug/Application.elf on an Arm target
project or build/debug/Application on the host. Additional size and hex 
files used by some flash memory software tools are generated for the 
Arm target.

You can add a -v option see the underlying build commands:

```
$ ./build.sh -v
```

The build.sh script supports the --help option for more information.

To delete all object files and recompile the complete project 
use the clean option:

```
$ ./build.sh clean
```

To clean the entire build directory and regenerate a new build 
configuration use the reset option:

```
$ ./build.sh reset
```

To run a hosted application from the command line use the command:

```
$ ./build/debug/Application
```

## Building an exercise solution

To build any of the exercise solutions run the script:
```
$ ./build-one.sh N 
```
where `N` is the exercise number.

The script will initially look in the workspace for a folder 
called `exercises` and copy the colutions from there. Fallback locations for solutions inlude a `solutions` folder in the work space or
and `exercises` or `solutions` folder in the home directory.

If youb are not using a presupplied VM you will need to copy the 
`exercises` folder in this project to your project workspace. This also 
applies if you are using teh Feabhas Docker image. 

**NOTE:** building a solution will copy all files in the `src` directory to 
the `src.bak` directory having removed any files already present in `src.bak`.

The `build-one.sh` script supports the `--help` option for more information.

Do not use the `--all` option as this will build each solution in turn and 
is used as part of our Continuous Integration testing.

# Disclaimer

Feabhas is furnishing these items *"as is"*. Feabhas does not provide any
warranty of them whatsoever, whether express, implied, or statutory,
including, but not limited to, any warranty of merchantability or fitness
for a particular purpose or any warranty that the contents their will
be error-free.

In no respect shall Feabhas incur any liability for any damages, including,
but limited to, direct, indirect, special, or consequential damages arising
out of, resulting from, or any way connected to the use of the item, whether
or not based upon warranty, contract, tort, or otherwise; whether or not
injury was sustained by persons or property or otherwise; and whether or not
loss was sustained from, or arose out of, the results of, the item, or any
services that may be provided by Feabhas.

The items are intended for use as an educational aid.Typically code solutions 
will show best practice of language features that have been introduced during 
the associated training, but do not represent production quality code. 
Comments and structured documentation are not included because the code 
itself is intended to be studied as part of the learning process.
