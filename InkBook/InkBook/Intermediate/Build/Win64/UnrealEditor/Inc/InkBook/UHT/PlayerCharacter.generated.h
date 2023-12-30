// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlayerCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef INKBOOK_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define INKBOOK_PlayerCharacter_generated_h

#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_SPARSE_DATA
#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOverlapEnd); \
	DECLARE_FUNCTION(execOverlapBegin);


#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_ACCESSORS
#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InkBook"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter)


#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerCharacter(APlayerCharacter&&); \
	NO_API APlayerCharacter(const APlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerCharacter) \
	NO_API virtual ~APlayerCharacter();


#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_23_PROLOG
#define FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_SPARSE_DATA \
	FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_ACCESSORS \
	FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_INCLASS_NO_PURE_DECLS \
	FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INKBOOK_API UClass* StaticClass<class APlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_InkBook_InkBook_Source_InkBook_PlayerCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
