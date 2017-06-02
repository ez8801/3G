/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
/*
ProudNet 1.8.38132-dev012


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

#if defined(_WIN32)

#include "BasicTypes.h"
#include "FakeClr.h"
#include "DataTree.h"
#include "FastMap.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup db_group
	*  @{
	 */

    class CDbCacheClient3Impl;
    class CDbCacheServer3Impl;
	class CLoadedDataTree;

	typedef RefCount<CLoadedDataTree> CLoadedDataTreePtr;
	typedef CFastMap<Guid, CDataTreePtr> DataTreeMap;
	typedef CFastList<CDataTreePtr> DataTreeList;

    class CLoadedDataTree
    {
        friend CDbCacheClient3Impl;
        friend CDbCacheServer3Impl;
        
	private:
		// forest¸¦ Á÷Á¢ ¼ÒÀ¯ÇÔ. 
		CDataTree*	m_Root;
		// forest¿¡¼­ guid¸¦ Å°·Î »¡¸® Ã£°Ô ÇÏ±â À§ÇÔ
		DataTreeMap		m_DataTreeMap;
		// DB¿¡ delete Äõ¸®·Î ´øÁ®Á®¾ß ÇÏ´Â ³ëµåµé
		DataTreeList	m_removeDataTreeList;

		/*
		\~korean
		ÀÌ°ÍÀ» ·ÎµùÇÑ DB cache client°¡ º¸³»ÁØ session ÀÎ½ÄÀÚ

		\~english
		Session identifier that sent by loaded DB cache client

		\~chinese
		??Ê¥?îÜDB cache client?áêîÜsessionîÜ??íº¡£
                
		\~japanese
		ª³ªìªò«í?«Ç«£«ó«°ª·ª¿DB cache clientª¬áêªÃªÆª¯ªìª¿sessionìããÛí­
		\~
		*/
		Guid m_INTERNAL_sessionGuid;

        CReaderWriterAccessChecker m_RWAccessChecker;


		inline int	GetRemoveCount(){ return (int)m_removeDataTreeList.GetCount(); }

		int _INTERNAL_NOACCESSMODE_GetDirtyCount();		
		CDataTreePtr _INTERNAL_NOACCESSMODE_GetNode(const Guid& guid);
		Proud::ErrorType _INTERNAL_NOACCESSMODE_CheckNode(CDataTreePtr node);

		Proud::ErrorType _INTERNAL_NOACCESSMODE_InsertChild(CDataTreePtr parent, CDataTreePtr newNode);
// 		Proud::ErrorType _INTERNAL_NOACCESSMODE_InsertSiblingAfter(CDataTreePtr sibling, CDataTreePtr newNode);
// 		Proud::ErrorType _INTERNAL_NOACCESSMODE_InsertSiblingBefore(CDataTreePtr sibling, CDataTreePtr newNode);
		CDataTree* _INTERNAL_NOACCESSMODE_GetEndSibling(CDataTree* node);

		Proud::ErrorType _INTERNAL_NOACCESSMODE_RemoveNode(CDataTreePtr node, bool addremovelist);
		Proud::CDataTreePtr _INTERNAL_NOACCESSMODE_GetRemoveNode(Proud::Guid &removeUUID);
		Proud::ErrorType _INTERNAL_NOACCESSMODE_AddRemoveDataTreeList(CDataTreePtr node);
		
		void _INTERNAL_NOACCESSMODE_SerializeToMessage(CMessage &msg);
		void _INTERNAL_NOACCESSMODE_DeserializeFromMessageToChangeList(CMessage &msg);
		
		Proud::ErrorType _INTERNAL_NOACCESSMODE_MoveDataTree(CDataTreePtr nodeToMove, CLoadedDataTree& destForest, CDataTreePtr& destParentNode);
		void _INTERNAL_NOACCESSMODE_RecursiveUpdateRootUUID(Proud::Guid& RootUUID, CDataTree* Node);
		void _INTERNAL_NOACCESSMODE_RecursiveRemove(CDataTree *node);
		void _INTERNAL_NOACCESSMODE_RecursiveAdd(CDataTreePtr node, DataTreeMap * destMap);
		
		void _INTERNAL_NOACCESSMODE_DeleteAll();

		void _INTERNAL_NOACCESSMODE_CopyTo(CLoadedDataTree& to);
		void _INTERNAL_NOACCESSMODE_CopyTo_Diff(CLoadedDataTree& to);
		void _INTERNAL_NOACCESSMODE_ClearChangeNode();

		CLoadedDataTree & CLoadedDataTree::operator=(const CLoadedDataTree& from);

    protected:
        virtual void	AssertThreadID(eAccessMode eMode) const;
        virtual void	ClearThreadID() const;
        
	protected:
		PROUDSRV_API virtual void Change_Serialize(CMessage& msg,bool isReading);
		PROUDSRV_API virtual CDataTreePtr GetRemoveNode(Proud::Guid removeUUID);

		PROUDSRV_API virtual void Serialize( CMessage& msg,bool isReading );
		PROUDSRV_API void CopyTo_NoChildren(CLoadedDataTree* output);

    public:
        CLoadedDataTree();
		CLoadedDataTree(const CLoadedDataTree& from);
        PROUDSRV_API virtual ~CLoadedDataTree();
		/** 
		\~korean
		nodeToMove ³ëµå¸¦ destForestÀÇ destParentNode ÇÏÀ§ ³ëµå·Î ÀÌµ¿ ½ÃÅµ´Ï´Ù. 
		nodeToMoveÀÇ OwnerUUID,RootUUID°¡ º¯°æµÇ°í
		nodeToMoveÀÇ ÇÏÀ§ ³ëµåÀÇ RootUUID°¡ destForestÀÇ RootUUID·Î º¯°æµË´Ï´Ù.

		\param destForest destParentNode°¡ ¼ÓÇØÀÖ´Â Forest
		\param nodeToMove ÀÌµ¿½ÃÅ³ ³ëµå
		\param destParentNode ÀÌµ¿½ÃÅ³ ³ëµåÀÇ Owner Node
		\return ¼º°øÀûÀ¸·Î ÀÌµ¿ÇÏ¸é ErrorType_Ok¸¦ ¸®ÅÏÇÕ´Ï´Ù. ±× ÀÌ¿Ü¿¡´Â ´Ù¸¥ ¿À·ù °ªÀÌ ¸®ÅÏµË´Ï´Ù.

		\~english 
		Move nodetoMove node to the lower node of destparentNode of destForest. 
		OwnerUUID,RootUUID of nodeToMove is changed and 
		RootUUID of the lower node of nodeToMove is changed to RootUUID of destForest
		\param destForest Forest where destParentNode belongs to
		\param nodeToMove ÀÌµ¿½ÃÅ³ ³ëµå Node to be moved 
		\param destParentNode Owner node of the node to be moved 
		\return When moved successfully, it returns ErrorType_Ok. Otherwise another error value is returned. 

		\~chinese
		÷ênodeToMove?ïÃì¹?ÓðdestForestîÜdestParentNodeù»ìé??ïÃ¡£ 
		nodeToMoveîÜOwnerUUID,RootUUID???ÌÚ
		nodeToMoveîÜù»ìé??ïÃîÜRootUUID?ÌÚ?destForestîÜRootUUID¡£

		\paramdestForestdestParentNodeøÐùßîÜForest
		\paramnodeToMove é©ì¹?îÜ?ïÃ
		\paramdestParentNode é©ì¹?îÜ?ïÃîÜOwner Node
		\return à÷Ííì¹?ñýý¨Ú÷üÞErrorType_Ok¡£Üú?Ú÷üÞÐìöâ???¡£
		
		\~japanese
		nodeToMove «Î?«ÉªòdestForestªÎdestParentNodeù»êÈ«Î?«ÉªËì¹ÔÑªµª»ªÞª¹¡£
		nodeToMoveªÎOwnerUUID,RootUUIDª¬?ÌÚªµªìªÆ¡¢
		nodeToMoveªÎù»êÈ«Î?«ÉªÎRootUUIDª¬destForestªÎRootUUIDªË?ÌÚªµªìªÞª¹¡£

		\param destForest destParentNodeª¬?ª·ªÆª¤ªëForest
		\param nodeToMove ì¹ÔÑªµª»ªë«Î?«É
		\param destParentNode ì¹ÔÑªµª»ªë«Î?«ÉªÎOwner Node
		\return ì¹ÔÑªËà÷Ííª·ª¿ªéErrorType_Okªò«ê«¿?«óª·ªÞª¹¡£ª½ªÎöâªËªÏöâªÎ«¨«é?ö·ª¬«ê«¿?«óªµªìªÞª¹¡£
		\~
		*/
		Proud::ErrorType MoveDataTree(CLoadedDataTree& destForest, CDataTreePtr nodeToMove, CDataTreePtr destParentNode);
	
		/** 
		\~korean
		parent ÀÇ ¸¶Áö¸· ÀÚ½Ä ³ëµå·Î¼­ newNode¸¦ ³Ö½À´Ï´Ù. parent=NULLÀÎ °æ¿ì ÃÖ»ó´ÜÀÇ ³ëµå·Î¼­ newNode°¡ Ãß°¡µË´Ï´Ù.

		\param parent ¸¸¾à NULLÀÎ °æ¿ì CPropTree ÀÇ ÃÖ»óÀ§ ·¹º§ÀÇ ¸Ç ¸¶Áö¸· ³ëµå·Î ºÙ½À´Ï´Ù.
		\param newNode »õ·Î Ãß°¡ÇÒ ³ëµå. ¾î¶°ÇÑ CPropForest ¿¡µµ ÀÌ¹Ì Á¾¼ÓµÈ »óÅÂÀÌ¾î¼­´Â ¾ÈµË´Ï´Ù. ÀÌ¸¦ ¾î±â¸é ¿À·ù °ªÀ» ¸®ÅÏÇÕ´Ï´Ù.
		\return ¼º°øÀûÀ¸·Î Ãß°¡ÇÏ¸é ErrorType_Ok ¸¦ ¸®ÅÏÇÕ´Ï´Ù. ±× ÀÌ¿Ü¿¡´Â ´Ù¸¥ ¿À·ù °ªÀÌ ¸®ÅÏµË´Ï´Ù.

		\~english
		Enters newNode as the last child node of parent. If parent=NULL then newNode will be added as the top node.
		If the newNode already has other child nodes then all of them will enter CPropForest all together.

		\param parent If it is equal to NULL then it will be attached as the last node of the top most node of CPropTree.
		\param newNode The node to be added newly. It must not be dependent to any CPropForest. If so, an error value will be returned.
		\return Returns ErrorType_Ok if successfuly added. Otherwise, a different error value will be returned.

		\~chinese
		ì×?ãÀParentîÜõÌý¨ìé?í­í­Ò³?ïÃnode,é©Û¯ìýnewNode¡£parent=NULL?£¬ì×?ãÀõÌß¾Ó®?ïÃnodeì¤á¶ì¤ôÕÊ¥newNode¡£

		\param parent åýÍýãÀNULLîÜ?ý¦£¬ CPropTree%îÜõÌß¾êÈ??îÜõÌý¨ìé?node?ïÄ?¡£
		\param newNode é©ôÕÊ¥îÜãænode¡£
		ÜôÎ·ãÀä§??îÜ CPropForest%×ìì«?????îÜ?ãÀÜôú¼îÜ¡£?ÛÎ?ìéïÃÚ÷üÞ????¡£
		\return à÷ÍíîÜôÕÊ¥îÜ?ErrorType_OkÊ¦ì¤Ú÷üÞ¡£ð¶ó®ñýèâ?îÜ???Ú÷üÞ¡£

		\~japanese
		ParentªÎõÌý­ªÎí­«Î?«ÉªÈª·ªÆnewNodeªòìýªìªÞª¹¡£parent=NULLªÎíÞùê¡¢õÌß¾Ó«ªÎ«Î?«ÉªÈª·ªÆnewNodeª¬õÚÊ¥ªµªìªÞª¹¡£
		
		\param parent ªâª·¡¢NULLªÇª¢ªëíÞùê¡¢CPropTreeªÎõÌß¾êÈ«ì«Ù«ëªÎõÌý­«Î?«ÉªËÜõª­ªÞª¹¡£
		\param newNode ãæª¿ªËõÚÊ¥ª¹ªë«Î?«É¡£ª¤ª«ªÊªëCPropForestªËªâ?ªË??ªµªìª¿?÷¾ªËªÊªÃªÆªÏª¤ª±ªÞª»ªó¡£ª³ªìªòáúªéªÊª±ªìªÐ«¨«é?ö·ªò«ê«¿?«óª·ªÞª¹¡£
		\return õÚÊ¥ªËà÷Ííª·ª¿ªéErrorType_Okªò«ê«¿?«óª·ªÞª¹¡£ª½ªÎöâªËªÏöâªÎ«¨«é?ö·ª¬«ê«¿?«óªµªìªÞª¹¡£
		\~
		*/
        PROUDSRV_API Proud::ErrorType InsertChild(CDataTreePtr parent, CDataTreePtr newNode);

		/** 
		\~korean
		ÀÌ °´Ã¼ÀÌ ÀÌ¹Ì ºÙ¾îÀÖ´ø CDataTree °´Ã¼¸¦ ºÐ¸®ÇØ³À´Ï´Ù.
		ºÐ¸®µÈ nodeÀÇ childµµ CPropForest ·ÎºÎÅÍ ºÐ¸®µË´Ï´Ù. ÇÏÁö¸¸ ºÐ¸®µÈ nodeÀÇ childµéÀº node¿ÍÀÇ ÀÚ½Ä°ü°è¸¦ °è¼Ó À¯ÁöÇÕ´Ï´Ù.

		\param node ºÐ¸®ÇÒ ³ëµåÀÔ´Ï´Ù. ÀÌ CPropForest ¿¡ Á¾¼ÓµÇ¾î ÀÖ¾î¾ß ÇÕ´Ï´Ù.ÀÌ¸¦ ¾î±â¸é ¿À·ù °ªÀ» ¸®ÅÏÇÕ´Ï´Ù.
		\param addremovelist removeDataTreeList ¿¡ Ãß°¡ÇÒÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù. true ·Î ¼ÂÆÃÇÏ½ÅÈÄ UpdateData¸¦ È£ÃâÇÏ¸é ÀÚµ¿À¸·Î DBMS¿¡¼­ »èÁ¦µË´Ï´Ù.
		\return ¼º°øÀûÀ¸·Î Á¦°ÅÇÏ¸é ErrorType_Ok ¸¦ ¸®ÅÏÇÕ´Ï´Ù. ±× ÀÌ¿Ü¿¡´Â ´Ù¸¥ ¿À·ù °ªÀÌ ¸®ÅÏµË´Ï´Ù.

		\~english 
		Separate the CDataTree object already attached to this object. 
		The child of the separated node is separated from CPropForest. However, the children of the separated node still maintain the parent and child relationship with the node. 

		\param node Node to be separated. It must be subordinated to this CPropForest. 
		\param addremovelist This is whether to add to removePropNodelist. After setting it to true and calling UpdateData, it is automatically deleted from DBMS. 
		\return When deleted successfully, it returns ErrorType_Ok. Otherwise another error value is returned. 

		\~chinese
		???ßÚÊ¦ì¤ÝÂ?ì«?ïÄ??îÜ CDataTree%îÜ?ßÚ¡£
		ÝÂ?îÜnodeîÜchild? CPropForest%ÝÂ?õó?¡£Ó£ãÀÝÂ?nodeîÜchild??node???ò¥í­Ò³?Í§¡£

		\param node âÍé©ÝÂ?îÜnode¡£?? CPropForest%ì«??éÍ????¡£?ÛÎ?ìéïÃÚ÷üÞ????¡£
		\param addremovelist removeDataTreeListãÀÜúé©ôÕÊ¥îÜ?Üú¡£ True?ïÒý¨û¼Ð£UpdateDataîÜ?í»?î¤DBMS?ð¶¡£
		\return à÷ÍíîÜ?ð¶îÜ?Ú÷üÞErrorType_Ok¡£ð¶ó®ñýèâ?îÜ???Ú÷üÞ¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«Èª¬?ªËªÄª¤ªÆª¤ª¿CPropNode«ª«Ö«¸«§«¯«ÈªòÝÂ×îª·ªÞª¹¡£
		ÝÂ×îªµªìª¿nodeªÎchildªâCPropForestª«ªéÝÂ×îªµªìªÞª¹¡£ª·ª«ª·¡¢ÝÂ×îªµªìª¿nodeªÎchildªÏnodeªÈªÎöÑí­?Ìõªò?ª±ªÆë«ò¥ª·ªÞª¹¡£
		\param node ÝÂ×îª¹ªë«Î?«ÉªÇª¹¡£ª³ªÎCPropForestªË??ªµªìªÆª¤ªÊª±ªìªÐªÊªêªÞª»ªó¡£ª³ªìªòáúªéªÊª±ªìªÐ«¨«é?ö·ªò«ê«¿?«óª·ªÞª¹¡£
		\param addremovelist removePropNodelist ªËõÚÊ¥ª¹ªëª«ªÉª¦ª«ªÇª¹¡£TrueªËàâïÒª·ª¿ý­¡¢UpdateDataªòû¼ªÓõóª¹ªÈí»ÔÑªËDBMSª«ªéÞûð¶ªµªìªÞª¹¡£
		\return ð¶ËÛªËà÷Ííª·ª¿ªéErrorType_Okªò«ê«¿?«óª·ªÞª¹¡£ª½ªÎöâªËªÏöâªÎ«¨«é?ö·ª¬«ê«¿?«óªµªìªÞª¹¡£
		\~
		*/
        PROUDSRV_API virtual Proud::ErrorType RemoveNode(CDataTreePtr node, bool addremovelist=true);

		/** 
		\~korean
		RemoveNode(node)¿Í °°Àº ±â´ÉÀ» ÇÏÁö¸¸, UUID·Î µ¿ÀÛ ÇÕ´Ï´Ù.

		\param removeUUID Á¦°ÅÇÒ Node UUID
		\param addremovelist removeDataTreeList¿¡ Ãß°¡ÇÒÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù. true ·Î ¼ÂÆÃÇÏ½ÅÈÄ UpdateData¸¦ È£ÃâÇÏ¸é ÀÚµ¿À¸·Î DBMS¿¡¼­ »èÁ¦µË´Ï´Ù.
		\return ¼º°øÀûÀ¸·Î Á¦°ÅÇÏ¸é ErrorType_Ok ¸¦ ¸®ÅÏÇÕ´Ï´Ù.±× ÀÌ¿Ü¿¡´Â ´Ù¸¥ ¿À·ù °ªÀÌ ¸®ÅÏµË´Ï´Ù.

		\~english 
		It has the same function as RemoveNode(node) but operates as UUID. 
		\param Node UUID to be deleted
		\param This is whether to add to removePropNodelist. After setting it to true and calling UpdateData, it is automatically deleted from DBMS. 
		\return When deleted successfully, it returns ErrorType_Ok. Otherwise another error value is returned.

		\param removeUUID Node UUID that will be removed.

		\return Once it successfully removed then return ErrorType_Ok instead of this case, other error value will be returned.

		\~chinese
		?æÔ?RemoveNode(node) ìé?îÜÐüÒö£¬Ó£ãÀì¤UUID???¡£

		\param removeUUID é©?ð¶îÜNode UUID
	        \param addremovelist ãÀÜúé©ôÕÊ¥ÓðremoveDataTreeListîÜ?Üú¡£True?ïÒý¨û¼Ð£UpdateDataîÜ?í»?î¤DBMS?ð¶¡£
	        \return à÷ÍíîÜö¢á¼îÜ?ErrorType_OkÊ¦ì¤Ú÷üÞ¡£ð¶ó®ñýèâ?îÜ???Ú÷üÞ¡£

		\~japanese
		RemoveNode(node)ªÎªèª¦ªÊÑ¦Òöªòª·ªÞª¹ª¬¡¢UUIDªÇÔÑíÂª·ªÞª¹¡£
		\param removeUUID ð¶ËÛª¹ªë Node UUID
		\param addremovelist removePropNodelistªËõÚÊ¥ª¹ªëª«ªÉª¦ª«ªÇª¹¡£trueªËàâïÒª·ª¿ý­¡¢UpdateDataªòû¼ªÓõóª¹ªÈí»ÔÑªËDBMSª«ªéÞûð¶ªµªìªÞª¹¡£
		\return ð¶ËÛªËà÷Ííª·ª¿ªéErrorType_Okªò«ê«¿?«óª·ªÞª¹¡£ª½ªÎöâªËªÏöâªÎ«¨«é?ö·ª¬«ê«¿?«óªµªìªÞª¹¡£
		\~
		*/
		PROUDSRV_API virtual Proud::ErrorType RemoveNode(Proud::Guid removeUUID, bool addremovelist=true);

		/** 
		\~korean
		guid¿¡ ÇØ´çÇÏ´Â node¸¦ ¸®ÅÏ ÇÕ´Ï´Ù.°Ë»ö ¿ëµµ·Î »ç¿ëµË´Ï´Ù.
		\param guid Ã£¾Æ³¾ nodeÀÇ uuid
		\return ¼º°øÀûÀÌ¶ó¸é, node¸¦ ¸®ÅÏ ÇÕ´Ï´Ù. NULL ÀÌ¶ó¸é ¾ø´Â node ÀÔ´Ï´Ù.

		\~english
		Return node that as guid. It will use for searching.
		\param UUID of node that find out guid
		\return If it succeed, return node. If it is NULL, it is not exsit node.

		\~chinese
		GuidßÓ?îÜnodeÚ÷üÞ¡£ÎÁéÄâ¤ßãÍíÒö¡£
		\param guid âÍé©?îÜnodeîÜuuid¡£
		\return à÷ÍíîÜ?nodeÚ÷üÞ£¬NULLîÜ??êónode¡£

		\~japanese
		GuidªËú±?ª¹ªënodeªò«ê«¿?«óª·ªÞª¹¡£?ßãéÄªÈªÇÞÅªïªìªÞª¹¡£
		\param guid Ì¸ªÄª±õóª¹nodeªÎuuid
		\return à÷ÍíªÊªé¡¢nodeªò«ê«¿?«óª·ªÞª¹¡£NULL ªÊªé¡¢Ùíª¤nodeªÇª¹¡£
		\~
		*/
		PROUDSRV_API virtual CDataTreePtr GetNode(const Guid& guid);
		
		/** 
		\~korean
		ÀÌ °´Ã¼°¡ °¡Áö°í ÀÖ´Â ÃÖ»óÀ§ µ¥ÀÌÅÍ ³ëµå¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		\return ¼º°øÀûÀÌ¶ó¸é, ÃÖ»óÀ§ ³ëµå¸¦ ¸®ÅÏÇÕ´Ï´Ù. ½ÇÆÐ¶ó¸é ºñ¾î ÀÖ´Â CDataTreePtr À» ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		It returns top data node that this object owned.
		\return If it is succeed, return top node. If it is failed, return an empty CDataTreePtr.

		\~chinese
		???ßÚ?êóîÜÚ÷üÞõÌß¾êÈ?Ëßnode¡£
		\return à÷ÍíîÜ?£¬Ú÷üÞÓðõÌß¾êÈnode¡£ã÷?îÜ?Ú÷üÞÓðÍöîÜ CDataTreePtr%¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«Èª¬ò¥ªÃªÆª¤ªëõÌß¾êÈ«Ç?«¿«Î?«Éªò«ê«¿?«óª·ªÞª¹¡£
		\return à÷ÍíªÊªé¡¢õÌß¾êÈ«Î?«Éªò«ê«¿?«óª·ªÞª¹¡£ã÷ø¨ªÊªéÍöª¤ªÆª¤ªëCPropNodePtrªò«ê«¿?«óª·ªÞª¹¡£
		\~
		*/
        PROUDSRV_API virtual CDataTreePtr GetRootNode();

		/** 
		\~korean
		ÀÌ °´Ã¼°¡ °¡Áö°í ÀÖ´Â ÃÖ»óÀ§ µ¥ÀÌÅÍ ³ëµåÀÇ UUID¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		It returns top data node that this object owned.

		\~chinese
		Ú÷üÞÓð???ßÚ?êóîÜõÌß¾êÈ?Ëß?ïÃîÜUUID¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«Èª¬ò¥ªÃªÆª¤ªëõÌß¾êÈ«Ç?«¿«Î?«ÉªÎUUIDªò«ê«¿?«óª·ªÞª¹¡£
		\~
		*/
        PROUDSRV_API Guid GetRootUUID();

		/** 
		\~korean
		Session Guid¸¦ ¾ò´Â´Ù.

		\~english TODO:translate needed.

		\~chinese
		ö¢ÔðSession Guid¡£

		\~japanese
		Session GuidªòÔðªÞª¹¡£
		\~
		*/
		PROUDSRV_API Guid GetSessionGuid() const;

		/** 
		\~korean
		\param val SessionGuid¸¦ ¼³Á¤ÇÑ´Ù.

		\~english
		Set SessionGuid.

		\~chinese
		\param val ?öÇSessionGuid¡£

		\~japanese
		\param val SessionGuidªòàâïÒª·ªÞª¹¡£
		\~
		*/
		PROUDSRV_API void SetSessionGuid(Guid val);

#if defined (_MSC_VER)
		__declspec(property(get=GetSessionGuid,put=SetSessionGuid)) Guid sessionGuid;
		__declspec(property(get=GetRootUUID)) Guid RootUUID;
#endif

		/** 
		\~korean
		µ¥ÀÌÅÍ¸¦ º¹»çÇÏ¿© ´Ù¸¥ °´Ã¼¸¦ ¸¸µì´Ï´Ù.

		\~english
		Create other object to copy data.

		\~chinese
		?Ëß?ð¤ý¨ð¤íÂ?îÜ?ßÚ¡£

		\~japanese
		«Ç?«¿ªò«³«Ô?ª·ªÆöâªÎ«ª«Ö«¸«§«¯«ÈªòíÂªêªÞª¹¡£
		\~
		*/
		PROUDSRV_API CLoadedDataTreePtr Clone();

		/** 
		\~korean
		³»ºÎ µ¥ÀÌÅÍ¸¦ ByteArray ·Î ´ã½À´Ï´Ù.
		\param output µ¥ÀÌÅÍ°¡ ´ã±æ ByteArray °´Ã¼ ÀÔ´Ï´Ù.

		\~english
		Put internal data to ByteArray.
		\param ByteArray object for output data.

		\~chinese
  		???Ý»?Ëß ByteArray¡£
		\param output é©?ìýîÜ?Ëß ByteArray%?ßÚ¡£

		\~japanese
		?Ý»«Ç?«¿ªò ByteArrayªËìýªìªÞª¹¡£
		\param output «Ç?«¿ª¬ìýªëByteArray«ª«Ö«¸«§«¯«ÈªÇª¹¡£

		\~
		*/
		PROUDSRV_API void ToByteArray(ByteArray& output);
		/** 
		\~korean
		input·Î ºÎÅÍ µ¥ÀÌÅÍ¸¦ º¹»çÇÕ´Ï´Ù.

		\param input µ¥ÀÌÅÍ°¡ ´ã±ä ByteArray °´Ã¼ ÀÔ´Ï´Ù.

		\~english
		Copy data from input.

		\param ByteArray object that has input data.

		\~chinese
		?input?ð¤?Ëß¡£
		
		\param input ì«ù¬?ìýîÜ?Ëß ByteArray%?ßÚ¡£

		\~japanese
		Inputª«ªé«Ç?«¿ªò«³«Ô?ª·ªÞª¹¡£
		\param input «Ç?«¿ª¬ìýªëByteArray«ª«Ö«¸«§«¯«ÈªÇª¹¡£
		\~
		*/
		PROUDSRV_API void FromByteArray(const ByteArray& input);
		
		// Æ®¸®ÀÇ consistent ¸¦ È®ÀÎ ÇÏ±â À§ÇØ¼­.
/*		PROUDSRV_API bool IsConsistent();*/

		/** 
		\~korean
		DBCacheServer2¿¡¼­ ³»ºÎÀûÀ¸·Î »ç¿ëÇÏ´Â ÇÔ¼öµé ÀÔ´Ï´Ù.
		- »ç¿ëÀÚ´Â »ç¿ëÇÏÁö ¸»¾Æ ÁÖ¼¼¿ä.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2×ìãÀ?Ý»ÞÅéÄîÜùÞ?¡£
		- éÄ??Üôé©ÞÅéÄ¡£

		\~japanese
		DBCacheServer2ªÇ?Ý»îÜªËÞÅª¦??ªÇª¹¡£
		- «æ?«¶?ªÏÞÅªïªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		PROUDSRV_API virtual void _INTERNAL_ClearChangeNode();

		/** 
		\~korean
		DBCacheServer2¿¡¼­ ³»ºÎÀûÀ¸·Î »ç¿ëÇÏ´Â ÇÔ¼öµé ÀÔ´Ï´Ù.
		- »ç¿ëÀÚ´Â »ç¿ëÇÏÁö ¸»¾Æ ÁÖ¼¼¿ä.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2×ìãÀ?Ý»ÞÅéÄîÜùÞ?¡£
		- éÄ??Üôé©ÞÅéÄ¡£

		\~japanese
		DBCacheServer2ªÇ?Ý»îÜªËÞÅª¦??ªÇª¹¡£
		- «æ?«¶?ªÏÞÅªïªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		PROUDSRV_API virtual void _INTERNAL_ChangeToByteArray(ByteArray& outArray);

		/** 
		\~korean
		DBCacheServer2¿¡¼­ ³»ºÎÀûÀ¸·Î »ç¿ëÇÏ´Â ÇÔ¼öµé ÀÔ´Ï´Ù.
		- »ç¿ëÀÚ´Â »ç¿ëÇÏÁö ¸»¾Æ ÁÖ¼¼¿ä.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2×ìãÀ?Ý»ÞÅéÄîÜùÞ?¡£
		- éÄ??Üôé©ÞÅéÄ¡£

		\~japanese
		DBCacheServer2ªÇ?Ý»îÜªËÞÅª¦??ªÇª¹¡£
		- «æ?«¶?ªÏÞÅªïªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		PROUDSRV_API virtual void _INTERNAL_FromByteArrayToChangeList(const ByteArray &inArray);

		/** 
		\~korean
		DBCacheServer2¿¡¼­ ³»ºÎÀûÀ¸·Î »ç¿ëÇÏ´Â ÇÔ¼öµé ÀÔ´Ï´Ù.
		- »ç¿ëÀÚ´Â »ç¿ëÇÏÁö ¸»¾Æ ÁÖ¼¼¿ä.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2×ìãÀ?Ý»ÞÅéÄîÜùÞ?¡£
		- éÄ??Üôé©ÞÅéÄ¡£

		\~japanese
		DBCacheServer2ªÇ?Ý»îÜªËÞÅª¦??ªÇª¹¡£
		- «æ?«¶?ªÏÞÅªïªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		PROUDSRV_API virtual const DataTreeList* _INTERNAL_GetRemoveNodeList() const;

		/** 
		\~korean
		DBCacheServer2¿¡¼­ ³»ºÎÀûÀ¸·Î »ç¿ëÇÏ´Â ÇÔ¼öµé ÀÔ´Ï´Ù.
		- »ç¿ëÀÚ´Â »ç¿ëÇÏÁö ¸»¾Æ ÁÖ¼¼¿ä.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2×ìãÀ?Ý»ÞÅéÄîÜùÞ?¡£
		- éÄ??Üôé©ÞÅéÄ¡£

		\~japanese
		DBCacheServer2ªÇ?Ý»îÜªËÞÅª¦??ªÇª¹¡£
		- «æ?«¶?ªÏÞÅªïªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		PROUDSRV_API virtual Proud::ErrorType _INTERNAL_AddRemoveDataTreeList(Proud::Guid removeUUID);


#ifdef _WIN32
#pragma push_macro("new")
#undef new
        // ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
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

#endif // _WIN32