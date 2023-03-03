#pragma once

#include "IO/FileManager.h"

#include <vector>
#include <string>

namespace Select
{
	struct Settings
	{
		IO::Path SourcePath;
		bool DisplayTokens;
		bool DisplayParseTree;
		bool RunInterpreter;
	};

	class Select
	{
	public:
		Select(std::vector<std::string> args);
		void Run();

	private:
		Settings& GenerateSettings();

	private:
		std::vector<std::string> m_Args;
	};
}