# include <iostream>
# include <string>
# include <fstream>

int	error(const std::string& err_msg)
{
	std::cout << err_msg << std::endl;
	return 1;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (error("Wrong usage(./sed [filename], [string to find], [string to replace with])"), 1);
	std::ifstream	in_file(argv[1], std::ifstream::in);
	std::ofstream	new_file;
	std::string		new_file_name(argv[1]);
	new_file_name.append(".replace");

	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	std::string	file_content;

	if (!in_file.is_open() )
		return (error("Failed to open file"), 1);
	std::getline(in_file, file_content, '\0');
	new_file.open(new_file_name.c_str());

	int	i;
	while ((i = file_content.find(s1)) != -1)
	{
		file_content.erase(i, s1.length());
		file_content.insert(i, s2);
	}
	new_file << file_content;

	in_file.close();
	new_file.close();
	return 0;
}
