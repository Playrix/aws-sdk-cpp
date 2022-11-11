﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/billingconductor/BillingConductor_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace BillingConductor
{
namespace Model
{
  enum class ValidationExceptionReason
  {
    NOT_SET,
    UNKNOWN_OPERATION,
    CANNOT_PARSE,
    FIELD_VALIDATION_FAILED,
    OTHER,
    PRIMARY_NOT_ASSOCIATED,
    PRIMARY_CANNOT_DISASSOCIATE,
    ACCOUNTS_NOT_ASSOCIATED,
    ACCOUNTS_ALREADY_ASSOCIATED,
    ILLEGAL_PRIMARY_ACCOUNT,
    ILLEGAL_ACCOUNTS,
    MISMATCHED_BILLINGGROUP_ARN,
    MISSING_BILLINGGROUP,
    MISMATCHED_CUSTOMLINEITEM_ARN,
    ILLEGAL_BILLING_PERIOD,
    ILLEGAL_BILLING_PERIOD_RANGE,
    TOO_MANY_ACCOUNTS_IN_REQUEST,
    DUPLICATE_ACCOUNT,
    INVALID_BILLING_GROUP_STATUS,
    MISMATCHED_PRICINGPLAN_ARN,
    MISSING_PRICINGPLAN,
    MISMATCHED_PRICINGRULE_ARN,
    DUPLICATE_PRICINGRULE_ARNS,
    ILLEGAL_EXPRESSION,
    ILLEGAL_SCOPE,
    ILLEGAL_SERVICE,
    PRICINGRULES_NOT_EXIST,
    PRICINGRULES_ALREADY_ASSOCIATED,
    PRICINGRULES_NOT_ASSOCIATED,
    INVALID_TIME_RANGE,
    INVALID_BILLINGVIEW_ARN,
    MISMATCHED_BILLINGVIEW_ARN,
    ILLEGAL_CUSTOMLINEITEM,
    MISSING_CUSTOMLINEITEM,
    ILLEGAL_CUSTOMLINEITEM_UPDATE,
    TOO_MANY_CUSTOMLINEITEMS_IN_REQUEST,
    ILLEGAL_CHARGE_DETAILS,
    ILLEGAL_UPDATE_CHARGE_DETAILS,
    INVALID_ARN,
    ILLEGAL_RESOURCE_ARNS,
    ILLEGAL_CUSTOMLINEITEM_MODIFICATION,
    MISSING_LINKED_ACCOUNT_IDS,
    MULTIPLE_LINKED_ACCOUNT_IDS,
    MISSING_PRICING_PLAN_ARN,
    MULTIPLE_PRICING_PLAN_ARN,
    ILLEGAL_CHILD_ASSOCIATE_RESOURCE,
    CUSTOM_LINE_ITEM_ASSOCIATION_EXISTS,
    INVALID_BILLING_PERIOD_FOR_OPERATION,
    INVALID_BILLING_GROUP
  };

namespace ValidationExceptionReasonMapper
{
AWS_BILLINGCONDUCTOR_API ValidationExceptionReason GetValidationExceptionReasonForName(const Aws::String& name);

AWS_BILLINGCONDUCTOR_API Aws::String GetNameForValidationExceptionReason(ValidationExceptionReason value);
} // namespace ValidationExceptionReasonMapper
} // namespace Model
} // namespace BillingConductor
} // namespace Aws
