/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#define NOTHROW_FUNCTION_CATCH_ALL \
	catch (std::bad_alloc&) \
		{ \
		outError = ErrorInfo::From(ErrorType_OutOfMemory, \
			HostID_None, Proud::String(ErrorInfo::TypeToString(ErrorType_OutOfMemory))); \
		} \
	catch (Exception& exception) \
		{ \
		outError = ErrorInfo::From(ErrorType_Unexpected, \
			exception.m_remote, StringA2T(exception.chMsg)); \
		}

// 클래스에 이걸 선언하면 복사 불가능한 상태가 된다.
// 실수로 assignment 구문을 넣는 것을 막게 하려면 유용하다. 
#define NO_COPYABLE(typeName) \
	private: \
		inline typeName& operator=(const typeName&) { return *this; } \
		inline typeName(const typeName&) {}

#ifdef _MSC_VER
#pragma pack(pop)
#endif