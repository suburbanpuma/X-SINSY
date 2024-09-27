# X-SINSY

X-SINSY is a fork of Sinsy-Remix with the purpose of adding support for Spanish and P-SAMPA multilingual databases.

## Usage:
```
    sinsy [ options ] [ infile ]
  options:                                           [def]
    -w langs    : languages                          [  j]
                  j: Japanese                             
                  c: Chinese
                  e: English                             
                  s: Spanish (coming soon)                             
                  x: Multilingual                             

    -x dir      : dictionary directory               [/usr/local/dic]
    -m htsvoice : HTS voice file                     [N/A]
    -o file     : filename of output wav audio       [N/A]
    -l          : output label
  infile:
    MusicXML file
```

## About the Chinese dictionary:

Chinese dictionaries are queried through chinese.table by default, and will be parsed using a pinyin parser if they can't be queried. General non-specific pinyin does not need to be added to the dictionary. Chinese input formats can be in yuan, yuan2, or yvan, but not van.

## About the Spanish dictionary：
For Spanish grapheme conversion I've used a modified version of [open-dict](https://github.com/open-dict-data/ipa-dict)). Go check it out, they have TONS of IPA dictionaries, with an MIT license!

## CMUdict license：
```
CMUdict
-------

CMUdict (the Carnegie Mellon Pronouncing Dictionary) is a free
pronouncing dictionary of English, suitable for uses in speech
technology and is maintained by the Speech Group in the School of
Computer Science at Carnegie Mellon University.

The Carnegie Mellon Speech Group does not guarantee the accuracy of
this dictionary, nor its suitability for any specific purpose. In
fact, we expect a number of errors, omissions and inconsistencies to
remain in the dictionary. We intend to continually update the
dictionary by correction existing entries and by adding new ones. From
time to time a new major version will be released.

We welcome input from users: Please send email to Alex Rudnicky
(air+cmudict@cs.cmu.edu).

The Carnegie Mellon Pronouncing Dictionary, in its current and
previous versions is Copyright (C) 1993-2014 by Carnegie Mellon
University.  Use of this dictionary for any research or commercial
purpose is completely unrestricted.  If you make use of or
redistribute this material we request that you acknowledge its
origin in your descriptions.

If you add words to or correct words in your version of this
dictionary, we would appreciate it if you could send these additions
and corrections to us (air+cmudict@cs.cmu.edu) for consideration in a
subsequent version. All submissions will be reviewed and approved by
the current maintainer, Alex Rudnicky at Carnegie Mellon.

Copyright (C) 1993-2015 Carnegie Mellon University. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
   The contents of this file are deemed to be source code.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in
   the documentation and/or other materials provided with the
   distribution.

This work was supported in part by funding from the Defense Advanced
Research Projects Agency, the Office of Naval Research and the National
Science Foundation of the United States of America, and by member
companies of the Carnegie Mellon Sphinx Speech Consortium. We acknowledge
the contributions of many volunteers to the expansion and improvement of
this dictionary.

THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY ``AS IS'' AND
ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY
NOR ITS EMPLOYEES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

## Original README
```
===============================================================================
       The HMM-Based Singing Voice Synthesis System Remix "Sinsy-r" version 0.95.2

The Sinsy is an HMM-Based Singing Voice Synthesis System. It has been being
developed by Sinsy working group (see "Who we are" below) and some graduate
students in Nagoya Institute of Technology (see "AUTHORS" in the same
directory).

*******************************************************************************
                                    Copying
*******************************************************************************

The Sinsy is released under the Modified BSD license (see
http://www.opensource.org/). Using and distributing this software is free
(without restriction including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies of this
work, and to permit persons to whom this work is furnished to do so) subject to
the conditions in the following license:

/* ----------------------------------------------------------------- */
/*           The HMM-Based Singing Voice Synthesis System "Sinsy"    */
/*           developed by Sinsy Working Group                        */
/*           http://sinsy.sourceforge.net/                           */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2009-2015  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the Sinsy working group nor the names of    */
/*   its contributors may be used to endorse or promote products     */
/*   derived from this software without specific prior written       */
/*   permission.                                                     */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

Although this software is free, we still offer no warranties and no
maintenance. We will continue to endeavor to fix bugs and answer queries when
can, but are not in a position to guarantee it. We will consider consultancy if
desired, please contacts us for details.

If you are using the Sinsy in commercial environments, even though no license
is required, we would be grateful if you let us know as it helps justify
ourselves to our various sponsors. We also strongly encourage you to

 * refer to the use of Sinsy in any publications that use this software
 * report bugs, where possible with bug fixes, that are found

See also "COPYING" file in the current directory for details.

*******************************************************************************
                                 Installation
*******************************************************************************

See "INSTALL" in the same directory for details.

*******************************************************************************
                               Acknowledgements
*******************************************************************************

Keiichi Tokuda
Yoshihiko Nankaku
Keiichiro Oura
Kazuhiro Nakamura
Shinji Sako

*******************************************************************************
                                  Who we are
*******************************************************************************

The Sinsy working group is a voluntary group for developing the HMM-Based
Singing Voice Synthesis System. Current members are

 Keiichi Tokuda      http://www.sp.nitech.ac.jp/~tokuda/
 (Produce and Design)
 Keiichiro Oura      http://www.sp.nitech.ac.jp/~uratec/
 (Design and Development)
 Kazuhiro Nakamura   http://www.sp.nitech.ac.jp/~nkazu/
 (Development and Main Maintainer)
 Yoshihiko Nankaku   http://www.sp.nitech.ac.jp/~nankaku/

and the members are dynamically changing. The current formal contact address of
Sinsy working group and a mailing list for Sinsy users can be found at
http://sinsy.sourceforge.net/

*******************************************************************************
                                  Remix
*******************************************************************************

Remix by HyperDeep(hyperzlib)
Add Chinese support
in future this project will support windows

*******************************************************************************
                                X-SINSY
*******************************************************************************

X-SINSY by suburbanpuma(pumas)
lets see if i don't blow everything up xoxo

===============================================================================
```
