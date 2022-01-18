#include "Misc/AutomationTest.h"
#include "GoogleTest/include/gmock/gmock.h"
#include "GMock/Public/GMockUEAdapter.h"
#include "SampleProject/Tests/Mocks/MockGun.h"
#include "SampleProject/Tests/Mocks/MockWeapon.h"
#include "Engine/Engine.h"

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
			LatentIt("test 1", [this](const FDoneDelegate& Done)
				{
					//MockGun* mockWeapon = new MockGun();
					UMockWeapon* mockWeapon = NewObject<UMockWeapon>();
					EXPECT_CALL(*mockWeapon, Fire())
						.Times(Exactly(1));

					//delete mockWeapon;
					//mockWeapon->ConditionalBeginDestroy();
					//mockWeapon = NULL;

					UWorld* World = GEngine->GetWorld();
					//World->ForceGarbageCollection();

					World->GetTimerManager().SetTimerForNextTick(Done);
				});

		});
}