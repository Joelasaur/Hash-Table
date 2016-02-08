#include "gtest/gtest.h"
#include "adt.h"
#include "csString.h"
#include <string.h>

#define SEND(receiver, wutdo)\
	receiver->methods->wutdo(receiver)

#define SEND1(receiver,wutdo,arg)\
	receiver->methods->wutdo(receiver,arg)

TEST(AdtTest, testHash){
	csAdtRef thing1 = newCsAdt();
	csAdtRef thing2 = newCsAdt();
	uint32_t hash1 = SEND(thing1,hash);
	uint32_t hash2 = SEND(thing2,hash);
	EXPECT_EQ(hash1, SEND(thing1,hash));
	EXPECT_EQ(hash2, SEND(thing2,hash));
	EXPECT_NE(hash1,hash2);
}

TEST(AdtTest, testEquals){
	csAdtRef thing1 = newCsAdt();
	csAdtRef thing2 = newCsAdt();
	EXPECT_TRUE(SEND1(thing1,equals,thing1));
	EXPECT_TRUE(SEND1(thing2,equals,thing2));
	EXPECT_FALSE(SEND1(thing1,equals,thing2));
}

TEST(csStringTest, testHash){
	csStringRef thing1 = newCSString((char *)"testString1");
	csStringRef thing2 = newCSString((char *)"testString2");
	uint32_t hash1 = SEND(thing1,hash);
	uint32_t hash2 = SEND(thing2,hash);
	EXPECT_EQ(hash1, SEND(thing1,hash));
	EXPECT_EQ(hash2, SEND(thing2,hash));
	EXPECT_NE(hash1,hash2);
}

TEST(csStringTest, testEquals){
	csStringRef string1 = newCSString((char *)"testString");
	csStringRef string2 = newCSString((char *)"testString");
	csStringRef string3 = newCSString((char *)"testString");
	csStringRef string4 = newCSString((char *)"notLikeTheOthers");
	EXPECT_TRUE(SEND1(string1, equals, (csAdtRef)string2));
	EXPECT_TRUE(SEND1(string2, equals, (csAdtRef)string3));
	EXPECT_TRUE(SEND1(string1, equals, (csAdtRef)string3));
	EXPECT_FALSE(SEND1(string1, equals, (csAdtRef)string4));
}

