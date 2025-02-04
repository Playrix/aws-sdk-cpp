﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/quicksight/QuickSight_EXPORTS.h>
#include <aws/quicksight/model/ValueWhenUnsetOption.h>
#include <aws/core/utils/DateTime.h>
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
namespace QuickSight
{
namespace Model
{

  /**
   * <p>The configuration that defines the default value of a <code>DateTime</code>
   * parameter when a value has not been set.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/quicksight-2018-04-01/DateTimeValueWhenUnsetConfiguration">AWS
   * API Reference</a></p>
   */
  class AWS_QUICKSIGHT_API DateTimeValueWhenUnsetConfiguration
  {
  public:
    DateTimeValueWhenUnsetConfiguration();
    DateTimeValueWhenUnsetConfiguration(Aws::Utils::Json::JsonView jsonValue);
    DateTimeValueWhenUnsetConfiguration& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The built-in options for default values. The value can be one of the
     * following:</p> <ul> <li> <p> <code>RECOMMENDED</code>: The recommended
     * value.</p> </li> <li> <p> <code>NULL</code>: The <code>NULL</code> value.</p>
     * </li> </ul>
     */
    inline const ValueWhenUnsetOption& GetValueWhenUnsetOption() const{ return m_valueWhenUnsetOption; }

    /**
     * <p>The built-in options for default values. The value can be one of the
     * following:</p> <ul> <li> <p> <code>RECOMMENDED</code>: The recommended
     * value.</p> </li> <li> <p> <code>NULL</code>: The <code>NULL</code> value.</p>
     * </li> </ul>
     */
    inline bool ValueWhenUnsetOptionHasBeenSet() const { return m_valueWhenUnsetOptionHasBeenSet; }

    /**
     * <p>The built-in options for default values. The value can be one of the
     * following:</p> <ul> <li> <p> <code>RECOMMENDED</code>: The recommended
     * value.</p> </li> <li> <p> <code>NULL</code>: The <code>NULL</code> value.</p>
     * </li> </ul>
     */
    inline void SetValueWhenUnsetOption(const ValueWhenUnsetOption& value) { m_valueWhenUnsetOptionHasBeenSet = true; m_valueWhenUnsetOption = value; }

    /**
     * <p>The built-in options for default values. The value can be one of the
     * following:</p> <ul> <li> <p> <code>RECOMMENDED</code>: The recommended
     * value.</p> </li> <li> <p> <code>NULL</code>: The <code>NULL</code> value.</p>
     * </li> </ul>
     */
    inline void SetValueWhenUnsetOption(ValueWhenUnsetOption&& value) { m_valueWhenUnsetOptionHasBeenSet = true; m_valueWhenUnsetOption = std::move(value); }

    /**
     * <p>The built-in options for default values. The value can be one of the
     * following:</p> <ul> <li> <p> <code>RECOMMENDED</code>: The recommended
     * value.</p> </li> <li> <p> <code>NULL</code>: The <code>NULL</code> value.</p>
     * </li> </ul>
     */
    inline DateTimeValueWhenUnsetConfiguration& WithValueWhenUnsetOption(const ValueWhenUnsetOption& value) { SetValueWhenUnsetOption(value); return *this;}

    /**
     * <p>The built-in options for default values. The value can be one of the
     * following:</p> <ul> <li> <p> <code>RECOMMENDED</code>: The recommended
     * value.</p> </li> <li> <p> <code>NULL</code>: The <code>NULL</code> value.</p>
     * </li> </ul>
     */
    inline DateTimeValueWhenUnsetConfiguration& WithValueWhenUnsetOption(ValueWhenUnsetOption&& value) { SetValueWhenUnsetOption(std::move(value)); return *this;}


    /**
     * <p>A custom value that's used when the value of a parameter isn't set.</p>
     */
    inline const Aws::Utils::DateTime& GetCustomValue() const{ return m_customValue; }

    /**
     * <p>A custom value that's used when the value of a parameter isn't set.</p>
     */
    inline bool CustomValueHasBeenSet() const { return m_customValueHasBeenSet; }

    /**
     * <p>A custom value that's used when the value of a parameter isn't set.</p>
     */
    inline void SetCustomValue(const Aws::Utils::DateTime& value) { m_customValueHasBeenSet = true; m_customValue = value; }

    /**
     * <p>A custom value that's used when the value of a parameter isn't set.</p>
     */
    inline void SetCustomValue(Aws::Utils::DateTime&& value) { m_customValueHasBeenSet = true; m_customValue = std::move(value); }

    /**
     * <p>A custom value that's used when the value of a parameter isn't set.</p>
     */
    inline DateTimeValueWhenUnsetConfiguration& WithCustomValue(const Aws::Utils::DateTime& value) { SetCustomValue(value); return *this;}

    /**
     * <p>A custom value that's used when the value of a parameter isn't set.</p>
     */
    inline DateTimeValueWhenUnsetConfiguration& WithCustomValue(Aws::Utils::DateTime&& value) { SetCustomValue(std::move(value)); return *this;}

  private:

    ValueWhenUnsetOption m_valueWhenUnsetOption;
    bool m_valueWhenUnsetOptionHasBeenSet = false;

    Aws::Utils::DateTime m_customValue;
    bool m_customValueHasBeenSet = false;
  };

} // namespace Model
} // namespace QuickSight
} // namespace Aws
