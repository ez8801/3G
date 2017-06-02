/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
/*
ProudNet 1.8.38132-dev012


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ���� : ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


���������??Nettention�������
?����������ǡ����ġ�?����?����?���������������?���??��
������???��?�������������ġ�
���������?��٥���?��������?�������?�졣

** ��������?�����ڪ��߾��٥�ơ�


���Ϋ׫���������?��Nettention�˪���ު���
���Ϋ׫��������ᡢ���ġ����֪�?������������׫��������?�Ȫ���峪�?����
��峪��������ʪ����ꡢ����ܪ���?���Ī��ת��ު���
��?���Ī˪���������׫��������?�Ȫ��������٥�ƪ���ƪ��ު���

** �������ڪ��?����߾����٥�ƪ���۪��ʪ��Ǫ���������

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
		// forest�� ���� ������. 
		CDataTree*	m_Root;
		// forest���� guid�� Ű�� ���� ã�� �ϱ� ����
		DataTreeMap		m_DataTreeMap;
		// DB�� delete ������ �������� �ϴ� ����
		DataTreeList	m_removeDataTreeList;

		/*
		\~korean
		�̰��� �ε��� DB cache client�� ������ session �ν���

		\~english
		Session identifier that sent by loaded DB cache client

		\~chinese
		??ʥ?��DB cache client?����session��??��
                
		\~japanese
		������?�ǫ��󫰪���DB cache client����êƪ��쪿session�����
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
		nodeToMove ��带 destForest�� destParentNode ���� ���� �̵� ��ŵ�ϴ�. 
		nodeToMove�� OwnerUUID,RootUUID�� ����ǰ�
		nodeToMove�� ���� ����� RootUUID�� destForest�� RootUUID�� ����˴ϴ�.

		\param destForest destParentNode�� �����ִ� Forest
		\param nodeToMove �̵���ų ���
		\param destParentNode �̵���ų ����� Owner Node
		\return ���������� �̵��ϸ� ErrorType_Ok�� �����մϴ�. �� �̿ܿ��� �ٸ� ���� ���� ���ϵ˴ϴ�.

		\~english 
		Move nodetoMove node to the lower node of destparentNode of destForest. 
		OwnerUUID,RootUUID of nodeToMove is changed and 
		RootUUID of the lower node of nodeToMove is changed to RootUUID of destForest
		\param destForest Forest where destParentNode belongs to
		\param nodeToMove �̵���ų ��� Node to be moved 
		\param destParentNode Owner node of the node to be moved 
		\return When moved successfully, it returns ErrorType_Ok. Otherwise another error value is returned. 

		\~chinese
		��nodeToMove?���?��destForest��destParentNode����??�á� 
		nodeToMove��OwnerUUID,RootUUID???��
		nodeToMove������??����RootUUID?��?destForest��RootUUID��

		\paramdestForestdestParentNode������Forest
		\paramnodeToMove ��?��?��
		\paramdestParentNode ��?��?����Owner Node
		\return �����?��������ErrorType_Ok����?��������???��
		
		\~japanese
		nodeToMove ��?�ɪ�destForest��destParentNode���ȫ�?�ɪ���Ѫ����ު���
		nodeToMove��OwnerUUID,RootUUID��?�ڪ���ơ�
		nodeToMove�����ȫ�?�ɪ�RootUUID��destForest��RootUUID��?�ڪ���ު���

		\param destForest destParentNode��?���ƪ���Forest
		\param nodeToMove ��Ѫ������?��
		\param destParentNode ��Ѫ������?�ɪ�Owner Node
		\return ��Ѫ���������ErrorType_Ok��꫿?�󪷪ު���������˪���Ϋ���?�����꫿?�󪵪�ު���
		\~
		*/
		Proud::ErrorType MoveDataTree(CLoadedDataTree& destForest, CDataTreePtr nodeToMove, CDataTreePtr destParentNode);
	
		/** 
		\~korean
		parent �� ������ �ڽ� ���μ� newNode�� �ֽ��ϴ�. parent=NULL�� ��� �ֻ���� ���μ� newNode�� �߰��˴ϴ�.

		\param parent ���� NULL�� ��� CPropTree �� �ֻ��� ������ �� ������ ���� �ٽ��ϴ�.
		\param newNode ���� �߰��� ���. ��� CPropForest ���� �̹� ���ӵ� �����̾�� �ȵ˴ϴ�. �̸� ���� ���� ���� �����մϴ�.
		\return ���������� �߰��ϸ� ErrorType_Ok �� �����մϴ�. �� �̿ܿ��� �ٸ� ���� ���� ���ϵ˴ϴ�.

		\~english
		Enters newNode as the last child node of parent. If parent=NULL then newNode will be added as the top node.
		If the newNode already has other child nodes then all of them will enter CPropForest all together.

		\param parent If it is equal to NULL then it will be attached as the last node of the top most node of CPropTree.
		\param newNode The node to be added newly. It must not be dependent to any CPropForest. If so, an error value will be returned.
		\return Returns ErrorType_Ok if successfuly added. Otherwise, a different error value will be returned.

		\~chinese
		��?��Parent��������?��ҳ?��node,�ۯ��newNode��parent=NULL?����?����߾Ӯ?��node�����ʥnewNode��

		\param parent ������NULL��?���� CPropTree%����߾��??��������?node?��?��
		\param newNode ���ʥ����node��
		��η���??�� CPropForest%���?????��?�������ܡ�?��?��������????��
		\return ��������ʥ��?ErrorType_Okʦ����ޡ�������?��???���ޡ�

		\~japanese
		Parent����������?�ɪȪ���newNode������ު���parent=NULL�����ꡢ��߾ӫ�Ϋ�?�ɪȪ���newNode����ʥ����ު���
		
		\param parent �⪷��NULL�Ǫ������ꡢCPropTree����߾�ȫ�٫��������?�ɪ������ު���
		\param newNode �檿����ʥ�����?�ɡ������ʪ�CPropForest�˪�?��??���쪿?���˪ʪêƪϪ����ު��󡣪��������ʪ���Ы���?����꫿?�󪷪ު���
		\return ��ʥ����������ErrorType_Ok��꫿?�󪷪ު���������˪���Ϋ���?�����꫿?�󪵪�ު���
		\~
		*/
        PROUDSRV_API Proud::ErrorType InsertChild(CDataTreePtr parent, CDataTreePtr newNode);

		/** 
		\~korean
		�� ��ü�� �̹� �پ��ִ� CDataTree ��ü�� �и��س��ϴ�.
		�и��� node�� child�� CPropForest �κ��� �и��˴ϴ�. ������ �и��� node�� child���� node���� �ڽİ��踦 ��� �����մϴ�.

		\param node �и��� ����Դϴ�. �� CPropForest �� ���ӵǾ� �־�� �մϴ�.�̸� ���� ���� ���� �����մϴ�.
		\param addremovelist removeDataTreeList �� �߰������� ���� �����Դϴ�. true �� �����Ͻ��� UpdateData�� ȣ���ϸ� �ڵ����� DBMS���� �����˴ϴ�.
		\return ���������� �����ϸ� ErrorType_Ok �� �����մϴ�. �� �̿ܿ��� �ٸ� ���� ���� ���ϵ˴ϴ�.

		\~english 
		Separate the CDataTree object already attached to this object. 
		The child of the separated node is separated from CPropForest. However, the children of the separated node still maintain the parent and child relationship with the node. 

		\param node Node to be separated. It must be subordinated to this CPropForest. 
		\param addremovelist This is whether to add to removePropNodelist. After setting it to true and calling UpdateData, it is automatically deleted from DBMS. 
		\return When deleted successfully, it returns ErrorType_Ok. Otherwise another error value is returned. 

		\~chinese
		???��ʦ���?�?��??�� CDataTree%��?�ڡ�
		��?��node��child? CPropForest%��?��?��ӣ����?node��child??node???��ҳ?ͧ��

		\param node �����?��node��?? CPropForest%�??��????��?��?��������????��
		\param addremovelist removeDataTreeList�������ʥ��?���� True?������УUpdateData��?�?�DBMS?𶡣
		\return ������?���?����ErrorType_Ok��������?��???���ޡ�

		\~japanese
		���Ϋ��֫������Ȫ�?�˪Ī��ƪ���CPropNode���֫������Ȫ�����ު���
		����쪿node��child��CPropForest���������ު���������������쪿node��child��node�Ȫ����?����?�����򥪷�ު���
		\param node ������?�ɪǪ�������CPropForest��??����ƪ��ʪ���Ъʪ�ު��󡣪��������ʪ���Ы���?����꫿?�󪷪ު���
		\param addremovelist removePropNodelist ����ʥ���몫�ɪ����Ǫ���True�����Ҫ�������UpdateData�������󪹪���Ѫ�DBMS������𶪵��ު���
		\return ��۪���������ErrorType_Ok��꫿?�󪷪ު���������˪���Ϋ���?�����꫿?�󪵪�ު���
		\~
		*/
        PROUDSRV_API virtual Proud::ErrorType RemoveNode(CDataTreePtr node, bool addremovelist=true);

		/** 
		\~korean
		RemoveNode(node)�� ���� ����� ������, UUID�� ���� �մϴ�.

		\param removeUUID ������ Node UUID
		\param addremovelist removeDataTreeList�� �߰������� ���� �����Դϴ�. true �� �����Ͻ��� UpdateData�� ȣ���ϸ� �ڵ����� DBMS���� �����˴ϴ�.
		\return ���������� �����ϸ� ErrorType_Ok �� �����մϴ�.�� �̿ܿ��� �ٸ� ���� ���� ���ϵ˴ϴ�.

		\~english 
		It has the same function as RemoveNode(node) but operates as UUID. 
		\param Node UUID to be deleted
		\param This is whether to add to removePropNodelist. After setting it to true and calling UpdateData, it is automatically deleted from DBMS. 
		\return When deleted successfully, it returns ErrorType_Ok. Otherwise another error value is returned.

		\param removeUUID Node UUID that will be removed.

		\return Once it successfully removed then return ErrorType_Ok instead of this case, other error value will be returned.

		\~chinese
		?��?RemoveNode(node) ��?��������ӣ���UUID???��

		\param removeUUID �?���Node UUID
	        \param addremovelist �������ʥ��removeDataTreeList��?����True?������УUpdateData��?�?�DBMS?𶡣
	        \return �����������?ErrorType_Okʦ����ޡ�������?��???���ޡ�

		\~japanese
		RemoveNode(node)�Ϊ誦��Ѧ���򪷪ު�����UUID�����ª��ު���
		\param removeUUID ��۪��� Node UUID
		\param addremovelist removePropNodelist����ʥ���몫�ɪ����Ǫ���true�����Ҫ�������UpdateData�������󪹪���Ѫ�DBMS������𶪵��ު���
		\return ��۪���������ErrorType_Ok��꫿?�󪷪ު���������˪���Ϋ���?�����꫿?�󪵪�ު���
		\~
		*/
		PROUDSRV_API virtual Proud::ErrorType RemoveNode(Proud::Guid removeUUID, bool addremovelist=true);

		/** 
		\~korean
		guid�� �ش��ϴ� node�� ���� �մϴ�.�˻� �뵵�� ���˴ϴ�.
		\param guid ã�Ƴ� node�� uuid
		\return �������̶��, node�� ���� �մϴ�. NULL �̶�� ���� node �Դϴ�.

		\~english
		Return node that as guid. It will use for searching.
		\param UUID of node that find out guid
		\return If it succeed, return node. If it is NULL, it is not exsit node.

		\~chinese
		Guid��?��node���ޡ��������������
		\param guid ���?��node��uuid��
		\return ������?node���ޣ�NULL��??��node��

		\~japanese
		Guid����?����node��꫿?�󪷪ު���?���ĪȪ��Ū��ު���
		\param guid ̸�Ī���node��uuid
		\return ����ʪ顢node��꫿?�󪷪ު���NULL �ʪ顢��node�Ǫ���
		\~
		*/
		PROUDSRV_API virtual CDataTreePtr GetNode(const Guid& guid);
		
		/** 
		\~korean
		�� ��ü�� ������ �ִ� �ֻ��� ������ ��带 �����մϴ�.
		\return �������̶��, �ֻ��� ��带 �����մϴ�. ���ж�� ��� �ִ� CDataTreePtr �� �����մϴ�.

		\~english
		It returns top data node that this object owned.
		\return If it is succeed, return top node. If it is failed, return an empty CDataTreePtr.

		\~chinese
		???��?����������߾��?��node��
		\return ������?����������߾��node����?��?���������� CDataTreePtr%��

		\~japanese
		���Ϋ��֫������Ȫ��êƪ�����߾�ȫ�?����?�ɪ�꫿?�󪷪ު���
		\return ����ʪ顢��߾�ȫ�?�ɪ�꫿?�󪷪ު��������ʪ������ƪ���CPropNodePtr��꫿?�󪷪ު���
		\~
		*/
        PROUDSRV_API virtual CDataTreePtr GetRootNode();

		/** 
		\~korean
		�� ��ü�� ������ �ִ� �ֻ��� ������ ����� UUID�� �����մϴ�.

		\~english
		It returns top data node that this object owned.

		\~chinese
		������???��?������߾��?��?����UUID��

		\~japanese
		���Ϋ��֫������Ȫ��êƪ�����߾�ȫ�?����?�ɪ�UUID��꫿?�󪷪ު���
		\~
		*/
        PROUDSRV_API Guid GetRootUUID();

		/** 
		\~korean
		Session Guid�� ��´�.

		\~english TODO:translate needed.

		\~chinese
		����Session Guid��

		\~japanese
		Session Guid����ު���
		\~
		*/
		PROUDSRV_API Guid GetSessionGuid() const;

		/** 
		\~korean
		\param val SessionGuid�� �����Ѵ�.

		\~english
		Set SessionGuid.

		\~chinese
		\param val ?��SessionGuid��

		\~japanese
		\param val SessionGuid�����Ҫ��ު���
		\~
		*/
		PROUDSRV_API void SetSessionGuid(Guid val);

#if defined (_MSC_VER)
		__declspec(property(get=GetSessionGuid,put=SetSessionGuid)) Guid sessionGuid;
		__declspec(property(get=GetRootUUID)) Guid RootUUID;
#endif

		/** 
		\~korean
		�����͸� �����Ͽ� �ٸ� ��ü�� ����ϴ�.

		\~english
		Create other object to copy data.

		\~chinese
		?��?������?��?�ڡ�

		\~japanese
		��?���򫳫�?������Ϋ��֫������Ȫ��ª�ު���
		\~
		*/
		PROUDSRV_API CLoadedDataTreePtr Clone();

		/** 
		\~korean
		���� �����͸� ByteArray �� ����ϴ�.
		\param output �����Ͱ� ��� ByteArray ��ü �Դϴ�.

		\~english
		Put internal data to ByteArray.
		\param ByteArray object for output data.

		\~chinese
  		???ݻ?�� ByteArray��
		\param output �?����?�� ByteArray%?�ڡ�

		\~japanese
		?ݻ��?���� ByteArray������ު���
		\param output ��?��������ByteArray���֫������ȪǪ���

		\~
		*/
		PROUDSRV_API void ToByteArray(ByteArray& output);
		/** 
		\~korean
		input�� ���� �����͸� �����մϴ�.

		\param input �����Ͱ� ��� ByteArray ��ü �Դϴ�.

		\~english
		Copy data from input.

		\param ByteArray object that has input data.

		\~chinese
		?input?�?�ߡ�
		
		\param input ���?����?�� ByteArray%?�ڡ�

		\~japanese
		Input�����?���򫳫�?���ު���
		\param input ��?��������ByteArray���֫������ȪǪ���
		\~
		*/
		PROUDSRV_API void FromByteArray(const ByteArray& input);
		
		// Ʈ���� consistent �� Ȯ�� �ϱ� ���ؼ�.
/*		PROUDSRV_API bool IsConsistent();*/

		/** 
		\~korean
		DBCacheServer2���� ���������� ����ϴ� �Լ��� �Դϴ�.
		- ����ڴ� ������� ���� �ּ���.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2����?ݻ��������?��
		- ��??������ġ�

		\~japanese
		DBCacheServer2��?ݻ�ܪ��Ū�??�Ǫ���
		- ��?��?���Ū�ʪ��Ǫ���������
		\~
		*/
		PROUDSRV_API virtual void _INTERNAL_ClearChangeNode();

		/** 
		\~korean
		DBCacheServer2���� ���������� ����ϴ� �Լ��� �Դϴ�.
		- ����ڴ� ������� ���� �ּ���.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2����?ݻ��������?��
		- ��??������ġ�

		\~japanese
		DBCacheServer2��?ݻ�ܪ��Ū�??�Ǫ���
		- ��?��?���Ū�ʪ��Ǫ���������
		\~
		*/
		PROUDSRV_API virtual void _INTERNAL_ChangeToByteArray(ByteArray& outArray);

		/** 
		\~korean
		DBCacheServer2���� ���������� ����ϴ� �Լ��� �Դϴ�.
		- ����ڴ� ������� ���� �ּ���.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2����?ݻ��������?��
		- ��??������ġ�

		\~japanese
		DBCacheServer2��?ݻ�ܪ��Ū�??�Ǫ���
		- ��?��?���Ū�ʪ��Ǫ���������
		\~
		*/
		PROUDSRV_API virtual void _INTERNAL_FromByteArrayToChangeList(const ByteArray &inArray);

		/** 
		\~korean
		DBCacheServer2���� ���������� ����ϴ� �Լ��� �Դϴ�.
		- ����ڴ� ������� ���� �ּ���.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2����?ݻ��������?��
		- ��??������ġ�

		\~japanese
		DBCacheServer2��?ݻ�ܪ��Ū�??�Ǫ���
		- ��?��?���Ū�ʪ��Ǫ���������
		\~
		*/
		PROUDSRV_API virtual const DataTreeList* _INTERNAL_GetRemoveNodeList() const;

		/** 
		\~korean
		DBCacheServer2���� ���������� ����ϴ� �Լ��� �Դϴ�.
		- ����ڴ� ������� ���� �ּ���.

		\~english
		Function that use internally at DBCacheServer2.
		- Do not use.

		\~chinese
		DBCacheServer2����?ݻ��������?��
		- ��??������ġ�

		\~japanese
		DBCacheServer2��?ݻ�ܪ��Ū�??�Ǫ���
		- ��?��?���Ū�ʪ��Ǫ���������
		\~
		*/
		PROUDSRV_API virtual Proud::ErrorType _INTERNAL_AddRemoveDataTreeList(Proud::Guid removeUUID);


#ifdef _WIN32
#pragma push_macro("new")
#undef new
        // �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
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