// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BasePawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HW07_BasePawn_generated_h
#error "BasePawn.generated.h already included, missing '#pragma once' in BasePawn.h"
#endif
#define HW07_BasePawn_generated_h

#define FID_Unreal_Github_HW07_HW07_Source_HW07_Public_BasePawn_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABasePawn(); \
	friend struct Z_Construct_UClass_ABasePawn_Statics; \
public: \
	DECLARE_CLASS(ABasePawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HW07"), NO_API) \
	DECLARE_SERIALIZER(ABasePawn)


#define FID_Unreal_Github_HW07_HW07_Source_HW07_Public_BasePawn_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABasePawn(ABasePawn&&); \
	ABasePawn(const ABasePawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasePawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasePawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABasePawn) \
	NO_API virtual ~ABasePawn();


#define FID_Unreal_Github_HW07_HW07_Source_HW07_Public_BasePawn_h_12_PROLOG
#define FID_Unreal_Github_HW07_HW07_Source_HW07_Public_BasePawn_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Github_HW07_HW07_Source_HW07_Public_BasePawn_h_15_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Github_HW07_HW07_Source_HW07_Public_BasePawn_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HW07_API UClass* StaticClass<class ABasePawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Github_HW07_HW07_Source_HW07_Public_BasePawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
