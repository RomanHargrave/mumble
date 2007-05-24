/* Copyright (C) 2005-2006, Thorvald Natvig <thorvald@natvig.com>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _ALSAAUDIO_H
#define _ALSAAUDIO_H

#include "AudioInput.h"
#include "AudioOutput.h"
#include <alsa/asoundlib.h>

class ALSAAudioOutput;
class ALSAAudioInput;

class ALSAAudioInput : public AudioInput {
	Q_OBJECT
	protected:
		void release();
	public:
		ALSAAudioInput();
		~ALSAAudioInput();
		void run();
};

class ALSAAudioOutput;
class ALSAOutputPlayer : public AudioOutputPlayer {
	friend class ALSAAudioOutput;
	Q_OBJECT
	protected:
		snd_pcm_t *pcm_handle;
		ALSAAudioOutput *aao;
		int iAliveHold;
		bool playFrames();
 	public:
 		void initialize();
		ALSAOutputPlayer(ALSAAudioOutput *, Player *);
		~ALSAOutputPlayer();
};


class ALSAAudioOutput : public AudioOutput {
	friend class ALSAOutputPlayer;
	Q_OBJECT
	protected:
    	virtual AudioOutputPlayer *getPlayer(Player *);
	public:
		ALSAAudioOutput();
		~ALSAAudioOutput();
		void run();
};

#else
class ALSAAudioInput;
class ALSAAudioOutput;
#endif
