#include "Misc/AutomationTest.h"
#include "GoogleTest/include/gmock/gmock.h"

#include "Tests/Mocks/MockShield.h"
#include "../../Plugins/SamplePlugin/Source/SamplePlugin/Public/Tests/GTestFailureReporter.h"

using ::testing::Exactly;
using ::testing::UnitTest;

BEGIN_DEFINE_SPEC(GunslingerSpec, "SampleProject.GunslingerSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	END_DEFINE_SPEC(GunslingerSpec)

	void GunslingerSpec::Define()
{
	BeforeEach([this]()
		{
			// Register a custom listener that adapts GTest failure events to UE error 
			// messages which the UE AutomationTest framework uses to detect test
			// failures.
			UnitTest::GetInstance()->listeners()
				.Append(new GTestFailureReporter());
		});

	Describe("this simple test", [this]()
		{
			It("test 1", [this]()
				{
					MockShield* mockShield = new MockShield();
					EXPECT_CALL(*mockShield, SetPower(5.0))
						.Times(Exactly(1));

					delete mockShield;
				});

			It("test 2", [this]()
				{
					MockShield* mockShield = new MockShield();
					EXPECT_CALL(*mockShield, SetPower(8.0))
						.Times(Exactly(1));

					delete mockShield;
				});
		});
}