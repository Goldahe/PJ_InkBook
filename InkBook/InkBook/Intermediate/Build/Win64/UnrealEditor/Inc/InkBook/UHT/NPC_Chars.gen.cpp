// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InkBook/NPC_Chars.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNPC_Chars() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	INKBOOK_API UClass* Z_Construct_UClass_ANPC_Chars();
	INKBOOK_API UClass* Z_Construct_UClass_ANPC_Chars_NoRegister();
	UPackage* Z_Construct_UPackage__Script_InkBook();
// End Cross Module References
	void ANPC_Chars::StaticRegisterNativesANPC_Chars()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANPC_Chars);
	UClass* Z_Construct_UClass_ANPC_Chars_NoRegister()
	{
		return ANPC_Chars::StaticClass();
	}
	struct Z_Construct_UClass_ANPC_Chars_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharPanel_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CharPanel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANPC_Chars_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_InkBook,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Chars_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANPC_Chars_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "NPC_Chars.h" },
		{ "ModuleRelativePath", "NPC_Chars.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANPC_Chars_Statics::NewProp_CharPanel_MetaData[] = {
		{ "Category", "CharPanel" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NPC_Chars.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANPC_Chars_Statics::NewProp_CharPanel = { "CharPanel", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANPC_Chars, CharPanel), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Chars_Statics::NewProp_CharPanel_MetaData), Z_Construct_UClass_ANPC_Chars_Statics::NewProp_CharPanel_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANPC_Chars_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANPC_Chars_Statics::NewProp_CharPanel,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANPC_Chars_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANPC_Chars>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANPC_Chars_Statics::ClassParams = {
		&ANPC_Chars::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANPC_Chars_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Chars_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Chars_Statics::Class_MetaDataParams), Z_Construct_UClass_ANPC_Chars_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANPC_Chars_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANPC_Chars()
	{
		if (!Z_Registration_Info_UClass_ANPC_Chars.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANPC_Chars.OuterSingleton, Z_Construct_UClass_ANPC_Chars_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANPC_Chars.OuterSingleton;
	}
	template<> INKBOOK_API UClass* StaticClass<ANPC_Chars>()
	{
		return ANPC_Chars::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANPC_Chars);
	ANPC_Chars::~ANPC_Chars() {}
	struct Z_CompiledInDeferFile_FID_InkBook_InkBook_Source_InkBook_NPC_Chars_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_InkBook_InkBook_Source_InkBook_NPC_Chars_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANPC_Chars, ANPC_Chars::StaticClass, TEXT("ANPC_Chars"), &Z_Registration_Info_UClass_ANPC_Chars, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANPC_Chars), 2804296501U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_InkBook_InkBook_Source_InkBook_NPC_Chars_h_3523001080(TEXT("/Script/InkBook"),
		Z_CompiledInDeferFile_FID_InkBook_InkBook_Source_InkBook_NPC_Chars_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_InkBook_InkBook_Source_InkBook_NPC_Chars_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
