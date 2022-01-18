#include "Misc/AutomationTest.h"
#include "GoogleTest/include/gmock/gmock.h"
#include "GMock/Public/GMockUEAdapter.h"
#include "SampleProject/Tests/Mocks/MockGun.h"

using ::testing::Exactly;

BEGIN_DEFINE_SPEC(SampleSpec, "SampleProject.SampleSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	END_DEFINE_SPEC(SampleSpec)

	void SampleSpec::Define()
{
	BeforeEach([this]()
		{
			GMockUEAdapter::Enable();
		});

	Describe("this simple test", [this]()
		{
			It("test 1", [this]()
				{
					MockGun* mockWeapon = new MockGun();
					EXPECT_CALL(*mockWeapon, Fire())
						.Times(Exactly(1));

					delete mockWeapon;
				});

		});
}