﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/redshift-data/RedshiftDataAPIService_EXPORTS.h>
#include <aws/redshift-data/RedshiftDataAPIServiceRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace RedshiftDataAPIService
{
namespace Model
{

  /**
   */
  class AWS_REDSHIFTDATAAPISERVICE_API DescribeStatementRequest : public RedshiftDataAPIServiceRequest
  {
  public:
    DescribeStatementRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeStatement"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline const Aws::String& GetId() const{ return m_id; }

    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline bool IdHasBeenSet() const { return m_idHasBeenSet; }

    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline void SetId(const Aws::String& value) { m_idHasBeenSet = true; m_id = value; }

    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline void SetId(Aws::String&& value) { m_idHasBeenSet = true; m_id = std::move(value); }

    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline void SetId(const char* value) { m_idHasBeenSet = true; m_id.assign(value); }

    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline DescribeStatementRequest& WithId(const Aws::String& value) { SetId(value); return *this;}

    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline DescribeStatementRequest& WithId(Aws::String&& value) { SetId(std::move(value)); return *this;}

    /**
     * <p>The identifier of the SQL statement to describe. This value is a universally
     * unique identifier (UUID) generated by Amazon Redshift Data API. A suffix
     * indicates the number of the SQL statement. For example,
     * <code>d9b6c0c9-0747-4bf4-b142-e8883122f766:2</code> has a suffix of
     * <code>:2</code> that indicates the second SQL statement of a batch query. This
     * identifier is returned by <code>BatchExecuteStatment</code>,
     * <code>ExecuteStatement</code>, and <code>ListStatements</code>. </p>
     */
    inline DescribeStatementRequest& WithId(const char* value) { SetId(value); return *this;}

  private:

    Aws::String m_id;
    bool m_idHasBeenSet = false;
  };

} // namespace Model
} // namespace RedshiftDataAPIService
} // namespace Aws
