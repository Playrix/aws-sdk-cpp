﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/customer-profiles/CustomerProfiles_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace CustomerProfiles
{
namespace Model
{

  /**
   * <p>A data type pair that consists of a <code>KeyName</code> and
   * <code>Values</code> list that is used in conjunction with the <a
   * href="https://docs.aws.amazon.com/customerprofiles/latest/APIReference/API_SearchProfiles.html#customerprofiles-SearchProfiles-request-KeyName">KeyName</a>
   * and <a
   * href="https://docs.aws.amazon.com/customerprofiles/latest/APIReference/API_SearchProfiles.html#customerprofiles-SearchProfiles-request-Values">Values</a>
   * parameters to search for profiles using the <a
   * href="https://docs.aws.amazon.com/customerprofiles/latest/APIReference/API_SearchProfiles.html">SearchProfiles</a>
   * API.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/customer-profiles-2020-08-15/AdditionalSearchKey">AWS
   * API Reference</a></p>
   */
  class AWS_CUSTOMERPROFILES_API AdditionalSearchKey
  {
  public:
    AdditionalSearchKey();
    AdditionalSearchKey(Aws::Utils::Json::JsonView jsonValue);
    AdditionalSearchKey& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline const Aws::String& GetKeyName() const{ return m_keyName; }

    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline bool KeyNameHasBeenSet() const { return m_keyNameHasBeenSet; }

    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline void SetKeyName(const Aws::String& value) { m_keyNameHasBeenSet = true; m_keyName = value; }

    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline void SetKeyName(Aws::String&& value) { m_keyNameHasBeenSet = true; m_keyName = std::move(value); }

    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline void SetKeyName(const char* value) { m_keyNameHasBeenSet = true; m_keyName.assign(value); }

    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline AdditionalSearchKey& WithKeyName(const Aws::String& value) { SetKeyName(value); return *this;}

    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline AdditionalSearchKey& WithKeyName(Aws::String&& value) { SetKeyName(std::move(value)); return *this;}

    /**
     * <p>A searchable identifier of a customer profile.</p>
     */
    inline AdditionalSearchKey& WithKeyName(const char* value) { SetKeyName(value); return *this;}


    /**
     * <p>A list of key values.</p>
     */
    inline const Aws::Vector<Aws::String>& GetValues() const{ return m_values; }

    /**
     * <p>A list of key values.</p>
     */
    inline bool ValuesHasBeenSet() const { return m_valuesHasBeenSet; }

    /**
     * <p>A list of key values.</p>
     */
    inline void SetValues(const Aws::Vector<Aws::String>& value) { m_valuesHasBeenSet = true; m_values = value; }

    /**
     * <p>A list of key values.</p>
     */
    inline void SetValues(Aws::Vector<Aws::String>&& value) { m_valuesHasBeenSet = true; m_values = std::move(value); }

    /**
     * <p>A list of key values.</p>
     */
    inline AdditionalSearchKey& WithValues(const Aws::Vector<Aws::String>& value) { SetValues(value); return *this;}

    /**
     * <p>A list of key values.</p>
     */
    inline AdditionalSearchKey& WithValues(Aws::Vector<Aws::String>&& value) { SetValues(std::move(value)); return *this;}

    /**
     * <p>A list of key values.</p>
     */
    inline AdditionalSearchKey& AddValues(const Aws::String& value) { m_valuesHasBeenSet = true; m_values.push_back(value); return *this; }

    /**
     * <p>A list of key values.</p>
     */
    inline AdditionalSearchKey& AddValues(Aws::String&& value) { m_valuesHasBeenSet = true; m_values.push_back(std::move(value)); return *this; }

    /**
     * <p>A list of key values.</p>
     */
    inline AdditionalSearchKey& AddValues(const char* value) { m_valuesHasBeenSet = true; m_values.push_back(value); return *this; }

  private:

    Aws::String m_keyName;
    bool m_keyNameHasBeenSet = false;

    Aws::Vector<Aws::String> m_values;
    bool m_valuesHasBeenSet = false;
  };

} // namespace Model
} // namespace CustomerProfiles
} // namespace Aws
