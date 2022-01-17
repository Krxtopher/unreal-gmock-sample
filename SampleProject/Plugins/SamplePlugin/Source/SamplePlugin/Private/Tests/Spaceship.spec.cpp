#include "Misc/AutomationTest.h"
#include "GoogleTest/include/gmock/gmock.h"

#include "Spaceship.h"
#include "Mocks/MockWeapon.h"

using ::testing::Exactly;

BEGIN_DEFINE_SPEC(SpaceshipSpec, "SamplePlugin.SpaceshipSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

END_DEFINE_SPEC(SpaceshipSpec)

void SpaceshipSpec::Define()
{
	Describe("Attack()", [this]()
		{
			It("should fire its weapon", [this]()
				{
					// SETUP

					MockWeapon* mockWeapon = new MockWeapon();
					EXPECT_CALL(*mockWeapon, Fire())
						.Times(Exactly(2));

					// Create a USpaceship instance that uses our mock weapon.
					USpaceship* Ship = USpaceship::Create(mockWeapon);

					// EXERCISE

					Ship->FireAt(FVector());

					// VALIDATE
					
					// IMPORTANT: The expectations of the mock are not evaluated until the object is destroyed so you must
					// explicitly delete the mock object in the scope of the test.
					delete mockWeapon;
				});
		});
}