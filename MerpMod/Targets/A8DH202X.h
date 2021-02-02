#define MOD_DATE 15.4.8.911

#include "Switch.h"
#define MOD_CONFIG Switch
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DH202X
#define ECU_IDENTIFIER 4312584206
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CFB8C)
#define dRomHoleStart (0x000E1400)
#define pRamHoleStart (0xFFFF96C0)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Switch Hacks
/////////////////////

#define pTGVLeftVoltage ((unsigned short*)0xFFFF5C0A)
#define pTGVRightVoltage ((unsigned short*)0xFFFF5C0C)
#define sShortToFloat (0x00002594)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00014EB4)
#define sRevLimStart (0x00033D68)
#define sRevLimEnd (0x00033D9E)
#define pFlagsRevLim ((unsigned char*)0xFFFF74EC)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008314)
#define sMafCalc (0x000082B8)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C82E8)
#define hInjectorScaling (0x0002B738)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0008C1FC)
#define hCelSignal (0x0008C314)
#define pCelSignalOem ((unsigned char*)0xFFFF930E)

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x00017750)
#define hTableTargetBoost (0x00017764)
#define tTargetBoost (0x000939C4)
#define hTableTargetBoostAlt (0x00017758)
#define tTargetBoostAlt (0x000939A8)

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x00017BCC)
#define hWgdc (0x00014964)
#define sWgdc (0x00017260)
#define sJsrWgdcInitial (0x00017AC2)
#define hTableWgdcInitial (0x00017BD4)
#define tWgdcInitial (0x0009391C)
#define tTableWgdcInitialAlt (0x00017BDC)
#define hJsrWgdcMax (0x00017B24)
#define hTableWgdcMax (0x00017C10)
#define tWgdcMax (0x00093954)
#define tWgdcMaxAlt (0x00093938)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7324)
#define hPull3DPolf (0x000306A0)
#define tPolf (0x00095420)
#define hTablePolf (0x000306AC)
#define hJsrPolf (0x00030518)
#define hPolf (0x00014EE0)
#define sPolf (0x0003046C)
#define pPolfEnrich (0xFFFF7324)

/////////////////////
// Timing Hacks
/////////////////////

#define hBaseTiming (0x00014F9C)
#define hTableBaseTiming (0x00037DE0)
#define tBaseTiming (0x00095B28)
#define pBaseTiming (0xFFFF76A4)
#define sBaseTiming (0x00037C72)
#define hPull3DTiming (0x00037DDC)
#define hSubKca (0x00037654)
#define pKcaIam (0xFFFF7840)
#define pBaseTimingIdle (0xFFFF76C0)
#define hPullBaseTimingIdle (0x00038290)
#define hTableBaseTimingIdleInGearA (0x00038294)
#define tBaseTimingIdleInGearA (0x00095734)
#define hTableBaseTimingIdleInGearB (0x00038298)
#define tBaseTimingIdleInGearB (0x00095748)
#define hTableBaseTimingIdleNeutralA (0x0003829C)
#define tBaseTimingIdleNeutralA (0x0009575C)
#define hTableBaseTimingIdleNeutralB (0x000382A0)
#define tBaseTimingIdleNeutralB (0x00095770)

/////////////////////
// Spark Cut
/////////////////////

#define sSparkCutOcrStart (0x0000A756)
#define sSparkCutOcrEnd (0x0000A76C)
#define sSparkCutGrStart (0x0000A7C6)
#define sSparkCutGrEnd (0x0000A7CE)

/////////////////////
// Flags-Signals
/////////////////////

#define pCruiseMasterFlags ((unsigned char*)0xFFFF64B0)
#define CruiseMasterBitMask ((unsigned char)0x01)
#define pResumeFlags ((unsigned char*)0xFFFF64B0)
#define ResumeBitMask ((unsigned char)0x04)
#define pCoastFlags ((unsigned char*)0xFFFF64B0)
#define CoastBitMask ((unsigned char)0x02)
#define pBrakeFlags ((unsigned char*)0xFFFF64B0)
#define BrakeBitMask ((unsigned char)0x08)
#define pClutchFlags ((unsigned char*)0xFFFF69F1)
#define ClutchBitMask ((unsigned char)0x80)
#define pIdleFlags ((unsigned char*)0xFFFF6946)
#define IdleBitMask ((unsigned char)0x80)
#define pNeutralFlags ((unsigned char*)0xFFFF69EF)
#define NeutralBitMask ((unsigned char)0x02)
#define pDefoggerFlags ((unsigned char*)0xFFFF69EF)
#define DefoggerBitMask ((unsigned char)0x20)
#define pClosedLoopFlags ((unsigned char*)0xFFFF9299)
//8 = Closed Loop (normal)]  [10 = Open Loop (normal)]  [7 = Open Loop due insufficient coolant temp]  [14 = Open Loop due to system failure].

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6B6C)
#define pFbkc4 ((float*)0xFFFF77FC)
#define pIam1 ((unsigned char*)0xFFFF6B71)
#define pIam4 ((float*)0xFFFF2B3C)
#define pEngineSpeed ((float*)0xFFFF6A18)
#define pVehicleSpeed ((float*)0xFFFF6A10)
#define pCoolantTemp ((float*)0xFFFF67C4)
#define pAtmoPress ((float*)0xFFFF5CD4)
#define pManifoldAbsolutePressure ((float*)0xFFFF6698)
#define pIntakeAirTemp ((float*)0xFFFF5C9C)
#define pMassAirFlow ((float*)0xFFFF5CD0)
#define pMafSensorVoltage ((short*)0xFFFF5BFE)
#define pEngineLoad ((float*)0xFFFF6848)
#define pReqTorque ((float*)0xFFFF7AF0)
#define pThrottlePlate ((float*)0xFFFF673C)
#define pWgdc4 ((float*)0xFFFF63A0)
#define pCurrentGear ((unsigned char*)0xFFFF6B21)
#define pAf1Res ((float*)0xFFFF5F08)
#define pDeltaMap ((float*)0xFFFF668C)
#define pAcceleratorPedal ((float*)0xFFFF68E4)
#define pThrottlePlateTarget ((float*)0xFFFF7AE8)
#define tTargetThrottlePlateA (0x00096498)
#define hTableTargetThrottlePlateA (0x000BE734)
#define pTargetIdleSpeed ((float*)0xFFFF7C3C)
#define hPullTargetIdleSpeed (0x00042EB8)
#define hTableTargetIdleSpeedA (0x00042EBC)
#define tTargetIdleSpeedA (0x00095F1C)
#define hTableTargetIdleSpeedB (0x00042EC4)
#define tTargetIdleSpeedB (0x00095F44)
#define hTableTargetIdleSpeedC (0x00042ECC)
#define tTargetIdleSpeedC (0x00095F6C)
#define hPullIdleMapSelection (0x00042EA4)
#define pIdleMapSelection (0xFFFF7CB4)
#define hPullRequestedTorqueA (0x000BEA7C)
#define tRequestedTorqueA (0x000964D0)
#define hTableRequestedTorqueA (0x000BE9FC)
#define sFloatToShort (0x00002564)
#define sFloatToByte (0x000025A4)
#define dEvapFuelComp (0x000273c0)              //fix
#define pCPCDutyRatio ((float*)0xFFFF6BC0)
#define pAirPump ((float*)0xFFFF62CC)
#define pFuelLevel ((float*)0xFFFF67F0)
#define pSTFTs1 ((float*)0xFFFF707C)
#define pLTFTsA ((float*)0xFFFF7238)
//#define dLTFTLimitA (0x000C8568)  Ready for idatohew & Metahooks
//#define dLTFTLimitB (0x000C856C)  Ready for idatohew & Metahooks
#define hLTFTLimitA1 (0x0002EE44)
#define hLTFTLimitB1 (0x0002EE40)
#define hLTFTLimitA2 (0x0002F50C)
#define hLTFTLimitB2 (0x0002F508)
#define pAVCS ((float*)0xFFFF8308)
#define hPullAVCS (0x00053984)
#define tAVCS (0x00096A28)
#define hTableAVCS (0x0005398C)
#define pO2SensorScaling ((float*)0xFFFF5F00)
#define hPullO2SensorScaling (0x0000BFD8)
#define tO2SensorScaling (0x00096600)
#define hTableO2SensorScaling (0x0000BFD4)
#define pAFSensor1Current ((float*)0xFFFF5F04)
#define hOpenLoopAFRmin (0x000306C0)
#define dOpenLoopAFRmin (0x000C8598)
#define dSSMReplace (0x0004E510)
#define hSSMReplace1 (0x00056290)
#define hSSMReplace2 (0x00056294)
#define hTargetTPSBandPass (0x000BE73C)
#define sBandPass (0x000024D8)
#define sDutyCycleOut (0x000023A8)
#define hDutyCycleOut (0x00011A00)
#define hTargetTPSIdle (0x000BEB2C)
#define pTargetTPSIdle ((float*)0xFFFF7B70)
////#define sBasicMotions (0x0002495A)
////#define hBasicMotions (0x0002495A)
#define hFuelCut (0x00035BD0)
#define pFuelCut ((short*)0xFFFF6F74)
#define pBoost ((float*)0xFFFF669C)
#define hPrepForSpark (0x00006E0C)
#define sPrepForSpark (0x0000A458)
#define pCyl1SparkCut ((unsigned char*)0xFFFF5DF0)
#define pCyl2SparkCut ((unsigned char*)0xFFFF5DF8)
#define pCyl3SparkCut ((unsigned char*)0xFFFF5E00)
#define pCyl4SparkCut ((unsigned char*)0xFFFF5E08)
#define hPedalSub (0x000067DC)
#define sPedalSub (0x0000CF24)
//#define sAfterAD (0x00006e64)
//#define sAfterReloadAD (0x000066b8)
//#define hAfterAD (0x000067b4)
//#define hAfterReloadAD (0x000066b8)
#define pPedalVoltage ((short*)0xFFFF5c00)
#define pSubPedalVoltage ((short*)0xFFFF5c02)
#define pTargetIdleAir ((float*)0xFFFF7b6c)


/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C23B8)
#define dLoadSmoothingB (0x000C23BC)
#define dLoadSmoothingFinal (0x000C23C8)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FCAC)
#define hMemoryReset (0x0000DBC8)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00012038)
#define sMemorySoftReset (0x00056A24)


