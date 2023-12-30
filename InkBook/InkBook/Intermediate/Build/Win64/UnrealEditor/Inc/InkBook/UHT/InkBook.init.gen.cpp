// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInkBook_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_InkBook;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_InkBook()
	{
		if (!Z_Registration_Info_UPackage__Script_InkBook.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/InkBook",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xBD7D457C,
				0x19849487,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_InkBook.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_InkBook.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_InkBook(Z_Construct_UPackage__Script_InkBook, TEXT("/Script/InkBook"), Z_Registration_Info_UPackage__Script_InkBook, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBD7D457C, 0x19849487));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
