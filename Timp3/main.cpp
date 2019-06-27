#include <unittest++/UnitTest++.h>
#include "modAlphaCipher.h"

struct KeyB_fixture {
	modAlphaCipher * p;
	KeyB_fixture() {
		p = new modAlphaCipher("Б");
	}
	~KeyB_fixture() {
		delete p;
	}
};

SUITE(KeyTest)
{
	TEST(ValidKey) {
		CHECK_EQUAL("БВГБВ",modAlphaCipher("БВГ").encrypt("ААААА"));
	}
	TEST(LongKey) {
		CHECK_EQUAL("БВГДЕ",modAlphaCipher("БВГДЕЁЖЗИЙ").encrypt("ААААА"));
	}
	TEST(LowCaseKey) {
		CHECK_EQUAL("БВГБВ",modAlphaCipher("бвг").encrypt("ААААА"));
	}
	TEST(DigitsInKey) {
		CHECK_THROW(modAlphaCipher cp("Б1"),cipher_error);
	}
	TEST(PunctuationInKey) {
		CHECK_THROW(modAlphaCipher cp("Б,В"),cipher_error);
	}
	TEST(WhitespaceInKey) {
		CHECK_THROW(modAlphaCipher cp("Б В"),cipher_error);
	}
	TEST(EmptyKey) {
		CHECK_THROW(modAlphaCipher cp(""),cipher_error);
	}
	TEST(WeakKey) {
		CHECK_THROW(modAlphaCipher cp("ААА"),cipher_error);
	}
}

SUITE(EncryptTest)
{
	TEST_FIXTURE(KeyB_fixture, UpCaseString) {
		CHECK_EQUAL("БВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯА", p->encrypt("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"));
	}
	TEST_FIXTURE(KeyB_fixture, LowCaseString) {
		CHECK_EQUAL("БВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯА", p->encrypt("абвгдеёжзийклмнопрстуфхцчшщъыьэюя"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
		CHECK_EQUAL("БВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯА", p->encrypt("АБВГ ДЕЁЖЗИЙ КЛМНОПР СТУФХЦЧ ШЩЪЫЬЭЮ Я!!!"));
	}
	TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
		CHECK_EQUAL("ТШБТУМЙГПДПОПГПДПДПЕБ", p->encrypt("Счастливого Нового 2019 года"));
	}
	TEST_FIXTURE(KeyB_fixture, EmptyString) {
		CHECK_THROW(p->encrypt(""),cipher_error);
	}
	TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
		CHECK_THROW(p->encrypt("1234+8765=9999"),cipher_error);
	}
	TEST(MaxShiftKey) {
		CHECK_EQUAL("ЯАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮ", modAlphaCipher("Я").encrypt("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"));
	}
}

SUITE(DecryptText)
{
	TEST_FIXTURE(KeyB_fixture, UpCaseString) {
		CHECK_EQUAL("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ", p->decrypt("БВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯА"));
	}
	TEST_FIXTURE(KeyB_fixture, LowCaseString) {
		CHECK_THROW(p->decrypt("бвгДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯА"),cipher_error);
	}
	TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
		CHECK_THROW(p->decrypt("БВГД ЕЁЖЗИЙКЛ МНОПРСТУФХ ЦЧШЩЪЫЬЭЮЯА"),cipher_error);
	}
	TEST_FIXTURE(KeyB_fixture, DigitsString) {
		CHECK_THROW(p->decrypt("БВГДЕЁЖ222ЩЪЫЬЭЮЯА"),cipher_error);
	}
	TEST_FIXTURE(KeyB_fixture, PunctString) {
		CHECK_THROW(p->decrypt("БВГДЕ,ЫЬЭЮЯА"),cipher_error);
	}
	TEST_FIXTURE(KeyB_fixture, EmptyString) {
		CHECK_THROW(p->decrypt(""),cipher_error);
	}
	TEST(MaxShiftKey) {
		CHECK_EQUAL("АБВГДЕЁЖЗИЙКЛМНОПРCТУФХЦЧШЩЪЫЬЭЮЯ", modAlphaCipher("Я").decrypt("ЯАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮ"));
	}
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
