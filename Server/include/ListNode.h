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

#include "./Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	
	extern const char* ConsistencyProblemText;
	
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	double linked list ¸¦ ±¸¼ºÇÏ´Â nodeÀÌ´Ù.
	- CListOwner ¿¡ ºÙ´Â °æ¿ì¿¡¸¸ ¿¬°á °ü°è¸¦ ±¸¼ºÇÒ ¼ö ÀÖ´Ù. 

	\~english
	node that consist double linked list
	- A linkage can be set only if attached to CListOwner.

	\~chinese
	?à÷double linked listîÜnode¡£
	- ñşêóî¤?éÍ CListOwner%îÜï×?ù»î¦Òö?à÷?ïÈ?Í§¡£

	\~japanese
	double linked listªòÏ°à÷ª¹ªënodeªÇª¹¡£
	- ClistOwnerªËÜõª¯íŞùêªÎªßÖ§Ì¿?ÌõªòÏ°à÷ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£ 
	\~
	*/
	template<typename T>
	class CListNode
	{
	public:	
		class CListOwner
		{
			T* m_first;
			T* m_last;
			int m_count;

			void AssertInThis(bool expResult)
			{
				if (m_enableAssertInThis && !expResult)
					ThrowException(ConsistencyProblemText);
			}

			// ³»ºÎ µ¥ÀÌÅÍ ÀÏ°ü¼º °Ë»ç
			// ÀÌ ÇÔ¼ö´Â ±¸µ¿ÀÌ ´À¸®´Ù. µû¶ó¼­ ²À ÇÊ¿äÇÑ °æ¿ì¿¡¸¸ ±â´ÉÀ» ÄÑÀÚ.
			void AssertConsist()
			{
				if (m_enableAssertInThis)
				{
					T* node = m_first;

					if (m_first == NULL)
					{
						// ÅÖºó °æ¿ìÀÇ °Ë»ç
						AssertInThis(m_count == 0);
						AssertInThis(m_last == NULL);
					}

					while (node != NULL)
					{
						// ³¡±îÁö µ¹¸é¼­ prev-node-next °ü°è ÀÏ°ü¼º °Ë»ç
						AssertInThis(node->m_listOwner == this);

						if (node->m_prev == NULL)
						{
							AssertInThis(m_first == node);
						}
						else
						{
							AssertInThis(node->m_prev->m_next == node);
						}
						if (node->m_next == NULL)
						{
							AssertInThis(m_last == node);
						}
						else
						{
							AssertInThis(node->m_next->m_prev == node);
						}
						node = node->m_next;
					}
				}
			}

		public:
			// ÀÌ °ªÀ» true·Î ¼¼ÆÃÇÏ¸é ÀÏ°ü¼º °Ë»ç¸¦ ÇÏ´Â ·çÆ¾ÀÌ ÀÛµ¿ÇÑ´Ù.
			// ¼º´ÉÀÌ Å©°Ô ¶³¾îÁö¹Ç·Î ÁÖÀÇ ¿ä¸Á.
			// debug or release »ó°ü¾øÀÌ ÄÑ°Å³ª ²ø ¼ö ÀÖ¾î¾ß ÇØ¼­ Ãß°¡µÊ.
			bool m_enableAssertInThis;

			inline CListOwner()
			{
				m_first = NULL;
				m_last = NULL;
				m_count = 0;
				m_enableAssertInThis = false;
			}

			inline ~CListOwner()
			{
				UnlinkAll();
			}

			/**
			\~korean
			¿¬°áµÈ ¸µÅ©¸¦ Á¦°ÅÇÕ´Ï´Ù.

			\~english 
			Removed the connected link 

			\~chinese
			?ğ¶?ïÈîÜ?ïÈ¡£

			\~japanese
			Ö§Ì¿ªµªìª¿«ê«ó«¯ªòğ¶ËÛª·ªŞª¹¡£
			\~
			*/
			inline void UnlinkAll()
			{
				while(!IsEmpty())
				{
					Erase(m_first);
				}
			}

			/**
			\~korean
			³ëµå°¡ ºñ¾ú´ÂÁö È®ÀÎÇÑ´Ù. \return ºñ¾úÀ¸¸é true, ºñ¾îÀÖÁö ¾ÊÀ¸¸é false ¸®ÅÏ

			\~english 
			Check to see if the node is empty. \return Return true if empty, false if not. 
			
			\~chinese
			???ïÃãÀÜúÍö¡£
			\return ÍöîÜ?true£¬ÜôãÀÍöîÜ?Ú÷üŞfalse¡£

			\~japanese
			«Î?«Éª¬Íöª¤ªÆª¤ªëª«ü¬ìãª·ªŞª¹¡£\returnª¬Íöª¤ªÆª¤ªìªĞtrue¡¢Íöª¤ªÆª¤ªÊª±ªìªĞfalseªò«ê«¿?«ó
			\~
			*/
			inline bool IsEmpty() const
			{
				return m_first == NULL;
			}

			// node¸¦ this container¿¡¼­ Á¦°ÅÇÑ´Ù.
			void Erase(T* node)
			{
				// °¢Á¾ °Ë»ç
				AssertInThis(node->m_listOwner == this);

				T* nextNode = node->m_next;
				T* prevNode = node->m_prev;

				if (nextNode == NULL)
				{
					AssertInThis(m_last == node);
				}

				if (prevNode == NULL)
				{
					AssertInThis(m_first == node);
				}

				// µ¥ÀÌÅÍ ¾÷µ¥ÀÌÆ®.
				// ÀÌ·¸°Ô °Ë»ç ±¸°£°ú ¾÷µ¥ÀÌÆ® ±¸°£À» ³ª´©¾î¾ß ºÎºĞ¸¸ º¯°æÇÏ´Ù ¸¶´Â »çÅÂ ¿¹¹æ.
				if (nextNode != NULL)
					nextNode->m_prev = prevNode;

				if (prevNode != NULL)
					prevNode->m_next = nextNode;

				if (nextNode == NULL)
				{
					m_last = prevNode;
				}

				if (prevNode == NULL)
				{
					m_first = nextNode;
				}

				node->m_prev = NULL;
				node->m_next = NULL;
				node->m_listOwner = NULL;

				m_count--;

				AssertConsist();
			}

			// prevNodeÀÇ µÚ¿¡ node¸¦ Ãß°¡ÇÑ´Ù.
			// prevNode=nullÀÌ¸é ¸Ç ¾Õ¿¡ Ãß°¡ÇÑ´Ù.
			void Insert(T* prevNode, T* node)
			{
				// ÁÖÀÇ: °Ë»ç¸¦ ¸ğµÎ ¸¶Ä¡±â Àü¿¡´Â µ¥ÀÌÅÍ º¯ÇüÀ» °¡ÇÏÁö ¸» °Í
				AssertInThis(node->m_listOwner == NULL);

				if (prevNode == NULL)
				{
					// ¸Ç ¾Õ¿¡ Ãß°¡
					if (m_first != NULL)
					{
						m_first->m_prev = node;
						node->m_next = m_first;
						m_first = node;
					}
					else
					{
						m_first = m_last = node;
					}
				}
				else
				{
					// prevNode µÚ¿¡ Ãß°¡
					AssertInThis(prevNode->m_listOwner == this);

					T* node_next = prevNode->m_next;
					prevNode->m_next = node;
					node->m_prev = prevNode;
					node->m_next = node_next;
					if (node_next == NULL)
					{
						// prevNode´Â last¿´´Ù. ÀÌÁ¦ node°¡ last°¡ µÇ¾î¾ß ÇÑ´Ù.
						m_last = node;
					}
					else
					{
						// nextÀÇ »óÅÂµµ °»½ÅÇØ¾ß
						node_next->m_prev = node;
					}
				}
				node->m_listOwner = this;
				m_count++;
				AssertConsist();
			}

			// ¸Ç µÚ¿¡ Ãß°¡ÇÑ´Ù.
			inline void PushBack(T* node)
			{
				Insert(m_last, node);
			}

			/* ±âÁ¸ ³ëµåÀÇ À§Ä¡¿¡ »õ·Î¿î ³ëµå·Î ±³Ã¼ÇÑ´Ù.
			node: ±âÁ¸ ³ëµå newNode º¯°æÇÒ ³ëµå */
			inline void Replace(T* node, T* newNode)
			{
				T* prev = node->m_prev;

				// ¾Æ·¡ erase-insert°¡ partially doneÀÌ µÇ¸é ¾ÈµÇ¹Ç·Î ¿©±â¼­ »çÀü °Ë»ç¸¦ ´Ù ÇØ¹ö·Á¾ß ÇÑ´Ù.
				AssertInThis(node->m_listOwner == this);
				AssertInThis(newNode->m_listOwner == NULL);

				Erase(node);
				Insert(prev, newNode);
			}

			/**
			\~korean
			first ³ëµå¸¦ ¸®ÅÏ¹Ş½À´Ï´Ù.

			\~english 
			Get the first node returned

			\~chinese
			Ú÷üŞïÈâ¥first?ïÃ¡£

			\~japanese
			first «Î?«Éªò«ê«¿?«óª·ªÆªâªéª¤ªŞª¹¡£
			\~
			*/
			inline T* GetFirst() const
			{
				return (T*)m_first;
			}

			/**
			\~korean
			last³ëµå¸¦ ¸®ÅÏ¹Ş½À´Ï´Ù.

			\~english 
			Get the last node returned

			\~chinese
			Ú÷üŞïÈâ¥last?ïÃ¡£

			\~japanese
			last«Î?«Éªò«ê«¿?«óª·ªÆªâªéª¤ªŞª¹¡£
			\~
			*/
			inline T* GetLast() const
			{
				return (T*)m_last;
			}

			/**
			\~korean
			¿¬°áµÇ¾î ÀÖ´Â ³ëµåÀÇ Ä«¿îÆ®¸¦ ¸®ÅÏ¹Ş½À´Ï´Ù.

			\~english 
			Get the count of the connected node

			\~chinese
			Ú÷üŞïÈâ¥ì«?ïÈîÜ?ïÃîÜ?¡£

			\~japanese
			Ö§Ì¿ªµªìªÆª¤ªë«Î?«ÉªÎ«««¦«ó«Èªò«ê«¿?«óª·ªÆªâªéª¤ªŞª¹¡£
			\~
			*/
			inline int GetCount() const
			{
				return m_count;
			}

#if defined(_MSC_VER)
			__declspec(property(get=GetCount)) int Count;
#endif
		};

	private:
		friend class CListOwner;
		T* m_prev, *m_next;
		CListOwner* m_listOwner;

	public:
		inline CListNode(void)
		{
			m_prev = NULL;
			m_next = NULL;
			m_listOwner = NULL;
		}

		inline ~CListNode(void)
		{
			if(m_listOwner!=NULL)
				m_listOwner->Erase((T*)this);
		}

		/**
		\~korean
		ÀÌ node¸¦ °¡Áö°í ÀÖ´Â owner¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		Return the owner who has this node

		\~chinese
		Ú÷üŞ?êóó®nodeîÜwoner¡£

		\~japanese
		ª³ªÎnodeªòò¥ªÃªÆª¤ªëownerªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline CListOwner* GetListOwner() const 
		{
			return m_listOwner;
		}

		/**
		\~korean
		´ÙÀ½³ëµå¸¦ ¸®ÅÏ¹Ş½À´Ï´Ù.

		\~english 
		Get the next node returned

		\~chinese
		Ú÷üŞïÈâ¥ñıı¨îÜ?ïÃ¡£

		\~japanese
		ó­ªÎ«Î?«Éªò«ê«¿?«óª·ªÆªâªéª¤ªŞª¹¡£
		\~
		*/
		inline T* GetNext() const
		{
			return (T*)m_next;
		}

		/**
		\~korean
		ÀÌÀü ³ëµå¸¦ ¸®ÅÏ¹Ş½À´Ï´Ù.

		\~english 
		Get the previous node returned

		\~chinese
		Ú÷üŞïÈâ¥ñıîñîÜ?ïÃ¡£

		\~japanese
		ì¤îñªÎ«Î?«Éªò«ê«¿?«óª·ªÆªâªéª¤ªŞª¹¡£
		\~
		*/
		inline T* GetPrev() const
		{
			return (T*)m_prev;
		}

		/* \~korean owner ¿ÍÀÇ ¸µÅ©¸¦ Á¦°ÅÇÕ´Ï´Ù. \~english Remove the link with the owner \~chinese ?ğ¶?ownerîÜ?ïÈ¡£
		\~japanese ownerªÈªÎ«ê«ó«¯ªòğ¶ËÛª·ªŞª¹¡£
		ÀÌ°Å Åğ¿ª ??÷Üæµ
		inline void UnlinkSelf()
		{
			if(m_pListOwner!=NULL)
				m_pListOwner->Erase((T*)this);
		}
\~
*/
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
