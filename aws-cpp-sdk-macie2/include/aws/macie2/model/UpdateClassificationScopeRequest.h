﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/macie2/Macie2_EXPORTS.h>
#include <aws/macie2/Macie2Request.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/macie2/model/S3ClassificationScopeUpdate.h>
#include <utility>

namespace Aws
{
namespace Macie2
{
namespace Model
{

  /**
   */
  class AWS_MACIE2_API UpdateClassificationScopeRequest : public Macie2Request
  {
  public:
    UpdateClassificationScopeRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "UpdateClassificationScope"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline const Aws::String& GetId() const{ return m_id; }

    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline bool IdHasBeenSet() const { return m_idHasBeenSet; }

    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline void SetId(const Aws::String& value) { m_idHasBeenSet = true; m_id = value; }

    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline void SetId(Aws::String&& value) { m_idHasBeenSet = true; m_id = std::move(value); }

    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline void SetId(const char* value) { m_idHasBeenSet = true; m_id.assign(value); }

    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline UpdateClassificationScopeRequest& WithId(const Aws::String& value) { SetId(value); return *this;}

    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline UpdateClassificationScopeRequest& WithId(Aws::String&& value) { SetId(std::move(value)); return *this;}

    /**
     * <p>The unique identifier for the Amazon Macie resource that the request applies
     * to.</p>
     */
    inline UpdateClassificationScopeRequest& WithId(const char* value) { SetId(value); return *this;}


    /**
     * <p>The S3 buckets to add or remove from the exclusion list defined by the
     * classification scope.</p>
     */
    inline const S3ClassificationScopeUpdate& GetS3() const{ return m_s3; }

    /**
     * <p>The S3 buckets to add or remove from the exclusion list defined by the
     * classification scope.</p>
     */
    inline bool S3HasBeenSet() const { return m_s3HasBeenSet; }

    /**
     * <p>The S3 buckets to add or remove from the exclusion list defined by the
     * classification scope.</p>
     */
    inline void SetS3(const S3ClassificationScopeUpdate& value) { m_s3HasBeenSet = true; m_s3 = value; }

    /**
     * <p>The S3 buckets to add or remove from the exclusion list defined by the
     * classification scope.</p>
     */
    inline void SetS3(S3ClassificationScopeUpdate&& value) { m_s3HasBeenSet = true; m_s3 = std::move(value); }

    /**
     * <p>The S3 buckets to add or remove from the exclusion list defined by the
     * classification scope.</p>
     */
    inline UpdateClassificationScopeRequest& WithS3(const S3ClassificationScopeUpdate& value) { SetS3(value); return *this;}

    /**
     * <p>The S3 buckets to add or remove from the exclusion list defined by the
     * classification scope.</p>
     */
    inline UpdateClassificationScopeRequest& WithS3(S3ClassificationScopeUpdate&& value) { SetS3(std::move(value)); return *this;}

  private:

    Aws::String m_id;
    bool m_idHasBeenSet = false;

    S3ClassificationScopeUpdate m_s3;
    bool m_s3HasBeenSet = false;
  };

} // namespace Model
} // namespace Macie2
} // namespace Aws
