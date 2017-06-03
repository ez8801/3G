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

#include "CompactScalarValue.h"

namespace Proud
{
	//////////////////////////////////////////////////////////////////////////
	// ������ ���� �Դ� �͵��� �Ϸ� �Ű���.

	const int StringSerializeMaxLength = 1024 * 1024;
	extern const char* ReadOffsetAlignErrorText;
	extern const char* NullAccessErrorText;


	inline void AdjustReadOffsetByteAlign(CMessage& msg)
	{
		// ��Ʈ ���� �б⸦ �ϴ� ���̶� �б� ����Ʈ�� byte align�� �ƴϸ� �����Ѵ�.
		int octetOffset = msg.m_readBitOffset & 7; // mod 8

		msg.m_readBitOffset &= 0xfffffff8; // mod 8��ŭ�� �� ����

		if (octetOffset != 0)
			msg.m_readBitOffset += 8;
	}

	inline void AssureReadOffsetByteAlign(CMessage& msg)
	{
		if ((msg.m_readBitOffset & 7) != 0)
		{
			CMessage::ThrowOnWrongLength(ReadOffsetAlignErrorText, (int)strlen(ReadOffsetAlignErrorText), StringSerializeMaxLength);
		}
	}

	inline bool CMessage::Read(uint8_t* data, int count)
	{
		// �ƿ� ������ ������ splitter test ��ü�� ������.
		if (count == 0)
			return true;

		AdjustReadOffsetByteAlign(*this);

		if (!Read_NoTestSplitter(data, count))
			return false;

#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif

		return true;
	}

	template<typename POD>
	inline bool CMessage::Read_POD(POD* data)
	{
		AdjustReadOffsetByteAlign(*this);

		if (!Read_NoTestSplitter_POD<POD>(data))
			return false;

#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif
		return true;
	}


	inline void CMessage::Write(const Guid &b)
	{
		const PNGUID* p = &b;
		Write((const uint8_t*)p, sizeof(*p));
	}

	inline bool CMessage::Read(Guid &b)
	{
		PNGUID* p = &b;
		return Read((uint8_t*)p, sizeof(*p));
	}

	inline bool CMessage::CanRead(int count)
	{
		// �ƿ� ������ ������ splitter test ��ü�� ������.
		if (count == 0)
			return true;

		int oldReadBitOffset = m_readBitOffset;

		AdjustReadOffsetByteAlign(*this);

		if (!CanRead_NoTestSplitter(count))
		{
			m_readBitOffset = oldReadBitOffset;
			return false;
		}
#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif

		m_readBitOffset = oldReadBitOffset;

		return true;
	}

	inline void CMessage::Write(const AddrPort &b)
	{
		Write((uint8_t*)&b.m_addr, sizeof(b.m_addr));
		Write(b.m_port);
	}



	inline void CMessage::CopyFromArrayAndResetReadOffset(const uint8_t* src, int srcLength)
	{
		m_msgBuffer.Clear();
		m_msgBuffer.AddRange(src, srcLength);
		m_readBitOffset = 0;
	}

	inline CMessage::CMessage()
	{
		Clear();
	}

	// ���� ������
	inline CMessage::CMessage(const CMessage &src)
	{
		m_readBitOffset = src.m_readBitOffset;
#ifdef _DEBUG
		m_enableTestSplitter = src.m_enableTestSplitter;
#endif
		m_bitLengthInOneByte = src.m_bitLengthInOneByte;
		m_isSimplePacketMode = src.m_isSimplePacketMode;

		m_msgBuffer = src.m_msgBuffer;
	}

	/*void CMessage::ResetWritePointer()
	{
	m_msgBuffer.Clear();
	}*/

	inline int CMessage::GetWriteOffset()
	{
		return (int)m_msgBuffer.GetCount();
	}

	inline void CMessage::Clear()
	{
		m_readBitOffset = 0;
#ifdef _DEBUG
		m_enableTestSplitter = CNetConfig::EnableTestSplitter;
#endif
		m_bitLengthInOneByte = 0;
		m_isSimplePacketMode = false;

		m_msgBuffer.Clear(); // keeps buffer, however.
	}

	inline bool CMessage::Read(AddrPort &b)
	{
		b = AddrPort::Unassigned;
		return (Read((uint8_t*)&b.m_addr, sizeof(b.m_addr)) == true &&
			Read(b.m_port) == true);
	}


	inline bool CMessage::Read(HostID &b)
	{
		b = HostID_None;
		int x;
		bool r;
		r = Read(x);
		if (r == true)
			b = (HostID)x;
		return r;
	}



	inline void CMessage::Write(NamedAddrPort n)
	{
		WriteString(n.m_addr);
		Write(n.m_port);
	}

	inline bool CMessage::Read(NamedAddrPort &n)
	{
		return ReadString(n.m_addr) && Read(n.m_port);
	}



	inline void CMessage::SetReadOffset(int offset)
	{
		if (offset > (int)m_msgBuffer.GetCount())
		{
			ThrowReadOffsetOutOfRangeException(offset);
		}
		m_readBitOffset = offset * 8;
	}


	inline void CMessage::UseInternalBuffer()
	{
		/* Q: CMessage ctor�� ���ΰ� �� �Լ��� ���� �ֳ���?
		A: global object pool���� �������� ������ ������ ����Ǹ� �����ݾƿ�.t
		Q: �׷���, ������ write �� �߻��ϸ� JIT�� �ϸ� ���ݾƿ�?
		A: A��..... TODO�� ����ô� ������ */
		m_msgBuffer.UseInternalBuffer();
		m_msgBuffer.SetGrowPolicy(GrowPolicy_HighSpeed);
		m_msgBuffer.SetMinCapacity(CNetConfig::MessageMinLength);
	}

	inline void CMessage::WriteString(const char* str)
	{
		WriteStringA(str);
	}

	inline void CMessage::WriteString(const wchar_t* str)
	{
		WriteStringW(str);
	}

	inline void CMessage::WriteString(const StringA &str)
	{
		WriteStringA(str.GetString());
	}

	inline void CMessage::WriteString(const StringW &str)
	{
		WriteStringW(str.GetString());
	}

	inline bool CMessage::ReadString(StringA &str)
	{
		return ReadStringA(str);
	}

	inline bool CMessage::ReadString(StringW &str)
	{
		return ReadStringW(str);
	}


	inline void CMessage::SetLength(int count)
	{
		if (m_readBitOffset > count * 8)
		{
			m_readBitOffset = count * 8; // ��·�ų� ũ�� �����ϱ⸦ ����.
		}

		m_msgBuffer.SetCount(count);
	}



	/// ���� ��ó�� ����ģ��.
	inline bool CMessage::SkipRead(int count)
	{
#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif

		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		if (GetReadOffset() + count > (int)m_msgBuffer.GetCount())
			return false;
		// memcpy(data,m_msgBuffer.GetData()+m_readOffset,count); �̰͸� commented out.
		m_readBitOffset += count * 8;

		return true;

	}


	inline bool CMessage::Read_NoTestSplitter(uint8_t* data, int count)
	{
		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		AssureReadOffsetByteAlign(*this);

		if (GetReadOffset() + count > (int)m_msgBuffer.GetCount())
			return false;

		// #ikpil.choi 2016-11-07 : memcpy_s �� ����, destSize(2��° ����) ���� �׻� �ùٸ� ���̿��� �մϴ�.
		//UnsafeFastMemcpy(data, m_msgBuffer.GetData() + GetReadOffset(), count);
		memcpy_s(data, count, m_msgBuffer.GetData() + GetReadOffset(), count);
		m_readBitOffset += count * 8;

		return true;
	}

	template<typename POD>
	inline bool CMessage::Read_NoTestSplitter_POD(POD* data)
	{
		const int length = sizeof(POD); // ���. ���� ����.
		const int bitLength = sizeof(POD) * 8; // ���. ���� ����.

		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		AssureReadOffsetByteAlign(*this);

		// cache it
		int readOffset = GetReadOffset();

		if (readOffset + length > (int)m_msgBuffer.GetCount())
			return false;

		// �ϱ� if�� ���ؼ��� Write_NoTestSplitter_POD�� ������ �ִ�.
#if defined(__MARMALADE__) || defined(__ANDROID__) || defined(__arm__) // RVCT�� ���� ��� __packed keyword�� ���� ������ gcc�� ���Ƿ� 
		memcpy(data, m_msgBuffer.GetData() + readOffset, length);
#else
		*data = *((POD*)(m_msgBuffer.GetData() + readOffset));
#endif
		m_readBitOffset += bitLength;

		return true;
	}


	inline bool CMessage::CanRead_NoTestSplitter(int count)
	{
		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		int oldReadBitOffset = m_readBitOffset;

		AssureReadOffsetByteAlign(*this);

		if (GetReadOffset() + count > (int)m_msgBuffer.GetCount())
		{
			m_readBitOffset = oldReadBitOffset;
			return false;
		}

		m_readBitOffset = oldReadBitOffset;

		return true;
	}

#ifdef _DEBUG
	inline void CMessage::ReadAndCheckTestSplitterOnCase()
	{
		if (m_enableTestSplitter)
		{
			uint8_t s;
			if (!Read_NoTestSplitter(&s, sizeof(s)) || s != Splitter)
			{
				ThrowWrongSpliiterException();
			}
		}
	}

	inline void CMessage::EnableTestSplitter(bool enable)
	{
		m_enableTestSplitter = enable;
	}
#endif

	inline bool CMessage::ReadWithShareBuffer(CMessage& output, int length)
	{
		if (GetLength() < GetReadOffset() + length)
			return false;

		uint8_t* contentPtr = GetData() + GetReadOffset();
		output.UseExternalBuffer(contentPtr, length);
		output.SetLength(length); // �̰� �־�� ��!
		SkipRead(length);

		return true;
	}


	inline void CMessage::AppendByteArray(const uint8_t* fragment, int fragmentLength)
	{
		m_msgBuffer.AddRange(fragment, fragmentLength);
	}

	template<typename Type>
	inline bool Message_ReadScalar(CMessage& msg, Type &a)
	{
		if (msg.IsSimplePacketMode())
		{
			int64_t a0; // VLQ�� ���ؼ���, ����ڰ� � Ÿ���� ������ �����ϰ� ���Ƿ�
			bool ok = msg.Read(a0); 
			if (ok)
			{
				a = (Type)a0; // ũ�Ⱑ �۴��� ��������.
			}
			return ok;
		}
		else
		{
			CCompactScalarValue<Type> val;
			int readOffset = msg.GetReadOffset();
			if (!val.ExtractValue(msg.GetData() + readOffset, msg.GetLength() - readOffset))
				return false;

			a = val.m_extractedValue;
			msg.SkipRead(val.m_extracteeLength);

			return true;
		}
	}

	inline bool CMessage::ReadScalar(int64_t &a)
	{
		return Message_ReadScalar<int64_t>(*this, a);
	}

	inline bool CMessage::ReadScalar(int32_t &a)
	{
		return Message_ReadScalar<int32_t>(*this, a);
	}

	inline bool CMessage::ReadScalar(int16_t &a)
	{
		return Message_ReadScalar<int16_t>(*this, a);
	}

	inline bool CMessage::ReadScalar(int8_t &a)
	{
		return Message_ReadScalar<int8_t>(*this, a);
	}

	template <typename Type>
	inline void Message_WriteScalar(CMessage& msg, Type a)
	{
		if (msg.IsSimplePacketMode())
		{
			msg.Write((int64_t)a); // VLQ�� ���ؼ���, ����ڰ� � Ÿ���� ������ �����ϰ� ���Ƿ�
		}
		else
		{
			// ��ȯ�� �޸� �� ����
			CCompactScalarValue<Type> comp;
			comp.MakeBlock(a);

			// �̸� �޽��� ��ü�� �ֱ�
			msg.Write(comp.m_filledBlock, comp.m_filledBlockLength);
		}
	}

	inline void CMessage::WriteScalar(int64_t a)
	{
		Message_WriteScalar<int64_t>(*this, a);
	}

	inline void CMessage::WriteScalar(int32_t a)
	{
		Message_WriteScalar<int32_t>(*this, a);
	}

	inline void CMessage::WriteScalar(int16_t a)
	{
		Message_WriteScalar<int16_t>(*this, a);
	}

	inline void CMessage::WriteScalar(int8_t a)
	{
		Message_WriteScalar<int8_t>(*this, a);
	}

	inline void CMessage::UninitBuffer()
	{
		m_readBitOffset = 0;
		m_bitLengthInOneByte = 0;
		m_msgBuffer.UninitBuffer();
	}

#ifdef _DEBUG
	inline CMessageTestSplitterTemporaryDisabler::CMessageTestSplitterTemporaryDisabler(CMessage& msg)
	{
		m_msg = &msg;
		m_oldVal = m_msg->IsTestSplitterEnabled();
		m_msg->EnableTestSplitter(false);
	}

	inline CMessageTestSplitterTemporaryDisabler::~CMessageTestSplitterTemporaryDisabler()
	{
		m_msg->EnableTestSplitter(m_oldVal);
	}
#endif

	// �� �Լ��� ȣ���ϸ� simple packet mode�� �����ų� ������.
	// read/write scalar ���� ��Ȱ��ȭ�ϴµ� ���ȴ�.
	inline void CMessage::SetSimplePacketMode(bool isSimplePacketMode)
	{
		m_isSimplePacketMode = isSimplePacketMode;
	}

	// �ٸ� ���� ��ü�� �����͸� �����ϱ� �����ϸ鼭 �б� ��ġ�� �����Ѵ�.
	inline void CMessage::ShareFromAndResetReadOffset(ByteArrayPtr data)
	{
		m_msgBuffer = data;
		m_readBitOffset = 0;
	}

	inline void CMessage::UseExternalBuffer(uint8_t* buf, int capacity)
	{
		// 		if (capacity > CNetConfig::MessageMaxLength)
		// 			throw Exception("UseExternalBuffer failed due to too large capacity");

		m_msgBuffer.UseExternalBuffer(buf, capacity);
	}





}