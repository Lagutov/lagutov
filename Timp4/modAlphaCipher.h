/** @file modAlphaCipher.h
* @author Максимов О.В.
* @version 1.0.0
* @date 13.06.2019
* @brief Заголовочный файл для модуля Gronsfeld
*/
#pragma once
#include <vector>
#include <string>
#include <codecvt>
#include <locale>
#include <map>
/** @brief Шифрование методом Гронсфельда
* @details Ключ устанавливается в конструкторе.Для зашифровывания
и расшифровывания предназначены методы encrypt и decrypt.
* @warning Реализация только для русского языка
*/
class modAlphaCipher
{
private:
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Русский алфавит
	std::map <wchar_t,int> alphaNum; ///< Ассоциативный массив"номер по символу"
	std::vector <int> key; ///< Ключ
/**
* @brief Преобразование строка-вектор
* @param [in] ws Строка в кодировке UTF-32
* @return Целочисленный вектор
*/
	std::vector<int> convert(const std::wstring& ws);
/**
* @brief Преобразование вектор-строка
* @param [in] v Целочисленный вектор
* @return Строка в кодировке UTF-8
*/
	std::string convert(const std::vector<int>& v);
/**
* @brief Валидация ключа
* @param [in] ws Ключ в кодировке UTF-32. Не должен быть
пустой строкой.
* Строчные символы автоматически преобразуются к прописным.
* @return Валидный ключ в кодировке UTF-32
* @throw cipher_error ключ пустой или содержит недопустимые
символы
*/
	std::wstring getValidKey(const std::wstring & ws);
/**
* @brief Валидация открытого текста
* @param [in] ws Открытый текст в кодировке UTF-32. Не должен
быть пустой строкой.
* Строчные символы автоматически преобразуются к прописным.
* @return Валидный открытый текст в кодировке UTF-32
* @throw cipher_error текст пустой или содержит недопустимые
символы
*/
	inline std::wstring getValidOpenText(const std::wstring & ws);
/**
* @brief Валидация зашифрованного текста
* @param [in] ws Зашифрованный текст в кодировке UTF-32. Не
должен быть пустой строкой.
* Не должен содержать строчные символы и не-буквы.
* @return Валидный зашифрованный текст в кодировке UTF-32
* @throw cipher_error текст пустой или содержит недопустимые
символы
*/
	inline std::wstring getValidCipherText(const std::wstring & ws);
public:
/**
* @brief Конструктор без параметров
* @details Запрещен
*/
	modAlphaCipher()=delete;
/**
* @brief Конструктор для установки ключа
* @details Ключ проверяется на валидность. Переводится в
кодировку UTF-32.
* Формируется вектор-ключ.
* @param [in] skey Ключ в кодировке UTF-8
* @throw cipher_error ключ вырожденный
*/
	modAlphaCipher(const std::string& skey);
/**
* @brief Зашифровывание
* @param [in] open_text Открытый текст в кодировке UTF-8. Не
должен быть пустой строкой.
* Строчные символы автоматически преобразуются к прописным.Все
не-буквы удаляются.
* @return Зашифрованная строка в кодировке UTF-8
* @throw cipher_error текст пустой
*/
	std::string encrypt(const std::string& open_text);
/**
* @brief Расшифровывание
* @param [in] cipher_text Зашифрованный текст в кодировке
UTF-8. Не должен быть пустой строкой.
* Не должен содержать строчные символы и не-буквы.
* @return Расифрованная строка в кодировке UTF-8
* @throw cipher_error текст пустой
*/
	std::string decrypt(const std::string& cipher_text);
/**
* @brief Перевод из кодировки UTF-8 в UTF-32
* @param [in] s Строка в кодировке UTF-8
* @return Строка в кодировке UTF-32
*/
	std::wstring towstr(const std::string& s);
/**
* @brief Перевод из кодировки UTF-32 в UTF-8
* @param [in] s Строка в кодировке UTF-32
* @return Строка в кодировке UTF-8
*/
	std::string fromwstr(const std::wstring& ws);
};
/**@brief Класс-исключение.
* @details Призводный от класса invalid_argument.
* При перегрузке конструкторов явно указаны вызов конструктора
базового класса с параметром.
*/
class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg):std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):std::invalid_argument(what_arg) {}
};