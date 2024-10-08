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

#ifndef SINSY_CONF_MANAGER_H_
#define SINSY_CONF_MANAGER_H_

#include "IConf.h"
#include "ConfGroup.h"
#include "UnknownConf.h"

namespace sinsy
{
class Converter;
class JConf;
class CConf;
class EConf;
class SConf;

class ConfManager
{
public:
   //! constructor
   ConfManager();

   //! destructor
   virtual ~ConfManager();

   //! set confs to converter
   bool setLanguages(const std::string& languages, const std::string& dirPath);

   //! set default confs
   void setDefaultConfs(ConfGroup& confs) const;

private:
   //! copy constructor (donot use)
   ConfManager(const ConfManager&);

   //! assignment operator (donot use)
   ConfManager& operator=(const ConfManager&);

   //! clear all confs
   void clear();

   //! add conf
   void addConf(IConf* conf);

   //! Japanese conf (UTF-8)
   JConf* uJConf;

   //! Japanese conf (Shift_JIS)
   JConf* sJConf;

   //! Japanese conf (EUC-JP)
   JConf* eJConf;

   //! confs
   ConfGroup* confs;

   //! Chinese conf (UTF-8)
   CConf* uCConf;

   //! English conf (UTF-8)
   EConf* uEConf;

   //! Spanish conf (UTF-8)
   SConf* uSConf;

   //! conf for unknown language
   const UnknownConf uConf;

   typedef std::vector<IConf*> ConfList;

   //! list of IConf
   ConfList confList;

   //!< list of IConf to delete
   ConfList deleteList;
};

};

#endif // SINSY_CONF_MANAGER_H_
