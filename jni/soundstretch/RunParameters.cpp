////////////////////////////////////////////////////////////////////////////////
///
/// A class for parsing the 'soundstretch' application command line parameters
///
/// Author        : Copyright (c) Olli Parviainen
/// Author e-mail : oparviai 'at' iki.fi
/// SoundTouch WWW: http://www.surina.net/soundtouch
///
////////////////////////////////////////////////////////////////////////////////
//
// Last changed  : $Date: 2009-05-17 19:48:30 +0300 (Sun, 17 May 2009) $
// File revision : $Revision: 4 $
//
// $Id: RunParameters.cpp 72 2009-05-17 16:48:30Z oparviai $
//
////////////////////////////////////////////////////////////////////////////////
//
// License :
//
//  SoundTouch audio processing library
//  Copyright (c) Olli Parviainen
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <string>
#include <stdlib.h>

#include "RunParameters.h"

using namespace std;

// Program usage instructions 

static const char licenseText[] = 
    "    LICENSE:\n"
    "    ========\n"
    "    \n"
    "    SoundTouch sound processing library\n"
    "    Copyright (c) Olli Parviainen\n"
    "    \n"
    "    This library is free software; you can redistribute it and/or\n"
    "    modify it under the terms of the GNU Lesser General Public\n"
    "    License version 2.1 as published by the Free Software Foundation.\n"
    "    \n"
    "    This library is distributed in the hope that it will be useful,\n"
    "    but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    "    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n"
    "    Lesser General Public License for more details.\n"
    "    \n"
    "    You should have received a copy of the GNU Lesser General Public\n"
    "    License along with this library; if not, write to the Free Software\n"
    "    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA\n"
    "    \n"
    "This application is distributed with full source codes; however, if you\n"
    "didn't receive them, please visit the author's homepage (see the link above).";

static const char whatText[] = 
    "This application processes WAV audio files by modifying the sound tempo,\n"
    "pitch and playback rate properties independently from each other.\n"
    "\n";

static const char usage[] = 
    "Usage :\n"
    "    soundstretch infilename outfilename [switches]\n"
    "\n"
    "To use standard input/output pipes, give 'stdin' and 'stdout' as filenames.\n"
    "\n"
    "Available switches are:\n"
    "  -tempo=n : Change sound tempo by n percents  (n=-95..+5000 %)\n"
    "  -pitch=n : Change sound pitch by n semitones (n=-60..+60 semitones)\n"
    "  -rate=n  : Change sound rate by n percents   (n=-95..+5000 %)\n"
    "  -bpm=n   : Detect the BPM rate of sound and adjust tempo to meet 'n' BPMs.\n"
    "             If '=n' is omitted, just detects the BPM rate.\n"
    "  -quick   : Use quicker tempo change algorithm (gain speed, lose quality)\n"
    "  -naa     : Don't use anti-alias filtering (gain speed, lose quality)\n"
    "  -speech  : Tune algorithm for speech processing (default is for music)\n"
    "  -license : Display the program license text (LGPL)\n";


// Converts a char into lower case
static int _toLowerCase(int c)
{
    if (c >= 'A' && c <= 'Z') 
    {
        c += 'a' - 'A';
    }
    return c;
}


// Constructor
RunParameters::RunParameters()
{
}
