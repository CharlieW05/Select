#include "Program/Select.h"

int main(int argc, char** argv)
{
	std::vector<std::string> args(argv, argv + argc);

	Select::Select* program = new Select::Select(args);
	program->Run();
	delete program;
}