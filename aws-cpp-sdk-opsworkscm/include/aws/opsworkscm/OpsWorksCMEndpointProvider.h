﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/opsworkscm/OpsWorksCM_EXPORTS.h>
#include <aws/core/client/GenericClientConfiguration.h>
#include <aws/core/endpoint/DefaultEndpointProvider.h>
#include <aws/core/endpoint/EndpointParameter.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>

#include <aws/opsworkscm/OpsWorksCMEndpointRules.h>


namespace Aws
{
namespace OpsWorksCM
{
namespace Endpoint
{
using EndpointParameters = Aws::Endpoint::EndpointParameters;
using Aws::Endpoint::EndpointProviderBase;
using Aws::Endpoint::DefaultEndpointProvider;

using OpsWorksCMClientContextParameters = Aws::Endpoint::ClientContextParameters;

using OpsWorksCMClientConfiguration = Aws::Client::GenericClientConfiguration<false>;
using OpsWorksCMBuiltInParameters = Aws::Endpoint::BuiltInParameters;

/**
 * The type for the OpsWorksCM Client Endpoint Provider.
 * Inherit from this Base class / "Interface" should you want to provide a custom endpoint provider.
 * The SDK must use service-specific type for each service per specification.
 */
using OpsWorksCMEndpointProviderBase =
    EndpointProviderBase<OpsWorksCMClientConfiguration, OpsWorksCMBuiltInParameters, OpsWorksCMClientContextParameters>;

using OpsWorksCMDefaultEpProviderBase =
    DefaultEndpointProvider<OpsWorksCMClientConfiguration, OpsWorksCMBuiltInParameters, OpsWorksCMClientContextParameters>;

/**
 * Default endpoint provider used for this service
 */
class AWS_OPSWORKSCM_API OpsWorksCMEndpointProvider : public OpsWorksCMDefaultEpProviderBase
{
public:
    using OpsWorksCMResolveEndpointOutcome = Aws::Endpoint::ResolveEndpointOutcome;

    OpsWorksCMEndpointProvider()
      : OpsWorksCMDefaultEpProviderBase(Aws::OpsWorksCM::OpsWorksCMEndpointRules::Rules)
    {}

    ~OpsWorksCMEndpointProvider()
    {
    }
};
} // namespace Endpoint
} // namespace OpsWorksCM
} // namespace Aws
