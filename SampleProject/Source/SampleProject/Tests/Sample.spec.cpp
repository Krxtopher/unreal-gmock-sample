#include "Misc/AutomationTest.h"
#include "GoogleTest/include/gmock/gmock.h"
#include "GMock/Public/GMockUEAdapter.h"
#include "SampleProject/Tests/Mocks/MockWeapon.h"
#include "Engine/Engine.h"
#include "Spaceship.h"

using ::testing::Exactly;
using ::testing::Mock;

BEGIN_DEFINE_SPEC(SampleSpec, "SampleProject.SampleSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	END_DEFINE_SPEC(SampleSpec)

	void SampleSpec::Define()
{
	BeforeEach([this]()
		{
			GMockUEAdapter::Enable();
		});

	Describe("FireAt()", [this]()
		{
			It("fires the ship's weapon", [this]()
				{
					// SETUP

					UMockWeapon* MockWeapon = NewObject<UMockWeapon>();
					EXPECT_CALL(*MockWeapon, Fire())
						.Times(Exactly(1));

					ASpaceship* Ship = ASpaceship::Create(MockWeapon);

					// EXERCISE

					Ship->FireAt(FVector());

					// VERIFY

					Mock::VerifyAndClearExpectations(MockWeapon);
				});

		});
}