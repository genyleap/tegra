#PreAlpha            = 0x1,       ///< Pre-alpha refers to all activities performed during the software CONFIG before formal testing.
#Alpha               = 0x2,       ///< The alpha phase of the release life cycle is the first phase of software testing (alpha is the first letter of the Greek alphabet, used as the number 1).
#Beta                = 0x3,       ///< Beta, named after the second letter of the Greek alphabet, is the software development phase following alpha.
#ReleaseCandidate    = 0x4,       ///< A release candidate (RC), also known as "going silver", is a beta version with potential to be a stable product, which is ready to release unless significant bugs emerge.
#StableRelease       = 0x5        ///< Also called production release, the stable release is the last release candidate (RC) which has passed all verifications / tests. The remaining bugs are considered as acceptable.

option(CONFIG_RELEASE_TYPE    "CONFIG Release Type"  0x1)
if (CONFIG_RELEASE_TYPE)
  add_definitions(-DCONFIG_RELEASE_TYPE)
endif()

#Private      = 0x1, ///< Private.
#General      = 0x2, ///< General.
#Professional = 0x3, ///< Professional.
#Premium      = 0x4, ///< Premium.
#Default      = 0x5  ///< Default.

option(CONFIG_SYSTEM_TYPE    "CONFIG System Type"  0x5)
if (CONFIG_SYSTEM_TYPE)
  add_definitions(-DCONFIG_SYSTEM_TYPE)
endif()

#Free            = 0x1,  ///< This flag marks the system as the free version.
#Commercial      = 0x2   ///< This flag marks the system as the commercial version.

option(CONFIG_LICENCE_TYPE    "CONFIG License Type"  0x1)
if (CONFIG_LICENCE_TYPE)
  add_definitions(-DCONFIG_LICENCE_TYPE)
endif()
