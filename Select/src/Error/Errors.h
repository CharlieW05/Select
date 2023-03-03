#pragma once

#include <vector>
#include <iostream>
#include <exception>

namespace Select
{
	class Exception : public std::exception
	{
	public:
		Exception(const std::string& title, const std::string& message)
		{
			m_Message = "[";
			m_Message.append(title);
			m_Message.append(" Error] - ");
			m_Message.append(message);
		}

		const char* what() const
		{
			return m_Message.c_str();
		}

	protected:
		std::string m_Message;
	};

	class ArgsError : public Exception
	{
	public:
		ArgsError(const std::string& message) : Exception("Args", message) { }
	};
}

namespace IO
{
	class IOError : public Select::Exception
	{
	public:
		IOError(const std::string& message) : Exception("IO", message) { }
	};
}