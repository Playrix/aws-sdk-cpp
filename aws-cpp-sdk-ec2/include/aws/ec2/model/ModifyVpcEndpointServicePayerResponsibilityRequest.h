﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/ec2/EC2Request.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/PayerResponsibility.h>
#include <utility>

namespace Aws
{
namespace EC2
{
namespace Model
{

  /**
   */
  class AWS_EC2_API ModifyVpcEndpointServicePayerResponsibilityRequest : public EC2Request
  {
  public:
    ModifyVpcEndpointServicePayerResponsibilityRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ModifyVpcEndpointServicePayerResponsibility"; }

    Aws::String SerializePayload() const override;

  protected:
    void DumpBodyToUrl(Aws::Http::URI& uri ) const override;

  public:

    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline bool GetDryRun() const{ return m_dryRun; }

    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline bool DryRunHasBeenSet() const { return m_dryRunHasBeenSet; }

    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline void SetDryRun(bool value) { m_dryRunHasBeenSet = true; m_dryRun = value; }

    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline ModifyVpcEndpointServicePayerResponsibilityRequest& WithDryRun(bool value) { SetDryRun(value); return *this;}


    /**
     * <p>The ID of the service.</p>
     */
    inline const Aws::String& GetServiceId() const{ return m_serviceId; }

    /**
     * <p>The ID of the service.</p>
     */
    inline bool ServiceIdHasBeenSet() const { return m_serviceIdHasBeenSet; }

    /**
     * <p>The ID of the service.</p>
     */
    inline void SetServiceId(const Aws::String& value) { m_serviceIdHasBeenSet = true; m_serviceId = value; }

    /**
     * <p>The ID of the service.</p>
     */
    inline void SetServiceId(Aws::String&& value) { m_serviceIdHasBeenSet = true; m_serviceId = std::move(value); }

    /**
     * <p>The ID of the service.</p>
     */
    inline void SetServiceId(const char* value) { m_serviceIdHasBeenSet = true; m_serviceId.assign(value); }

    /**
     * <p>The ID of the service.</p>
     */
    inline ModifyVpcEndpointServicePayerResponsibilityRequest& WithServiceId(const Aws::String& value) { SetServiceId(value); return *this;}

    /**
     * <p>The ID of the service.</p>
     */
    inline ModifyVpcEndpointServicePayerResponsibilityRequest& WithServiceId(Aws::String&& value) { SetServiceId(std::move(value)); return *this;}

    /**
     * <p>The ID of the service.</p>
     */
    inline ModifyVpcEndpointServicePayerResponsibilityRequest& WithServiceId(const char* value) { SetServiceId(value); return *this;}


    /**
     * <p>The entity that is responsible for the endpoint costs. The default is the
     * endpoint owner. If you set the payer responsibility to the service owner, you
     * cannot set it back to the endpoint owner.</p>
     */
    inline const PayerResponsibility& GetPayerResponsibility() const{ return m_payerResponsibility; }

    /**
     * <p>The entity that is responsible for the endpoint costs. The default is the
     * endpoint owner. If you set the payer responsibility to the service owner, you
     * cannot set it back to the endpoint owner.</p>
     */
    inline bool PayerResponsibilityHasBeenSet() const { return m_payerResponsibilityHasBeenSet; }

    /**
     * <p>The entity that is responsible for the endpoint costs. The default is the
     * endpoint owner. If you set the payer responsibility to the service owner, you
     * cannot set it back to the endpoint owner.</p>
     */
    inline void SetPayerResponsibility(const PayerResponsibility& value) { m_payerResponsibilityHasBeenSet = true; m_payerResponsibility = value; }

    /**
     * <p>The entity that is responsible for the endpoint costs. The default is the
     * endpoint owner. If you set the payer responsibility to the service owner, you
     * cannot set it back to the endpoint owner.</p>
     */
    inline void SetPayerResponsibility(PayerResponsibility&& value) { m_payerResponsibilityHasBeenSet = true; m_payerResponsibility = std::move(value); }

    /**
     * <p>The entity that is responsible for the endpoint costs. The default is the
     * endpoint owner. If you set the payer responsibility to the service owner, you
     * cannot set it back to the endpoint owner.</p>
     */
    inline ModifyVpcEndpointServicePayerResponsibilityRequest& WithPayerResponsibility(const PayerResponsibility& value) { SetPayerResponsibility(value); return *this;}

    /**
     * <p>The entity that is responsible for the endpoint costs. The default is the
     * endpoint owner. If you set the payer responsibility to the service owner, you
     * cannot set it back to the endpoint owner.</p>
     */
    inline ModifyVpcEndpointServicePayerResponsibilityRequest& WithPayerResponsibility(PayerResponsibility&& value) { SetPayerResponsibility(std::move(value)); return *this;}

  private:

    bool m_dryRun;
    bool m_dryRunHasBeenSet = false;

    Aws::String m_serviceId;
    bool m_serviceIdHasBeenSet = false;

    PayerResponsibility m_payerResponsibility;
    bool m_payerResponsibilityHasBeenSet = false;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
