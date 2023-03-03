#pragma once

#include <filesystem>

namespace IO
{
	using Path = std::filesystem::path;

	static Path OpenFile(const std::string& fileName)
	{
		return Path(fileName);
	}
}