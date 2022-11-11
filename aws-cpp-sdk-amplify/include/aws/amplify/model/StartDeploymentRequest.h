﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/amplify/Amplify_EXPORTS.h>
#include <aws/amplify/AmplifyRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Amplify
{
namespace Model
{

  /**
   * <p> The request structure for the start a deployment request. </p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/amplify-2017-07-25/StartDeploymentRequest">AWS
   * API Reference</a></p>
   */
  class AWS_AMPLIFY_API StartDeploymentRequest : public AmplifyRequest
  {
  public:
    StartDeploymentRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "StartDeployment"; }

    Aws::String SerializePayload() const override;


    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline const Aws::String& GetAppId() const{ return m_appId; }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline bool AppIdHasBeenSet() const { return m_appIdHasBeenSet; }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline void SetAppId(const Aws::String& value) { m_appIdHasBeenSet = true; m_appId = value; }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline void SetAppId(Aws::String&& value) { m_appIdHasBeenSet = true; m_appId = std::move(value); }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline void SetAppId(const char* value) { m_appIdHasBeenSet = true; m_appId.assign(value); }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline StartDeploymentRequest& WithAppId(const Aws::String& value) { SetAppId(value); return *this;}

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline StartDeploymentRequest& WithAppId(Aws::String&& value) { SetAppId(std::move(value)); return *this;}

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline StartDeploymentRequest& WithAppId(const char* value) { SetAppId(value); return *this;}


    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline const Aws::String& GetBranchName() const{ return m_branchName; }

    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline bool BranchNameHasBeenSet() const { return m_branchNameHasBeenSet; }

    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline void SetBranchName(const Aws::String& value) { m_branchNameHasBeenSet = true; m_branchName = value; }

    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline void SetBranchName(Aws::String&& value) { m_branchNameHasBeenSet = true; m_branchName = std::move(value); }

    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline void SetBranchName(const char* value) { m_branchNameHasBeenSet = true; m_branchName.assign(value); }

    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline StartDeploymentRequest& WithBranchName(const Aws::String& value) { SetBranchName(value); return *this;}

    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline StartDeploymentRequest& WithBranchName(Aws::String&& value) { SetBranchName(std::move(value)); return *this;}

    /**
     * <p> The name for the branch, for the job. </p>
     */
    inline StartDeploymentRequest& WithBranchName(const char* value) { SetBranchName(value); return *this;}


    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline const Aws::String& GetJobId() const{ return m_jobId; }

    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline bool JobIdHasBeenSet() const { return m_jobIdHasBeenSet; }

    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline void SetJobId(const Aws::String& value) { m_jobIdHasBeenSet = true; m_jobId = value; }

    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline void SetJobId(Aws::String&& value) { m_jobIdHasBeenSet = true; m_jobId = std::move(value); }

    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline void SetJobId(const char* value) { m_jobIdHasBeenSet = true; m_jobId.assign(value); }

    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline StartDeploymentRequest& WithJobId(const Aws::String& value) { SetJobId(value); return *this;}

    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline StartDeploymentRequest& WithJobId(Aws::String&& value) { SetJobId(std::move(value)); return *this;}

    /**
     * <p> The job ID for this deployment, generated by the create deployment request.
     * </p>
     */
    inline StartDeploymentRequest& WithJobId(const char* value) { SetJobId(value); return *this;}


    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline const Aws::String& GetSourceUrl() const{ return m_sourceUrl; }

    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline bool SourceUrlHasBeenSet() const { return m_sourceUrlHasBeenSet; }

    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline void SetSourceUrl(const Aws::String& value) { m_sourceUrlHasBeenSet = true; m_sourceUrl = value; }

    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline void SetSourceUrl(Aws::String&& value) { m_sourceUrlHasBeenSet = true; m_sourceUrl = std::move(value); }

    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline void SetSourceUrl(const char* value) { m_sourceUrlHasBeenSet = true; m_sourceUrl.assign(value); }

    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline StartDeploymentRequest& WithSourceUrl(const Aws::String& value) { SetSourceUrl(value); return *this;}

    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline StartDeploymentRequest& WithSourceUrl(Aws::String&& value) { SetSourceUrl(std::move(value)); return *this;}

    /**
     * <p> The source URL for this deployment, used when calling start deployment
     * without create deployment. The source URL can be any HTTP GET URL that is
     * publicly accessible and downloads a single .zip file. </p>
     */
    inline StartDeploymentRequest& WithSourceUrl(const char* value) { SetSourceUrl(value); return *this;}

  private:

    Aws::String m_appId;
    bool m_appIdHasBeenSet = false;

    Aws::String m_branchName;
    bool m_branchNameHasBeenSet = false;

    Aws::String m_jobId;
    bool m_jobIdHasBeenSet = false;

    Aws::String m_sourceUrl;
    bool m_sourceUrlHasBeenSet = false;
  };

} // namespace Model
} // namespace Amplify
} // namespace Aws
