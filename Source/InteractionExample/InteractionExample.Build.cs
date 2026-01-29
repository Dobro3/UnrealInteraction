// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class InteractionExample : ModuleRules
{
	public InteractionExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
		
		PrivateDependencyModuleNames.AddRange(new string[] { "InteractionModule" });
	}
}
