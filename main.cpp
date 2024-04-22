#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Web.Syndication.h>
#include <winrt/Windows.UI.Shell.h>
#include <winrt/Windows.ApplicationModel.h>
#include <iostream>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

using Windows::ApplicationModel::LimitedAccessFeatureStatus;

using param::hstring;

void CheckFocusSessionState() {
    if (Windows::UI::Shell::FocusSessionManager::IsSupported()) {
        auto access = Windows::ApplicationModel::LimitedAccessFeatures::TryUnlockFeature(
                L"com.microsoft.windows.focussessionmanager.1",
                L"rIoGgkAp8W6/wkhP1J+Zsw==",
                L"bv3y43trt6crp has registered their use of com.microsoft.windows.focussessionmanager.1 with Microsoft and agrees to the terms of use."
        );
        if ((access.Status() == Windows::ApplicationModel::LimitedAccessFeatureStatus::Available) ||
            (access.Status() == Windows::ApplicationModel::LimitedAccessFeatureStatus::AvailableWithoutToken)) {
            std::cout << "Feature is accessible" << std::endl;
        }
        auto manager = Windows::UI::Shell::FocusSessionManager::GetDefault();
        bool focusActive = manager.IsFocusActive();

        // Use the focusActive status to update your application
        if (focusActive) {
            // Code to handle active focus session
        }
        else {
            auto r = manager.TryStartFocusSession();
            std::cout << "Tried to start focus sess" << r.Id().c_str() << std::endl;
            // Code to handle inactive focus session
        }
    }
}

int main()
{
    CheckFocusSessionState();
    std::cout << "Hello World!\n";
    return 0;
}