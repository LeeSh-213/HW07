// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HW07/Public/DronePawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDronePawn() {}

// Begin Cross Module References
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
HW07_API UClass* Z_Construct_UClass_ABasePawn();
HW07_API UClass* Z_Construct_UClass_ADronePawn();
HW07_API UClass* Z_Construct_UClass_ADronePawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_HW07();
// End Cross Module References

// Begin Class ADronePawn
void ADronePawn::StaticRegisterNativesADronePawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADronePawn);
UClass* Z_Construct_UClass_ADronePawn_NoRegister()
{
	return ADronePawn::StaticClass();
}
struct Z_Construct_UClass_ADronePawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "DronePawn.h" },
		{ "ModuleRelativePath", "Public/DronePawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[] = {
		{ "Category", "Flight" },
		{ "ModuleRelativePath", "Public/DronePawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TerminalVelocity_MetaData[] = {
		{ "Category", "Flight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xdf\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xb5\xef\xbf\xbd (cm/s^2)\n// \xef\xbf\xbd\xdf\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/DronePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xdf\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xb5\xef\xbf\xbd (cm/s^2)\n\xef\xbf\xbd\xdf\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd3\xb5\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundCheckDistance_MetaData[] = {
		{ "Category", "Flight" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/DronePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AirControlMultiplier_MetaData[] = {
		{ "Category", "Flight" },
		{ "ModuleRelativePath", "Public/DronePawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RollAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xd4\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/DronePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xd4\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RollSpeed_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/DronePawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Gravity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TerminalVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundCheckDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AirControlMultiplier;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RollAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RollSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADronePawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADronePawn_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADronePawn, Gravity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gravity_MetaData), NewProp_Gravity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADronePawn_Statics::NewProp_TerminalVelocity = { "TerminalVelocity", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADronePawn, TerminalVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TerminalVelocity_MetaData), NewProp_TerminalVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADronePawn_Statics::NewProp_GroundCheckDistance = { "GroundCheckDistance", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADronePawn, GroundCheckDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundCheckDistance_MetaData), NewProp_GroundCheckDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADronePawn_Statics::NewProp_AirControlMultiplier = { "AirControlMultiplier", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADronePawn, AirControlMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AirControlMultiplier_MetaData), NewProp_AirControlMultiplier_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADronePawn_Statics::NewProp_RollAction = { "RollAction", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADronePawn, RollAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RollAction_MetaData), NewProp_RollAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADronePawn_Statics::NewProp_RollSpeed = { "RollSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADronePawn, RollSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RollSpeed_MetaData), NewProp_RollSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADronePawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADronePawn_Statics::NewProp_Gravity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADronePawn_Statics::NewProp_TerminalVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADronePawn_Statics::NewProp_GroundCheckDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADronePawn_Statics::NewProp_AirControlMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADronePawn_Statics::NewProp_RollAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADronePawn_Statics::NewProp_RollSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADronePawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADronePawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABasePawn,
	(UObject* (*)())Z_Construct_UPackage__Script_HW07,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADronePawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADronePawn_Statics::ClassParams = {
	&ADronePawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADronePawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADronePawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADronePawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ADronePawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADronePawn()
{
	if (!Z_Registration_Info_UClass_ADronePawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADronePawn.OuterSingleton, Z_Construct_UClass_ADronePawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADronePawn.OuterSingleton;
}
template<> HW07_API UClass* StaticClass<ADronePawn>()
{
	return ADronePawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADronePawn);
ADronePawn::~ADronePawn() {}
// End Class ADronePawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Github_HW07_HW07_Source_HW07_Public_DronePawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADronePawn, ADronePawn::StaticClass, TEXT("ADronePawn"), &Z_Registration_Info_UClass_ADronePawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADronePawn), 246344469U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Github_HW07_HW07_Source_HW07_Public_DronePawn_h_4267158893(TEXT("/Script/HW07"),
	Z_CompiledInDeferFile_FID_Unreal_Github_HW07_HW07_Source_HW07_Public_DronePawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Github_HW07_HW07_Source_HW07_Public_DronePawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
