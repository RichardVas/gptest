#include "JSON.h"





std::vector<std::map<std::string,int>>JSON::readSteps(std::string str) {

	std::vector<std::map<std::string,int>>seq;

//	std::map<std::string, int>koord;
	std::string line;

	std::istringstream stream(str);

	while (std::getline(stream, line))
	{
		std::map<std::string, int>koord_holder;

		std::string rightside = "";
		std::string value = "";
		std::string leftside = "";
		std::string key = "";

		bool whiteSpacesOnly = std::all_of(line.begin(), line.end(), isspace);

		if (line.find('{') == std::string::npos && line.find('}') == std::string::npos && !whiteSpacesOnly)
		{
			/*check for :*/

			if (line.find(':') == std::string::npos)
				throw std::runtime_error("Invalid Json format");
			else
			{
				leftside = line.substr(0, line.find(':') - 1);
				/*determine key*/
				unsigned int str_start = leftside.find('"');

				key = leftside.substr(str_start + 1, (leftside.rfind('"') - str_start) - 1);
				rightside = line.substr(line.find(':'));

				value = rightside.substr(rightside.find(':') + 1);
				/*remove trash*/
				value.erase(std::remove_if(value.begin(), value.end(), isspace), value.end());
				if (value.back() == ',')
					value.pop_back();
				koord_holder[key] = stoi(value);
				seq.push_back(koord_holder);
				
			}
		}
	}
	for (int i = 0; i < seq.size(); ++i)
		for (auto &it : seq[i])
		{
			std::cout << it.first << "\t" << it.second << std::endl;
		}
	
	return seq;
}

std::vector<std::map<std::string, int>>JSON::parseJson(std::string fname) {
	std::vector<std::map<std::string, int>> newseq;
	std::ifstream file;
	file.open(fname);
	if (!file.good()) throw std::runtime_error("File cannot be opened!");
	else
	{
		std::string line, str = "";
		while (std::getline(file, line)) {
			str += line;
			str += "\n";
		}
		newseq = readSteps(str);
		file.close();
	}

	return newseq;
}
