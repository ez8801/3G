/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëŞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ŞÅéÄ¡¢?øÖßÓ?îÜŞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜĞ×ò­ôºí»ŞÅéÄ¡£
ôºí»ŞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ğ¶?éÍğ¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªŞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ŞÅéÄ¡¢ÛÕøÖªË?ª¹ªëŞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íŞùê¡¢ê«öÎîÜªËÙí?ŞÅéÄªòĞ×ª¸ªŞª¹¡£
Ùí?ŞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªŞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòğ¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "BasicTypes.h"
#include "Vector3D.h"

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

	class CPositionFollower_Interior;

	/**
	\~korean
	remote objectÀÇ jitteringµÇ´Â position,velocity¸¦ linear interpolationÀ¸·Î
	smoothing Ã³¸®ÇÏ´Â classÀÌ´Ù.

	¿¹¸¦ µé¾î, remote object¸¦ dead reckoningÀ» ÇÒ ¶§ À¯¿ëÇÏ´Ù.

	(³ªÁß¿¡, ÀÌ class¸¦ º¸°­ÇØ¼­, orientationÀ» quaternion µîÀ¸·Î interpolationÇÏ´Â
	±â´ÉÀÌ Ãß°¡µÇ¾îµµ ¾µ¸¸ÇÏ°Ú´Ù.)

	ÀÏ¹İÀûÀÎ »ç¿ë¹ı
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#dead_reckoning" >ÃßÃø Ç×¹ı(dead reckoning)</a>  Âü°í

	Áß·Â¿¡ ´ëÇÑ °í·Á »çÇ×
	- Á¡ÇÁ µîÀÌ ÀÖ´Â °ÔÀÓ¿¡¼­´Â Ä³¸¯ÅÍ°¡ Á¡ÇÁ Áß Á÷¼± ÀÌµ¿ÀÌ ¾î»öÇÒ ¼ö¹Û¿¡ ¾ø´Ù.
	µû¶ó¼­ Á¡ÇÁÁß¿¡´Â Áß·ÂÀÌ ÀÛ¿ëÇØ¼­ °è¼ÓÇØ¼­ ÇÏÇâ °î¼±À» ±×·Á¾ß ÇÑ´Ù.
	ÀÌ·² ¶§ SetGravity¸¦ ÅëÇØ Áß·Â °ªÀ» ¹Ì¸® ³Ö¾îµÑ ¼ö ÀÖ´Ù.

	\~english
	Class that smoothing processes position,velocity of remote object that are 'jittering'ed into linear interpolation

	For an example, it is useful when dead reckoning remote object.

	(Later, it'd be useful if this class is strengthened to have interpolation function that converts orientation into quarternion.)

	General usage
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#dead_reckoning" >Dead Reckoning</a>

	Considerations on gravity
	- In a game that has jump motions, the character jumps while moving in linear fashion must be somewhat un-natural.
	So, during jump motion, there must be gravity acting to result downward curve motion.
	In that case, you can use SetGravity to pre-input the gravity value.

	\~chinese
	÷êremote objectîÜjitteringîÜposition,velocity éÄlinear interpolation?ú¼smoothing?×âîÜclass¡£

	ÖÇåı÷êremote object?ú¼dead reckoningîÜ?ı¦êóéÄ¡£

	£¨ì¤ı¨Ê¥Ë­ó®?£¬÷êorientationéÄquaternionÔõ?ú¼interpolationîÜÍíÒöôÕÊ¥?ËÛå¥Üô??¡££©

	ìéÚõŞÅéÄÛ°Ûö
	- ?ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_  #dead_reckoning" >õÏ?Û°Ûö (dead reckoning)</a>%¡£

	?ñìÕôîÜÍÅ?ŞÀ?¡£
	- êóÔ¯?ÔõîÜêı?ñéÊÇßäÔ¯?ñéîÜòÁ?ì¹?ù±ïÒ?Üôí»æÔ¡£ì×ó®î¤Ô¯?ñéñìÕôé©ÑÃíÂéÄŞÅĞì???õóú¾ù»ÍØ?¡£??ı¦Ê¦ì¤÷×?SetGravity£¬?à»?ìıñìÕô?¡£

	\~japanese
	remote objectªÎjitteringªµªìªëposition¡¢velocityªòlinear interpolationªÇsmoothing?×âª¹ªëclassªÇª¹¡£
	ÖÇª¨ªĞ¡¢ remote objectªÇdead reckoningªòª¹ªëãÁªËêóéÄªÇª¹¡£
	(ı­ªÇ¡¢ª³ªÎclassªòÜÍ?ª·ªÆ¡¢orientationªòquaternionªÊªÉªÇinterpolationª¹ªëÑ¦Òöª¬õÚÊ¥ªµªìªÆªâÕŞª¤ªÈŞÖª¤ªŞª¹)
	ìéÚõîÜªÊŞÅéÄÛ°Ûö
	- \ref dead_reckoning  ?ÍÅ

	ñìÕôªË?ª¹ªëÍÅÕçŞÀú£
	- «¸«ã«ó«×ªÊªÉª¬ª¢ªë«²?«àªÇªÏ¡¢«­«ã«é«¯«¿?ª¬«¸«ã«ó«×ñéªËòÁàÊì¹ÔÑªÏª®ª³ªÁªÊª¤ª·ª«ª¢ªêªŞª»ªó¡£
	ªèªÃªÆ¡¢«¸«ã«ó«×ñéªËªÏñìÕôª¬íÂéÄª·ªÆ?ª±ªÆù»ú¾ª­ÍØàÊªòÙÚª¯ù±é©ª¬ª¢ªêªŞª¹¡£
	ª³ªÎªèª¦ªÊãÁ¡¢SetGravityªò÷×ª¸ñìÕôö·ªòîñªâªÃªÆìıªìªÆöÇª¯ù±é©ª¬ª¢ªêªŞª¹¡£
	\~
	*/
	class CPositionFollower
	{
		CPositionFollower_Interior* m_interior;

	public:
		PROUD_API CPositionFollower();
		PROUD_API ~CPositionFollower();

		/**
		\~korean
		Áß·ÂÀ» ¼¼ÆÃÇÑ´Ù.
		- Áß·ÂÀ» ¼¼ÆÃÇÏ°Ô µÇ¸é, follower¿Í targetÀÌ ¸ğµÎ ¿µÇâÀ» ¹Ş´Â´Ù.
		¿¹¸¦ µé¾î, Á¡ÇÁ¸¦ ÇÏ´Â Ä³¸¯ÅÍ¶ó¸é ÀÌ ¸Ş¼­µå°¡ ÇÊ¿äÇÒ °ÍÀÌ´Ù.

		\~english
		Sets gravity
		- Once gravity is set then both follower and taget are affected.
		For an example, if it is a jumping character then it will need this method.

		\~chinese
		?öÇñìÕô¡£
		- ?öÇñìÕôîÜ?followerûútargetÔ´?áôÓğç¯?¡£
		ÖÇåı£¬åıÍıãÀâÍé©Ô¯?îÜÊÇßäÊ¦Òö?âÍé©ó®Û°Ûö¡£

		\~japanese
		ñìÕôªòàâïÒª·ªŞª¹¡£
		- ñìÕôªòàâïÒª¹ªëª³ªÈªËªÊªëªÈ¡¢followerªÈtargetª¬îïªÆç¯úÂªòáôª±ªŞª¹¡£
		ÖÇª¨ªĞ¡¢«¸«ã«ó«×ª¹ªë«­«ã«é«¯«¿?ªÊªéª³ªÎ«á«½«Ã«Éª¬ù±é©ªÇª¹¡£
		\~
		*/
		PROUD_API void SetGravity(const Vector3 &value);

		/**
		\~korean
		position follower°¡ ÂÑ¾Æ°¥ Åõ¸í ¿ÀºêÁ§Æ®ÀÇ ¼Óµµ¸¦ ¼¼ÆÃÇÑ´Ù.
		- Å¸ È£½ºÆ®·ÎºÎÅÍ »ó´ë¹æ Ä³¸¯ÅÍÀÇ À§Ä¡¸¦ ¹ŞÀ¸¸é ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÒ ÇÊ¿ä°¡ ÀÖÀ» °ÍÀÌ´Ù.

		\~english
		Sets the speed of invisible object that position follower is to follow
		- When the location of opponent character is received from other host, there is a need to call this method.

		\~chinese
		?öÇposition followerõÚ?îÜ÷âÙ¥objectîÜáÜÓø¡£
		- ?Ğìöâñ«Ïõâ¥Óğ?Û°ÊÇßäîÜêÈöÇîÜ?£¬?êóù±é©û¼Ğ£ó®Û°Ûö¡£

		\~japanese
		position followerª¬ªÄª¤ªÆú¼ª¯÷âÙ¥«ª«Ö«¸«§«¯«ÈªÎáÜÓøªòàâïÒª·ªŞª¹¡£ 
		- öâªÎ«Û«¹«Èª«ªéßÓâ¢ªÎ«­«ã«é«¯«¿?ªÎêÈöÇªòáôª±ªëªÈ¡¢ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API void SetTargetVelocity(const Vector3 &value);

		/**
		\~korean
		position follower°¡ ÂÑ¾Æ°¥ Åõ¸í ¿ÀºêÁ§Æ®ÀÇ À§Ä¡¸¦ ¼¼ÆÃÇÑ´Ù.
		- Å¸ È£½ºÆ®·ÎºÎÅÍ »ó´ë¹æ Ä³¸¯ÅÍÀÇ À§Ä¡¸¦ ¹ŞÀ¸¸é ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÒ ÇÊ¿ä°¡ ÀÖÀ» °ÍÀÌ´Ù.

		\~english
		Sets the location of invisible object that position follower is to follow
		- When the location of opponent character is received from other host, there is a need to call this method.

		\~chinese
		?öÇposition followerõÚ?îÜ÷âÙ¥objectîÜêÈöÇ¡£
		- ?Ğìöâñ«Ïõâ¥Óğ?Û°ÊÇßäîÜêÈöÇîÜ?£¬?êóù±é©û¼Ğ£ó®Û°Ûö¡£

		\~japanese
		position followerª¬ªÄª¤ªÆú¼ª¯÷âÙ¥«ª«Ö«¸«§«¯«ÈªÎêÈöÇªòàâïÒª·ªŞª¹¡£ 
		- öâªÎ«Û«¹«Èª«ªéßÓâ¢ªÎ«­«ã«é«¯«¿?ªÎêÈöÇªòáôª±ªëªÈ¡¢ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API void SetTargetPosition(const Vector3 &value);

		/**
		\~korean
		spline ÇüÅÂ·Î ÂÑ¾Æ°¡´Â followerÀÇ À§Ä¡¸¦ ¾ò´Â´Ù.

		\~english
		Gets the location of follower that moves in spline shape

		\~chinese
		?Ôğì¤splineû¡ãÒõÚ?îÜfollwerîÜêÈöÇ¡£

		\~japanese
		Splineû¡÷¾ªÇÜõª¤ªÆú¼ª¯followerªÎêÈöÇªòÔğªŞª¹¡£
		\~
		*/
		PROUD_API Vector3 GetSplineFollowerPosition() const;

		/**
		\~korean
		spline ÇüÅÂ·Î ÂÑ¾Æ°¡´Â followerÀÇ Çö ¼Óµµ¸¦ ¾ò´Â´Ù.

		\~english
		Gets the current speed of follower moves in spline shape

		\~chinese
		?Ôğì¤splineû¡ãÒõÚ?îÜfollwerîÜ?áÜÓø¡£

		\~japanese
		Splineû¡÷¾ªÇÜõª¤ªÆú¼ª¯followerªÎúŞî¤áÜÓøªòÔğªŞª¹¡£
		\~
		*/
		PROUD_API Vector3 GetSplineFollowerVelocity() const;

		/**
		\~korean
		¸¶Áö¸·À¸·Î ÀÔ·ÂÇÑ Áß·Â °ªÀ» ¾ò´Â´Ù.

		\~english
		Gets the last input value of gravity

		\~chinese
		?ÔğõÌı¨?ìıîÜñìÕô?¡£

		\~japanese
		õÌı­ªËìıÕôª·ª¿ñìÕôö·ªòÔğªŞª¹¡£
		\~
		*/
		PROUD_API Vector3 GetGravity() const;

		/**
		\~korean
		position follower°¡ ÂÑ¾Æ°¡´Â ¸ñÇ¥ ÁöÁ¡ÀÇ ÇöÀç ¼Óµµ¸¦ ¾ò´Â´Ù.

		\~english
		Gets the current speed of target location that position follower is following

		\~chinese
		?Ôğposition followerõÚ?ËÛîÜÙÍ?ò¢ïÃîÜ?áÜÓø¡£

		\~japanese
		position followerª¬ªÄª¤ªÆú¼ª¯ÙÍøöò¢ïÃªÎúŞî¤áÜÓøªòÔğªŞª¹¡£
		\~
		*/
		PROUD_API Vector3 GetTargetVelocity() const;

		/**
		\~korean
		position follower°¡ ÂÑ¾Æ°¡´Â ¸ñÇ¥ ÁöÁ¡ÀÇ ÇöÀç À§Ä¡¸¦ ¾ò´Â´Ù.
		- SetTargetPosition¿¡¼­ ÀÔ·ÂÇÑ °ª°ú ´Ù¸¦ ¼ö ÀÖ´Ù. ¿Ö³ÄÇÏ¸é FrameMove¿¡ ÀÇÇØ Áö¼ÓÀûÀ¸·Î °»½ÅµÇ±â ¶§¹®ÀÌ´Ù.

		\~english
		Get the current location of target location that position follower is following
		- Can be different to the value entered in SetTargetPosition since it is continuously updated by FrameMove

		\~chinese
		?Ôğposition followerõÚ?ËÛîÜÙÍ?ò¢ïÃîÜ?êÈöÇ¡£
		- Ê¦Òö?î¤SetTargetPosition?ìıîÜ?ÜôÔÒ¡£ì×?ù¬FrameMoveò¥?ÌÚãæ¡£

		\~japanese
		position followerª¬ªÄª¤ªÆú¼ª¯ÙÍøöò¢ïÃªÎúŞî¤êÈöÇªòÔğªŞª¹¡£
		- SetTargetPositionªÇìıÕôª·ª¿ö·ªÈêŞª¦ª³ªÈª¬ª¢ªêªŞª¹¡£ªÊª¼ªÊªé¡¢FrameMoveªËªèªÃªÆò¥?îÜªËÌÚãæªµªìªëª«ªéªÇª¹¡£
		\~
		*/
		PROUD_API Vector3 GetTargetPosition() const;

		/**
		\~korean
		position follower ÀÚÃ¼ÀÇ ¼Óµµ¸¦ ÁöÁ¤ÇÑ´Ù.
		- remote objectÀÇ ÃÊ±â »óÅÂ¸¦ ¼¼ÆÃÇÒ ¶§¿¡ ¾²ÀÎ´Ù.

		\~english
		Sets the speed of position follower itself
		- Used to set the initial condition of remote object

		\~chinese
		ò¦ïÒposition followerÜâãóîÜáÜÓø¡£
		- ŞÅéÄéÍ?öÇremote objectîÜôøã·???¡£

		\~japanese
		position follower í»?ªÎáÜÓøªòò¦ïÒª·ªŞª¹¡£
		- remote objectªÎôøÑ¢?÷¾ªòàâïÒª¹ªëãÁªËŞÅªïªìªŞª¹¡£
		\~
		*/
		PROUD_API void SetFollowerVelocity(const Vector3 &value);

		/**
		\~korean
		position follower ÀÚÃ¼ÀÇ À§Ä¡¸¦ ÁöÁ¤ÇÑ´Ù.
		- remote objectÀÇ ÃÊ±â »óÅÂ¸¦ ¼¼ÆÃÇÒ ¶§¿¡ ¾²ÀÎ´Ù.

		\~english
		Sets the location of position follower itself
		- Used to set the initial condition of remote object

		\~chinese
		ò¦ïÒposition followerÜâãóîÜêÈöÇ¡£
		- ŞÅéÄéÍ?öÇremote objectîÜôøã·???¡£

		\~japanese
		position follower í»?ªÎêÈöÇªòò¦ïÒª·ªŞª¹¡£
		- remote objectªÎôøÑ¢?÷¾ªòàâïÒª¹ªëãÁªËŞÅªïªìªŞª¹¡£
		\~
		*/
		PROUD_API void SetFollowerPosition(const Vector3 &value);

		/**
		\~korean
		position follower ÀÚÃ¼ÀÇ ÇöÀç ¼Óµµ¸¦ ¾ò´Â´Ù.
		- SetFollowerVelocity¿¡¼­ ÀÔ·ÂÇÑ °ª°ú ´Ù¸¦ ¼ö ÀÖ´Ù. ¿Ö³ÄÇÏ¸é FrameMove¿¡ ÀÇÇØ Áö¼ÓÀûÀ¸·Î °»½ÅµÇ±â ¶§¹®ÀÌ´Ù.

		\~english
		Gets the current speed of position follower itself
		- Can be different to the value entered in SetFollowerVelocity since it is continuously updated by FrameMove

		\~chinese
		?Ôğposition followerÜâãóîÜ?áÜÓø¡£
		- Ê¦Òö?î¤SetFollowerVelocity?ìıîÜ?ÜôÔÒ¡£ì×?ù¬FrameMoveò¥?ÌÚãæ¡£

		\~japanese
		position follower í»?ªÎúŞî¤áÜÓøªòÔğªŞª¹¡£
		- SetFollowerVelocityªÇìıÕôª·ª¿ö·ªÈì¶ªÊªëíŞùêª¬ª¢ªêªŞª¹¡£ªÊª¼ªÊªé¡¢FrameMoveªËªèªÃªÆò¥?îÜªËÌÚãæªµªìªëª«ªéªÇª¹¡£
		\~
		*/
		PROUD_API Vector3 GetFollowerVelocity() const;

		/**
		\~korean
		position follower ÀÚÃ¼ÀÇ ÇöÀç À§Ä¡¸¦ ¾ò´Â´Ù.
		- SetFollowerPosition¿¡¼­ ÀÔ·ÂÇÑ °ª°ú ´Ù¸¦ ¼ö ÀÖ´Ù. ¿Ö³ÄÇÏ¸é FrameMove¿¡ ÀÇÇØ Áö¼ÓÀûÀ¸·Î °»½ÅµÇ±â ¶§¹®ÀÌ´Ù.

		\~english
		Gets the current location of position follower itself
		- Can be different to the value entered in SetFollowerPosition since it is continuously updated by FrameMove

		\~chinese
		?Ôğposition followerÜâãóîÜ?êÈöÇ¡£
		- Ê¦Òö?î¤SetFollowerPosition?ìıîÜ?ÜôÔÒ¡£ì×?ù¬FrameMoveò¥?ÌÚãæ¡£

		\~japanese
		position follower í»?ªÎúŞî¤êÈöÇªòÔğªŞª¹¡£
		- SetFollowerVelocityªÇìıÕôª·ª¿ö·ªÈì¶ªÊªëíŞùêª¬ª¢ªêªŞª¹¡£ªÊª¼ªÊªé¡¢FrameMoveªËªèªÃªÆò¥?îÜªËÌÚãæªµªìªëª«ªéªÇª¹¡£
		\~
		*/
		PROUD_API Vector3 GetFollowerPosition() const;

		/**
		\~korean
		¸¸¾à »õ·Î ¹ŞÀº target positionÀÌ follower¿ÍÀÇ °Å¸®Â÷°¡ Áö³ªÄ¡°Ô Å« °æ¿ì, ÀÇµµÀû ¿öÇÁ, ¸®½ºÆù
		È¤Àº Áö³ªÄ£ ·¢À¸·Î ÀÎÇÑ À§Ä¡ ¿ÀÂ÷ÀÏ ¼ö ÀÖ´Ù. ÀÌ·± °æ¿ì À§Ä¡ º¸Á¤Àº ¿ÀÈ÷·Á ÀÌ»óÇÑ °á°ú¸¦ ¾ß±âÇÑ´Ù.
		warp threshold¸¦ Á¤ÇØ³õÀ¸¸é Áö³ªÄ¡°Ô Å« À§Ä¡ ¿ÀÂ÷ÀÇ °æ¿ì º¸Á¤À» ÇÏÁö ¾Ê°í °­Á¦·Î follower¸¦ target À§Ä¡¿Í
		ÀÏÄ¡½ÃÅ²´Ù.
		\param warpThreshold À§Ä¡ º¸Á¤À» ¹«½ÃÇÒ ¼ö ÀÖ´Â ÀÓ°è°ªÀ¸·Î¼­ÀÇ °Å¸®

		\~english
		If newly received target position is too far from the location of follower, it may be location error due to intentional warp, resapwn or extreme lags. In this case, performing location correction will make the situation worse.
		    if warp threshold is set then it does not perform correction but forcefully synchronizes follower with target location.
		\param warpThreshold distance as critical value that can ignore location correction

		\~chinese
		åıÍıãæïÈâ¥îÜtarget position?followerîÜËå?ñıó¬?ÓŞîÜ?£¬Ê¦ÒöãÀì×?warp£¬resapwn£¬ûäíº?İÂîÜlagîÜêÈöÇ?ó¬¡£??ı¦êÈöÇÎèïáÚãì»ìÚÑÃĞôÎÖîÜ?Íı¡£
		?ïÒwarp thresholdîÜ?£¬õó??ÓŞîÜêÈöÇ?ó¬îÜï×??£¬Üô?ú¼Îèïá£¬ì»ãÀË­ğ¤àõîÜ÷êfollower?targetîÜêÈöÇ?ú¼ÎÁÛÕ¡£
		\param warpThreshold íÂ?Ê¦ì¤Ùé?êÈöÇÎèïá?Í£?îÜËå?¡£

		\~japanese
		ªâª·¡¢ãæª¿ªËáôª±ª¿target positionª¬followerªÈªÎËå×îó¬ª¬ª¢ªŞªêªËªâÓŞª­ª¤íŞùê¡¢ëò?îÜªÊ«ï?«×¡¢«ì«¹«İ?«óªŞª¿ªÏ«é«Ã«¯ªËªèªëêÈöÇè¦ó¬ªÇª¢ªëª«ªâò±ªìªŞª»ªó¡£ª³ªÎªèªÊíŞùê¡¢êÈöÇÜÍïáªÏªàª·ªíªªª«ª·ª¤Ì¿ÍıªòÑÃª³ª·ªŞª¹¡£
		warp thresholdªòÌ½ªáªÆöÇª±ªĞª¢ªŞªêªËªâÓŞª­ª¤êÈöÇè¦ó¬ªÎíŞùê¡¢ÜÍïáªòª·ªÊª¯?ğ¤ªËfollower targetêÈöÇªÈìéöÈªµª»ªŞª¹¡£
		\param warpThreshold êÈöÇÜÍïáªòÙíãÊªÇª­ªë×üÍ£ö·ªÈª·ªÆªÎËå×î
		\~
		*/
		PROUD_API void SetWarpThreshold(double warpThreshold);

		/**
		\~korean
		FrameMove()°¡ 1È¸ ÀÌ»ó »ç¿ëµÇ¾ú´Â°¡?

		\~english
		FrameMove() used more than once?

		\~chinese
		FrameMove()ù¬ŞÅéÄ?ìéó­ì¤ß¾?£¿

		\~japanese
		FrameMove()ª¬1üŞì¤ß¾ŞÅªïªìª¿ªÎª«£¿
		\~
		*/
		PROUD_API bool IsFirstUse();

		/**
		\~korean
		follower°¡ target±îÁö ´Ù´Ù¸£´Â ½Ã°£À» ¼³Á¤ÇÑ´Ù.
		- EnableAutoFollowDuration(true)¸¦ È£ÃâÇÑ »óÅÂÀÌ¸é ÀÌ ¸Ş¼­µå´Â ½ÇÇàÀÌ ¹«½ÃµÈ´Ù. ´ë½Å, ³»ºÎÀûÀ¸·Î ÀûÀıÇÑ
		durationÀ» ÀÚµ¿À¸·Î Ã£´Â´Ù.
		- ÀÌ °ªÀº ÀÏ¹İÀûÀ¸·Î SetTargetPosition,SetTarget,SetTargetVelocity°¡ È£ÃâµÇ´Â ÁÖ±âº¸´Ù ¾à°£ ±æ°Ô Àâ´Â °ÍÀÌ ÁÁ´Ù.
		Áö³ªÄ¡°Ô ÀÛÀº °ªÀ» ³ÖÀ¸¸é ¿òÁ÷ÀÓÀÌ ³Ê¹« Æ¢¸ç, ³Ê¹« Å« °ªÀ» ³ÖÀ¸¸é ¿òÁ÷ÀÓÀÇ Á¤È®¼ºÀÌ ¶³¾îÁø´Ù.
		\param duration follower°¡ target±îÁö ´Ù´Ù¸£´Â ½Ã°£(ÃÊ´ÜÀ§)

		\~english
		Sets the time taken that follower gets to target
		- This method will be ignored if EnableAutoFollowDuration(true) is called. Instead, it automatically finds suitable duration internally.
		- Usually, it is ideal to set this value a little bit larger than the period that calls SetTargetPosition,SetTarget,SetTargetVelocity.
		  If the value is too small then the movement will be jumpy but if too large then the precision of movement will be lost.
		\param duration time taken that follower gets to target (in second)

		\~chinese
		?öÇfollowerÓğ?targetîÜ??¡£
		- åıÍıãÀû¼Ğ£EnableAutoFollowDuration(true)îÜ??îÜ?ó®Û°ÛöîÜ?ú¼?ù¬Ùé?¡£Üô?î¤?İ»?í»???ùêÎÁîÜduration¡£
		- ìéÚõ÷êó®??öÇà÷İïSetTargetPosition,SetTarget,SetTargetVelocity ù¬û¼Ğ£îÜñ²Ñ¢õªÚ°??û¿¡£
		?ìı?á³?îÜ??íÂ?÷¼?äÑ£¬?ÓŞ?îÜ??íÂîÜïá?àõ?Ë½î¸¡£
		\param duration followerÓğ?targetîÜ??£¨õ©?êÈ£©¡£

		\~japanese
		Followerª¬targetªŞªÇò¸ªëãÁÊàªòàâïÒª·ªŞª¹¡£
		- EnableAutoFollowDuration(true)ªòû¼ªÓõóª·ª¿?÷¾ªÇª¢ªìªĞ¡¢ª³ªÎ«á«½«Ã«ÉªÏ?ú¼ª¬ÙíãÊªµªìªŞª¹¡£ÓÛªïªêªË¡¢?İ»îÜªËîêï·ªÊdurationªòí»ÔÑªË÷®ª·ªŞª¹¡£
		- ª³ªÎö·ªÏìéÚõîÜªËSetTargetPosition,SetTarget,SetTargetVelocityª¬û¼ªÓõóªµªìªëñ²Ñ¢ªèªêá´ª·íşª¯ö¢ªÃª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		ª¢ªŞªêªËªâá³ªµª¤ö·ªòìıªìªëªÈÔÑª­ª¬ªÈªÆªâÙÍØ¡ªÃªÆ¡¢ª¢ªŞªêªËªâÓŞª­ª¤ö·ªòìıªìªëªÈÔÑª­ªÎïáü¬àõª¬ÕªªÁªŞª¹¡£
		\param duration followerª¬targetªŞªÇò¸ªëãÁÊà(õ©?êÈ) 
		\~
		*/
		PROUD_API void SetFollowDuration(double duration);
		/**
		\~korean
		¸¶Áö¸·À¸·Î SetFollowDurationÀ¸·Î ÀÔ·ÂÇÑ °ªÀ» Ãâ·ÂÇÑ´Ù.

		\~english
		Outputs the last value entered to SetFollowDuration

		\~chinese
		?õóõÌı¨éÄSetFollowDuration?ìıîÜ?¡£

		\~japanese
		õÌı­ªËSetFollowDurationªÇìıÕôª·ª¿ö·ªòõóÕôª·ªŞª¹¡£ 
		\~
		*/
		PROUD_API double GetFollowDuration();
		/**
		\~korean
		true·Î ¼¼ÆÃÇÏ¸é follower°¡ target±îÁö ´Ù´Ù¸£´Â ½Ã°£À» ÀÚµ¿À¸·Î Á¶ÀıÇÑ´Ù.

		\~english
		If set as true then it automatically controls the time taken for follower to get to taget.

		\~chinese
		?öÇ?trueîÜ?í»??ïÚfollowerÓğ?targetîÜ??¡£

		\~japanese
		TrueªÇàâïÒª¹ªëªÈfollowerª¬targetªŞªÇò¸ªëãÁÊàªòí»ÔÑğàï½ª·ªŞª¹¡£ 
		\~
		*/
		PROUD_API void EnableAutoFollowDuration(bool val);

		/**
		\~korean
		follower°¡ µû¶ó°¡´Â targetÀÇ pos, velÀ» ±¸ÇÑ´Ù.
		\param position ¾ò¾î¿Ã Å¸°ÙÀÇ À§Ä¡ vector3
		\param velocity ¾ò¾î¿Ã Å¸°ÙÀÇ ¼Óµµ vector3

		\~english TODO:translate needed.
		Calculate the pos and vel of the target followed by the follower. 
		\param position Vector 3 location of the target to be obtained for the position. 
		\param velocity Vector 3 speed of the target to be obtained for the velocity.

		\~chinese
		Ï´followerõÚ?îÜtargetîÜpos, vel¡£
		\param position é©?ö¢îÜtargetêÈöÇvector3¡£
		\param velocity é©?ö¢îÜtargetáÜÓøvector3¡£

		\~japanese
		Followerª¬ªÄª¤ªÆú¼ª¯targetªÎpos, velªòÏ´ªáªŞª¹¡£
		\param position ÔğªÆ?ªë«¿?«²«Ã«ÈªÎêÈöÇ vector3
		\param velocity ÔğªÆ?ªë«¿?«²«Ã«ÈªÎáÜÓø vector3
		\~
		*/
		PROUD_API void GetTarget(Vector3 &position, Vector3 &velocity) const;

		/**
		\~korean
		followerÀÇ position, velocity¸¦ ±¸ÇÑ´Ù.
		\param position ¾ò¾î¿Ã FollowerÀÇ À§Ä¡ vector3
		\param velocity ¾ò¾î¿Ã FollowerÀÇ ¼Óµµ vector3

		\~english TODO:translate needed.
		Gets position, velocity of follower

		\~chinese
		Ï´followerõÚ?îÜtargetîÜposition, velocity¡£
		\param position é©?ö¢îÜtargetêÈöÇvector3¡£
		\param velocity é©?ö¢îÜtargetáÜÓøvector3¡£

		\~japanese
		FollowerªÎposition, velocityªòÏ´ªáªŞª¹¡£
		\param velocity ÔğªÆ?ªëFollowerªÎáÜÓø vector3 
		\~
		*/
		PROUD_API void GetFollower(Vector3 &position, Vector3 &velocity) const;

		/**
		\~korean
		SetFollowerVelocity,SetFollowerPositionÀ» ÇÑ¹ø¿¡ ¸ğµÎ È£ÃâÇÑ´Ù.

		\~english
		Calls SetFollowerVelocity,SetFollowerPosition at the same time

		\~chinese
		ìéó­àõîïİ»û¼Ğ£SetFollowerVelocity,SetFollowerPosition¡£

		\~japanese
		SetFollowerVelocity,SetFollowerPositionªòìéÓøªËîïªÆªòû¼ªÓõóª·ªŞª¹¡£ 
		\~
		*/
		PROUD_API void SetFollower(Vector3 position, Vector3 velocity);

		/**
		\~korean
		¸Å Å¸ÀÓ ÇÁ·¹ÀÓ¸¶´Ù ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇØ¾ß ÇÑ´Ù.
		\param elapsedTime ÇÑ ÇÁ·¹ÀÓÀÇ ½Ã°£(ÃÊ)

		\~english
		This method must be called by each time frame.
		\param elapsedTime length of a frame(in second)

		\~chinese
		é©î¤Øß?time frameû¼Ğ£ó®Û°Ûö¡£
		\param elapsedTime ìé?frameîÜ??£¨õ©£©¡£

		\~japanese
		«¿«¤«à«Õ«ì?«àª´ªÈªËª³ªÎ«á«½«Ã«Éªòû¼ªÓõóªµªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\param elapsedTime ìé«Õ«ì?«àªÎãÁÊà(õ©) 
		\~
		*/
		PROUD_API virtual void FrameMove(double elapsedTime);

		/**
		\~korean
		SetTargetPosition°ú SetTargetVelocity¸¦ ÇÑ¹ø¿¡ ¸ğµÎ È£ÃâÇÑ´Ù.

		\~english
		Calls SetTargetPosition and SetTargetVelocity at the same time

		\~chinese
		ìéó­àõîïİ»û¼Ğ£SetTargetPositionûúSetTargetVelocity¡£

		\~japanese
		SetTargetPositionªÈSetTargetVelocityªòìéÓøªËîïªÆªòû¼ªÓõóª·ªŞª¹¡£
		\~
		*/
		PROUD_API virtual void SetTarget(Vector3 position, Vector3 velocity);
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
