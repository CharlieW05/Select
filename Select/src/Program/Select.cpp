#include "Select.h"

#include <iostream>

#include "Error/Errors.h"

namespace Select
{
	Select::Select(std::vector<std::string> args)
	{
		m_Args = args;
	}

	void Select::Run()
	{
		try
		{
			Settings& settings = GenerateSettings();
		}
		catch (const Exception& exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}

	Settings& Select::GenerateSettings()
	{
		if (m_Args.size() == 1)
			throw ArgsError("No source file given!");

		Settings settings;

		IO::Path path = IO::OpenFile(m_Args[1]);
		if (path.extension() != ".sel")
			throw ArgsError("File extension should be *.sel!");

		settings.SourcePath = path;

		for (auto i = m_Args.begin(); i < m_Args.end(); ++i)
		{
			std::string argument = (*i);

			if (argument == "-plex")
			{
				settings.DisplayTokens = true;
				continue;
			}

			if (argument == "-past")
			{
				settings.DisplayParseTree = true;
				continue;
			}

			if (argument == "-drint")
			{
				settings.RunInterpreter = false;
				continue;
			}
		}

		return settings;
	}
}