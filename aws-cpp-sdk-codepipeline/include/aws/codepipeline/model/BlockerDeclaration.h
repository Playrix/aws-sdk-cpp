﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/codepipeline/CodePipeline_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/codepipeline/model/BlockerType.h>
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
namespace CodePipeline
{
namespace Model
{

  /**
   * <p>Reserved for future use.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/codepipeline-2015-07-09/BlockerDeclaration">AWS
   * API Reference</a></p>
   */
  class AWS_CODEPIPELINE_API BlockerDeclaration
  {
  public:
    BlockerDeclaration();
    BlockerDeclaration(Aws::Utils::Json::JsonView jsonValue);
    BlockerDeclaration& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>Reserved for future use.</p>
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * <p>Reserved for future use.</p>
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * <p>Reserved for future use.</p>
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>Reserved for future use.</p>
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * <p>Reserved for future use.</p>
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * <p>Reserved for future use.</p>
     */
    inline BlockerDeclaration& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * <p>Reserved for future use.</p>
     */
    inline BlockerDeclaration& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * <p>Reserved for future use.</p>
     */
    inline BlockerDeclaration& WithName(const char* value) { SetName(value); return *this;}


    /**
     * <p>Reserved for future use.</p>
     */
    inline const BlockerType& GetType() const{ return m_type; }

    /**
     * <p>Reserved for future use.</p>
     */
    inline bool TypeHasBeenSet() const { return m_typeHasBeenSet; }

    /**
     * <p>Reserved for future use.</p>
     */
    inline void SetType(const BlockerType& value) { m_typeHasBeenSet = true; m_type = value; }

    /**
     * <p>Reserved for future use.</p>
     */
    inline void SetType(BlockerType&& value) { m_typeHasBeenSet = true; m_type = std::move(value); }

    /**
     * <p>Reserved for future use.</p>
     */
    inline BlockerDeclaration& WithType(const BlockerType& value) { SetType(value); return *this;}

    /**
     * <p>Reserved for future use.</p>
     */
    inline BlockerDeclaration& WithType(BlockerType&& value) { SetType(std::move(value)); return *this;}

  private:

    Aws::String m_name;
    bool m_nameHasBeenSet = false;

    BlockerType m_type;
    bool m_typeHasBeenSet = false;
  };

} // namespace Model
} // namespace CodePipeline
} // namespace Aws
