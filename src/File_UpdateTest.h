#include <cxxtest/TestSuite.h>

//extern void file_UpdateMain(EMP emp_rec[], int size, FILE *fp);
extern const char* file_UpdateMain(int argc, char** argv);

class File_UpdateTest : public CxxTest::TestSuite
{

public:
	void setUp() {
	}

	void tearDown(){
	}

	void test_SimpleIOCompare(){
		char* argv[] = {};
		const char* message = file_UpdateMain(sizeof(argv), argv);

		TS_ASSERT_EQUALS("Hello world\n", message);
	}
	

	
};