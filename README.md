![logo](doc/logo.png)

Lely core libraries
===================

Introduction
------------

### C11 and POSIX compatibility library (liblely-libc)

liblely-libc makes a selection of C11 features available in C99 (and C++98) and implements certain C99 and POSIX features that may be missing on some platforms.
The library is intended to provide platform independence to C99- and
C11-compliant users.

See [doc/libc/overview.md](@ref md_doc_libc_overview) for an overview of the provided functionality.

### Test Anything Protocol (TAP) library (liblely-tap)

liblely-tap provides an implementation of the [Test Anything Protocol].

### Utilities library (liblely-util)

liblely-util provides a variety of functions and data structures used by, and
shared between, other Lely libraries.

See [doc/util/overview.md](@ref md_doc_util_overview) for an overview of the provided functionality.

### CAN library (lely-can)

lely-can provides generic CAN frame definitions, conversion functions for
different drivers and an interface designed to simplify CAN frame handling.

See [doc/can/overview.md](@ref md_doc_can_overview) for an overview of the
provided functionality.

### I/O library (liblely-io)

liblely-io provides uniform, platform-independent I/O interface for CAN devices,
regular files, serial I/O devices and network sockets. Depending on the
platform, some or all of these devices can be polled for events, allowing the
use of the reactor pattern.

See [doc/io/overview.md](@ref md_doc_io_overview) for an overview of the
provided functionality.

Download
--------

lely-core is hosted on [GitLab]. You can clone the repository with

    $ git clone https://gitlab.com/lely_industries/lely-core.git

or download the latest release
([v1.9.0](https://gitlab.com/lely_industries/lely-core/tags/v1.9.0)).

Build and install
-----------------

lely-core uses the GNU Build System (`configure`, `make`, `make install`) and
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
install [doxygen] and [Graphviz]. Building the [Python] bindings requires a
Python 2.x and/or Python 3.x interpreter as well as a [Cython] compiler.

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
    $ sudo dpkg -i liblely-*.deb

The Python bindings can be installed with

    $ sudo dpkg -i python-lely-can*.deb

and/or

    $ sudo dpkg -i python3-lely-can*.deb

depending on which Python version is available.

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

liblely-libc provides an implementation of the C11 multithreading support
library. Multithreading support can be disabled by providing the
`--disable-threads` option to `configure` or by defining the `LELY_NO_THREADS`
preprocessor macro. The implementation is based on pthreads. When building the
library without the autotools build system, define the `LELY_HAVE_PTHREAD`
preprocessor macro if pthreads is available.

On POSIX and Windows platforms, liblely-util provides functions to run a process
in the background as a daemon/service. This functionality can be disabled with
the `--disable-daemon` option to `configure` or by defining the `LELY_NO_DAEMON`
preprocessor macro.

The memory pool allocator allocates its memory in pages. By default these pages
are 64 KiB large and aligned on a 4 KiB boundary. For embedded systems this may
be far too large. The `LELY_PAGE_SIZE` and `LELY_PAGE_ALIGNMENT` preprocessor
macros can be used to set the size and alignment of memory pages (in bytes).

The CAN library provides a generic CAN message type suitable for both CAN and
CAN FD frames. If CAN FD support is not required, the message size can be
reduced by specifying the `--disable-canfd` option to `configure` or by defining
the `LELY_NO_CANFD` preprocessor macro.

Although the Lely core libraries are written in C, C++ interfaces are provided
for a subset of the functionality. These interfaces can be disabled with the
`--disable-cxx` option to `configure` or by defining the `LELY_NO_CXX`
preprocessor macro.

The Python bindings can be disabled by specifying the `--disable-python` option
to `configure`.

Documentation
-------------

Doxygen documentation for the latest development version can be found at
http://lely_industries.gitlab.io/lely-core/doxygen/.

Licensing
---------

Copyright 2013-2018 [Lely Industries N.V.]

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
[Cython]: http://cython.org/
[doxygen]: http://www.doxygen.org/
[GCC ARM Embedded]: https://launchpad.net/gcc-arm-embedded
[GitLab]: https://gitlab.com/lely_industries/libc
[Graphviz]: http://www.graphviz.org/
[Lely Industries N.V.]: http://www.lely.com
[MinGW-w64]: http://mingw-w64.org/
[Python]: https://www.python.org/
[Test Anything Protocol]: https://testanything.org
