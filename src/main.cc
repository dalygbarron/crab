#include <fstream>
#include "inipp.hh"

int main() {
	inipp::Ini<char> ini;
	std::ifstream is("creatures.ini");
	ini.parse(is);
	ini.default_section(ini.sections["DEFAULT"]);
	ini.interpolate();
	std::cout << "ini file after default section and interpolation:" << std::endl;
	ini.generate(std::cout);
	return 0;
}
