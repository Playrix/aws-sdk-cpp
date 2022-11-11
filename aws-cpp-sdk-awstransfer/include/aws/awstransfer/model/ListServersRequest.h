﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/awstransfer/Transfer_EXPORTS.h>
#include <aws/awstransfer/TransferRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Transfer
{
namespace Model
{

  /**
   */
  class AWS_TRANSFER_API ListServersRequest : public TransferRequest
  {
  public:
    ListServersRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ListServers"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>Specifies the number of servers to return as a response to the
     * <code>ListServers</code> query.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>Specifies the number of servers to return as a response to the
     * <code>ListServers</code> query.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>Specifies the number of servers to return as a response to the
     * <code>ListServers</code> query.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>Specifies the number of servers to return as a response to the
     * <code>ListServers</code> query.</p>
     */
    inline ListServersRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}


    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline ListServersRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline ListServersRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>When additional results are obtained from the <code>ListServers</code>
     * command, a <code>NextToken</code> parameter is returned in the output. You can
     * then pass the <code>NextToken</code> parameter in a subsequent command to
     * continue listing additional servers.</p>
     */
    inline ListServersRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;
  };

} // namespace Model
} // namespace Transfer
} // namespace Aws
