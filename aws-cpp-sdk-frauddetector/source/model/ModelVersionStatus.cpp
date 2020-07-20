﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/frauddetector/model/ModelVersionStatus.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace FraudDetector
  {
    namespace Model
    {
      namespace ModelVersionStatusMapper
      {

        static const int TRAINING_IN_PROGRESS_HASH = HashingUtils::HashString("TRAINING_IN_PROGRESS");
        static const int TRAINING_COMPLETE_HASH = HashingUtils::HashString("TRAINING_COMPLETE");
        static const int ACTIVATE_REQUESTED_HASH = HashingUtils::HashString("ACTIVATE_REQUESTED");
        static const int ACTIVATE_IN_PROGRESS_HASH = HashingUtils::HashString("ACTIVATE_IN_PROGRESS");
        static const int ACTIVE_HASH = HashingUtils::HashString("ACTIVE");
        static const int INACTIVATE_IN_PROGRESS_HASH = HashingUtils::HashString("INACTIVATE_IN_PROGRESS");
        static const int INACTIVE_HASH = HashingUtils::HashString("INACTIVE");
        static const int DELETE_REQUESTED_HASH = HashingUtils::HashString("DELETE_REQUESTED");
        static const int DELETE_IN_PROGRESS_HASH = HashingUtils::HashString("DELETE_IN_PROGRESS");
        static const int ERROR__HASH = HashingUtils::HashString("ERROR");


        ModelVersionStatus GetModelVersionStatusForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == TRAINING_IN_PROGRESS_HASH)
          {
            return ModelVersionStatus::TRAINING_IN_PROGRESS;
          }
          else if (hashCode == TRAINING_COMPLETE_HASH)
          {
            return ModelVersionStatus::TRAINING_COMPLETE;
          }
          else if (hashCode == ACTIVATE_REQUESTED_HASH)
          {
            return ModelVersionStatus::ACTIVATE_REQUESTED;
          }
          else if (hashCode == ACTIVATE_IN_PROGRESS_HASH)
          {
            return ModelVersionStatus::ACTIVATE_IN_PROGRESS;
          }
          else if (hashCode == ACTIVE_HASH)
          {
            return ModelVersionStatus::ACTIVE;
          }
          else if (hashCode == INACTIVATE_IN_PROGRESS_HASH)
          {
            return ModelVersionStatus::INACTIVATE_IN_PROGRESS;
          }
          else if (hashCode == INACTIVE_HASH)
          {
            return ModelVersionStatus::INACTIVE;
          }
          else if (hashCode == DELETE_REQUESTED_HASH)
          {
            return ModelVersionStatus::DELETE_REQUESTED;
          }
          else if (hashCode == DELETE_IN_PROGRESS_HASH)
          {
            return ModelVersionStatus::DELETE_IN_PROGRESS;
          }
          else if (hashCode == ERROR__HASH)
          {
            return ModelVersionStatus::ERROR_;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<ModelVersionStatus>(hashCode);
          }

          return ModelVersionStatus::NOT_SET;
        }

        Aws::String GetNameForModelVersionStatus(ModelVersionStatus enumValue)
        {
          switch(enumValue)
          {
          case ModelVersionStatus::TRAINING_IN_PROGRESS:
            return "TRAINING_IN_PROGRESS";
          case ModelVersionStatus::TRAINING_COMPLETE:
            return "TRAINING_COMPLETE";
          case ModelVersionStatus::ACTIVATE_REQUESTED:
            return "ACTIVATE_REQUESTED";
          case ModelVersionStatus::ACTIVATE_IN_PROGRESS:
            return "ACTIVATE_IN_PROGRESS";
          case ModelVersionStatus::ACTIVE:
            return "ACTIVE";
          case ModelVersionStatus::INACTIVATE_IN_PROGRESS:
            return "INACTIVATE_IN_PROGRESS";
          case ModelVersionStatus::INACTIVE:
            return "INACTIVE";
          case ModelVersionStatus::DELETE_REQUESTED:
            return "DELETE_REQUESTED";
          case ModelVersionStatus::DELETE_IN_PROGRESS:
            return "DELETE_IN_PROGRESS";
          case ModelVersionStatus::ERROR_:
            return "ERROR";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace ModelVersionStatusMapper
    } // namespace Model
  } // namespace FraudDetector
} // namespace Aws
