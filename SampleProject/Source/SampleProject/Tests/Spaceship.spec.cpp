#include "Misc/AutomationTest.h"
#include "GoogleTest/include/gmock/gmock.h"
#include "GMock/Public/GMockUEAdapter.h"
#include "Mocks/MockWeapon.h"
#include "Mocks/MockPlayerStatsService.h"
#include "Spaceship.h"

using ::testing::Exactly;
using ::testing::Mock;

BEGIN_DEFINE_SPEC(SpaceshipSpec, "SampleProject.SpaceshipSpec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

// Declare variables shared across tests.
ASpaceship* Ship;
UMockWeapon* MockWeapon;
FMockPlayerStatsService* MockPlayerStatsService;

END_DEFINE_SPEC(SpaceshipSpec)

void SpaceshipSpec::Define()
{
    BeforeEach([this]()
    {
        // Activate the GMockUEAdapter. This is required for GMock to work
        // in UE tests.
        GMockUEAdapter::Enable();

        // Create an instance of the class we're testing being careful to
        // supply mock implementations of all dependencies so that our 
        // instance is fully isolated from the rest of the system during the 
        // tests.
        MockWeapon = NewObject<UMockWeapon>();
        MockPlayerStatsService = new FMockPlayerStatsService();
        Ship = ASpaceship::Create(MockWeapon, MockPlayerStatsService);
    });

    Describe("FireAt()", [this]()
    {
        It("fires the ship's weapon", [this]()
        {
            // SETUP

            EXPECT_CALL(*MockWeapon, Fire())
                .Times(Exactly(1));

            // EXERCISE

            Ship->FireAt(FVector());

            // VERIFY

            Mock::VerifyAndClearExpectations(MockWeapon);
        });

        It("increments the player's 'shots fired' stats", [this]()
        {
            // SETUP

            EXPECT_CALL(*MockPlayerStatsService, RecordWeaponFire())
                .Times(Exactly(1));

            // EXERCISE

            Ship->FireAt(FVector());

            // VERIFY

            Mock::VerifyAndClearExpectations(MockPlayerStatsService);
        });
    });
}