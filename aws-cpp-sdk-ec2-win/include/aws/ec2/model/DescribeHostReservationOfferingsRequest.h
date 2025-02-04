﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/ec2/EC2Request.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/Filter.h>
#include <utility>

namespace Aws
{
namespace EC2
{
namespace Model
{

  /**
   */
  class AWS_EC2_API DescribeHostReservationOfferingsRequest : public EC2Request
  {
  public:
    DescribeHostReservationOfferingsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeHostReservationOfferings"; }

    Aws::String SerializePayload() const override;

  protected:
    void DumpBodyToUrl(Aws::Http::URI& uri ) const override;

  public:

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline const Aws::Vector<Filter>& GetFilter() const{ return m_filter; }

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline bool FilterHasBeenSet() const { return m_filterHasBeenSet; }

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline void SetFilter(const Aws::Vector<Filter>& value) { m_filterHasBeenSet = true; m_filter = value; }

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline void SetFilter(Aws::Vector<Filter>&& value) { m_filterHasBeenSet = true; m_filter = std::move(value); }

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline DescribeHostReservationOfferingsRequest& WithFilter(const Aws::Vector<Filter>& value) { SetFilter(value); return *this;}

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline DescribeHostReservationOfferingsRequest& WithFilter(Aws::Vector<Filter>&& value) { SetFilter(std::move(value)); return *this;}

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline DescribeHostReservationOfferingsRequest& AddFilter(const Filter& value) { m_filterHasBeenSet = true; m_filter.push_back(value); return *this; }

    /**
     * <p>The filters.</p> <ul> <li> <p> <code>instance-family</code> - The instance
     * family of the offering (for example, <code>m4</code>).</p> </li> <li> <p>
     * <code>payment-option</code> - The payment option (<code>NoUpfront</code> |
     * <code>PartialUpfront</code> | <code>AllUpfront</code>).</p> </li> </ul>
     */
    inline DescribeHostReservationOfferingsRequest& AddFilter(Filter&& value) { m_filterHasBeenSet = true; m_filter.push_back(std::move(value)); return *this; }


    /**
     * <p>This is the maximum duration of the reservation to purchase, specified in
     * seconds. Reservations are available in one-year and three-year terms. The number
     * of seconds specified must be the number of seconds in a year (365x24x60x60)
     * times one of the supported durations (1 or 3). For example, specify 94608000 for
     * three years.</p>
     */
    inline int GetMaxDuration() const{ return m_maxDuration; }

    /**
     * <p>This is the maximum duration of the reservation to purchase, specified in
     * seconds. Reservations are available in one-year and three-year terms. The number
     * of seconds specified must be the number of seconds in a year (365x24x60x60)
     * times one of the supported durations (1 or 3). For example, specify 94608000 for
     * three years.</p>
     */
    inline bool MaxDurationHasBeenSet() const { return m_maxDurationHasBeenSet; }

    /**
     * <p>This is the maximum duration of the reservation to purchase, specified in
     * seconds. Reservations are available in one-year and three-year terms. The number
     * of seconds specified must be the number of seconds in a year (365x24x60x60)
     * times one of the supported durations (1 or 3). For example, specify 94608000 for
     * three years.</p>
     */
    inline void SetMaxDuration(int value) { m_maxDurationHasBeenSet = true; m_maxDuration = value; }

    /**
     * <p>This is the maximum duration of the reservation to purchase, specified in
     * seconds. Reservations are available in one-year and three-year terms. The number
     * of seconds specified must be the number of seconds in a year (365x24x60x60)
     * times one of the supported durations (1 or 3). For example, specify 94608000 for
     * three years.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithMaxDuration(int value) { SetMaxDuration(value); return *this;}


    /**
     * <p>The maximum number of results to return for the request in a single page. The
     * remaining results can be seen by sending another request with the returned
     * <code>nextToken</code> value. This value can be between 5 and 500. If
     * <code>maxResults</code> is given a larger value than 500, you receive an
     * error.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>The maximum number of results to return for the request in a single page. The
     * remaining results can be seen by sending another request with the returned
     * <code>nextToken</code> value. This value can be between 5 and 500. If
     * <code>maxResults</code> is given a larger value than 500, you receive an
     * error.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>The maximum number of results to return for the request in a single page. The
     * remaining results can be seen by sending another request with the returned
     * <code>nextToken</code> value. This value can be between 5 and 500. If
     * <code>maxResults</code> is given a larger value than 500, you receive an
     * error.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>The maximum number of results to return for the request in a single page. The
     * remaining results can be seen by sending another request with the returned
     * <code>nextToken</code> value. This value can be between 5 and 500. If
     * <code>maxResults</code> is given a larger value than 500, you receive an
     * error.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}


    /**
     * <p>This is the minimum duration of the reservation you'd like to purchase,
     * specified in seconds. Reservations are available in one-year and three-year
     * terms. The number of seconds specified must be the number of seconds in a year
     * (365x24x60x60) times one of the supported durations (1 or 3). For example,
     * specify 31536000 for one year.</p>
     */
    inline int GetMinDuration() const{ return m_minDuration; }

    /**
     * <p>This is the minimum duration of the reservation you'd like to purchase,
     * specified in seconds. Reservations are available in one-year and three-year
     * terms. The number of seconds specified must be the number of seconds in a year
     * (365x24x60x60) times one of the supported durations (1 or 3). For example,
     * specify 31536000 for one year.</p>
     */
    inline bool MinDurationHasBeenSet() const { return m_minDurationHasBeenSet; }

    /**
     * <p>This is the minimum duration of the reservation you'd like to purchase,
     * specified in seconds. Reservations are available in one-year and three-year
     * terms. The number of seconds specified must be the number of seconds in a year
     * (365x24x60x60) times one of the supported durations (1 or 3). For example,
     * specify 31536000 for one year.</p>
     */
    inline void SetMinDuration(int value) { m_minDurationHasBeenSet = true; m_minDuration = value; }

    /**
     * <p>This is the minimum duration of the reservation you'd like to purchase,
     * specified in seconds. Reservations are available in one-year and three-year
     * terms. The number of seconds specified must be the number of seconds in a year
     * (365x24x60x60) times one of the supported durations (1 or 3). For example,
     * specify 31536000 for one year.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithMinDuration(int value) { SetMinDuration(value); return *this;}


    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>The token to use to retrieve the next page of results.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline const Aws::String& GetOfferingId() const{ return m_offeringId; }

    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline bool OfferingIdHasBeenSet() const { return m_offeringIdHasBeenSet; }

    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline void SetOfferingId(const Aws::String& value) { m_offeringIdHasBeenSet = true; m_offeringId = value; }

    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline void SetOfferingId(Aws::String&& value) { m_offeringIdHasBeenSet = true; m_offeringId = std::move(value); }

    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline void SetOfferingId(const char* value) { m_offeringIdHasBeenSet = true; m_offeringId.assign(value); }

    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithOfferingId(const Aws::String& value) { SetOfferingId(value); return *this;}

    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithOfferingId(Aws::String&& value) { SetOfferingId(std::move(value)); return *this;}

    /**
     * <p>The ID of the reservation offering.</p>
     */
    inline DescribeHostReservationOfferingsRequest& WithOfferingId(const char* value) { SetOfferingId(value); return *this;}

  private:

    Aws::Vector<Filter> m_filter;
    bool m_filterHasBeenSet = false;

    int m_maxDuration;
    bool m_maxDurationHasBeenSet = false;

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;

    int m_minDuration;
    bool m_minDurationHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    Aws::String m_offeringId;
    bool m_offeringIdHasBeenSet = false;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
