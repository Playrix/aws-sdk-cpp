﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/amp/PrometheusService_EXPORTS.h>
#include <aws/amp/PrometheusServiceRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/Array.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <utility>
#include <aws/core/utils/UUID.h>

namespace Aws
{
namespace PrometheusService
{
namespace Model
{

  /**
   * <p>Represents the input of a CreateRuleGroupsNamespace operation.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/amp-2020-08-01/CreateRuleGroupsNamespaceRequest">AWS
   * API Reference</a></p>
   */
  class AWS_PROMETHEUSSERVICE_API CreateRuleGroupsNamespaceRequest : public PrometheusServiceRequest
  {
  public:
    CreateRuleGroupsNamespaceRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CreateRuleGroupsNamespace"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline const Aws::String& GetClientToken() const{ return m_clientToken; }

    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline bool ClientTokenHasBeenSet() const { return m_clientTokenHasBeenSet; }

    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline void SetClientToken(const Aws::String& value) { m_clientTokenHasBeenSet = true; m_clientToken = value; }

    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline void SetClientToken(Aws::String&& value) { m_clientTokenHasBeenSet = true; m_clientToken = std::move(value); }

    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline void SetClientToken(const char* value) { m_clientTokenHasBeenSet = true; m_clientToken.assign(value); }

    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithClientToken(const Aws::String& value) { SetClientToken(value); return *this;}

    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithClientToken(Aws::String&& value) { SetClientToken(std::move(value)); return *this;}

    /**
     * <p>Optional, unique, case-sensitive, user-provided identifier to ensure the
     * idempotency of the request.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithClientToken(const char* value) { SetClientToken(value); return *this;}


    /**
     * <p>The namespace data that define the rule groups.</p>
     */
    inline const Aws::Utils::ByteBuffer& GetData() const{ return m_data; }

    /**
     * <p>The namespace data that define the rule groups.</p>
     */
    inline bool DataHasBeenSet() const { return m_dataHasBeenSet; }

    /**
     * <p>The namespace data that define the rule groups.</p>
     */
    inline void SetData(const Aws::Utils::ByteBuffer& value) { m_dataHasBeenSet = true; m_data = value; }

    /**
     * <p>The namespace data that define the rule groups.</p>
     */
    inline void SetData(Aws::Utils::ByteBuffer&& value) { m_dataHasBeenSet = true; m_data = std::move(value); }

    /**
     * <p>The namespace data that define the rule groups.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithData(const Aws::Utils::ByteBuffer& value) { SetData(value); return *this;}

    /**
     * <p>The namespace data that define the rule groups.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithData(Aws::Utils::ByteBuffer&& value) { SetData(std::move(value)); return *this;}


    /**
     * <p>The rule groups namespace name.</p>
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * <p>The rule groups namespace name.</p>
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * <p>The rule groups namespace name.</p>
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>The rule groups namespace name.</p>
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * <p>The rule groups namespace name.</p>
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * <p>The rule groups namespace name.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * <p>The rule groups namespace name.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * <p>The rule groups namespace name.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithName(const char* value) { SetName(value); return *this;}


    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetTags() const{ return m_tags; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline bool TagsHasBeenSet() const { return m_tagsHasBeenSet; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline void SetTags(const Aws::Map<Aws::String, Aws::String>& value) { m_tagsHasBeenSet = true; m_tags = value; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline void SetTags(Aws::Map<Aws::String, Aws::String>&& value) { m_tagsHasBeenSet = true; m_tags = std::move(value); }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithTags(const Aws::Map<Aws::String, Aws::String>& value) { SetTags(value); return *this;}

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithTags(Aws::Map<Aws::String, Aws::String>&& value) { SetTags(std::move(value)); return *this;}

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& AddTags(const Aws::String& key, const Aws::String& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, value); return *this; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& AddTags(Aws::String&& key, const Aws::String& value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), value); return *this; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& AddTags(const Aws::String& key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, std::move(value)); return *this; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& AddTags(Aws::String&& key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), std::move(value)); return *this; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& AddTags(const char* key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, std::move(value)); return *this; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& AddTags(Aws::String&& key, const char* value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), value); return *this; }

    /**
     * <p>Optional, user-provided tags for this rule groups namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& AddTags(const char* key, const char* value) { m_tagsHasBeenSet = true; m_tags.emplace(key, value); return *this; }


    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline const Aws::String& GetWorkspaceId() const{ return m_workspaceId; }

    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline bool WorkspaceIdHasBeenSet() const { return m_workspaceIdHasBeenSet; }

    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline void SetWorkspaceId(const Aws::String& value) { m_workspaceIdHasBeenSet = true; m_workspaceId = value; }

    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline void SetWorkspaceId(Aws::String&& value) { m_workspaceIdHasBeenSet = true; m_workspaceId = std::move(value); }

    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline void SetWorkspaceId(const char* value) { m_workspaceIdHasBeenSet = true; m_workspaceId.assign(value); }

    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithWorkspaceId(const Aws::String& value) { SetWorkspaceId(value); return *this;}

    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithWorkspaceId(Aws::String&& value) { SetWorkspaceId(std::move(value)); return *this;}

    /**
     * <p>The ID of the workspace in which to create the rule group namespace.</p>
     */
    inline CreateRuleGroupsNamespaceRequest& WithWorkspaceId(const char* value) { SetWorkspaceId(value); return *this;}

  private:

    Aws::String m_clientToken;
    bool m_clientTokenHasBeenSet = false;

    Aws::Utils::ByteBuffer m_data;
    bool m_dataHasBeenSet = false;

    Aws::String m_name;
    bool m_nameHasBeenSet = false;

    Aws::Map<Aws::String, Aws::String> m_tags;
    bool m_tagsHasBeenSet = false;

    Aws::String m_workspaceId;
    bool m_workspaceIdHasBeenSet = false;
  };

} // namespace Model
} // namespace PrometheusService
} // namespace Aws
