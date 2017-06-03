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

#include "ProcHeap.h"
#include "Exception.h"

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
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#quantizer" >������ ����ȭ</a> ����� ����ϴ� Ŭ�����Դϴ�.

	\~english
	Class manages <a target="_blank" href="http://guide.nettention.com/cpp_en#quantizer" >Data Quantization</a> function

	\~chinese
	?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#quantizer" >?�������</a>%������? ��

	\~japanese
	\ref quantizer  Ѧ����??���뫯�髹�Ǫ���
	\~
	*/
	class CQuantizer
	{
		double m_min,m_max;
		uint32_t m_granulation;
	public:
		/** 
		\~korean
		������
		\param min ����ȭ�Ǵ� ���� �� �� ���Ϸδ� ���� �ʽ��ϴ�.
		\param max ����ȭ�Ǵ� ���� �� �� �̻����δ� ���� �ʽ��ϴ�.
		\param granulation ����ȭ�Ǵ� ���� ���� Ÿ���Դϴ�. �� ���� ����ȭ�Ǵ� ���� 0���� �󸶱����� ���������� ��ȯ�Ǵ��ĸ� ��Ī�մϴ�.
		���� Ŭ���� ����ȭ�� ���� ���е��� ������ ����ȭ�� �����Ͱ� �ʿ�� �ϴ� ��Ʈ���� �����ϰ� �˴ϴ�. 

		\~english
		Constructor
		\param min the quantized value will not be entered and no less than this value.
		\param max the quantized value will not be entered and no more than this value.
		\param granulation the quantized value has integer type. This value points that the quantized value is to be converted from 0 to which integer.
		Larger value provides more pricise quantized value but the number of bits required by quantized data.

		\~chinese
		�����
		\param min ?���������?��������?��
		\param ma ?���������?���������?��
		\param granulation �������?����??���?���?�������?????0���������??��
		?���ޣ��������?�������ޣ�ӣ���������?�������bit??��ʥ��

		\~japanese
		�����
		\param min �������������Ϫ���������˪�����ު���
		\param min �������������Ϫ���������˪�����ު���
		\param max ����ȭ�Ǵ� ���� �� �� ���Ϸδ� ���� �ʽ��ϴ�.
		\param granulation ����������������?�����תǪ�������������������������0���骤����ުǪ���?����?������몫��򦪷�ު���
		�����ު����۪���������쪿�������������Ԫ��Ǫ�������������쪿��?������驪Ȫ���ӫë�?��?ʥ���ު���
		\~
		*/
		CQuantizer( double min, double max, uint32_t granulation )
		{
			m_min = min;
			m_max = max;
			m_granulation = granulation;
		}

		/** 
		\~korean
		����ȭ�� �մϴ�. 

		\~english
		Quantizing

		\~chinese
		?���������

		\~japanese
		������򪷪ު���
		\~
		*/
		uint32_t Quantize(double value)
		{
			value = PNMIN(m_max, value);
			value = PNMAX(m_min, value);
			double range = m_max - m_min;
			double offset = value - m_min;
			double offset2 = offset / range * (double)m_granulation;
			return (uint32_t)offset2;
		}

		/** 
		\~korean
		����ȭ�� ���� �����մϴ�. 

		\~english
		Recover quantized value

		\~chinese
		��?�������?��

		\~japanese
		��������쪿������ꪪ��ު���
		\~
		*/
		double Dequantize(uint32_t value)
		{
			double offset = (double)value;
			double range = m_max - m_min;
			double offset2 = offset / (double)m_granulation * range;
			return offset2 + m_min;
		}

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