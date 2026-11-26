using UnrealBuildTool;

public class IndieOnlineServicesPlugin : ModuleRules
{
    public IndieOnlineServicesPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "DeveloperSettings"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "OnlineSubsystem",
            "HTTP",
            "Json",
            "JsonUtilities"
        });
    }
}