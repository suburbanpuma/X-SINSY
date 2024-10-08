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

#ifndef SINSY_S_CONF_H_
#define SINSY_S_CONF_H_

#include <string>
#include <set>
#include "IConf.h"
#include "Configurations.h"
#include "PhonemeTable.h"
#include "MacronTable.h"
#include "MultibyteCharRange.h"

namespace sinsy
{

class SConf : public IConf
{
public:
   //! constructor
   SConf(const std::string& enc);

   //! destructor
   virtual ~SConf();

   //! read phoneme table and config from files
   bool read(const std::string& table, const std::string& conf, const std::string& macron);

   //! convert lyrics to phonemes
   virtual bool convert(const std::string& enc, ConvertableList::iterator begin, ConvertableList::iterator end) const;

   //! get sil str
   virtual std::string getSilStr() const;

   //! check encoding
   bool checkEncoding(const std::string& enc) const;

   //! get multibyte char range
   const MultibyteCharRange& getMultibyteCharRange() const;

private:
   //! copy constructor (donot use)
   SConf(const SConf&);

   //! assignment operator (donot use)
   SConf& operator=(const SConf&);

   //! phoneme table
   PhonemeTable phonemeTable;

   //! configure
   Configurations config;

   //! macron table
   MacronTable macronTable;

   //! ranges of multibyte chars
   MultibyteCharRange multibyteCharRange;

   typedef std::set<std::string> Encodings;

   //! encoding
   Encodings encodings;
};

};

#endif // SINSY_S_CONF_H_
