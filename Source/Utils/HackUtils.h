#pragma once
#include "cocos2d.h"
#include "udis86.h"
#include "fasm.h"

using namespace cocos2d;

class HackUtils
{
public:
	enum DataType
	{
		Byte,
		SByte,
		Int16,
		UInt16,
		Int32,
		UInt32,
		Int64,
		UInt64,
		Single,
		Double,
	};

	static Fasm::FasmResult* assemble(std::string assembly, void* addressStart);
	static std::string disassemble(void* bytes, int length);
	static std::string hexAddressOf(void* address, bool zeroPad, bool prefix);
	static DataType stdTypeToDataType(const std::type_info* typeInfo);
	static std::string dataTypeToString(DataType dataType);
	static std::string valueStringOf(void* dataPointer, DataType dataType);
	static std::string arrayOfByteStringOf(void* dataPointer, int length, int maxLength);
};

