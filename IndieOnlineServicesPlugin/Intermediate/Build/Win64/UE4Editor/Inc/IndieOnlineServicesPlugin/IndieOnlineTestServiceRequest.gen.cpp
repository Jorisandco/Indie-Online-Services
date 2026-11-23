// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IndieOnlineServicesPlugin/Public/IndieOnlineTestServiceRequest.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIndieOnlineTestServiceRequest() {}
// Cross Module References
	INDIEONLINESERVICESPLUGIN_API UClass* Z_Construct_UClass_UIndieOnlineTestServiceRequest_NoRegister();
	INDIEONLINESERVICESPLUGIN_API UClass* Z_Construct_UClass_UIndieOnlineTestServiceRequest();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_IndieOnlineServicesPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UIndieOnlineTestServiceRequest::execTokenGeneration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FText*)Z_Param__Result=UIndieOnlineTestServiceRequest::TokenGeneration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UIndieOnlineTestServiceRequest::execFormatPlayerGreeting)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_PlayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UIndieOnlineTestServiceRequest::FormatPlayerGreeting(Z_Param_PlayerName);
		P_NATIVE_END;
	}
	void UIndieOnlineTestServiceRequest::StaticRegisterNativesUIndieOnlineTestServiceRequest()
	{
		UClass* Class = UIndieOnlineTestServiceRequest::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FormatPlayerGreeting", &UIndieOnlineTestServiceRequest::execFormatPlayerGreeting },
			{ "TokenGeneration", &UIndieOnlineTestServiceRequest::execTokenGeneration },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics
	{
		struct IndieOnlineTestServiceRequest_eventFormatPlayerGreeting_Parms
		{
			FString PlayerName;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PlayerName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::NewProp_PlayerName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::NewProp_PlayerName = { "PlayerName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndieOnlineTestServiceRequest_eventFormatPlayerGreeting_Parms, PlayerName), METADATA_PARAMS(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::NewProp_PlayerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::NewProp_PlayerName_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndieOnlineTestServiceRequest_eventFormatPlayerGreeting_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::NewProp_PlayerName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::Function_MetaDataParams[] = {
		{ "Category", "IndieOnlineServices" },
		{ "ModuleRelativePath", "Public/IndieOnlineTestServiceRequest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndieOnlineTestServiceRequest, nullptr, "FormatPlayerGreeting", nullptr, nullptr, sizeof(IndieOnlineTestServiceRequest_eventFormatPlayerGreeting_Parms), Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics
	{
		struct IndieOnlineTestServiceRequest_eventTokenGeneration_Parms
		{
			FText ReturnValue;
		};
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndieOnlineTestServiceRequest_eventTokenGeneration_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::Function_MetaDataParams[] = {
		{ "Category", "IndieOnlineServices" },
		{ "ModuleRelativePath", "Public/IndieOnlineTestServiceRequest.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndieOnlineTestServiceRequest, nullptr, "TokenGeneration", nullptr, nullptr, sizeof(IndieOnlineTestServiceRequest_eventTokenGeneration_Parms), Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UIndieOnlineTestServiceRequest_NoRegister()
	{
		return UIndieOnlineTestServiceRequest::StaticClass();
	}
	struct Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_IndieOnlineServicesPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UIndieOnlineTestServiceRequest_FormatPlayerGreeting, "FormatPlayerGreeting" }, // 2283981781
		{ &Z_Construct_UFunction_UIndieOnlineTestServiceRequest_TokenGeneration, "TokenGeneration" }, // 3655431045
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "IndieOnlineTestServiceRequest.h" },
		{ "ModuleRelativePath", "Public/IndieOnlineTestServiceRequest.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIndieOnlineTestServiceRequest>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::ClassParams = {
		&UIndieOnlineTestServiceRequest::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIndieOnlineTestServiceRequest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIndieOnlineTestServiceRequest_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIndieOnlineTestServiceRequest, 1823011449);
	template<> INDIEONLINESERVICESPLUGIN_API UClass* StaticClass<UIndieOnlineTestServiceRequest>()
	{
		return UIndieOnlineTestServiceRequest::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIndieOnlineTestServiceRequest(Z_Construct_UClass_UIndieOnlineTestServiceRequest, &UIndieOnlineTestServiceRequest::StaticClass, TEXT("/Script/IndieOnlineServicesPlugin"), TEXT("UIndieOnlineTestServiceRequest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIndieOnlineTestServiceRequest);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
