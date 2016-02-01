#include "gtest/gtest.h"
#include "adt.h"
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
