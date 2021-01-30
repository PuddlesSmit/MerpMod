#define MOD_DATE 2.2.20.001

#include "Switch.h"
#define MOD_CONFIG Switch
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DH200V
#define ECU_IDENTIFIER 4352594006
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CDD54)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF8FE0)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Switch Hacks
/////////////////////

#define pTGVLeftVoltage ((unsigned short*)0xFFFF5C0A)
#define pTGVRightVoltage ((unsigned short*)0xFFFF5C0C)
#define sShortToFloat (0x00002594)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0001483C)
#define sRevLimStart (0x00030D10)
#define sRevLimEnd (0x00030D46)
#define pFlagsRevLim ((unsigned char*)0xFFFF71BC)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000081BC)
#define sMafCalc (0x00008160)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C6A0C)
#define hInjectorScaling (0x00028C70)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007806C)
#define hCelSignal (0x00078184)
#define pCelSignalOem ((unsigned char*)0xFFFF8BA2)

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x000170C8)
#define hTableTargetBoost (0x000170DC)
#define tTargetBoost (0x0007F78C)
#define hTableTargetBoostAlt (0x000170D0)
#define tTargetBoostAlt (0x000939A8)

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x000174F0)
#define hWgdc (0x000143F4)
#define sWgdc (0x00016BD8)
#define sJsrWgdcInitial (0x0001742C)
#define hTableWgdcInitial (0x000174F8)
#define tWgdcInitial (0x0007F6E4)
#define tTableWgdcInitialAlt (0x00017500)
#define hJsrWgdcMax (0x0001756C)
#define hTableWgdcMax (0x00017534)
#define tWgdcMax (0x0007F71C)
#define tWgdcMaxAlt (0x0007F700)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7028)
#define hPull3DPolf (0x0002DBA8)
#define tPolf (0x80EB4)
#define hTablePolf (0x0002DBB4)
#define hJsrPolf (0x0002DA20)
#define hPolf (0x00014858)
#define sPolf (0x0002D974)
#define pPolfEnrich (0xFFFF7028)

/////////////////////
// Timing Hacks
/////////////////////

#define hBaseTiming (0x00014914)
#define hTableBaseTiming (0x343E8)
#define tBaseTiming (0x0008154C)
#define pBaseTiming (0xFFFF7354)
#define sBaseTiming (0x0003427A)
#define hPull3DTiming (0x000343E4)
#define hSubKca (00033C74)
#define pKcaIam (0xFFFF74D4)
#define pBaseTimingIdle (0xFFFF7370)
#define hPullBaseTimingIdle (0x00034898)
#define hTableBaseTimingIdleInGearA (0x0003489C)
#define tBaseTimingIdleInGearA (0x000811BC)
#define hTableBaseTimingIdleInGearB (0x000348A0)
#define tBaseTimingIdleInGearB (0x000811D0)
#define hTableBaseTimingIdleNeutralA (0x000348A4)
#define tBaseTimingIdleNeutralA (0x000811E4)
#define hTableBaseTimingIdleNeutralB (0x000348A8)
#define tBaseTimingIdleNeutralB (0x000811F8)
#define hFBKCRetardValue (0x368B0)
#define dFBKCRetardValue ((float*)0xC9FBC)
#define hFBKCRetardValueAlternate (0x36890)
#define dFBKCRetardValueAlternate ((float*)0xC9FC0)

/////////////////////
// Spark Cut
/////////////////////

#define sSparkCutOcrStart (0x0000A5FE)
#define sSparkCutOcrEnd (0x0000A614)
#define sSparkCutGrStart (0x0000A66E)
#define sSparkCutGrEnd (0x0000A676)

/////////////////////
// Flags-Signals
/////////////////////

#define pCruiseMasterFlags ((unsigned char*)0xFFFF643C)
#define CruiseMasterBitMask ((unsigned char)0x01)
#define pResumeFlags ((unsigned char*)0xFFFF643C)
#define ResumeBitMask ((unsigned char)0x04)
#define pCoastFlags ((unsigned char*)0xFFFF643C)
#define CoastBitMask ((unsigned char)0x02)
#define pBrakeFlags ((unsigned char*)0xFFFF643C)
#define BrakeBitMask ((unsigned char)0x08)
#define pClutchFlags ((unsigned char*)0xFFFF6975)
#define ClutchBitMask ((unsigned char)0x80)
#define pIdleFlags ((unsigned char*)0xFFFF68CA)
#define IdleBitMask ((unsigned char)0x80)
#define pNeutralFlags ((unsigned char*)0xFFFF6973)
#define NeutralBitMask ((unsigned char)0x02)
#define pDefoggerFlags ((unsigned char*)0xFFFF6973)
#define DefoggerBitMask ((unsigned char)0x20)
#define pClosedLoopFlags ((unsigned char*)0xFFFF8B2D)
//8 = Closed Loop (normal)]  [10 = Open Loop (normal)]  [7 = Open Loop due insufficient coolant temp]  [14 = Open Loop due to system failure].

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6AF0)
#define pFbkc4 ((float*)0xFFFF7490)
#define pIam1 ((unsigned char*)0xFFFF6AF5)
#define pIam4 ((float*)0xFFFF2910)
#define pEngineSpeed ((float*)0xFFFF699C)
#define pVehicleSpeed ((float*)0xFFFF6994)
#define pCoolantTemp ((float*)0xFFFF5CAC)
#define pAtmoPress ((float*)0xFFFF5CD4)
#define pManifoldAbsolutePressure ((float*)0xFFFF6624)
#define pIntakeAirTemp ((float*)0xFFFF5C9C)
#define pMassAirFlow ((float*)0xFFFF5CD0)
#define pMafSensorVoltage ((short*)0xFFFF5BFE)
#define pEngineLoad ((float*)0xFFFF67CC)
#define pReqTorque ((float*)0xFFFF7784)
#define pThrottlePlate ((float*)0xFFFF66C8)
#define pWgdc4 ((float*)0xFFFF63A0)
#define pCurrentGear ((unsigned char*)0xFFFF6AA5)
#define pAf1Res ((float*)0xFFFF5F08)
#define pDeltaMap ((float*)0xFFFF6618)
#define pAcceleratorPedal ((float*)0xFFFF6868)
#define pThrottlePlateTarget ((float*)0x)
#define tTargetThrottlePlateA (0x00081E6C)
#define hTableTargetThrottlePlateA (0x000BE708)
#define pTargetIdleSpeed ((float*)0xFFFF78D0)
#define hPullTargetIdleSpeed (0x0003F1C0)
#define hTableTargetIdleSpeedA (0x0003F1C4)
#define tTargetIdleSpeedA (0x00081940)
#define hTableTargetIdleSpeedB (0x0003F1CC)
#define tTargetIdleSpeedB (0x00081968)
#define hTableTargetIdleSpeedC (0x0003F1D4)
#define tTargetIdleSpeedC (0x00081990)
#define hPullIdleMapSelection (0x0003F1AC)
#define pIdleMapSelection (0xFFFF7948)
#define hPullRequestedTorqueA (0x000BEA50)
#define tRequestedTorqueA (0x00081EA4)
#define hTableRequestedTorqueA (0x000BE9D0)
#define sFloatToShort (0x00002524)
#define sFloatToByte (0x00002564)
#define dEvapFuelComp (0x00025EE8)              //fix
#define pCPCDutyRatio ((float*)0xFFFF6B44)
#define pAirPump ((float*)0x00008230)
#define pFuelLevel ((float*)0xFFFF677C)
#define pSTFTs1 ((float*)0xFFFF6D80)
#define pLTFTsA ((float*)0xFFFF6F3C)
//#define dLTFTLimitA (0x000C8568)  Ready for idatohew & Metahooks
//#define dLTFTLimitB (0x000C856C)  Ready for idatohew & Metahooks
#define hLTFTLimitA1 (0x0002C350)
#define hLTFTLimitB1 (0x0002C34C)
#define hLTFTLimitA2 (0x0002C350)
#define hLTFTLimitB2 (0x0002C34C)
#define pAVCS ((float*)0xFFFF7F1C)
#define hPullAVCS (0x0004EDF0)
#define tAVCS (0x000823FC)
#define hTableAVCS (0x0004EDF8)
#define pO2SensorScaling ((float*)0xFFFF5F00)
#define hPullO2SensorScaling (0x0000BE80)
#define tO2SensorScaling (0x00081FD4)
#define hTableO2SensorScaling (0x0000BE7C)
#define pAFSensor1Current ((float*)0xFFFF5F04)
#define hOpenLoopAFRmin (0x0002DBC8)
#define dOpenLoopAFRmin (0x000C6CBC)
#define dSSMReplace (0x0004A278)
#define hSSMReplace1 (0x000515B0)
#define hSSMReplace2 (0x000515B4)
#define hTargetTPSBandPass (0x000BE710)
#define sBandPass (0x00002498)
#define sDutyCycleOut (0x00002368)
#define hDutyCycleOut (0x000118A8)
#define hTargetTPSIdle (0x000BEB00)
#define pTargetTPSIdle ((float*)0xFFFF7804)
////#define sBasicMotions (0x0002495A)
////#define hBasicMotions (0x0002495A)
#define hFuelCut (0x000321F8)
#define pFuelCut ((short*)0xFFFF6C78) //TBC
#define pBoost ((float*)0xFFFF6628)
#define hPrepForSpark (0x00006CB4)
#define sPrepForSpark (0x0000A300)
#define pCyl1SparkCut ((unsigned char*)0xFFFF5DF0)
#define pCyl2SparkCut ((unsigned char*)0xFFFF5DF8)
#define pCyl3SparkCut ((unsigned char*)0xFFFF5E00)
#define pCyl4SparkCut ((unsigned char*)0xFFFF5E08)
#define hPedalSub (0x00006684)
#define sPedalSub (0x0000CDCC)
//#define sAfterAD (0x00006e64)
//#define sAfterReloadAD (0x000066b8)
//#define hAfterAD (0x000067b4)
//#define hAfterReloadAD (0x000066b8)
#define pPedalVoltage ((short*)0xFFFF5c00)
#define pSubPedalVoltage ((short*)0xFFFF5c02)
#define pTargetIdleAir ((float*)0xFFFF7800)


/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C1AF4)
#define dLoadSmoothingB (0x000C1AF8)
#define dLoadSmoothingFinal (0x000C1B04)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FB54)
#define hMemoryReset (0x0000DA70)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00011EE0)
#define sMemorySoftReset (0x00051D44)


