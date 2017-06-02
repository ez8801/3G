/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


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

#include "BasicTypes.h"
#include "FakeClr.h"
#include "ThreadPool.h"
#include "IRmiHost.h"
#include "P2PGroup.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup net_group
	*  @{
	*/

	/**
\~korean
������, ������ �����ϴ� Ŭ���̾�Ʈ�� ����� �� ����� UDP ������ �����ϴ� ��å�Դϴ�.
�ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_udp_assign" >������ UDP ��Ʈ ��� ���</a> �� �����Ͻʽÿ�.

\~english
This is a policy allocating UDP sockets to be used by the serverwhen communicating with the clients.
Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_udp_assign" >Method of using Server UDP Port</a> for more details.

\~chinese
������?��??����?����client������?��������UDP socket��������
????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_udp_assign" >��?��UDPӮϢ����۰��</a>%��

\~japanese
��?��?������?��?����?���뫯�髤����Ȫ����᪹�������Ū�UDP�����ëȪ��ܪ�?�ƪ�ݫ꫷?�Ǫ���
�٪����ϡ�\ref server_udp_assign ��?�Ϊ���������
\~
*/
	enum ServerUdpAssignMode
	{
		/**
		\~korean
		�����ȵ�. ����ڴ� �� ���� ���� ���ʽÿ�.

		\~english
		Not designated. Users are not to use this value.

		\~chinese
		?����ҡ���?��������?��

		\~japanese
		ڱ��ҡ���?��?�Ϫ��������ŪêƪϪ����ު���
		\~
		*/
		ServerUdpAssignMode_None,

		/**
		\~korean
		������ ������ �� Ŭ���̾�Ʈ�� ���ؼ� ���� �ٸ� UDP ��Ʈ�� ����մϴ�.
		- �� ���� �⺻���̸�, ����Ǵ� ���Դϴ�.
		- �� ���� Proud.CStartServerParameter.m_udpPorts ���� ������ ��Ĩ�ϴ�.

		\~english
		For each clients that coonects, it is to use different UDP port for each of them.
		- This value is a default and recommended value.
		- This value affects Proud.CStartServerParameter.m_udpPorts also.

		\~chinese
		??����client����������UDPӮϢ��
		- �?����??����������?��?��
		- �?�? Proud.CStartServerParameter.m_udpPorts%?���?��

		\~japanese
		��?�����êƪ��������髤����Ȫ�?���������ު�UDP��?�Ȫ����Ī��ު���
		- ���������������ǡ�??���Ǫ���
		- �������ϡ�Proud.CStartServerParameter.m_udpPorts�˪���ª���ܪ��ު���
		\~
		*/
		ServerUdpAssignMode_PerClient,

		/**
		\~korean
		������ ������ ��� Ŭ���̾�Ʈ�� �̸� �غ�Ǿ� �ִ� ������ ������ UDP ��Ʈ�� �����մϴ�.
		�� ������ ����� ��� UDP�� Ư���� ������ ����� �ϱ� ����� Ŭ���̾�Ʈ���� ���� �� �ֽ��ϴ�.
		- �� �ɼ��� ProudNet�� ���� ȣȯ�� ������ �غ�� ����̸�, �������� �ʴ� ����Դϴ�.
		- �� �ɼ� ���� ��ȭ�� ������ �ʿ��մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#block_icmp" >ICMP ���� ��ȭ�� ����</a> �� �����Ͻʽÿ�.
		�� ���� Proud.CStartServerParameter.m_udpPorts ���� ������ ��Ĩ�ϴ�.

		\~english
		All the clients that connect reuse the UDP ports that are already prepared.
		When using this option, it is possible to cause some clients hard to communicate with the server due to UDP characteristics.
		- This is option is prepared for the lower compatibility of Proudnet and it is not recommended to use.
		- It is necessary to use a firewall setup to use this feature. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#block_icmp" >Firewall setup for ICMP related
</a> for more details.
		This value affects Proud.CStartServerParameter.m_udpPorts also.

		\~chinese
		?����client�������?��?����ͳ��??��UDPӮϢ��
		�����?����?������UDP��������ʦ��??��?��?��?�������client��
		- �??��?��?ProudNet��������������?��������������?��������
		- �����???�������??�ǡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#block_icmp" >ICMP ��?������??��</a>%��
		�?�? Proud.CStartServerParameter.m_udpPorts%?���?��

		\~japanese
		��?�����êƪ�����ƪΫ��髤����Ȫ����ê����᪵��ƪ���ͳ��?��UDP��?�Ȫ�����Ī��ު���
		�������Ҫ����Ī������ꡢUDP���������髵?��?�Ȫ����᪬�񪷪����髤����Ȫ�?�檹�몳�Ȫ�����ު���
		- ���Ϋ��׫�����ProudNet�������������Ϊ������᪵�쪿Ѧ���ǡ�??���ʪ�Ѧ���Ǫ���
		- ���Ϋ��׫������Ū����ϫի���������?�����Ҫ���驪Ǫ����٪����ϡ�\ref block_icmp��?�Ϊ���������
		�������ϡ�Proud.CStartServerParameter.m_udpPorts�˪���ª���ܪ��ު���
		\~
		*/
		ServerUdpAssignMode_Static,
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
