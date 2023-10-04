```
Welcome to Dungeon.			This version created 11-MAR-91.
You are in an open field west of a big white house with a boarded
front door.
There is a small mailbox here.
>
```
# DUNGEON (Zork I) port for Agon Light

Public Domain source code to the original DUNGEON game (Zork I). Released to the PD by Infocom. Includes 
source files, headers, and information.

The original repository is located at https://github.com/devshane/zork.
This repository contains a genuine port of the game to
the [Agon Light](https://www.thebyteattic.com/p/agon.html) 8-bit computer.

# Building 

The game is a tad large and would not fit in the 64k of standard Z80 RAM
address space without extra C code optimization. Luckily, the Agon Light
can utilize its eZ80's larger 24-bit address space and its 512k memory.

## Compilation prerequisites

The game runs in eZ80 ADL mode and requires C compiler capable of producing
such code. The port was developed using AgDev LLVM compiler targetted for eZ80.
Feel free to follow instructions at [AgDev GitHub page](https://github.com/pcawte/AgDev)
to install the suite. It is by itself an adaptation of
the [CE C/C++ Toolchain](https://ce-programming.github.io/toolchain/static/getting-started.html)
originally created for the TI-84 calculator.

_Please note: When placing AgDev on top of CEdev pack, don't try to build
the latest version of C/CE++ from the source, but use the provided downloadable
stable distribution. The AgDev placed on top of the latest C/CE++ built from source
works just fine, but creates incorrect Agon binaries at the moment (as of Oct 4th, 2023)._

## Making the binary

The `Makefile` of the original project was adapted to follow CE C/C++ Toolchain guidance.
Feel free to check `Makefile` for additional settings - Agon video mode and additional flags,
alongside `agon.h` for more colorization and other settings.

The build is executed using the below command:

```
$ make
```

The build will produce object files in `obj/` directory and binary result in `dist/` directory.

The following files need to be transfered to Agon Light (or Agon emulator start directory):
```
dist/zork.bin -> zork.bin
dtextc.dat    -> zork.dat
```

## History of the C Implementation of Dungeon

This version of dungeon has been modified from FORTRAN to C.  The
original was written in DEC FORTRAN, translated from MDL.  It was then
translated to f77 for UN*X systems, from which it was translated to C.
The C translation was done with the help of f2c, the FORTRAN to C
translator written by David Gay (AT&T Bell Labs), Stu Feldman
(Bellcore), Mark Maimone (Carnegie-Mellon University), and Norm
Schryer (AT&T Bell Labs).

I. From the original documentation...

To: Dungeon Players
From: "The Translator"
Subj: Game Information
Date: 8-OCT-80


This is the first (and last) source release of the PDP-11 version of 
Dungeon.

Please note that Dungeon has been superceded by the game ZORK(tm).
The following is an extract from the new product announcement for
ZORK in the September, 1980 issue of the RT-11 SIG newsletter:

  "'ZORK:  The Great Underground Empire - Part I' ...was developed
   by the original authors based on their ZORK (Dungeon) game for
   the PDP-10.  It features a greatly improved parser;  command
   input and transcript output files;  SAVEs to any device and
   file name;  and adaptation to different terminal types,
   including a status line on VT100s.  Note:  this is not the
   FORTRAN version that has been available through DECUS.  This
   version has been completely rewritten to run efficiently on
   small machines - up to 10 times as fast as the DECUS version.

   ...ZORK runs under RT-ll, HT-ll, or RSTS/E and requires as
   little as 20K words of memory and a single floppy disk drive.
   The game package, consisting of an RX01-format diskette and
   an instruction booklet, is available from Infocom, Inc.,
   P.O. Box 120, Kendall Station, Cambridge, Ma. 02142."

ZORK(tm) is a trademark of Infocom, Inc.  It is available for several
popular personal computers as well as for the PDP-ll.


## Summary

   Welcome to Dungeon!

   Dungeon is a game of adventure, danger, and low cunning.  In it
you will explore some of the most amazing territory ever seen by mortal
man.  Hardened adventurers have run screaming from the terrors contained
within.

   In Dungeon, the intrepid explorer delves into the forgotten secrets
of a lost labyrinth deep in the bowels of the earth, searching for
vast treasures long hidden from prying eyes, treasures guarded by
fearsome monsters and diabolical traps!

   No DECsystem should be without one!

   Dungeon was created at the Programming Technology Division of the MIT
Laboratory for Computer Science by Tim Anderson, Marc Blank, Bruce
Daniels, and Dave Lebling.  It was inspired by the Adventure game of
Crowther and Woods, and the Dungeons and Dragons game of Gygax
and Arneson.  The original version was written in MDL (alias MUDDLE).
The current version was translated from MDL into FORTRAN IV by
a somewhat paranoid DEC engineer who prefers to remain anonymous.

   On-line information may be obtained with the commands HELP and INFO.

II. DEC FORTRAN to f77 Conversion (17-nov-81)

The conversion from DEC FORTRAN to Unix f77 was done by Randy
Dietrich, Lynn Cochran and Sig Peterson.  Much hacking was done to get
it to fit in the limited address space of a PDP-11/44 (split I/D).
Suffice it to say that by leaving out the debugging package and not
linking in the f77 i/o library they managed to get it to run.

III. PDP to VAX (dec-85)

Based on the work of Randy, Lynn and Sig, Bill Randle folded in the
full save/restore functions and the game debugging package (gdt) into
the pdp version to create a Vax/Unix version.  This version also uses
f77 i/o, thus eliminating the extra speak and listen processes needed
on the pdp.

IV. Cleanup I (11-dec-86)

John Gilmore (hoptoad!gnu) cleaned up the source files by moving
most of the common declarations into include files and added
comments from the original (FORTRAN or MDL?) source.  His efforts
are greatly appreciated.

V. Cleanup II (9-feb-87)

Bill Randle (billr@tekred.tek.com) added the pdp dependencies back
into the Vax source files with #ifdefs in order to have just one
set of sources.  Previously, there were two sets of source: one for
the pdp and one for the Vax.  In addition, a shell escape of the
form !cmd was added and the wizard can enter the gdt without having
to recompile the source.  Finally, a man page was generated, based
on the dungeon.doc file.

VI. f77 to C (11-mar-91)

Ian Lance Taylor (ian@airs.com or uunet!airs!ian) used the f2c
translator to generate C source code.  The resulting code was modified
to remove the FORTRAN I/O library, to add simple more processing, and
to change the format of the database file.  Andre Srinivasan
(andre@cs.pitt.edu) help test it.  Jonathan Mark
(uunet!microsoft!jonm) made it work under MS-DOS and Microsoft C.

VII. C port to Agon Light (4-oct-2023)

Roman Dolejsi slightly adapted the original C code to work on eZ80
8-bit CPU w/ 24-bit address space by utilizing the AgDev fork
of LLVM-based CE C/C++ toolkit originally built for TI-84 calculator.
As part of this port, colorization and video mode selection was added
to the repository, currently working for Agon only.
