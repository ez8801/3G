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

#include <assert.h>
#include <math.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	µÎ °ª v1,v2ÀÇ v1->v2·ÎÀÇ ³»ºĞ°ª ratioÀ» ±¸ÇÑ´Ù.
	ratio°¡ 0¿¡ °¡±î¿ï¼ö·Ï v1¿¡ °¡±õ´Ù. 

	\~english
	Get a ratio of interior division of v1 and v2 by v1 -> v2.
	As ratio is closer to 0, it's closer to v1.

	\~chinese
	Ï´???v1£¬v2èÙv1->v2îÜ?İÂ?ratio¡£
	Ratio êÆïÈĞÎ0£¬ö¦?êÆïÈĞÎv1¡£

	\~japanese
	?ö·v1¡¢v2ªÎv1->v2ªØªÎ?İÂö·ratioªòÏ´ªáªŞª¹¡£
	Ratioª¬0ªËĞÎªÅª¯ªÛªÉv1ªËĞÎª¤ªÇª¹¡£
	\~
	*/
	template<typename FloatType>
	inline FloatType ScalarLerp(const FloatType v1, const FloatType v2, const FloatType ratio)
	{
		return v1 + (v2 - v1) * ratio;
	}

	/** 
	\~korean
	Vector 3D Å¬·¡½º
	- Vector3T µîÀÌ ÀÖÀ½¿¡µµ ºÒ±¸ÇÏ°í º°µµ ±¸ÇöµÈ ÀÌÀ¯´Â, ÇÃ·§Æû ºñ Á¾¼ÓÀ» À§ÇÔÀÌ´Ù. 
	- º¸´Ù ³ôÀº Á¤È®µµ¸¦ À§ÇØ(¿¹: ¿ìÁÖ°ø°£ ¹è°æÀÇ ¿Â¶óÀÎ °ÔÀÓ) FloatTypeÀ» ¾²°í ÀÖ´Ù. º¸´Ù ³·Àº ¿ë·®À» ÇÊ¿ä·Î ÇÏ´Â °æ¿ì Vector3T ´ë½Å
	´Ù¸¥ °´Ã¼ Å¸ÀÔÀ» ¾²´Â °ÍÀ» ±ÇÀåÇÑ´Ù.
	- »çÄ¢ ¿¬»ê ¿¬»êÀÚ¸¦ Áö¿øÇÑ´Ù. µû¶ó¼­ ¾Æ·¡¿Í °°Àº ÄÚµùÀÌ °¡´ÉÇÏ´Ù.

	\~english
	Vector 3D Class
	- The purpose of this class is to avoid platform depedence even though Vector 3 already exists.
	- To increase the accuracy(i.e. Online game with the outer space backgroundw), FloatType is used. If you require the lower specification then we suggest
	to use a different object type rather than Vector 3.
	- This module supports arithmetic operators thus it's possible to code as shown in below.

	\~chinese
	Vector 3D?
	- ?ŞÅêóVector3TÔõ?é©?èâ??îÜ×âë¦ãÀ?Öõù­?øÁ÷»îÜİ¾?¡£
	- ?ÖõÌÚÍÔîÜïá?áã£¨ÖÇ£ºéÔñµÍö?ÛÎÌØîÜ??êı?£©£¬î¤ŞÅéÄFloatType¡£âÍé©ÌÚî¸é»ÕáîÜ?£¬Ëï?Üôé©ŞÅéÄVector3Tì»ãÀĞìöâ?ßÚ?úş¡£
	- ò¨ò¥ŞÌ??ß©?ß©İ¬¡£ì×ó®Ê¦ì¤åıù»?ïï¡£

	\~japanese
	Vector3D«¯«é«¹
	- Vector3TªÊªÉª¬ª¢ªëªËªâ?ªïªéªº¡¢Ü¬ªË?úŞªµªìª¿×âë¦ªÏ¡¢«×«é«Ã«È«Õ«©?«àŞª??ªÎª¿ªáªÇª¹¡£
	- ªèªêÍÔª¤ïáü¬ÓøªÎª¿ªáªË(ÖÇ£ºéÔñµÍöÊàÛÎÌØªÎ«ª«ó«é«¤«ó«²?«à)FloatTypeªòŞÅªÃªÆª¤ªŞª¹¡£ªèªêî¸ª¤é»Õáªòù±é©ªÈª¹ªëíŞùê¡¢Vector3TªÎÓÛªïªêªËöâªÎ«ª«Ö«¸«§«¯«È«¿«¤«×ªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
	- ŞÌöÎæÑß©æÑß©í­ªòò¨êµª·ªŞª¹¡£ªèªÃªÆ¡¢ù»ªÎªèª¦ªÊ«³?«Ç«£«ó«°ª¬Ê¦ÒöªÇª¹¡£

	\~


	\code
	Vector3T a = Vector3T(1,2,3);
	Vector3T b = Vector3T(4,5,6);
	Vector3T c = (a * b) + c - d;
	\endcode

	*/
	template <typename FloatType>
	struct Vector3T
	{
		/// x
		FloatType x;
		/// y
		FloatType y;
		/// z
		FloatType z;
	public:
		inline Vector3T() {};

		inline Vector3T( const FloatType * from)
		{
			x = from[0];
			y = from[1];
			z = from[2];
		}

		inline Vector3T( FloatType x, FloatType y, FloatType z )
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		// casting
		inline operator FloatType* () {
			return &x;
		}
		inline operator const FloatType* () const {
			return &x;
		}

#ifdef _WIN32
		template<typename D3DXVECTOR3>
		__forceinline Vector3T(const D3DXVECTOR3 &from)
		{
			x = from.x;
			y = from.y;
			z = from.z;
		}

		template<typename D3DXVECTOR3>
		__forceinline operator D3DXVECTOR3 const ()
		{
			D3DXVECTOR3 ret;
			ret.x = x;
			ret.y = y;
			ret.z = z;
			return ret;
		}
#endif // _WIN32

		// assignment operators
		inline Vector3T& operator += ( const Vector3T& src )
		{
			x += src.x;
			y += src.y;
			z += src.z;
			return *this;
		}

		inline Vector3T& operator -= ( const Vector3T& src)
		{
			x -= src.x;
			y -= src.y;
			z -= src.z;
			return *this;
		}

		inline Vector3T& operator *= ( FloatType scale)
		{
			x *= scale;
			y *= scale;
			z *= scale;
			return *this;
		}

		inline Vector3T& operator /= ( FloatType scale)
		{
			x /= scale;
			y /= scale;
			z /= scale;
			return *this;
		}

		// unary operators
		inline Vector3T operator + () const
		{			
			return *this;
		}

		inline Vector3T operator - () const
		{
			return Vector3T(-x,-y,-z);			
		}

		// binary operators
		inline Vector3T operator + ( const Vector3T& src) const
		{
			Vector3T ret;
			ret.x = x + src.x;
			ret.y = y + src.y;
			ret.z = z + src.z;

			return ret;
		}

		inline Vector3T operator - ( const Vector3T& src) const
		{
			Vector3T ret;
			ret.x = x - src.x;
			ret.y = y - src.y;
			ret.z = z - src.z;

			return ret;
		}

		inline Vector3T operator * ( FloatType scale) const
		{
			Vector3T ret;
			ret.x = x * scale;
			ret.y = y * scale;
			ret.z = z * scale;

			return ret;
		}

		inline Vector3T operator / ( FloatType scale) const
		{
			Vector3T ret;
			ret.x = x / scale;
			ret.y = y / scale;
			ret.z = z / scale;

			return ret;
		}

		inline bool operator == ( const Vector3T& rhs) const
		{
			return x == rhs.x && y == rhs.y && z == rhs.z;
		}
		inline bool operator != ( const Vector3T& rhs) const
		{
			return x != rhs.x || y != rhs.y || z != rhs.z;
		}

#if defined(_WIN32)        
		__declspec(property(get = GetLengthSq)) FloatType LengthSq;
		__declspec(property(get = GetLength)) FloatType Length;
#endif

		/** 
		\~korean 
		Normal Vector¸¦ ±¸ÇÕ´Ï´Ù.		
		
		\~english 
		Calculates the normal vector. 

		\~chinese
		Ï´Normal Vector¡£

		\~japanese
		Normal VectorªòÏ´ªáªŞª¹¡£
		\~
		*/
		inline Vector3T GetNormal() const
		{
			FloatType length=GetLength();
			return (length==0) ? Vector3T(0,0,0) : (*this) / length;
		}

		/** 
		\~korean 
		±æÀÌÀÇ Á¦°öÀ» ±¸ÇÕ´Ï´Ù.		
		
		\~english 
		Calculate the square value of the length.	

		\~chinese
		Ï´?ÓøîÜøÁÛ°¡£

		\~japanese
		íşªµªÎì£?ªòÏ´ªáªŞª¹¡£
		\~
		*/
		inline FloatType GetLengthSq() const
		{
			return x*x + y*y + z*z;
		}

		/** 
		\~korean 
		vectorÀÇ ±æÀÌ		
		
		\~english 
		Length of the vector

		\~chinese
		Vector îÜ?Óø¡£

		\~japanese
		VectorªÎíşªµ
		\~
		*/
		inline FloatType GetLength() const
		{
			return sqrt(x*x + y*y + z*z);
		}

		/** 
		\~korean 
		µÎ vector¸¦ º¸°£ÇÕ´Ï´Ù.  
		- a + (b - a) * ratio

		\~english 
		Interpolate two vectors.  
		- a + (b - a) * ratio


		\~chinese
		?ìı??vector¡£
		- a + (b - a) * ratio

		\~japanese
		?VectorªòÜÍÊàª·ªŞª¹¡£
		- a + (b - a) * ratio

		\~
		*/
		static inline Vector3T Lerp(const Vector3T &a,const Vector3T &b,FloatType ratio)
		{
			Vector3T ret;
			ret.x=ScalarLerp(a.x,b.x,ratio);
			ret.y=ScalarLerp(a.y,b.y,ratio);
			ret.z=ScalarLerp(a.z,b.z,ratio);
			
			return ret;
		}

		/** 
		\~korean 
		µÎ vectorÀÇ ³»ÀûÀ» ±¸ÇÕ´Ï´Ù 
		
		\~english 
		Calculate the interval of two vectors

		\~chinese
		Ï´??vectorîÜ??¡£

		\~japanese
		?VectorªÎ?îİªòÏ´ªáªŞª¹¡£
		\~
		*/
		static inline FloatType Dot(const Vector3T &a,const Vector3T &b)
		{
			return a.x*b.x+a.y*b.y+a.z*b.z;
		}

		inline FloatType Distance(const Vector3T &a) const
		{
			Vector3T d(a.x - x, a.y - y, a.z - z);
			return d.GetLength();
		}

		inline FloatType Distance2(const Vector3T &a) const
		{
			Vector3T d(a.x - x, a.y - y, a.z - z);
			return d.GetLengthSq();
		}

		/** 
		\~korean 
		º¤ÅÍÀÇ ¹æÇâÀ» À¯ÁöÇÑ Ã¤ ±æÀÌ¸¦ Á¶Á¤ÇÕ´Ï´Ù.

		\~english 
		Sets the length of the vector to a specified length without changing the orientation.

		\~chinese 
		ÜôËÇ?Û°ú¾îÜï×?ù»£¬?öÇ?ò¦ïÒîÜ?ÓøîÜú¾Õá?Óø¡£

		\~japanese
		«Ù«¯«È«ëªÎÛ°ú¾ªòë«ò¥ª·ª¿ªŞªŞªÎíşªµªòğàïÚª·ªŞª¹¡£
		\~
		*/
		inline void SetLength( FloatType length ) 
		{
			Vector3T n = GetNormal();
			n*=length;
			*this = n;
		}


	};

	template <typename FloatType>
	inline Vector3T<FloatType> operator * (FloatType scale, const struct Vector3T<FloatType>& src)
	{
		Vector3T<FloatType> ret;
		ret.x = scale * src.x;
		ret.y = scale * src.y;
		ret.z = scale * src.z;
		return ret;
	}

	typedef Vector3T<double> Vector3;
	typedef Vector3T<float> FloatVector3;


	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif