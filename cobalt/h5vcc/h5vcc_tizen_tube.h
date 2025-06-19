// Copyright 2016 The Cobalt Authors. All Rights Reserved.
// Copyright 2025 Reis Can (reisxd). All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef COBALT_H5VCC_H5VCC_TIZEN_TUBE_H_
#define COBALT_H5VCC_H5VCC_TIZEN_TUBE_H_

#include <string>

#include "cobalt/media/media_module.h"
#include "cobalt/network/network_module.h"
#include "cobalt/persistent_storage/persistent_settings.h"
#include "cobalt/script/global_environment.h"
#include "cobalt/script/union_type.h"
#include "cobalt/script/wrappable.h"
#include "cobalt/web/navigator_ua_data.h"

#if SB_IS(EVERGREEN)
#include "chrome/updater/updater_module.h"
#endif

namespace cobalt {
namespace h5vcc {

// This class is used for internal methods for TizenTube Cobalt.
class H5vccTizenTube : public script::Wrappable {
 public:
  typedef base::Callback<bool(const std::string& name, int value)>
      SetSettingFunc;

  typedef script::UnionType2<int32, std::string> SetValueType;

  H5vccTizenTube();

  // Calls a Java method in order to download the APK
  // and install it.
  bool InstallAppFromURL(const std::string& url) const;
  std::string GetVersion() const;

  DEFINE_WRAPPABLE_TYPE(H5vccTizenTube);

 private:
  DISALLOW_COPY_AND_ASSIGN(H5vccTizenTube);
};

}  // namespace h5vcc
}  // namespace cobalt

#endif  // COBALT_H5VCC_H5VCC_TIZEN_TUBE_H_
