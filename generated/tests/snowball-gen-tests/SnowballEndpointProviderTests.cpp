﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <gtest/gtest.h>
#include <aws/testing/AwsTestHelpers.h>

#include <aws/core/auth/AWSCredentials.h>
#include <aws/core/http/standard/StandardHttpResponse.h>
#include <aws/core/http/HttpClientFactory.h>

#include <aws/snowball/SnowballEndpointProvider.h>


static const char* ALLOCATION_TAG = "AWSSnowballEndpointProviderTests";
using SnowballEndpointProvider = Aws::Snowball::Endpoint::SnowballEndpointProvider;
using EndpointParameters = Aws::Vector<Aws::Endpoint::EndpointParameter>;
using ResolveEndpointOutcome = Aws::Endpoint::ResolveEndpointOutcome;

using EpParam = Aws::Endpoint::EndpointParameter;
using EpProp = Aws::Endpoint::EndpointParameter; // just a container to store test expectations
using ExpEpProps = Aws::UnorderedMap<Aws::String, Aws::Vector<EpProp>>;
using ExpEpHeaders = Aws::UnorderedMap<Aws::String, Aws::Vector<Aws::String>>;

class SnowballEndpointProviderTests : public ::testing::TestWithParam<size_t> {};

struct SnowballEndpointProviderEndpointTestCase
{
    using OperationParamsFromTest = EndpointParameters;

    struct Expect
    {
        struct Endpoint
        {
            Aws::String url;
            ExpEpProps properties;
            ExpEpHeaders headers;
        } endpoint;
        Aws::String error;
    };
    struct OperationInput
    {
        Aws::String operationName;
        OperationParamsFromTest operationParams;
        OperationParamsFromTest builtinParams;
        OperationParamsFromTest clientParams;
    };

    std::string documentation;
    // Specification tells us it is Client Initialization parameters
    // At the same time, specification tells us to test EndpointProvider not the client itself
    // Hence params here will be set as a client params (just like a dedicated field above).
    Aws::Vector<Aws::Endpoint::EndpointParameter> params;
    Aws::Vector<Aws::String> tags;
    Expect expect;
    // Aws::Vector<OperationInput> operationInput;
};

static const Aws::Vector<SnowballEndpointProviderEndpointTestCase> TEST_CASES = {
  /*TEST CASE 0*/
  {"For region ap-south-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-south-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-south-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 1*/
  {"For region ap-south-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-south-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-south-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 2*/
  {"For region ap-south-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-south-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-south-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 3*/
  {"For region ap-south-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-south-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-south-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 4*/
  {"For region eu-south-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-south-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-south-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 5*/
  {"For region eu-south-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-south-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-south-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 6*/
  {"For region eu-south-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-south-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-south-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 7*/
  {"For region eu-south-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-south-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-south-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 8*/
  {"For region us-gov-east-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-gov-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-gov-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 9*/
  {"For region us-gov-east-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-gov-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-gov-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 10*/
  {"For region us-gov-east-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-gov-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-gov-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 11*/
  {"For region us-gov-east-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-gov-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-gov-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 12*/
  {"For region me-central-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "me-central-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.me-central-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 13*/
  {"For region me-central-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "me-central-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.me-central-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 14*/
  {"For region me-central-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "me-central-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.me-central-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 15*/
  {"For region me-central-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "me-central-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.me-central-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 16*/
  {"For region ca-central-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ca-central-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ca-central-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 17*/
  {"For region ca-central-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ca-central-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ca-central-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 18*/
  {"For region ca-central-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ca-central-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ca-central-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 19*/
  {"For region ca-central-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ca-central-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ca-central-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 20*/
  {"For region eu-central-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-central-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-central-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 21*/
  {"For region eu-central-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-central-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-central-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 22*/
  {"For region eu-central-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-central-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-central-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 23*/
  {"For region eu-central-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-central-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-central-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 24*/
  {"For region us-iso-west-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-iso-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"FIPS and DualStack are enabled, but this partition does not support one or both"} // expect
  },
  /*TEST CASE 25*/
  {"For region us-iso-west-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-iso-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-iso-west-1.c2s.ic.gov",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 26*/
  {"For region us-iso-west-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-iso-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"DualStack is enabled but this partition does not support DualStack"} // expect
  },
  /*TEST CASE 27*/
  {"For region us-iso-west-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-iso-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-iso-west-1.c2s.ic.gov",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 28*/
  {"For region us-west-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-west-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 29*/
  {"For region us-west-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-west-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 30*/
  {"For region us-west-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-west-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 31*/
  {"For region us-west-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-west-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 32*/
  {"For region us-west-2 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-west-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-west-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 33*/
  {"For region us-west-2 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-west-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-west-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 34*/
  {"For region us-west-2 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-west-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-west-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 35*/
  {"For region us-west-2 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-west-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-west-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 36*/
  {"For region af-south-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "af-south-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.af-south-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 37*/
  {"For region af-south-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "af-south-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.af-south-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 38*/
  {"For region af-south-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "af-south-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.af-south-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 39*/
  {"For region af-south-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "af-south-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.af-south-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 40*/
  {"For region eu-north-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-north-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-north-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 41*/
  {"For region eu-north-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-north-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-north-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 42*/
  {"For region eu-north-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-north-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-north-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 43*/
  {"For region eu-north-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-north-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-north-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 44*/
  {"For region eu-west-3 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-west-3"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-west-3.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 45*/
  {"For region eu-west-3 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-west-3"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-west-3.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 46*/
  {"For region eu-west-3 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-west-3"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-west-3.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 47*/
  {"For region eu-west-3 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-west-3"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-west-3.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 48*/
  {"For region eu-west-2 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-west-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-west-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 49*/
  {"For region eu-west-2 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-west-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-west-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 50*/
  {"For region eu-west-2 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-west-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-west-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 51*/
  {"For region eu-west-2 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-west-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-west-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 52*/
  {"For region eu-west-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-west-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 53*/
  {"For region eu-west-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "eu-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.eu-west-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 54*/
  {"For region eu-west-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-west-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 55*/
  {"For region eu-west-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "eu-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.eu-west-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 56*/
  {"For region ap-northeast-3 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-northeast-3"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-northeast-3.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 57*/
  {"For region ap-northeast-3 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-northeast-3"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-northeast-3.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 58*/
  {"For region ap-northeast-3 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-northeast-3"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-northeast-3.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 59*/
  {"For region ap-northeast-3 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-northeast-3"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-northeast-3.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 60*/
  {"For region ap-northeast-2 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-northeast-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-northeast-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 61*/
  {"For region ap-northeast-2 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-northeast-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-northeast-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 62*/
  {"For region ap-northeast-2 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-northeast-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-northeast-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 63*/
  {"For region ap-northeast-2 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-northeast-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-northeast-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 64*/
  {"For region ap-northeast-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-northeast-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-northeast-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 65*/
  {"For region ap-northeast-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-northeast-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-northeast-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 66*/
  {"For region ap-northeast-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-northeast-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-northeast-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 67*/
  {"For region ap-northeast-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-northeast-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-northeast-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 68*/
  {"For region sa-east-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "sa-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.sa-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 69*/
  {"For region sa-east-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "sa-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.sa-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 70*/
  {"For region sa-east-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "sa-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.sa-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 71*/
  {"For region sa-east-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "sa-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.sa-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 72*/
  {"For region ap-east-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 73*/
  {"For region ap-east-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 74*/
  {"For region ap-east-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 75*/
  {"For region ap-east-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 76*/
  {"For region cn-north-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "cn-north-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.cn-north-1.api.amazonwebservices.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 77*/
  {"For region cn-north-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "cn-north-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.cn-north-1.amazonaws.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 78*/
  {"For region cn-north-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "cn-north-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.cn-north-1.api.amazonwebservices.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 79*/
  {"For region cn-north-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "cn-north-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.cn-north-1.amazonaws.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 80*/
  {"For region us-gov-west-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-gov-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-gov-west-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 81*/
  {"For region us-gov-west-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-gov-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-gov-west-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 82*/
  {"For region us-gov-west-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-gov-west-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-gov-west-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 83*/
  {"For region us-gov-west-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-gov-west-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-gov-west-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 84*/
  {"For region ap-southeast-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-southeast-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-southeast-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 85*/
  {"For region ap-southeast-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-southeast-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-southeast-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 86*/
  {"For region ap-southeast-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-southeast-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-southeast-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 87*/
  {"For region ap-southeast-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-southeast-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-southeast-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 88*/
  {"For region ap-southeast-2 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-southeast-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-southeast-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 89*/
  {"For region ap-southeast-2 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-southeast-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-southeast-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 90*/
  {"For region ap-southeast-2 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-southeast-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-southeast-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 91*/
  {"For region ap-southeast-2 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-southeast-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-southeast-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 92*/
  {"For region us-iso-east-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-iso-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"FIPS and DualStack are enabled, but this partition does not support one or both"} // expect
  },
  /*TEST CASE 93*/
  {"For region us-iso-east-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-iso-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-iso-east-1.c2s.ic.gov",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 94*/
  {"For region us-iso-east-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-iso-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"DualStack is enabled but this partition does not support DualStack"} // expect
  },
  /*TEST CASE 95*/
  {"For region us-iso-east-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-iso-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-iso-east-1.c2s.ic.gov",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 96*/
  {"For region ap-southeast-3 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-southeast-3"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-southeast-3.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 97*/
  {"For region ap-southeast-3 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "ap-southeast-3"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.ap-southeast-3.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 98*/
  {"For region ap-southeast-3 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-southeast-3"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-southeast-3.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 99*/
  {"For region ap-southeast-3 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "ap-southeast-3"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.ap-southeast-3.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 100*/
  {"For region us-east-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 101*/
  {"For region us-east-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 102*/
  {"For region us-east-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-east-1.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 103*/
  {"For region us-east-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-east-1.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 104*/
  {"For region us-east-2 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-east-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-east-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 105*/
  {"For region us-east-2 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-east-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-east-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 106*/
  {"For region us-east-2 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-east-2"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-east-2.api.aws",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 107*/
  {"For region us-east-2 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-east-2"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-east-2.amazonaws.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 108*/
  {"For region cn-northwest-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "cn-northwest-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.cn-northwest-1.api.amazonwebservices.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 109*/
  {"For region cn-northwest-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "cn-northwest-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.cn-northwest-1.amazonaws.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 110*/
  {"For region cn-northwest-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "cn-northwest-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.cn-northwest-1.api.amazonwebservices.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 111*/
  {"For region cn-northwest-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "cn-northwest-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.cn-northwest-1.amazonaws.com.cn",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 112*/
  {"For region us-isob-east-1 with FIPS enabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-isob-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"FIPS and DualStack are enabled, but this partition does not support one or both"} // expect
  },
  /*TEST CASE 113*/
  {"For region us-isob-east-1 with FIPS enabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Region", "us-isob-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball-fips.us-isob-east-1.sc2s.sgov.gov",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 114*/
  {"For region us-isob-east-1 with FIPS disabled and DualStack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-isob-east-1"), EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"DualStack is enabled but this partition does not support DualStack"} // expect
  },
  /*TEST CASE 115*/
  {"For region us-isob-east-1 with FIPS disabled and DualStack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Region", "us-isob-east-1"), EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://snowball.us-isob-east-1.sc2s.sgov.gov",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 116*/
  {"For custom endpoint with fips disabled and dualstack disabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Endpoint", "https://example.com"), EpParam("Region", "us-east-1"),
     EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*epUrl*/"https://example.com",
       {/*properties*/},
       {/*headers*/}}, {/*No error*/}} // expect
  },
  /*TEST CASE 117*/
  {"For custom endpoint with fips enabled and dualstack disabled", // documentation
    {EpParam("UseFIPS", true), EpParam("Endpoint", "https://example.com"), EpParam("Region", "us-east-1"),
     EpParam("UseDualStack", false)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"Invalid Configuration: FIPS and custom endpoint are not supported"} // expect
  },
  /*TEST CASE 118*/
  {"For custom endpoint with fips disabled and dualstack enabled", // documentation
    {EpParam("UseFIPS", false), EpParam("Endpoint", "https://example.com"), EpParam("Region", "us-east-1"),
     EpParam("UseDualStack", true)}, // params
    {}, // tags
    {{/*No endpoint expected*/}, /*error*/"Invalid Configuration: Dualstack and custom endpoint are not supported"} // expect
  }
};

Aws::String RulesToSdkSignerName(const Aws::String& rulesSignerName)
{
    Aws::String sdkSigner = "NullSigner";
    if (rulesSignerName == "sigv4") {
        sdkSigner = "SignatureV4";
    } else if (rulesSignerName == "sigv4a") {
        sdkSigner = "AsymmetricSignatureV4";
    } else if (rulesSignerName == "none") {
        sdkSigner = "NullSigner";
    } else if (rulesSignerName == "bearer") {
        sdkSigner = "Bearer";
    } else {
        sdkSigner = rulesSignerName;
    }

    return sdkSigner;
}

void ValidateOutcome(const ResolveEndpointOutcome& outcome, const SnowballEndpointProviderEndpointTestCase::Expect& expect)
{
    if(!expect.error.empty())
    {
        ASSERT_FALSE(outcome.IsSuccess()) << "Expected failure with message:\n" << expect.error;
        ASSERT_EQ(outcome.GetError().GetMessage(), expect.error);
    }
    else
    {
        AWS_ASSERT_SUCCESS(outcome);
        ASSERT_EQ(outcome.GetResult().GetURL(), expect.endpoint.url);
        const auto expAuthSchemesIt = expect.endpoint.properties.find("authSchemes");
        if (expAuthSchemesIt != expect.endpoint.properties.end())
        {
            const auto& endpointResultAttrs = outcome.GetResult().GetAttributes();
            ASSERT_TRUE(endpointResultAttrs) << "Expected non-empty EndpointAttributes (authSchemes)";
            for (const auto& expProperty : expAuthSchemesIt->second)
            {
                if (expProperty.GetName() == "name") {
                    ASSERT_TRUE(!endpointResultAttrs->authScheme.GetName().empty());
                    ASSERT_EQ(RulesToSdkSignerName(expProperty.GetStrValueNoCheck()), endpointResultAttrs->authScheme.GetName());
                } else if (expProperty.GetName() == "signingName") {
                    ASSERT_TRUE(endpointResultAttrs->authScheme.GetSigningName());
                    ASSERT_EQ(expProperty.GetStrValueNoCheck(), endpointResultAttrs->authScheme.GetSigningName().value());
                } else if (expProperty.GetName() == "signingRegion") {
                    ASSERT_TRUE(endpointResultAttrs->authScheme.GetSigningRegion());
                    ASSERT_EQ(expProperty.GetStrValueNoCheck(), endpointResultAttrs->authScheme.GetSigningRegion().value());
                } else if (expProperty.GetName() == "signingRegionSet") {
                    ASSERT_TRUE(endpointResultAttrs->authScheme.GetSigningRegionSet());
                    ASSERT_EQ(expProperty.GetStrValueNoCheck(), endpointResultAttrs->authScheme.GetSigningRegionSet().value());
                } else if (expProperty.GetName() == "disableDoubleEncoding") {
                    ASSERT_TRUE(endpointResultAttrs->authScheme.GetDisableDoubleEncoding());
                    ASSERT_EQ(expProperty.GetBoolValueNoCheck(), endpointResultAttrs->authScheme.GetDisableDoubleEncoding().value());
                } else {
                    FAIL() << "Unsupported Auth type property " << expProperty.GetName() << ". Need to update test.";
                }
            }
        }

        EXPECT_EQ(expect.endpoint.headers.empty(), outcome.GetResult().GetHeaders().empty());
        for(const auto& expHeaderVec : expect.endpoint.headers)
        {
            const auto& retHeaderIt = outcome.GetResult().GetHeaders().find(expHeaderVec.first);
            ASSERT_TRUE(retHeaderIt != outcome.GetResult().GetHeaders().end());

            auto retHeaderVec = Aws::Utils::StringUtils::Split(retHeaderIt->second, ';');
            std::sort(retHeaderVec.begin(), retHeaderVec.end());

            auto expHeaderVecSorted = expHeaderVec.second;
            std::sort(expHeaderVecSorted.begin(), expHeaderVecSorted.end());

            ASSERT_EQ(expHeaderVecSorted, retHeaderVec);
        }
    }
}

TEST_P(SnowballEndpointProviderTests, EndpointProviderTest)
{
    const size_t TEST_CASE_IDX = GetParam();
    ASSERT_LT(TEST_CASE_IDX, TEST_CASES.size()) << "Something is wrong with the test fixture itself.";
    const SnowballEndpointProviderEndpointTestCase& TEST_CASE = TEST_CASES.at(TEST_CASE_IDX);
    SCOPED_TRACE(Aws::String("\nTEST CASE # ") + Aws::Utils::StringUtils::to_string(TEST_CASE_IDX) + ": " + TEST_CASE.documentation);

    std::shared_ptr<SnowballEndpointProvider> endpointProvider = Aws::MakeShared<SnowballEndpointProvider>(ALLOCATION_TAG);
    ASSERT_TRUE(endpointProvider) << "Failed to allocate/initialize SnowballEndpointProvider";

    EndpointParameters endpointParameters;
    for(const auto& param : TEST_CASE.params)
    {
        endpointParameters.emplace(endpointParameters.end(), Aws::Endpoint::EndpointParameter(param));
    }
    auto resolvedEndpointOutcome = endpointProvider->ResolveEndpoint(endpointParameters);
    ValidateOutcome(resolvedEndpointOutcome, TEST_CASE.expect);

#if 0 // temporarily disabled
    for(const auto& operation : TEST_CASE.operationInput)
    {
        /*
         * Most specific to least specific value locations:
            staticContextParams
            contextParam
            clientContextParams
            Built-In Bindings
            Built-in binding default values
         */
        const Aws::Vector<std::reference_wrapper<const SnowballEndpointProviderEndpointTestCase::OperationParamsFromTest>>
                operationInputParams = {std::cref(operation.builtinParams), std::cref(operation.clientParams), std::cref(operation.operationParams)};

        for(const auto& paramSource : operationInputParams)
        {
            for(const auto& param : paramSource.get())
            {
                endpointParameters.emplace(endpointParameters.end(), Aws::Endpoint::EndpointParameter(param));
            }
        }
        auto resolvedEndpointOutcomePerOperation = endpointProvider->ResolveEndpoint(endpointParameters);
        ValidateOutcome(resolvedEndpointOutcomePerOperation, TEST_CASE.expect);
    }
#endif
}

INSTANTIATE_TEST_SUITE_P(EndpointTestsFromModel,
                         SnowballEndpointProviderTests,
                         ::testing::Range((size_t) 0u, TEST_CASES.size()));
