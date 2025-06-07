// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Arcane_Archer : ModuleRules
{
	public Arcane_Archer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
