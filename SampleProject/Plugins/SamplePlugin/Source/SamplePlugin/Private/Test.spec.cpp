#include "Misc/AutomationTest.h" // Required in all spec files
#include "GoogleTest/include/gmock/gmock.h"

#include "MockWeapon.h"

using ::testing::Exactly;

// Generate the header for our spec class using a macro.
BEGIN_DEFINE_SPEC(TestSpec, "SampleProject.TestSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	// Declare any variables shared across this spec's tests here.
	
END_DEFINE_SPEC(TestSpec)

// Override the Define() method to define our tests.
void TestSpec::Define()
{
	Describe("The test", [this]()
		{
			It("mock", [this]()
				{
					MockWeapon* Weapon = new MockWeapon();
					EXPECT_CALL(*Weapon, Fire())
						.Times(Exactly(1));

					// IMPORTANT: The expectations of the mock are not evaluated until the object is destroyed so you must
					// explicitly delete the mock object in the scope of the test.
					delete Weapon;
				});
		});
}