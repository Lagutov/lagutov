#pragma once
#include <vector>
#include <string>
#include <codecvt>
#include <locale>
#include <map>

class modAlphaCipher
{
private:
	std::wstring numAlpha =
	    L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	std::map <wchar_t,int> alphaNum;
	std::vector <int> key; //ключ
	std::vector<int> convert(const std::wstring& ws);
	std::string convert(const std::vector<int>& v);
	std::wstring getValidKey(const std::wstring & ws);
	inline std::wstring getValidOpenText(const
	                                     std::wstring & ws);
	inline std::wstring getValidCipherText(const
	                                       std::wstring & ws);
public:
	modAlphaCipher()=delete;
	modAlphaCipher(const std::string& skey);
	std::string encrypt(const std::string& open_text);

	std::string decrypt(const std::string& cipher_text);
	std::wstring towstr(const std::string& s);
	std::string fromwstr(const std::wstring& ws);
};
class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string&what_arg):std::invalid_argument(what_arg) {}
	explicit cipher_error (const char*what_arg):std::invalid_argument(what_arg) {}
};
