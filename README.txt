CasparCG Server 2.1.0 Unstable
==============================

Thank you for your interest in CasparCG Server, a professional software used to
play out and record professional graphics, audio and video to multiple outputs.
CasparCG Server has been in 24/7 broadcast production since 2006.
The included software is provided as-is by Sveriges Televison AB.

This release is considered untested and unstable, and is NOT intended for use in
professional production. Stable and production-proven versions can be downloaded
at http://casparcg.com/download/

Alpha and beta builds are available at http://builds.casparcg.com/

More information about CasparCG is available at http://casparcg.com/ and
in the forum at http://casparcg.com/forum/


COMMON SYSTEM REQUIREMENTS FOR WINDOWS AND LINUX
------------------------------------------------

- Intel processor capable of using SSSE3 instructions.
  Please refer to
  http://en.wikipedia.org/wiki/SSSE3 for a complete list.
  While AMD processors might work, CasparCG Server has only been tested on Intel
  processors.

- A graphics card (GPU) capable of OpenGL 3.0 is required.
  We strongly recommend that you use a separate graphics card, and avoid
  using the built-in GPU that exists in many CPUs. Your playback performance
  might suffer if using a built-in GPU.


SYSTEM REQUIREMENTS FOR WINDOWS
-------------------------------

- Windows 7 (64-bit)
  CasparCG Server has also been used successfully on Windows 8 (64-bit).
  NOT SUPPORTED: 32-bit Windows versions and Windows 2003 Server.

- Microsoft Visual C++ 2015 Redistributable Package must be installed.
  See link in the 'INSTALLATION ON WINDOWS' section below.


SYSTEM REQUIREMENTS FOR LINUX
-----------------------------

- Ubuntu Desktop 14.04.3 LTS 64-bit.
  Other distributions might be ABI compatible and supported but not tested.

- An Nvidia graphics card.
  Other manufacturers might also work but are untested.


INSTALLATION ON WINDOWS
-----------------------

1. Check that your system meets the requirements above.

2. Unzip and place the "CasparCG Server" folder anywhere you like.

3. Install "Microsoft Visual C++ Redistributable for Visual Studio 2015" from
   https://www.microsoft.com/en-us/download/details.aspx?id=48145


INSTALLATION ON LINUX
---------------------

1. Check that your system meets the requirements above.

2. Unpack and place the "CasparCG Server" folder anywhere you like.

3. If using an Nvidia graphics card enable the use of "NVIDIA binary driver"
   under "Software & Updates -- Additional Drivers".


INSTALLATION OF ADDITIONAL NON-GPL SOFTWARE
-------------------------------------------

- For Flash template support (Windows only):

  1. Uninstall any previous version of the Adobe Flash Player using this file:
     http://download.macromedia.com/get/flashplayer/current/support/uninstall_flash_player.exe

  2. Download and unpack
     http://download.macromedia.com/pub/flashplayer/installers/archive/fp_11.8.800.94_archive.zip

  3. Install Adobe Flash Player 11.8.800.94 from the unpacked archive:
     fp_11.8.800.94_archive\11_8_r800_94\flashplayer11_8r800_94_winax.exe

- For NewTek iVGA support (Windows only), please download and install the
  following driver:
  http://new.tk/NetworkSendRedist


CONFIGURATION
-------------

1. Configure the server by editing the self-documented "casparcg.config" file in
   a text editor.

2. On Windows, start the "casparcg.exe" program, or on Linux start the "run.sh"
   program.

3. Connect to the Server from a client software, such as the "CasparCG Client"
   which is available as a separate download.


DOCUMENTATION
-------------

The most up-to-date documentation is always available at
http://casparcg.com/wiki/

Ask questions in the forum: http://casparcg.com/forum/


LICENSING
---------

CasparCG is distributed under the GNU General Public License GPLv3 or higher,
see the file LICENSE.txt for details.

More information, samples and documentation at:

http://casparcg.com/
http://casparcg.com/forum/
http://casparcg.com/wiki/

CasparCG Server uses FFmpeg (http://ffmpeg.org/) under the GPLv2 Licence.
FFmpeg is a trademark of Fabrice Bellard, originator of the FFmpeg project.

CasparCG Server uses the Threading Building Blocks
(http://www.threadingbuildingblocks.org/) library under the GPLv2 Licence.

CasparCG Server uses FreeImage (http://freeimage.sourceforge.net/) under the
GPLv2 License.

CasparCG Server uses SFML (http://www.sfml-dev.org/) under the zlib/libpng
License.

CasparCG Server uses GLEW (http://glew.sourceforge.net) under the modified BSD
License.

CasparCG Server uses boost (http://www.boost.org/) under the Boost Software
License, version 1.0.

