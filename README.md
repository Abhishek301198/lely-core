![logo](doc/logo.png)

CAN library
===========

Introduction
------------

The Lely CAN library ([liblely-can]) provides generic CAN frame definitions,
conversion functions for different drivers and an interface designed to simplify
CAN frame handling.

Download
--------

liblely-can is hosted on [GitLab]. You can clone the repository with

    $ git clone https://gitlab.com/lely_industries/can.git

or download the latest release
([v1.3.2](https://gitlab.com/lely_industries/can/tags/v1.3.2)).

Binary packages for Ubuntu 16.04 LTS (Xenial Xerus) can be found at
https://launchpad.net/~lely/+archive/ubuntu/ppa.

Build and install
-----------------

liblely-can uses the GNU Build System (`configure`, `make`, `make install`) and
has native support for POSIX platforms (Debian-based Linux distributions in
particular) and Windows (Vista and higher) through [Cygwin] or [MinGW-w64].
[GCC ARM Embedded] and Microsoft Visual Studio (2013 and higher) are also
supported, but project files will have to be created by hand.

The release archive includes the build system, but if you want to build a
checkout of the repository, you need to install the autotools (autoconf,
automake and libtool). The build system can then be generated by running

    $ autoreconf -i

in the root directory of the repository.

If you want to generate HTML documentation from the source code, you need to
install [doxygen] and [Graphviz].

liblely-can requires the Lely C11 and POSIX compatibility library
([liblely-libc]) and the Lely utilities library ([liblely-util]) to be
installed.

### Debian packages

For Debian-based Linux distributions, the preferred installation method is to
generate and install Debian packages. Install the Debian package build system
with

    $ sudo apt-get install cdbs devscripts

The packages can now be built by running

    $ debuild -uc -us -b

from the root directory of the project. Once the packages are generated, you can
clean up the project directory with

    $ debuild clean

debuild creates the packages in the parent directory of the project. Install
them with

    $ cd ..
    $ sudo dpkg -i liblely-can*.deb

### configure, make, make install

It is also possible to build and install the library by hand. First, configure
the build system by running

    $ ./configure

from the root directory of the project.

The `configure` script supports many options. The full list can be shown with

    $ ./configure --help

Once the build system is configured, the library can be built with

    $ make

Run

    $ make html

to generate the HTML documentation from the source code. The binaries, headers
and documentation can be installed by running

    # make install

as root.

### Options

liblely-can uses the multithreading functions of liblely-libc. If multithreading
support was disabled or unavailable when liblely-libc was built, it should also
be disabled when building liblely-can. This can be achieved by providing the
`--disable-threads` option to `configure` or by defining the `LELY_NO_THREADS`
preprocessor macro.

liblely-can is written in C, but a C++ interface is provided. This interface
requires support from liblely-util. If the C++ interface is not required, or
liblely-util was built without C++ support, it can be disabled with the
`--disable-cxx` option to `configure` or by defining the `LELY_NO_CXX`
preprocessor macro.

The CAN library provides a generic CAN message type suitable for both CAN and
CAN FD frames. If CAN FD support is not required, the message size can be
reduced by specifying the `--disable-canfd` option to `configure` or by defining
the `LELY_NO_CANFD` preprocessor macro.

Usage
-----

See [doc/overview.md](@ref md_doc_overview) for an overview of the provided
functionality. Doxygen documentation for the latest development version can be
found at http://lely_industries.gitlab.io/can/doxygen/.

Licensing
---------

Copyright 2017 [Lely Industries N.V.]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

[Cygwin]: https://www.cygwin.com/
[doxygen]: http://www.doxygen.org/
[GCC ARM Embedded]: https://launchpad.net/gcc-arm-embedded
[GitLab]: https://gitlab.com/lely_industries/can
[Graphviz]: http://www.graphviz.org/
[Lely Industries N.V.]: http://www.lely.com
[liblely-can]: https://gitlab.com/lely_industries/can
[liblely-libc]: https://gitlab.com/lely_industries/libc
[liblely-util]: https://gitlab.com/lely_industries/util
[MinGW-w64]: http://mingw-w64.org/

