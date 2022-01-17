#include "Misc/AutomationTest.h"

#include "Gunslinger.h"

BEGIN_DEFINE_SPEC(GunslingerSpec, "SampleProject.GunslingerSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	END_DEFINE_SPEC(GunslingerSpec)

	void GunslingerSpec::Define()
{
	Describe("this simple test", [this]()
		{
			It("should pass", [this]()
				{
					TestEqual("equality", "Player 1", "Player 1");
				});
		});
}