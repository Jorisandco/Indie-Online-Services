#include "IndieOnlineServicesPluginModule.h"

DEFINE_LOG_CATEGORY(LogIndieOnlineServices);

void FIndieOnlineServicesPluginModule::StartupModule()
{
    UE_LOG(LogIndieOnlineServices, Log, TEXT("IndieOnlineServicesPlugin module started."));
}

void FIndieOnlineServicesPluginModule::ShutdownModule()
{
    UE_LOG(LogIndieOnlineServices, Log, TEXT("IndieOnlineServicesPlugin module shut down."));
}

IMPLEMENT_MODULE(FIndieOnlineServicesPluginModule, IndieOnlineServicesPlugin)