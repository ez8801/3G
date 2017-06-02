/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³ÝÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±ÝÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëÞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ÞÅéÄ¡¢?øÖßÓ?îÜÞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜÐ×ò­ôºí»ÞÅéÄ¡£
ôºí»ÞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ð¶?éÍð¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªÞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ÞÅéÄ¡¢ÛÕøÖªË?ª¹ªëÞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íÞùê¡¢ê«öÎîÜªËÙí?ÞÅéÄªòÐ×ª¸ªÞª¹¡£
Ùí?ÞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªÞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòð¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "BasicTypes.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	Æ¯Á¤ÇÑ °¢µµ¸¦ ÇâÇØ ºÎµå·´°Ô °¢µµ°¡ º¯È­ÇÏµµ·Ï ÇÑ´Ù.
	°¢µµÀÇ ºÎµå·¯¿î ¿òÁ÷ÀÓÀ» ±¸ÇöÇÒ ¶§ »ç¿ëÇÏ´Â Å¬·¡½ºÀÌ´Ù.
	¿¹¸¦ µé¾î, remote characterÀÇ ¹æÇâ ÀüÈ¯ÀÌ ºÎµå·´°Ô ÀÌ·ç¾îÁö´Â Ã³¸® µî¿¡ È¿°úÀûÀÌ´Ù.

	ÀÏ¹ÝÀûÀÎ »ç¿ë¹ý:
	- GetFollowerAngle()·Î, follower angleÀ» ³Ö´Â´Ù. (º¸Åë ÃÊ±â 1È¸)
	- SetTargetAngle()·Î, target angleÀ» ÁöÁ¤ÇÑ´Ù. Åë»ó ¸Å framemove¸¶´Ù ÇÑ´Ù.
	- FrameMove()À» ¸Å ÇÁ·¹ÀÓ¸¶´Ù È£ÃâÇÑ´Ù.
	- ¸Å ÇÁ·¹ÀÓ¹Ì´Ù GetTargetAngle()·Î follower angleÀ» ¾ò´Â´Ù.

	\~english
	This method helps changing an angle more smoothly.
	This class is helpful and effective in handling smooth direction change of remote character.

	General Usage:
	- Insert a follower angle with GetFollowerAngle() (Normally at one inital time)
	- Assign a target angle with SetTargetAngle(). Normally set a target at every each framemove.
	- Calll for FrameMove() at each frame.
	- Get a follower angle by GetTargetAngle() at each frame.

	\~chinese
	ú¾÷åïÒîÜÊÇÓø£¬?ÊÇÓøêõ?ò¢?ûù¡£
	??ÊÇÓøîÜêõ??íÂ?ÞÅéÄîÜclass¡£
	ÖÇåý£¬?remote characterîÜÛ°ú¾??êõ??ú¼îÜ?×âÔõêóüù¡£

	ìéÚõÞÅéÄÛ°Ûö£º
	- éÄ GetFollowerAngle()%Û¯ìýfollower angle¡££¨ìéÚõôøÑ¢ìéó­£©
	- éÄ SetTargetAngle()%ò¦ïÒtarget angle¡£÷×ßÈØßframemoveÞÅéÄ¡£
	- ØßframeÔ´û¼õó FrameMove()%¡£
	- ØßframeÔ´éÄ GetTargetAngle()%?Ôðfollower angle¡£

	\~japanese
	÷åïÒªÊÊÇÓøªòú¾ª±êõªéª«ª¯ÊÇÓøª¬?ûùª¹ªëªèª¦ªËª·ªÞª¹¡£
	ÊÇÓøªÎêõªéª«ª¤ÔÑª­ªò?úÞª¹ªëãÁªËÞÅª¦«¯«é«¹ªÇª¹¡£
	ÖÇª¨ªÐ¡¢remote characterªÎÛ°ú¾?üµª¬êõªéª«ª¯ú¼ªïªìªë?×âªÊªÉªË?ÍýîÜªÇª¹¡£

	ìéÚõîÜªÊÞÅéÄÛ°Ûö£º
	- GetFollowerAngle()ªË follower angleªòìýªìªÞª¹¡££¨÷×ßÈªÏôøÑ¢1üÞ£©
	- SetTargetAngle()ªÇ target angleªòò¦ïÒª·ªÞª¹¡£÷×ßÈ¡¢framemoveª´ªÈªËú¼ª¤ªÞª¹¡£
	- FrameMove()ªò?«Õ«ì?«àª´ªÈªËû¼ªÓõóª·ªÞª¹¡£
	- «Õ«ì?«àª´ªÈªËGetTargetAngle()ªÇfollower angleªòÔðªÞª¹¡£
	\~
	 */
	class CAngleFollower
	{
		double m_followerAngle; // following angle, Áï source.
		double m_targetAngle; // following target, Áï source°¡ ÀÌ °ª¿¡ ±ÙÁ¢ÇÏ°Ô º¯ÇÑ´Ù.
		double m_followerAngleVelocity; // followerÀÇ °¢¼Óµµ
	public:
		PROUD_API CAngleFollower(void);
		PROUD_API ~CAngleFollower(void);

		/**
		\~korean
		¸Å ÇÁ·¹ÀÓ¸¶´Ù ÀÌ ¸Þ¼­µå¸¦ È£ÃâÇØ¾ß follower°¡ °ªÀÌ °è¼Ó º¯ÇÑ´Ù.
		\param elapsedTime ÇÁ·¹ÀÓ Ã³¸® ½Ã°£(in sec)

		\~english TODO:translate needed.
		The follower changes the value constantly when this method is called in every frame
		\param elapsedTime frame processing time (in sec)


		\~chinese
		ØßframeÔ´é©û¼õóó®method£¬follower?î¦Ê¦ì¤??ËÇ?¡£
		\param elapsedTime frameîÜ?×âÞÀËì£¨in sec£©

		\~japanese
		«Õ«ì?«àª´ªÈªËª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹ªÈfollowerªÎö·ª¬?ª±ªÆ?ªïªêªÞª¹¡£
		\param elapsedTime «Õ«ì?«à?×âãÁÊà(in sec)
		\~
		*/
		PROUD_API void FrameMove(double elapsedTime);

		/**
		\~korean
		follower angleÀ» ¼¼ÆÃÇÑ´Ù.
		\param value °¢µµ(in radian)

		\~english TODO:translate needed.
		Set the follower angle
		\param value angle (in radian)


		\~chinese
		?öÇfollower angle¡£
		\param value ÊÇÓø£¨in radian£©

		\~japanese
		follower angleªò«»«Ã«Æ«£«ó«°ª·ªÞª¹¡£
		\param value ÊÇÓø(in radian)
		\~
		*/
		PROUD_API void SetFollowerAngle(double value);

		/**
		\~korean
		follower angleÀ» ±¸ÇÑ´Ù.
		\return °¢µµ(in radian)

		\~english TODO:translate needed.
		Calculate the follower angle
		\return angle (in radian)


		\~chinese
		Ï´follower angle¡£
		\return ÊÇÓø£¨in radian£©

		\~japanese
		follower angleªòÏ´ªáªÞª¹¡£
		\return ÊÇÓø(in radian)
		\~
		*/
		PROUD_API double GetFollowerAngle();

		/**
		\~korean
		target angleÀ» ¼¼ÆÃÇÑ´Ù.
		\param value °¢µµ(in radian)

		\~english TODO:translate needed.
		Set the target angle
		\param value angle (in radian)


		\~chinese
		?öÇtarget angle¡£
		\param value ÊÇÓø£¨in radian£©

		\~japanese
		target angleªò«»«Ã«Æ«£«ó«°ª·ªÞª¹¡£'	
		\param value ÊÇÓø(in radian)
		\~
		*/
		PROUD_API void SetTargetAngle(double value);

		/**
		\~korean
		target angleÀ» ±¸ÇÑ´Ù.
		\return °¢µµ(in radian)

		\~english TODO:translate needed.
		Calculate the target angle
		\return angle (in radian)


		\~chinese
		Ï´target angle¡£
		\return ÊÇÓø£¨in radian£©

		\~japanese
		target angleªòÏ´ªáªÞª¹¡£
		\return ÊÇÓø(in radian)
		\~
		*/
		PROUD_API double GetTargetAngle();

		/**
		\~korean
		followerÀÇ ÀÌµ¿ °¢¼Óµµ¸¦ ³Ö´Â´Ù.
		\param value °¢¼Óµµ(in radian/sec)

		\~english TODO:translate needed.
		Insert the moving angle speed of the follower
		\param value angle speed (in radian/sec)


		\~chinese
		Û¯ìýfollowerîÜì¹?ÊÇáÜÓø¡£
		\param value ÊÇáÜÓø£¨in radian/sec£©

		\~japanese
		followerªÎì¹ÔÑÊÇáÜÓøªòìýªìªÞª¹¡£
		\param value ÊÇáÜÓø(in radian/sec)
		\~
		*/
		PROUD_API void SetFollowerAngleVelocity(double value);

		/**
		\~korean
		followerÀÇ ÀÌµ¿ °¢¼Óµµ¸¦ ±¸ÇÑ´Ù.
		\return °¢¼Óµµ(in radian/sec)

		\~english TODO:translate needed.
		Calculate the moving angle speed of the follower
		\return angle speed (in radian/sec)


		\~chinese
		Ï´followerîÜì¹?ÊÇáÜÓø¡£
		\return ÊÇáÜÓø£¨in radian/sec£©

		\~japanese
		followerªÎì¹ÔÑÊÇáÜÓøªòÏ´ªáªÞª¹¡£
		\return ÊÇáÜÓø(in radian/sec)
		\~
		*/
		PROUD_API double GetFollowerAngleVelocity();
        
#if defined(_MSC_VER)
		__declspec(property(get = GetFollowerAngle, put = SetFollowerAngle)) double followerAngle;
		__declspec(property(get = GetTargetAngle, put = SetTargetAngle)) double targetAngle;
		__declspec(property(get = GetFollowerAngleVelocity, put = SetFollowerAngleVelocity)) double followerAngleVelocity;
#endif
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif