﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3control/S3Control_EXPORTS.h>
#include <aws/s3control/model/BucketVersioningStatus.h>
#include <aws/s3control/model/MFADeleteStatus.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace S3Control
{
namespace Model
{
  class AWS_S3CONTROL_API GetBucketVersioningResult
  {
  public:
    GetBucketVersioningResult();
    GetBucketVersioningResult(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    GetBucketVersioningResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);


    /**
     * <p>The versioning state of the S3 on Outposts bucket.</p>
     */
    inline const BucketVersioningStatus& GetStatus() const{ return m_status; }

    /**
     * <p>The versioning state of the S3 on Outposts bucket.</p>
     */
    inline void SetStatus(const BucketVersioningStatus& value) { m_status = value; }

    /**
     * <p>The versioning state of the S3 on Outposts bucket.</p>
     */
    inline void SetStatus(BucketVersioningStatus&& value) { m_status = std::move(value); }

    /**
     * <p>The versioning state of the S3 on Outposts bucket.</p>
     */
    inline GetBucketVersioningResult& WithStatus(const BucketVersioningStatus& value) { SetStatus(value); return *this;}

    /**
     * <p>The versioning state of the S3 on Outposts bucket.</p>
     */
    inline GetBucketVersioningResult& WithStatus(BucketVersioningStatus&& value) { SetStatus(std::move(value)); return *this;}


    /**
     * <p>Specifies whether MFA delete is enabled in the bucket versioning
     * configuration. This element is returned only if the bucket has been configured
     * with MFA delete. If MFA delete has never been configured for the bucket, this
     * element is not returned.</p>
     */
    inline const MFADeleteStatus& GetMFADelete() const{ return m_mFADelete; }

    /**
     * <p>Specifies whether MFA delete is enabled in the bucket versioning
     * configuration. This element is returned only if the bucket has been configured
     * with MFA delete. If MFA delete has never been configured for the bucket, this
     * element is not returned.</p>
     */
    inline void SetMFADelete(const MFADeleteStatus& value) { m_mFADelete = value; }

    /**
     * <p>Specifies whether MFA delete is enabled in the bucket versioning
     * configuration. This element is returned only if the bucket has been configured
     * with MFA delete. If MFA delete has never been configured for the bucket, this
     * element is not returned.</p>
     */
    inline void SetMFADelete(MFADeleteStatus&& value) { m_mFADelete = std::move(value); }

    /**
     * <p>Specifies whether MFA delete is enabled in the bucket versioning
     * configuration. This element is returned only if the bucket has been configured
     * with MFA delete. If MFA delete has never been configured for the bucket, this
     * element is not returned.</p>
     */
    inline GetBucketVersioningResult& WithMFADelete(const MFADeleteStatus& value) { SetMFADelete(value); return *this;}

    /**
     * <p>Specifies whether MFA delete is enabled in the bucket versioning
     * configuration. This element is returned only if the bucket has been configured
     * with MFA delete. If MFA delete has never been configured for the bucket, this
     * element is not returned.</p>
     */
    inline GetBucketVersioningResult& WithMFADelete(MFADeleteStatus&& value) { SetMFADelete(std::move(value)); return *this;}

  private:

    BucketVersioningStatus m_status;

    MFADeleteStatus m_mFADelete;
  };

} // namespace Model
} // namespace S3Control
} // namespace Aws
