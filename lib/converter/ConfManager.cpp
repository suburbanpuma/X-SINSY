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

#include <stdexcept>
#include <algorithm>
#include "util_log.h"
#include "StringTokenizer.h"
#include "Deleter.h"
#include "ConfManager.h"
#include "ConfGroup.h"
#include "util_converter.h"
#include "JConf.h"
#include "CConf.h"
#include "EConf.h"
#include "SConf.h"

namespace sinsy
{

namespace
{
const std::string UTF_8_STRS("utf_8, utf8, utf-8");
const std::string SHIFT_JIS_STRS("shift_jis, shift-jis, sjis");
const std::string EUC_JP_STRS("euc-jp, euc_jp, eucjp");
const std::string GBK_STRS("cp936,gbk,gb2312");
const std::string BIG_5_STRS("big-5,big_5,big5");
const std::string CODE_SEPARATOR = "|";
};

/*!
 constructor
 */
ConfManager::ConfManager() : uJConf(NULL), sJConf(NULL), eJConf(NULL),
	uCConf(NULL), uEConf(NULL),
	confs(NULL)
{
}

/*!
 destructor
*/
ConfManager::~ConfManager()
{
   clear();
}

/*!
 @internal

 clear all confs
*/
void ConfManager::clear()
{
   std::for_each(deleteList.begin(), deleteList.end(), Deleter<IConf>());
   deleteList.clear();
   uJConf = NULL;
   sJConf = NULL;
   eJConf = NULL;
   confs = NULL;
   uCConf = NULL;
   uEConf = NULL;
   uSConf = NULL;
   confList.clear();
}

/*!
 @internal

 add Japanese conf
 */
void ConfManager::addConf(IConf* conf)
{
   if (!confs) {
      confs = new ConfGroup();
      deleteList.push_back(confs);
      confList.push_back(confs);
   }
   confs->add(conf);
}

/*!
 set languages
 */
bool ConfManager::setLanguages(const std::string& languages, const std::string& dirPath)
{
   clear();

   const std::string::const_iterator itrEnd(languages.end());
   for (std::string::const_iterator itr(languages.begin()); itrEnd != itr; ++itr) {
      char lang(*itr);
      switch (lang) {
      case 'j' : { // Japanese
         const std::string TABLE_UTF_8(dirPath + "/japanese.utf_8.table");
         const std::string CONF_UTF_8(dirPath + "/japanese.utf_8.conf");
         const std::string TABLE_SHIFT_JIS(dirPath + "/japanese.shift_jis.table");
         const std::string CONF_SHIFT_JIS(dirPath + "/japanese.shift_jis.conf");
         const std::string TABLE_EUC_JP(dirPath + "/japanese.euc_jp.table");
         const std::string CONF_EUC_JP(dirPath + "/japanese.euc_jp.conf");
         const std::string MACRON_TABLE(dirPath + "/japanese.macron");

         uJConf = new JConf(UTF_8_STRS);
         sJConf = new JConf(SHIFT_JIS_STRS);
         eJConf = new JConf(EUC_JP_STRS);

         // utf-8
         if (!uJConf->read(TABLE_UTF_8, CONF_UTF_8, MACRON_TABLE)) {
            ERR_MSG("Cannot read Japanese table or config or macron file : " << TABLE_UTF_8 << ", " << CONF_UTF_8);
            delete uJConf;
            uJConf = NULL;
            return false;
         }
         addConf(uJConf);
         deleteList.push_back(uJConf);


         // shift_jis
         if (!sJConf->read(TABLE_SHIFT_JIS, CONF_SHIFT_JIS, MACRON_TABLE)) {
            ERR_MSG("Cannot read Japanese table or config or macron file :" << TABLE_SHIFT_JIS << ", " << CONF_SHIFT_JIS);
            delete sJConf;
            sJConf = NULL;
            return false;
         }
         addConf(sJConf);
         deleteList.push_back(sJConf);

         // euc-jp
         if (!eJConf->read(TABLE_EUC_JP, CONF_EUC_JP, MACRON_TABLE)) {
            ERR_MSG("Cannot read Japanese table or config or macron file : " << TABLE_EUC_JP << ", " << CONF_EUC_JP);
            delete eJConf;
            eJConf = NULL;
            return false;
         }
         addConf(eJConf);
         deleteList.push_back(eJConf);

         break;
      }
      case 'c' : { // chinese
         const std::string TABLE(dirPath + "/chinese.table");
         const std::string CONF(dirPath + "/chinese.conf");
         const std::string MACRON_TABLE(dirPath + "/chinese.macron");

         uCConf = new CConf(UTF_8_STRS);

         // utf-8
         if (!uCConf->read(TABLE, CONF, MACRON_TABLE)) {
            ERR_MSG("Cannot read Chinese table or config or macron file : " << TABLE << ", " << CONF);
            delete uCConf;
            uCConf = NULL;
            return false;
         }
         addConf(uCConf);
         deleteList.push_back(uCConf);
         break;
      }
	  case 'e': { // english
		  const std::string TABLE(dirPath + "/english.table");
		  const std::string CONF(dirPath + "/english.conf");
		  const std::string MACRON_TABLE(dirPath + "/english.macron");

		  uEConf = new EConf(UTF_8_STRS);

		  // utf-8
		  if (!uEConf->read(TABLE, CONF, MACRON_TABLE)) {
			  ERR_MSG("Cannot read English table or config or macron file : " << TABLE << ", " << CONF);
			  delete uEConf;
			  uEConf = NULL;
			  return false;
		  }
		  addConf(uEConf);
		  deleteList.push_back(uEConf);
		  break;
	  }
	  case 's': { // spanish
		  const std::string TABLE(dirPath + "/spanish.table");
		  const std::string CONF(dirPath + "/spanish.conf");
		  const std::string MACRON_TABLE(dirPath + "/spanish.macron");

		  uSConf = new SConf(UTF_8_STRS);

		  // utf-8
		  if (!uSConf->read(TABLE, CONF, MACRON_TABLE)) {
			  ERR_MSG("Cannot read Spanish table, config, or macron file : " << TABLE << ", " << CONF);
			  delete uSConf;
			  uSConf = NULL;
			  return false;
		  }
		  addConf(uSConf);
		  deleteList.push_back(uSConf);
		  break;
	  }
      default :
         ERR_MSG("Unknown language flag : " << lang);
         return false;
      }
   }
   return true;
}

/*!
 set default confs
 */
void ConfManager::setDefaultConfs(ConfGroup& confs) const
{
   confs.clear();
   const ConfList::const_iterator itrEnd(confList.end());
   for (ConfList::const_iterator itr(confList.begin()); itrEnd != itr ; ++itr) {
      confs.add(*itr);
   }
   // unknown conf
   confs.add(&uConf);

   return;
}

};  // namespace sinsy
