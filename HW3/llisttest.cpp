#include "llistint.h"
#include "gtest/gtest.h"

class LListIntTest : public testing::Test {
protected:
	

	LListIntTest() {
		
	}

	virtual ~LListIntTest() {
			
	}

	
	virtual void SetUp() {
		
		list.insert(0, 12);
		list.insert(1, 3);
		list.insert(2, 87);
	}

	
	LListInt list;
};

TEST_F(LListIntTest, CopyConstructor) {
	LListInt* newList = new LListInt();
	newList(list); // not too sure about syntax here when using the copy constructor
	EXPECT_EQ(newList.size(), 3);
	EXPECT_EQ(newList.get(0), 12);
	EXPECT_EQ(newList.get(1), 3);
	EXPECT_EQ(newList.get(2), 87);

}

TEST_F(LListIntTest, AssignnmentOp) {
	list.insert(3, 30);
	LListInt* newList = new LListInt();
	newList.insert(0, 22);
	newList.insert(1, 45);
	EXPECT_EQ(list.size(), 2);
	newList = list;
	EXPECT_EQ(newList.get(3), 30);
	EXPECT_EQ(newList.get(1), 3);
	EXPECT_EQ(newList.size(), 4);


}

TEST_F(LListIntTest, ConcatenationOp) {
	LListInt* newList = new LListInt();
	newList.insert(0, 22);
	newList.insert(1, 45);
	list = list + newList;
	EXPECT_EQ(list.get(3), 22);
	EXPECT_EQ(list.get(4), 45);
	EXPECT_EQ(list.size(), 5);
}

TEST_F(ArrayListTest, AccessOp) {
	EXPECT_EQ(list[0], 12);
	EXPECT_EQ(list[1], 3);
	EXPECT_EQ(list[2], 87);


}
