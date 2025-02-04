﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/macie2/Macie2_EXPORTS.h>
#include <aws/macie2/model/RevealConfiguration.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace Macie2
{
namespace Model
{
  class AWS_MACIE2_API UpdateRevealConfigurationResult
  {
  public:
    UpdateRevealConfigurationResult();
    UpdateRevealConfigurationResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    UpdateRevealConfigurationResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>The new configuration settings and the status of the configuration for the
     * account.</p>
     */
    inline const RevealConfiguration& GetConfiguration() const{ return m_configuration; }

    /**
     * <p>The new configuration settings and the status of the configuration for the
     * account.</p>
     */
    inline void SetConfiguration(const RevealConfiguration& value) { m_configuration = value; }

    /**
     * <p>The new configuration settings and the status of the configuration for the
     * account.</p>
     */
    inline void SetConfiguration(RevealConfiguration&& value) { m_configuration = std::move(value); }

    /**
     * <p>The new configuration settings and the status of the configuration for the
     * account.</p>
     */
    inline UpdateRevealConfigurationResult& WithConfiguration(const RevealConfiguration& value) { SetConfiguration(value); return *this;}

    /**
     * <p>The new configuration settings and the status of the configuration for the
     * account.</p>
     */
    inline UpdateRevealConfigurationResult& WithConfiguration(RevealConfiguration&& value) { SetConfiguration(std::move(value)); return *this;}

  private:

    RevealConfiguration m_configuration;
  };

} // namespace Model
} // namespace Macie2
} // namespace Aws
