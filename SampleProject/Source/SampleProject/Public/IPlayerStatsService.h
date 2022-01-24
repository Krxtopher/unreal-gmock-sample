#pragma once

/**
 * An interface for any service that records player stats.
 */
class SAMPLEPROJECT_API IPlayerStatsService
{
public:
    virtual ~IPlayerStatsService() {}
    virtual void RecordWeaponFire() = 0;
};