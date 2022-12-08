# DCMTK

This DICOM ToolKit (DCMTK) package consists of source code, documentation and installation instructions for a set of software libraries and applications implementing part of the DICOM/MEDICOM Standard.

DCMTK contains the following sub-packages, each in its own sub-directory:

- **config**   - configuration utilities for DCMTK
- **dcmdata**  - a data encoding/decoding library and utility apps
- **dcmect**   - a library for working with Enhanced CT objects
- **dcmfg**    - a library for working with functional groups
- **dcmimage** - adds support for color images to dcmimgle
- **dcmimgle** - an image processing library and utility apps
- **dcmiod**   - a library for working with information objects and modules
- **dcmjpeg**  - a compression/decompression library and utility apps
- **dcmjpls**  - a compression/decompression library and utility apps
- **dcmnet**   - a networking library and utility apps
- **dcmpmap**  - a library for working with parametric map objects
- **dcmpstat** - a presentation state library and utility apps
- **dcmqrdb**  - an image database server
- **dcmrt**    - a radiation therapy library and utility apps
- **dcmseg**   - a library for working with segmentation objects
- **dcmsign**  - a digital signature library and utility apps
- **dcmsr**    - a structured reporting library and utility apps
- **dcmtls**   - security extensions for the network library
- **dcmtract** - a library for working with tractography results
- **dcmwlm**   - a modality worklist database server
- **oflog**    - a logging library based on log4cplus
- **ofstd**    - a library of general purpose classes

Each sub-directory (except _config_) contains further sub-directories for application source code (_apps_), library source code (_libsrc_), library include files (_include_), configuration data (_etc_), documentation (_docs_), sample and support data (_data_) as well as test programs (_tests_).

To build and install the DCMTK package see the [INSTALL](INSTALL) file.  For copyright information see the [COPYRIGHT](COPYRIGHT) file.  For information about the history of this software see the [HISTORY](HISTORY) file.  For answers to frequently asked questions please consult the [FAQ](https://forum.dcmtk.org/faq/).

In addition to the API documentation, which is also available [online](https://support.dcmtk.org/docs/), there is a [Wiki](https://support.dcmtk.org/wiki/) system where further information (e.g. HOWTOs) can be found.

If you find bugs or other problems with this software, we would appreciate hearing about them.  Please send electronic mail to: bugs/at/dcmtk/dot/org

Please try to describe the problem in detail and if possible give a suggested fix.  For general questions on how to compile, install or use the toolkit we recommend the [public discussion forum](https://forum.dcmtk.org/).




BUILD

The goal of building this repo is to build two applications called `dcm2pnm` and `dcmj2pnm`. 
Following are the steps in any operating system.

On Windows:
1. Pull the repo in to any location where there is lot of disk space available. Let the root directory of DCMTK be `$DCMTK`. Checkout the git branch `3.6.6`.
2. Make a directory called `build` in `$DCMTK`.
3. Use CMake-GUI to generate Visual Studio solution by giving the directory `$DCMTK` as the source and `$DCMTK/build` as the build directory. I have generated the solution for `Visual Studio 15 2017` but one could use with any more recent generator.
4. Go to `$DCMTK/build` and open the `DCMTK.sln` with the appropriate Visual Studio version.
5. Set `Release` mode and build the projects `dcm2pnm` and `dcmj2pnm`.
6. The executables would be generated and the following executables are of interest.
a) `$DCMTK\build\bin\Release\dcm2pnm.exe`
b) `$DCMTK\build\bin\Release\dcmj2pnm.exe`
7. Rename the file `dcm2pnm.exe` to `pdftrondicom1.dll`.
8. Rename the file `dcmj2pnm.exe` to `pdftrondicom2.dll`.
9. Copy the two files to `PDFTronCore/AdvancedImagingModule/Lib/Windows/` folder.

On Linux and Mac:
1. Same as above for Windows
2. Same as above for Windows
3. Execute the three commands on a CLI environment
 i) `cd $DCMTK/build`
 ii) `cmake ..`
 iii) `make`
4. The executables would be generated and the following executables are of interest.
a) `$DCMTK/build/bin/dcm2pnm`
b) `$DCMTK/build/bin/dcmj2pnm`
5. Rename the file `dcm2pnm` to `pdftrondicom1.so` on Linux and 
`pdftrondicom1.dylib` on Mac.
6. Rename the file `dcmj2pnm` to `pdftrondicom2.so` on Linux and
`pdftrondicom2.dylib` on Mac.
7. Copy two files to `PDFTronCore/AdvancedImagingModule/Lib/Linux` on Linux
and `PDFTronCore/AdvancedImagingModule/Lib/MacOS` on MacOS.

USAGE

The executable `dcm2pnm` can be executed with two extra arguments:

The first argument is the utility function we want. It is specifically build to convert between formats.
So, the first argument is `+Fa` for our purpose. 

The second argument is a JSON file where the input and output files are specified.
The input file is the file that needs to be converted and the output is what we would like it to be.

We will get a JSON output file and lots of raw image data dumps representing single frames of the DICOM image.