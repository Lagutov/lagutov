#include <unittest++/UnitTest++.h>
#include "Cipher.h"

struct Key_fixture {
	Cipher * p;
	Key_fixture() {
		p = new Cipher(4,"qkuxecoohirftubn");
	}
	~Key_fixture() {
		delete p;
	}
};

SUITE(KeyTest)
{
	TEST(ValidKrKey) {
		CHECK_EQUAL("qkuxecoohirftubn",Cipher(4,"qkuxecoohirftubn").encrypt("thequickbrounfox"));
	}
	TEST(ValidNotKrKey) {
		CHECK_EQUAL("uro*qbf*ekn*hcu*tiox", Cipher(5,"qkuxecoohirftubn").encrypt("thequickbrounfox"));
	}
	TEST(ZeroKey) {
		CHECK_THROW(Cipher cp(0,"qkuxecoohirftubn"),Error);
	}
	TEST(WeakKey) {
		CHECK_THROW(Cipher cp(1,"qkuxecoohirftubn"),Error);
	}
	TEST(NegativeKey) {
		CHECK_THROW(Cipher cp(-4,"qkuxecoohirftubn"),Error);
	}
}
SUITE(EncryptTest)
{
	TEST_FIXTURE(Key_fixture, UpCaseString) {
	CHECK_EQUAL("QKUXECOOHIRFTUBN",p->encrypt("THEQUICKBROUNFOX"));
	}
	TEST_FIXTURE(Key_fixture, LowCaseString) {
		CHECK_EQUAL("qkuxecoohirftubn",p->encrypt("thequickbrounfox"));
	}
	TEST_FIXTURE(Key_fixture, LowAndUpCaseString) {
		CHECK_EQUAL("QkuxecoohirFTuBn",p->encrypt("TheQuickBrounFox"));
	}
	TEST_FIXTURE(Key_fixture, SpaceAndPunctString) {
		CHECK_THROW(p->encrypt("the quick broun fox!!!"),Error);
	}
	TEST_FIXTURE(Key_fixture, digitString) {
		CHECK_THROW(p->encrypt("thequickbrounfox99"), Error);
	}
	TEST_FIXTURE(Key_fixture, EmptyString) {
		CHECK_THROW(p->encrypt(""),Error);
	}
	TEST_FIXTURE(Key_fixture, noAlphaString) {
		CHECK_THROW(p->encrypt("2+2=4"),Error);
	}
	
}

SUITE(DecryptTest)
{
	TEST_FIXTURE(Key_fixture, UpCaseString) {
		CHECK_EQUAL("THEQUICKBROUNFOX",p->decrypt("QKUXECOOHIRFTUBN"));
	}
	TEST_FIXTURE(Key_fixture, LowCaseString) {
		CHECK_EQUAL("thequickbrounfox",p->decrypt("qkuxecoohirftubn"));
	}
	TEST_FIXTURE(Key_fixture, LowAndUpCaseString) {
		CHECK_EQUAL("TheQuickBrounFox",p->decrypt("QkuxecoohirFTuBn"));
	}
	TEST_FIXTURE(Key_fixture, PunctString) {
		CHECK_THROW(p->decrypt("qkuxe,coohirftubn"), Error);
	}
	TEST_FIXTURE(Key_fixture, digitString) {
		CHECK_THROW(p->decrypt("qkuxecoohirftubn99"), Error);
	}
	TEST_FIXTURE(Key_fixture, EmptyString) {
		CHECK_THROW(p->decrypt(""),Error);
	}
	TEST_FIXTURE(Key_fixture, SpaceString) {
		CHECK_THROW(p->decrypt("qkuxe coohirftubn"), Error);
	}

}
int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}