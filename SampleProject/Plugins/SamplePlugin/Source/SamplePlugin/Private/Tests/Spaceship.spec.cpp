#include "Misc/AutomationTest.h" // Required in all spec files
#include "GoogleTest/include/gmock/gmock.h"

#include "Mocks/MockWeapon.h"

using ::testing::Exactly;

// Generate the header for our spec class using a macro.
BEGIN_DEFINE_SPEC(SpaceshipSpec, "SampleProject.SpaceshipSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	// Declare any variables shared across this spec's tests here.
	
END_DEFINE_SPEC(SpaceshipSpec)

// Override the Define() method to define our tests.
void SpaceshipSpec::Define()
{
	Describe("The test", [this]()
		{
			It("mock", [this]()
				{
					// SETUP

					MockWeapon* Weapon = new MockWeapon();
					EXPECT_CALL(*Weapon, Fire())
						.Times(Exactly(1));

					// EXERCISE

					Weapon->Fire();

					// VALIDATE
					
					// IMPORTANT: The expectations of the mock are not evaluated until the object is destroyed so you must
					// explicitly delete the mock object in the scope of the test.
					delete Weapon;
				});
		});
}