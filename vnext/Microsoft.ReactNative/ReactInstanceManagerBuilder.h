#pragma once
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "LifecycleState.h"
#include "ReactInstanceManager.h"
#include "ReactInstanceSettings.h"

using namespace winrt;
using namespace Microsoft::ReactNative;

namespace winrt::Microsoft::ReactNative::implementation {
class ReactInstanceManagerBuilder {
 public:
  void JavaScriptBundleFile(hstring jsBundleFile) {
    m_jsBundleFile = jsBundleFile;
  };
  void JavaScriptMainModuleName(hstring jsMainModuleName) {
    m_jsMainModuleName = jsMainModuleName;
  };
  void UseDeveloperSupport(bool useDevSupport) {
    m_useDeveloperSupport = useDevSupport;
  };

  Microsoft::ReactNative::ReactInstanceSettings InstanceSettings() {
    return m_instanceSettings;
  }

  void InstanceSettings(
      Microsoft::ReactNative::ReactInstanceSettings const &settings) {
    m_instanceSettings = settings;
  }

  void InitialLifecycleState(LifecycleState const &state) {
    m_initialLifecycleState = state;
    m_isLifecycleStateSet = TRUE;
  };

  void Packages(IVectorView<IReactPackage> const &packages) {
    m_packages = packages;
  }

  Microsoft::ReactNative::ReactInstanceManager Build();

 private:
  Windows::Foundation::Collections::IVectorView<IReactPackage> m_packages;
  Microsoft::ReactNative::ReactInstanceSettings m_instanceSettings{nullptr};
  std::wstring m_jsBundleFile{};
  std::wstring m_jsMainModuleName{};
  bool m_useDeveloperSupport{false};
  bool m_isLifecycleStateSet{false};
  LifecycleState m_initialLifecycleState{LifecycleState::BeforeCreate};
};
} // namespace winrt::Microsoft::ReactNative::implementation
